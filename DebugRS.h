#pragma once
#ifndef DEBUG_RS_H
#define DEBUG_RS_H

#include <Arduino.h>

#ifdef DEBUG_RS
// PRINTF_RS("line = %d connected = %d\n", __LINE__, bot.client.connected());
#pragma message("This debug version. Define DEBUG_RS in platform.ini")
#define SERIAL_BEGIN_RS(...) Serial.begin(__VA_ARGS__)
#define SERIAL_SETTIMEOUT(...) Serial.setTimeout(__VA_ARGS__)
#define PRINT_RS(...) Serial.print(__VA_ARGS__)
#define PRINTLN_RS(...) Serial.println(__VA_ARGS__)
// Print formatted data to stdout
// https://cplusplus.com/reference/cstdio/printf/
#define PRINTF_RS(...) Serial.printf(__VA_ARGS__)
#define PRINTLN_ERR_RS Serial.println(String(__FILE__) + " [" + String(__FUNCTION__) + "]:" + String(__LINE__) + "  **********************************************")
#define START_TIME_SENSOR_MS uint32_t __ms__ = millis();
#define STOP_TIME_SENSOR_MS   \
  __ms__ = millis() - __ms__; \
  if (__ms__ > 100)           \
    Serial.println(String(__FILE__) + " [" + String(__FUNCTION__) + "]:" + String(__LINE__) + String(" ############## time: ") + __ms__ + String(" ms"));
#else
// #pragma message("This release version. No define DEBUG_RS in platform.ini")
#define SERIAL_BEGIN_RS(...)
#define SERIAL_SETTIMEOUT(...)
#define PRINT_RS(...)
#define PRINTLN_RS(...)
#define PRINTF_RS(...)
#define START_TIME_SENSOR_MS
#define STOP_TIME_SENSOR_MS
#endif

#endif // DEBUG_RS_H
