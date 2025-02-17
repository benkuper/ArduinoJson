// ArduinoJson - arduinojson.org
// Copyright Benoit Blanchon 2014-2020
// MIT License

#pragma once

#include "../Namespace.hpp"

namespace ARDUINOJSON_NAMESPACE {
template <typename T>
inline void swap(T& a, T& b) {
  T t(a);
  a = b;
  b = t;
}
}  // namespace ARDUINOJSON_NAMESPACE
