// ArduinoJson - arduinojson.org
// Copyright Benoit Blanchon 2014-2020
// MIT License

#pragma once

#include <stddef.h>  // size_t
#include <string.h>  // strcmp

#include "../Polyfills/safe_strcmp.hpp"
#include "../Strings/IsString.hpp"
#include "../Strings/StoragePolicy.hpp"

namespace ARDUINOJSON_NAMESPACE {

class ConstRamStringAdapter {
 public:
  ConstRamStringAdapter(const char* str = 0) : _str(str) {}

  int8_t compare(const char* other) const {
    return safe_strcmp(_str, other);
  }

  bool equals(const char* expected) const {
    return compare(expected) == 0;
  }

  bool isNull() const {
    return !_str;
  }

  size_t size() const {
    if (!_str)
      return 0;
    return strlen(_str);
  }

  const char* data() const {
    return _str;
  }

  typedef storage_policy::store_by_address storage_policy;

 protected:
  const char* _str;
};

inline ConstRamStringAdapter adaptString(const char* str) {
  return ConstRamStringAdapter(str);
}

}  // namespace ARDUINOJSON_NAMESPACE
