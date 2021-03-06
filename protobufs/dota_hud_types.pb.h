// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: dota_hud_types.proto

#ifndef PROTOBUF_dota_5fhud_5ftypes_2eproto__INCLUDED
#define PROTOBUF_dota_5fhud_5ftypes_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 2006000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 2006001 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/generated_enum_reflection.h>
#include "google/protobuf/descriptor.pb.h"
// @@protoc_insertion_point(includes)

// Internal implementation detail -- do not call these.
void  protobuf_AddDesc_dota_5fhud_5ftypes_2eproto();
void protobuf_AssignDesc_dota_5fhud_5ftypes_2eproto();
void protobuf_ShutdownFile_dota_5fhud_5ftypes_2eproto();


enum EHeroSelectionText {
  k_EHeroSelectionText_Invalid = -1,
  k_EHeroSelectionText_None = 0,
  k_EHeroSelectionText_ChooseHero = 1,
  k_EHeroSelectionText_AllDraft_Planning_YouFirst = 2,
  k_EHeroSelectionText_AllDraft_Planning_TheyFirst = 3,
  k_EHeroSelectionText_AllDraft_BanSelected_YouFirst = 4,
  k_EHeroSelectionText_AllDraft_BanSelected_TheyFirst = 5,
  k_EHeroSelectionText_AllDraft_YouPicking = 6,
  k_EHeroSelectionText_AllDraft_TheyPicking = 7,
  k_EHeroSelectionText_AllDraft_TeammateRandomed = 8,
  k_EHeroSelectionText_AllDraft_YouPicking_LosingGold = 9,
  k_EHeroSelectionText_AllDraft_TheyPicking_LosingGold = 10
};
bool EHeroSelectionText_IsValid(int value);
const EHeroSelectionText EHeroSelectionText_MIN = k_EHeroSelectionText_Invalid;
const EHeroSelectionText EHeroSelectionText_MAX = k_EHeroSelectionText_AllDraft_TheyPicking_LosingGold;
const int EHeroSelectionText_ARRAYSIZE = EHeroSelectionText_MAX + 1;

const ::google::protobuf::EnumDescriptor* EHeroSelectionText_descriptor();
inline const ::std::string& EHeroSelectionText_Name(EHeroSelectionText value) {
  return ::google::protobuf::internal::NameOfEnum(
    EHeroSelectionText_descriptor(), value);
}
inline bool EHeroSelectionText_Parse(
    const ::std::string& name, EHeroSelectionText* value) {
  return ::google::protobuf::internal::ParseNamedEnum<EHeroSelectionText>(
    EHeroSelectionText_descriptor(), name, value);
}
// ===================================================================


// ===================================================================

static const int kHudLocalizeTokenFieldNumber = 50501;
extern ::google::protobuf::internal::ExtensionIdentifier< ::google::protobuf::EnumValueOptions,
    ::google::protobuf::internal::StringTypeTraits, 9, false >
  hud_localize_token;

// ===================================================================


// @@protoc_insertion_point(namespace_scope)

#ifndef SWIG
namespace google {
namespace protobuf {

template <> struct is_proto_enum< ::EHeroSelectionText> : ::google::protobuf::internal::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::EHeroSelectionText>() {
  return ::EHeroSelectionText_descriptor();
}

}  // namespace google
}  // namespace protobuf
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_dota_5fhud_5ftypes_2eproto__INCLUDED
