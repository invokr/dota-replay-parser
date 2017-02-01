#include <emscripten/bind.h>
#include "animate2.hpp"

void ReplayViewer::open(std::string path) {
  p.open(path);
  p.generateFullPacketCache();
  p.readHeader();
}

void ReplayViewer::setTick(int tick) {
  p.skipTo(tick);
  replayTick = tick;
  isPaused = false;
}

int ReplayViewer::skipToNextFullPacket(int direction) {
  uint32_t tick = 0;
  for (int i = 0; i < p.fpackcachetick.size(); ++i) {
    if (direction == -1) {
      if (p.fpackcachetick[i] >= p.tick) {
        break;
      }
      tick = p.fpackcachetick[i];
    }
    else {
      tick = p.fpackcachetick[i];
      if (p.fpackcachetick[i] > p.tick) {
        break;
      }
    }
  }
  p.skipTo(tick);
  replayTick = tick;
  isPaused = false;
  return (int)tick;
}

int ReplayViewer::changePlayback(int state) {
  switch (state) {
    case 0:
      isPaused = false;
    break;
    case 1:
      isPaused = true;
    break;
    case 2:
      return (int)skipToNextFullPacket(-1);
    break;
    case 3:
      return (int)skipToNextFullPacket(1);
    break;
    case 4:
      if (playbackSpeed > 1) playbackSpeed = (int)(playbackSpeed / 2);
      return playbackSpeed;
    break;
    case 5:
      if (playbackSpeed < 1024) playbackSpeed = (int)(playbackSpeed * 2);
      return playbackSpeed;
    break;
  }
  return 0;
}

bool ReplayViewer::getCoordinates(PacketEntity* pe, Point2f& pos) {
  uint64_t cX;
  uint64_t cY;
  float vX;
  float vY;
  
  if (!pe->fetchUint64("CBodyComponentBaseAnimatingOverlay.m_cellX", cX)) return false;
  if (!pe->fetchUint64("CBodyComponentBaseAnimatingOverlay.m_cellY", cY)) return false;
  if (!pe->fetchFloat32("CBodyComponentBaseAnimatingOverlay.m_vecX", vX)) return false;
  if (!pe->fetchFloat32("CBodyComponentBaseAnimatingOverlay.m_vecY", vY)) return false;
  
  pos.x = (((double)cX * cellWidth) - MAX_COORDINATE) + (double)vX;
  pos.y = (((double)cY * cellWidth) - MAX_COORDINATE) + (double)vY;
  
  return true;
}

TickState ReplayViewer::getCurrentTickState() {
  TickState tickState;
  
  tickState.game.isPaused = isPaused;
  tickState.game.state = gameState;
  tickState.tick = p.tick;
  
  if (isPaused) return tickState;
  
  while (p.good() && p.tick < replayTick) {
    p.read();
  }
  
  tickState.tick = p.tick;
  
  for(auto& kv : p.packetEntities) {
    if (isPrefix(kv.second->className, "CDOTA_Unit_Hero_")) {
      HeroState hero;
      
      uint64_t lifeState;
      if (!kv.second->fetchUint64("m_lifeState", lifeState)) continue;
      hero.lifeState = (int)lifeState;
      if (lifeState != 0) continue;

      uint32_t replicatingOtherHeroModel;
      if (!kv.second->fetchUint32("m_hReplicatingOtherHeroModel", replicatingOtherHeroModel)) continue;
      hero.isIllusion = (replicatingOtherHeroModel & 2047) != 2047;
      
      Point2f pos;
      if (!getCoordinates(kv.second, pos)) {
        continue;
      }
      else {
        hero.pos = pos;
      }
      
      hero.className = kv.second->className;
      
      int32_t health;
      if (kv.second->fetchInt32("m_iHealth", health)) {
        hero.health = (int)health;
      }
      
      tickState.heroes.push_back(hero);
    }
    else if (isPrefix(kv.second->className, "CDOTA_Unit_Courier")) {
      CourierState courier;
      
      uint64_t lifeState;
      if (!kv.second->fetchUint64("m_lifeState", lifeState)) continue;
      courier.lifeState = (int)lifeState;
      if (lifeState != 0) continue;
      
      bool isFlying;
      kv.second->fetchBool("m_bFlyingCourier", isFlying);
      courier.isFlying = isFlying;
    
      Point2f pos;
      if (!getCoordinates(kv.second, pos)) {
        continue;
      }
      else {
        courier.pos = pos;
      }
      

      float respawnTime;
      if (kv.second->fetchFloat32("m_flRespawnTime", respawnTime)) {
        courier.respawnTime = respawnTime;
      }
      
      tickState.couriers.push_back(courier);
    }
    else if (isPrefix(kv.second->className, "CDOTA_BaseNPC_Creep")) {
      CreepState creep;
      
      bool isWaitingToSpawn;
      if (!kv.second->fetchBool("m_bIsWaitingToSpawn", isWaitingToSpawn)) continue;
      creep.isWaitingToSpawn = isWaitingToSpawn;
      if (isWaitingToSpawn) continue;
      
      uint64_t lifeState;
      if (!kv.second->fetchUint64("m_lifeState", lifeState)) continue;
      creep.lifeState = (int)lifeState;
      if (lifeState != 0) continue;
      
      uint64_t team;
      getTeam(kv.second, team);
      creep.team = (int)team;

      Point2f pos;
      if (!getCoordinates(kv.second, pos)) {
        continue;
      }
      else {
        creep.pos = pos;
      }
      
      tickState.creeps.push_back(creep);
      
    }
    else if (isPrefix(kv.second->className, "CDOTA_BaseNPC_Fort") ||
               isPrefix(kv.second->className, "CDOTA_BaseNPC_Barracks") ||
               isPrefix(kv.second->className, "CDOTA_BaseNPC_Tower")) {
      if (gameState < 4) continue;
      
      BuildingState building;
      
      uint64_t team;
      getTeam(kv.second, team);
      building.team = (int)team;

      building.className = kv.second->className;
      
      Point2f pos;
      if (!getCoordinates(kv.second, pos)) {
        continue;
      }
      else {
        building.pos = pos;
      }
      
      // draw hp
      int32_t health;
      int32_t maxHealth;
      if (!kv.second->fetchInt32("m_iHealth", health)) continue;
      building.health = (int)health;
      if (!kv.second->fetchInt32("m_iMaxHealth", maxHealth)) continue;
      building.maxHealth = (int)maxHealth;

      tickState.buildings.push_back(building);
      
    }
    else if (isPrefix(kv.second->className, "CDOTA_NPC_Observer_Ward")) {
      WardState ward;
      
      uint64_t team;
      getTeam(kv.second, team);
      ward.team = (int)team;

      ward.className = kv.second->className;
      
      Point2f pos;
      if (!getCoordinates(kv.second, pos)) {
        continue;
      }
      else {
        ward.pos = pos;
      }
      
      tickState.wards.push_back(ward);
    }
    else if (isPrefix(kv.second->className, "CDOTAGamerulesProxy")) {
      float _gameTime;            // current time
      float gameStartTime;        // game time at which the pre-game to game transition occurs (creeps spawning). 
      float preGameStartTime;     // game time when the heroes are loaded in and the pre-game begins.
      float stateTransitionTime;  // game time when game mode changes.
      float extraTimeRadiant;     // seconds of reserve/bonus time remaining (0000 for Radiant, 0001 for Dire)
      float extraTimeDire;        // seconds of reserve/bonus time remaining (0000 for Radiant, 0001 for Dire)
      int32_t gameMode;           // Game Mode
      int32_t _gameState;         // Game State
      int32_t netTimeOfDay;       // Time of Day
      uint32_t heroPickState;     // Hero Pick state
      int32_t activeTeam;         // Active Team   
                                  // 2: Radiant is currently picking/banning.
                                  // 3: Dire is currently picking/banning.
      int32_t startingTeam;       // Starting Team
                                  // 0: Not a CM or reverse-CM game.
                                  // 2: Radiant has first pick.
                                  // 3: Dire has first pick.

      kv.second->fetchFloat32("CDOTAGamerules.m_fGameTime", _gameTime);
      kv.second->fetchFloat32("CDOTAGamerules.m_flGameStartTime", gameStartTime);
      kv.second->fetchFloat32("CDOTAGamerules.m_flPreGameStartTime", preGameStartTime);
      kv.second->fetchFloat32("CDOTAGamerules.m_flStateTransitionTime", stateTransitionTime);
      kv.second->fetchFloat32("CDOTAGamerules.m_fExtraTimeRemaining.0000", extraTimeRadiant);
      kv.second->fetchFloat32("CDOTAGamerules.m_fExtraTimeRemaining.0001", extraTimeDire);
      kv.second->fetchInt32("CDOTAGamerules.m_iGameMode", gameMode);
      kv.second->fetchInt32("CDOTAGamerules.m_nGameState", _gameState);
      kv.second->fetchInt32("CDOTAGamerules.m_iNetTimeOfDay", netTimeOfDay);
      kv.second->fetchUint32("CDOTAGamerules.m_nHeroPickState", heroPickState);
      kv.second->fetchInt32("CDOTAGamerules.m_iActiveTeam", activeTeam);
      kv.second->fetchInt32("CDOTAGamerules.m_iStartingTeam", startingTeam);

      tickState.game.state = _gameState;
      tickState.game.time = _gameTime;
      tickState.game.startTime = gameStartTime;
      tickState.game.preGameStartTime = preGameStartTime;
      tickState.game.stateTransitionTime = stateTransitionTime;
      tickState.game.extraTimeRadiant = extraTimeRadiant;
      tickState.game.extraTimeDire = extraTimeDire;
      tickState.game.netTimeOfDay = (int)netTimeOfDay;
      tickState.game.heroPickState = (int)heroPickState;
      tickState.game.activeTeam = (int)activeTeam;
      tickState.game.startingTeam = (int)startingTeam;
    
      if (gameState >= 4) continue;
      for (int i = 0; i < 10; ++i) {
        std::string n = "000" + std::to_string(i);
        int32_t bannedHero;
        int32_t pickedHero;
        kv.second->fetchInt32("CDOTAGamerules.m_BannedHeroes." + n, bannedHero);
        kv.second->fetchInt32("CDOTAGamerules.m_SelectedHeroes." + n, pickedHero);

        if (bannedHero != 0) {
          tickState.game.bans.push_back((int)bannedHero);
        }
        
        if (pickedHero != 0) {
          tickState.game.picks.push_back((int)pickedHero);
        }
      }
    }
    else if (isPrefix(kv.second->className, "CDOTA_DataSpectator")) {
    
    }
    else if (isPrefix(kv.second->className, "CDOTA_DataDire")) {
      for (int i = 0; i < 5; ++i) {
        std::string n = "000" + std::to_string(i);
        int32_t goldUnreliable;
        int32_t goldReliable;
        kv.second->fetchInt32("m_vecDataTeam." + n + ".m_iUnreliableGold", goldUnreliable);
        tickState.dire.unreliableGold.push_back((int)goldUnreliable);
        kv.second->fetchInt32("m_vecDataTeam." + n + ".m_iReliableGold", goldReliable);
        tickState.dire.reliableGold.push_back((int)goldReliable);
      }
    }
    else if (isPrefix(kv.second->className, "CDOTA_DataRadiant")) {
      for (int i = 0; i < 5; ++i) {
        std::string n = "000" + std::to_string(i);
        int32_t goldUnreliable;
        int32_t goldReliable;
        kv.second->fetchInt32("m_vecDataTeam." + n + ".m_iUnreliableGold", goldUnreliable);
        tickState.radiant.unreliableGold.push_back((int)goldUnreliable);
        kv.second->fetchInt32("m_vecDataTeam." + n + ".m_iReliableGold", goldReliable);
        tickState.radiant.reliableGold.push_back((int)goldReliable);
      }
    }
    else if (isPrefix(kv.second->className, "CDOTA_PlayerResource")) {
      if (gameState < 4) continue;
      
      for (int i = 0; i < 10; ++i) {
        PlayerResourceState playerResource;
        
        std::string n = "000" + std::to_string(i);
        std::string playerName;
        uint64_t steamId;
        uint32_t heroEntId;
        int32_t kills;
        int32_t deaths;
        int32_t assists;
        int32_t streak;
        int32_t level;
        int32_t respawnSeconds;
        
        if (!kv.second->fetchString("m_vecPlayerData." + n + ".m_iszPlayerName", playerName)) continue;
        if (!kv.second->fetchUint64("m_vecPlayerData." + n + ".m_iPlayerSteamID", steamId)) continue;
        if (!kv.second->fetchUint32("m_vecPlayerTeamData." + n + ".m_hSelectedHero", heroEntId)) continue;
        if (!kv.second->fetchInt32("m_vecPlayerTeamData." + n + ".m_iKills", kills)) continue;
        if (!kv.second->fetchInt32("m_vecPlayerTeamData." + n + ".m_iDeaths", deaths)) continue;
        if (!kv.second->fetchInt32("m_vecPlayerTeamData." + n + ".m_iAssists", assists)) continue;
        if (!kv.second->fetchInt32("m_vecPlayerTeamData." + n + ".m_iStreak", streak)) continue;
        if (!kv.second->fetchInt32("m_vecPlayerTeamData." + n + ".m_iLevel", level)) continue;
        if (!kv.second->fetchInt32("m_vecPlayerTeamData." + n + ".m_iRespawnSeconds", respawnSeconds)) continue;
        
        heroEntId = heroEntId & 2047;
        
        playerResource.playerName = playerName;
        playerResource.steamId = (float)steamId;
        playerResource.heroEntId = (int)heroEntId;
        playerResource.kills = (int)kills;
        playerResource.deaths = (int)deaths;
        playerResource.assists = (int)assists;
        playerResource.streak = (int)streak;
        playerResource.level = (int)level;
        playerResource.respawnSeconds = (int)respawnSeconds;
        
        if (p.packetEntities.find(heroEntId) == p.packetEntities.end()) continue;

        for (int j = 0; j < 16; ++j) {
          AbilityState ability;
          
          char buf[5];
          sprintf(buf, "%04d", j);
          std::string m = std::string(buf, 4);
          uint32_t abilityEntityId;
          if (!p.packetEntities[heroEntId]->fetchUint32("m_hAbilities." + m, abilityEntityId)) continue;
          abilityEntityId = abilityEntityId & 2047;
          if (abilityEntityId != 2047) {
            if (p.packetEntities.find(abilityEntityId) == p.packetEntities.end()) continue;
            int32_t abilityEntNameIndex;
            p.packetEntities[abilityEntityId]->fetchInt32("CEntityIdentity.m_nameStringableIndex", abilityEntNameIndex);
            StringTable* entityNamesTable = p.stringTables.tables[p.stringTables.nameIndex["EntityNames"]];
            const std::string& abilityEntName = entityNamesTable->items[abilityEntNameIndex]->key;
            
            ability.name = abilityEntName;
            
            int32_t abilityLevel;
            if (p.packetEntities[abilityEntityId]->fetchInt32("m_iLevel", abilityLevel)) {
              ability.level = (int)abilityLevel;
            }
            
            float cooldown;
            if (p.packetEntities[abilityEntityId]->fetchFloat32("m_fCooldown", cooldown)) {
              ability.level = cooldown;
            }
          }
          
          playerResource.abilities.push_back(ability);
        }
        
        playerResource.heroClassName = p.packetEntities[heroEntId]->className;
        
        for (int j = 0; j < 14; ++j) {
          ItemState item;
          
          std::string k = "000" + std::to_string(j);
          uint32_t itemEntId;
          if (!p.packetEntities[heroEntId]->fetchUint32("m_hItems." + k, itemEntId)) {
            item.isEmpty = true;
          }
          
          itemEntId = itemEntId & 2047;
          if (itemEntId == 2047) {
            item.isEmpty = true;
          }
          else {
            item.isEmpty = false;
            if (p.packetEntities.find(itemEntId) == p.packetEntities.end()) continue;
            int32_t itemEntNameIndex;
            p.packetEntities[itemEntId]->fetchInt32("CEntityIdentity.m_nameStringableIndex", itemEntNameIndex);
            StringTable* entityNamesTable = p.stringTables.tables[p.stringTables.nameIndex["EntityNames"]];
            const std::string& itemEntName = entityNamesTable->items[itemEntNameIndex]->key;
            
            item.name = itemEntName;
          }
          
          playerResource.items.push_back(item);
        }
        
        tickState.playerResources.push_back(playerResource);
      }
    }
  }
  
  return tickState;
}

using namespace emscripten;

EMSCRIPTEN_BINDINGS(stl_wrappers) {
    register_vector<int>("VectorInt");
    register_vector<HeroState>("VectorHeroState");
    register_vector<CreepState>("VectorCreepState");
    register_vector<WardState>("VectorWardState");
    register_vector<CourierState>("VectorCourierState");
    register_vector<BuildingState>("VectorBuildingState");
    register_vector<PlayerResourceState>("VectorPlayerResourceState");
    register_vector<AbilityState>("VectorAbilityState");
    register_vector<ItemState>("VectorItemState");
}

EMSCRIPTEN_BINDINGS(ReplayViewer) {
    class_<ReplayViewer>("ReplayViewer")
        .constructor()
        .function("open", &ReplayViewer::open)
        .function("setTick", &ReplayViewer::setTick)
        .function("skipToNextFullPacket", &ReplayViewer::skipToNextFullPacket)
        .function("getCurrentTickState", &ReplayViewer::getCurrentTickState)
        .function("changePlayback", &ReplayViewer::changePlayback)
        .property("replayTick", &ReplayViewer::getReplayTick, &ReplayViewer::setReplayTick)
        ;
        
    value_array<Point2f>("Point2f")
        .element(&Point2f::x)
        .element(&Point2f::y)
        ;
        
    value_object<HeroState>("HeroState")
        .field("isIllusion", &HeroState::isIllusion)
        .field("pos", &HeroState::pos)
        .field("className", &HeroState::className)
        .field("lifeState", &HeroState::lifeState)
        .field("health", &HeroState::health)
        ;
        
    value_object<CreepState>("CreepState")
        .field("isWaitingToSpawn", &CreepState::isWaitingToSpawn)
        .field("lifeState", &CreepState::lifeState)
        .field("team", &CreepState::team)
        .field("pos", &CreepState::pos)
        ;
        
    value_object<WardState>("WardState")
        .field("team", &WardState::team)
        .field("className", &WardState::className)
        .field("pos", &WardState::pos)
        ;
        
    value_object<CourierState>("CourierState")
        .field("lifeState", &CourierState::lifeState)
        .field("isFlying", &CourierState::isFlying)
        .field("pos", &CourierState::pos)
        .field("respawnTime", &CourierState::respawnTime)
        ;
        
    value_object<BuildingState>("BuildingState")
        .field("team", &BuildingState::team)
        .field("className", &BuildingState::className)
        .field("pos", &BuildingState::pos)
        .field("health", &BuildingState::health)
        .field("maxHealth", &BuildingState::maxHealth)
        ;
        
    value_object<ItemState>("ItemState")
        .field("name", &ItemState::name)
        .field("isEmpty", &ItemState::isEmpty)
        ;
        
    value_object<AbilityState>("AbilityState")
        .field("name", &AbilityState::name)
        .field("level", &AbilityState::level)
        .field("cooldown", &AbilityState::cooldown)
        ;
        
    value_object<PlayerResourceState>("PlayerResourceState")
        .field("playerName", &PlayerResourceState::playerName)
        .field("heroClassName", &PlayerResourceState::heroClassName)
        .field("steamId", &PlayerResourceState::steamId)
        .field("heroEntId", &PlayerResourceState::heroEntId)
        .field("kills", &PlayerResourceState::kills)
        .field("deaths", &PlayerResourceState::deaths)
        .field("assists", &PlayerResourceState::assists)
        .field("streak", &PlayerResourceState::streak)
        .field("level", &PlayerResourceState::level)
        .field("respawnSeconds", &PlayerResourceState::respawnSeconds)
        .field("abilities", &PlayerResourceState::abilities)
        .field("items", &PlayerResourceState::items)
        ;
        
    value_object<GameState>("GameState")
        .field("isPaused", &GameState::isPaused)
        .field("state", &GameState::state)
        .field("time", &GameState::time)
        .field("startTime", &GameState::startTime)
        .field("preGameStartTime", &GameState::preGameStartTime)
        .field("stateTransitionTime", &GameState::stateTransitionTime)
        .field("extraTimeRadiant", &GameState::extraTimeRadiant)
        .field("extraTimeDire", &GameState::extraTimeDire)
        .field("netTimeOfDay", &GameState::netTimeOfDay)
        .field("heroPickState", &GameState::heroPickState)
        .field("activeTeam", &GameState::activeTeam)
        .field("startingTeam", &GameState::startingTeam)
        .field("bans", &GameState::bans)
        .field("picks", &GameState::picks)
        ;
        
    value_object<TeamState>("TeamState")
        .field("reliableGold", &TeamState::reliableGold)
        .field("unreliableGold", &TeamState::unreliableGold)
        ;
    
    value_object<TickState>("TickState")
        .field("tick", &TickState::tick)
        .field("heroes", &TickState::heroes)
        .field("creeps", &TickState::creeps)
        .field("wards", &TickState::wards)
        .field("couriers", &TickState::couriers)
        .field("buildings", &TickState::buildings)
        .field("playerResources", &TickState::playerResources)
        .field("game", &TickState::game)
        .field("dire", &TickState::dire)
        .field("radiant", &TickState::radiant)
        ;
}