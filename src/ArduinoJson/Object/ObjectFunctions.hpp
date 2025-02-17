// ArduinoJson - arduinojson.org
// Copyright Benoit Blanchon 2014-2020
// MIT License

#pragma once

#include "../Collection/CollectionData.hpp"

namespace ARDUINOJSON_NAMESPACE {

template <typename Visitor>
void objectAccept(const CollectionData *obj, Visitor &visitor) {
  if (obj)
    visitor.visitObject(*obj);
  else
    visitor.visitNull();
}

inline bool objectEquals(const CollectionData *lhs, const CollectionData *rhs) {
  if (lhs == rhs)
    return true;
  if (!lhs || !rhs)
    return false;
  return lhs->equalsObject(*rhs);
}

template <typename TAdaptedString>
inline VariantData *objectGet(const CollectionData *obj, TAdaptedString key) {
  if (!obj)
    return 0;
  return obj->getMember(key);
}

template <typename TAdaptedString>
void objectRemove(CollectionData *obj, TAdaptedString key) {
  if (!obj)
    return;
  obj->removeMember(key);
}

template <typename TAdaptedString>
inline VariantData *objectGetOrCreate(CollectionData *obj, TAdaptedString key,
                                      MemoryPool *pool) {
  if (!obj)
    return 0;

  // ignore null key
  if (key.isNull())
    return 0;

  // search a matching key
  VariantData *var = obj->getMember(key);
  if (var)
    return var;

  return obj->addMember(key, pool);
}
}  // namespace ARDUINOJSON_NAMESPACE
