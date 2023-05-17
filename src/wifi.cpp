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

#include "wifi.h"

void initWifi(const char* ssid, const char* password){
  #ifdef DEBUG
  Serial.println("setting up wifi");
  #endif
  WiFi.mode(WIFI_STA);
  /*//
  WiFiManager wm;
  wm.resetSettings();
  wm.setTimeout(600);
  wm.autoConnect("CallMonitorConfig");
  //*/
  WiFi.begin(ssid, password);
  #ifdef DEBUG
  Serial.println("done setting up wifi");
  #endif

}