// automatically generated by the FlatBuffers compiler, do not modify


#ifndef FLATBUFFERS_GENERATED_MODEL_SECAGG_H_
#define FLATBUFFERS_GENERATED_MODEL_SECAGG_H_

#include "flatbuffers/flatbuffers.h"

namespace secagg {

struct KVPair;
struct KVPairBuilder;

struct Model;
struct ModelBuilder;

struct KVPair FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  typedef KVPairBuilder Builder;
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_KEY = 4,
    VT_VALUE = 6
  };
  const flatbuffers::String *key() const {
    return GetPointer<const flatbuffers::String *>(VT_KEY);
  }
  const flatbuffers::Vector<double> *value() const {
    return GetPointer<const flatbuffers::Vector<double> *>(VT_VALUE);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyOffset(verifier, VT_KEY) &&
           verifier.VerifyString(key()) &&
           VerifyOffset(verifier, VT_VALUE) &&
           verifier.VerifyVector(value()) &&
           verifier.EndTable();
  }
};

struct KVPairBuilder {
  typedef KVPair Table;
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_key(flatbuffers::Offset<flatbuffers::String> key) {
    fbb_.AddOffset(KVPair::VT_KEY, key);
  }
  void add_value(flatbuffers::Offset<flatbuffers::Vector<double>> value) {
    fbb_.AddOffset(KVPair::VT_VALUE, value);
  }
  explicit KVPairBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  KVPairBuilder &operator=(const KVPairBuilder &);
  flatbuffers::Offset<KVPair> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<KVPair>(end);
    return o;
  }
};

inline flatbuffers::Offset<KVPair> CreateKVPair(
    flatbuffers::FlatBufferBuilder &_fbb,
    flatbuffers::Offset<flatbuffers::String> key = 0,
    flatbuffers::Offset<flatbuffers::Vector<double>> value = 0) {
  KVPairBuilder builder_(_fbb);
  builder_.add_value(value);
  builder_.add_key(key);
  return builder_.Finish();
}

inline flatbuffers::Offset<KVPair> CreateKVPairDirect(
    flatbuffers::FlatBufferBuilder &_fbb,
    const char *key = nullptr,
    const std::vector<double> *value = nullptr) {
  auto key__ = key ? _fbb.CreateString(key) : 0;
  auto value__ = value ? _fbb.CreateVector<double>(*value) : 0;
  return secagg::CreateKVPair(
      _fbb,
      key__,
      value__);
}

struct Model FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  typedef ModelBuilder Builder;
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_KV = 4
  };
  const flatbuffers::Vector<flatbuffers::Offset<secagg::KVPair>> *kv() const {
    return GetPointer<const flatbuffers::Vector<flatbuffers::Offset<secagg::KVPair>> *>(VT_KV);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyOffset(verifier, VT_KV) &&
           verifier.VerifyVector(kv()) &&
           verifier.VerifyVectorOfTables(kv()) &&
           verifier.EndTable();
  }
};

struct ModelBuilder {
  typedef Model Table;
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_kv(flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<secagg::KVPair>>> kv) {
    fbb_.AddOffset(Model::VT_KV, kv);
  }
  explicit ModelBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  ModelBuilder &operator=(const ModelBuilder &);
  flatbuffers::Offset<Model> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<Model>(end);
    return o;
  }
};

inline flatbuffers::Offset<Model> CreateModel(
    flatbuffers::FlatBufferBuilder &_fbb,
    flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<secagg::KVPair>>> kv = 0) {
  ModelBuilder builder_(_fbb);
  builder_.add_kv(kv);
  return builder_.Finish();
}

inline flatbuffers::Offset<Model> CreateModelDirect(
    flatbuffers::FlatBufferBuilder &_fbb,
    const std::vector<flatbuffers::Offset<secagg::KVPair>> *kv = nullptr) {
  auto kv__ = kv ? _fbb.CreateVector<flatbuffers::Offset<secagg::KVPair>>(*kv) : 0;
  return secagg::CreateModel(
      _fbb,
      kv__);
}

inline const secagg::Model *GetModel(const void *buf) {
  return flatbuffers::GetRoot<secagg::Model>(buf);
}

inline const secagg::Model *GetSizePrefixedModel(const void *buf) {
  return flatbuffers::GetSizePrefixedRoot<secagg::Model>(buf);
}

inline bool VerifyModelBuffer(
    flatbuffers::Verifier &verifier) {
  return verifier.VerifyBuffer<secagg::Model>(nullptr);
}

inline bool VerifySizePrefixedModelBuffer(
    flatbuffers::Verifier &verifier) {
  return verifier.VerifySizePrefixedBuffer<secagg::Model>(nullptr);
}

inline void FinishModelBuffer(
    flatbuffers::FlatBufferBuilder &fbb,
    flatbuffers::Offset<secagg::Model> root) {
  fbb.Finish(root);
}

inline void FinishSizePrefixedModelBuffer(
    flatbuffers::FlatBufferBuilder &fbb,
    flatbuffers::Offset<secagg::Model> root) {
  fbb.FinishSizePrefixed(root);
}

}  // namespace secagg

#endif  // FLATBUFFERS_GENERATED_MODEL_SECAGG_H_
