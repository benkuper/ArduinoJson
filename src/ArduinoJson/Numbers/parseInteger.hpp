// ArduinoJson - arduinojson.org
// Copyright Benoit Blanchon 2014-2020
// MIT License

#pragma once

#include "../Numbers/convertNumber.hpp"
#include "../Numbers/parseNumber.hpp"
#include "../Polyfills/type_traits.hpp"

namespace ARDUINOJSON_NAMESPACE {
template <typename T>
T parseInteger(const char *s) {
  // try to reuse the same parameters as JsonDeserializer
  typedef typename choose_largest<UInt, typename make_unsigned<T>::type>::type
      TUInt;
  return parseNumber<Float, TUInt>(s).template as<T>();
}
}  // namespace ARDUINOJSON_NAMESPACE
