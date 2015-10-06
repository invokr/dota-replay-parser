#ifndef _PARSER_HPP_
#define _PARSER_HPP_

#include <snappy.h>

#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <string.h>
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>

// Protobuf objects
#include "protobufs/ai_activity.pb.h"
#include "protobufs/demo.pb.h"
#include "protobufs/dota_commonmessages.pb.h"
#include "protobufs/dota_modifiers.pb.h"
#include "protobufs/usermessages.pb.h"
#include "protobufs/netmessages.pb.h"
#include "protobufs/networkbasetypes.pb.h"
#include "protobufs/usermessages.pb.h"
#include "protobufs/dota_usermessages.pb.h"
#include "protobufs/gameevents.pb.h"

#include "bitstream.hpp"
#include "parser_types.hpp"
#include "fieldpath.hpp"
#include "property.hpp"
#include "property_decoder.hpp"
#include "flattened_serializers.hpp"
#include "class_info.hpp"
#include "string_table.hpp"
#include "message_lookup.hpp"
#include "packet_entity.hpp"

uint32_t readVarUInt32(std::ifstream &stream);
uint32_t readVarUInt32(const char*, int*);
int packet_priority(int type);
bool compare_packet_priority(pendingMessage i,pendingMessage j);

#endif /* _PARSER_HPP_ */