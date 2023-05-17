/*
    ESP-01 7-Segment LED clock
    Copyright (C) 2023 Thomas Fišer

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.
*/

#ifndef __WIFI_H__
#define __WIFI_H__
#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include "config.h"

void initWifi(const char* ssid, const char* password);


#endif