// ArduinoJson - arduinojson.org
// Copyright Benoit Blanchon 2014-2020
// MIT License

#pragma once

#include "../Namespace.hpp"

#include <stddef.h>  // size_t

namespace ARDUINOJSON_NAMESPACE {

inline bool isAligned(void *ptr) {
  const size_t mask = sizeof(void *) - 1;
  size_t addr = reinterpret_cast<size_t>(ptr);
  return (addr & mask) == 0;
}

inline size_t addPadding(size_t bytes) {
  const size_t mask = sizeof(void *) - 1;
  return (bytes + mask) & ~mask;
}

template <typename T>
inline T *addPadding(T *p) {
  size_t address = addPadding(reinterpret_cast<size_t>(p));
  return reinterpret_cast<T *>(address);
}

template <size_t bytes>
struct AddPadding {
  static const size_t mask = sizeof(void *) - 1;
  static const size_t value = (bytes + mask) & ~mask;
};

}  // namespace ARDUINOJSON_NAMESPACE
