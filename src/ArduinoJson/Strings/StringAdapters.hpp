// ArduinoJson - arduinojson.org
// Copyright Benoit Blanchon 2014-2020
// MIT License

#pragma once

#include <ArduinoJson/Strings/ConstRamStringAdapter.hpp>
#include <ArduinoJson/Strings/RamStringAdapter.hpp>
#include <ArduinoJson/Strings/SizedRamStringAdapter.hpp>

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
