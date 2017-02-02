// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: networksystem_protomessages.proto

#ifndef PROTOBUF_networksystem_5fprotomessages_2eproto__INCLUDED
#define PROTOBUF_networksystem_5fprotomessages_2eproto__INCLUDED

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
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)

// Internal implementation detail -- do not call these.
void  protobuf_AddDesc_networksystem_5fprotomessages_2eproto();
void protobuf_AssignDesc_networksystem_5fprotomessages_2eproto();
void protobuf_ShutdownFile_networksystem_5fprotomessages_2eproto();

class NetMessageSplitscreenUserChanged;
class NetMessageConnectionClosed;
class NetMessageConnectionCrashed;
class NetMessagePacketStart;
class NetMessagePacketEnd;

// ===================================================================

class NetMessageSplitscreenUserChanged : public ::google::protobuf::Message {
 public:
  NetMessageSplitscreenUserChanged();
  virtual ~NetMessageSplitscreenUserChanged();

  NetMessageSplitscreenUserChanged(const NetMessageSplitscreenUserChanged& from);

  inline NetMessageSplitscreenUserChanged& operator=(const NetMessageSplitscreenUserChanged& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const NetMessageSplitscreenUserChanged& default_instance();

  void Swap(NetMessageSplitscreenUserChanged* other);

  // implements Message ----------------------------------------------

  NetMessageSplitscreenUserChanged* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const NetMessageSplitscreenUserChanged& from);
  void MergeFrom(const NetMessageSplitscreenUserChanged& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:
  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // optional uint32 slot = 1;
  inline bool has_slot() const;
  inline void clear_slot();
  static const int kSlotFieldNumber = 1;
  inline ::google::protobuf::uint32 slot() const;
  inline void set_slot(::google::protobuf::uint32 value);

  // @@protoc_insertion_point(class_scope:NetMessageSplitscreenUserChanged)
 private:
  inline void set_has_slot();
  inline void clear_has_slot();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::uint32 _has_bits_[1];
  mutable int _cached_size_;
  ::google::protobuf::uint32 slot_;
  friend void  protobuf_AddDesc_networksystem_5fprotomessages_2eproto();
  friend void protobuf_AssignDesc_networksystem_5fprotomessages_2eproto();
  friend void protobuf_ShutdownFile_networksystem_5fprotomessages_2eproto();

  void InitAsDefaultInstance();
  static NetMessageSplitscreenUserChanged* default_instance_;
};
// -------------------------------------------------------------------

class NetMessageConnectionClosed : public ::google::protobuf::Message {
 public:
  NetMessageConnectionClosed();
  virtual ~NetMessageConnectionClosed();

  NetMessageConnectionClosed(const NetMessageConnectionClosed& from);

  inline NetMessageConnectionClosed& operator=(const NetMessageConnectionClosed& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const NetMessageConnectionClosed& default_instance();

  void Swap(NetMessageConnectionClosed* other);

  // implements Message ----------------------------------------------

  NetMessageConnectionClosed* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const NetMessageConnectionClosed& from);
  void MergeFrom(const NetMessageConnectionClosed& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:
  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // optional uint32 reason = 1;
  inline bool has_reason() const;
  inline void clear_reason();
  static const int kReasonFieldNumber = 1;
  inline ::google::protobuf::uint32 reason() const;
  inline void set_reason(::google::protobuf::uint32 value);

  // @@protoc_insertion_point(class_scope:NetMessageConnectionClosed)
 private:
  inline void set_has_reason();
  inline void clear_has_reason();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::uint32 _has_bits_[1];
  mutable int _cached_size_;
  ::google::protobuf::uint32 reason_;
  friend void  protobuf_AddDesc_networksystem_5fprotomessages_2eproto();
  friend void protobuf_AssignDesc_networksystem_5fprotomessages_2eproto();
  friend void protobuf_ShutdownFile_networksystem_5fprotomessages_2eproto();

  void InitAsDefaultInstance();
  static NetMessageConnectionClosed* default_instance_;
};
// -------------------------------------------------------------------

class NetMessageConnectionCrashed : public ::google::protobuf::Message {
 public:
  NetMessageConnectionCrashed();
  virtual ~NetMessageConnectionCrashed();

  NetMessageConnectionCrashed(const NetMessageConnectionCrashed& from);

  inline NetMessageConnectionCrashed& operator=(const NetMessageConnectionCrashed& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const NetMessageConnectionCrashed& default_instance();

  void Swap(NetMessageConnectionCrashed* other);

  // implements Message ----------------------------------------------

  NetMessageConnectionCrashed* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const NetMessageConnectionCrashed& from);
  void MergeFrom(const NetMessageConnectionCrashed& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:
  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // optional uint32 reason = 1;
  inline bool has_reason() const;
  inline void clear_reason();
  static const int kReasonFieldNumber = 1;
  inline ::google::protobuf::uint32 reason() const;
  inline void set_reason(::google::protobuf::uint32 value);

  // @@protoc_insertion_point(class_scope:NetMessageConnectionCrashed)
 private:
  inline void set_has_reason();
  inline void clear_has_reason();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::uint32 _has_bits_[1];
  mutable int _cached_size_;
  ::google::protobuf::uint32 reason_;
  friend void  protobuf_AddDesc_networksystem_5fprotomessages_2eproto();
  friend void protobuf_AssignDesc_networksystem_5fprotomessages_2eproto();
  friend void protobuf_ShutdownFile_networksystem_5fprotomessages_2eproto();

  void InitAsDefaultInstance();
  static NetMessageConnectionCrashed* default_instance_;
};
// -------------------------------------------------------------------

class NetMessagePacketStart : public ::google::protobuf::Message {
 public:
  NetMessagePacketStart();
  virtual ~NetMessagePacketStart();

  NetMessagePacketStart(const NetMessagePacketStart& from);

  inline NetMessagePacketStart& operator=(const NetMessagePacketStart& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const NetMessagePacketStart& default_instance();

  void Swap(NetMessagePacketStart* other);

  // implements Message ----------------------------------------------

  NetMessagePacketStart* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const NetMessagePacketStart& from);
  void MergeFrom(const NetMessagePacketStart& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:
  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // optional uint32 incoming_sequence = 1;
  inline bool has_incoming_sequence() const;
  inline void clear_incoming_sequence();
  static const int kIncomingSequenceFieldNumber = 1;
  inline ::google::protobuf::uint32 incoming_sequence() const;
  inline void set_incoming_sequence(::google::protobuf::uint32 value);

  // optional uint32 outgoing_acknowledged = 2;
  inline bool has_outgoing_acknowledged() const;
  inline void clear_outgoing_acknowledged();
  static const int kOutgoingAcknowledgedFieldNumber = 2;
  inline ::google::protobuf::uint32 outgoing_acknowledged() const;
  inline void set_outgoing_acknowledged(::google::protobuf::uint32 value);

  // @@protoc_insertion_point(class_scope:NetMessagePacketStart)
 private:
  inline void set_has_incoming_sequence();
  inline void clear_has_incoming_sequence();
  inline void set_has_outgoing_acknowledged();
  inline void clear_has_outgoing_acknowledged();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::uint32 _has_bits_[1];
  mutable int _cached_size_;
  ::google::protobuf::uint32 incoming_sequence_;
  ::google::protobuf::uint32 outgoing_acknowledged_;
  friend void  protobuf_AddDesc_networksystem_5fprotomessages_2eproto();
  friend void protobuf_AssignDesc_networksystem_5fprotomessages_2eproto();
  friend void protobuf_ShutdownFile_networksystem_5fprotomessages_2eproto();

  void InitAsDefaultInstance();
  static NetMessagePacketStart* default_instance_;
};
// -------------------------------------------------------------------

class NetMessagePacketEnd : public ::google::protobuf::Message {
 public:
  NetMessagePacketEnd();
  virtual ~NetMessagePacketEnd();

  NetMessagePacketEnd(const NetMessagePacketEnd& from);

  inline NetMessagePacketEnd& operator=(const NetMessagePacketEnd& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const NetMessagePacketEnd& default_instance();

  void Swap(NetMessagePacketEnd* other);

  // implements Message ----------------------------------------------

  NetMessagePacketEnd* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const NetMessagePacketEnd& from);
  void MergeFrom(const NetMessagePacketEnd& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:
  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // @@protoc_insertion_point(class_scope:NetMessagePacketEnd)
 private:

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::uint32 _has_bits_[1];
  mutable int _cached_size_;
  friend void  protobuf_AddDesc_networksystem_5fprotomessages_2eproto();
  friend void protobuf_AssignDesc_networksystem_5fprotomessages_2eproto();
  friend void protobuf_ShutdownFile_networksystem_5fprotomessages_2eproto();

  void InitAsDefaultInstance();
  static NetMessagePacketEnd* default_instance_;
};
// ===================================================================


// ===================================================================

// NetMessageSplitscreenUserChanged

// optional uint32 slot = 1;
inline bool NetMessageSplitscreenUserChanged::has_slot() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void NetMessageSplitscreenUserChanged::set_has_slot() {
  _has_bits_[0] |= 0x00000001u;
}
inline void NetMessageSplitscreenUserChanged::clear_has_slot() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void NetMessageSplitscreenUserChanged::clear_slot() {
  slot_ = 0u;
  clear_has_slot();
}
inline ::google::protobuf::uint32 NetMessageSplitscreenUserChanged::slot() const {
  // @@protoc_insertion_point(field_get:NetMessageSplitscreenUserChanged.slot)
  return slot_;
}
inline void NetMessageSplitscreenUserChanged::set_slot(::google::protobuf::uint32 value) {
  set_has_slot();
  slot_ = value;
  // @@protoc_insertion_point(field_set:NetMessageSplitscreenUserChanged.slot)
}

// -------------------------------------------------------------------

// NetMessageConnectionClosed

// optional uint32 reason = 1;
inline bool NetMessageConnectionClosed::has_reason() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void NetMessageConnectionClosed::set_has_reason() {
  _has_bits_[0] |= 0x00000001u;
}
inline void NetMessageConnectionClosed::clear_has_reason() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void NetMessageConnectionClosed::clear_reason() {
  reason_ = 0u;
  clear_has_reason();
}
inline ::google::protobuf::uint32 NetMessageConnectionClosed::reason() const {
  // @@protoc_insertion_point(field_get:NetMessageConnectionClosed.reason)
  return reason_;
}
inline void NetMessageConnectionClosed::set_reason(::google::protobuf::uint32 value) {
  set_has_reason();
  reason_ = value;
  // @@protoc_insertion_point(field_set:NetMessageConnectionClosed.reason)
}

// -------------------------------------------------------------------

// NetMessageConnectionCrashed

// optional uint32 reason = 1;
inline bool NetMessageConnectionCrashed::has_reason() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void NetMessageConnectionCrashed::set_has_reason() {
  _has_bits_[0] |= 0x00000001u;
}
inline void NetMessageConnectionCrashed::clear_has_reason() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void NetMessageConnectionCrashed::clear_reason() {
  reason_ = 0u;
  clear_has_reason();
}
inline ::google::protobuf::uint32 NetMessageConnectionCrashed::reason() const {
  // @@protoc_insertion_point(field_get:NetMessageConnectionCrashed.reason)
  return reason_;
}
inline void NetMessageConnectionCrashed::set_reason(::google::protobuf::uint32 value) {
  set_has_reason();
  reason_ = value;
  // @@protoc_insertion_point(field_set:NetMessageConnectionCrashed.reason)
}

// -------------------------------------------------------------------

// NetMessagePacketStart

// optional uint32 incoming_sequence = 1;
inline bool NetMessagePacketStart::has_incoming_sequence() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void NetMessagePacketStart::set_has_incoming_sequence() {
  _has_bits_[0] |= 0x00000001u;
}
inline void NetMessagePacketStart::clear_has_incoming_sequence() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void NetMessagePacketStart::clear_incoming_sequence() {
  incoming_sequence_ = 0u;
  clear_has_incoming_sequence();
}
inline ::google::protobuf::uint32 NetMessagePacketStart::incoming_sequence() const {
  // @@protoc_insertion_point(field_get:NetMessagePacketStart.incoming_sequence)
  return incoming_sequence_;
}
inline void NetMessagePacketStart::set_incoming_sequence(::google::protobuf::uint32 value) {
  set_has_incoming_sequence();
  incoming_sequence_ = value;
  // @@protoc_insertion_point(field_set:NetMessagePacketStart.incoming_sequence)
}

// optional uint32 outgoing_acknowledged = 2;
inline bool NetMessagePacketStart::has_outgoing_acknowledged() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void NetMessagePacketStart::set_has_outgoing_acknowledged() {
  _has_bits_[0] |= 0x00000002u;
}
inline void NetMessagePacketStart::clear_has_outgoing_acknowledged() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void NetMessagePacketStart::clear_outgoing_acknowledged() {
  outgoing_acknowledged_ = 0u;
  clear_has_outgoing_acknowledged();
}
inline ::google::protobuf::uint32 NetMessagePacketStart::outgoing_acknowledged() const {
  // @@protoc_insertion_point(field_get:NetMessagePacketStart.outgoing_acknowledged)
  return outgoing_acknowledged_;
}
inline void NetMessagePacketStart::set_outgoing_acknowledged(::google::protobuf::uint32 value) {
  set_has_outgoing_acknowledged();
  outgoing_acknowledged_ = value;
  // @@protoc_insertion_point(field_set:NetMessagePacketStart.outgoing_acknowledged)
}

// -------------------------------------------------------------------

// NetMessagePacketEnd


// @@protoc_insertion_point(namespace_scope)

#ifndef SWIG
namespace google {
namespace protobuf {


}  // namespace google
}  // namespace protobuf
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_networksystem_5fprotomessages_2eproto__INCLUDED