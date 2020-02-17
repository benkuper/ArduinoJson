// ArduinoJson - arduinojson.org
// Copyright Benoit Blanchon 2014-2020
// MIT License

#pragma once

#include "../Memory/MemoryPool.hpp"
#include "../Polyfills/type_traits.hpp"

namespace ARDUINOJSON_NAMESPACE {
template <typename>
struct IsString : false_type {};

template <typename T>
struct IsString<const T> : IsString<T> {};

template <typename T>
struct IsString<T&> : IsString<T> {};
}  // namespace ARDUINOJSON_NAMESPACE

#include "../Strings/ConstRamStringAdapter.hpp"
#include "../Strings/RamStringAdapter.hpp"
#include "../Strings/SizedRamStringAdapter.hpp"

#if ARDUINOJSON_ENABLE_STD_STRING
#include "../Strings/StlStringAdapter.hpp"
#endif

#if ARDUINOJSON_ENABLE_ARDUINO_STRING
#include "../Strings/ArduinoStringAdapter.hpp"
#endif

#if ARDUINOJSON_ENABLE_PROGMEM
#include "../Strings/FlashStringAdapter.hpp"
#include "../Strings/SizedFlashStringAdapter.hpp"
#endif
