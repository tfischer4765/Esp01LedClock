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

#include "main.h"

char *ssid = SSID;
const char *password = PASSWORD;
volatile uint32_t lastMillis = 0;
volatile uint32_t lastTimeFetch =0;

void IRAM_ATTR isrTimer();

void setup()
{
#ifdef DEBUG
  Serial.begin(9600);
  Serial.println("ESPClock running in debug mode");
#endif
  initSntp();
  initDisplay();

  initWifi(ssid, password);
  displayWifiWait();
}

void loop()
{
#ifdef DEBUG
  Serial.print("L");
#endif
  if (WiFi.status() != WL_CONNECTED)
  {
#ifdef DEBUG
    Serial.print("W");
#endif
    displayWifiWait();
  }
  else if (!hasTime())
  {
#ifdef DEBUG
    Serial.print("T");
#endif
    displayTimeWait();
  }
  else
  {
    int milli = millis();
#ifdef DEBUG
    Serial.print("D");
#endif
    timev m;
    if(lastTimeFetch ==0) 
    m = getLocalizedTime();

    if(lastTimeFetch < milli +3600000){
      m = getLocalizedTime();
      lastTimeFetch = milli;
    }
    displayTime(m);
    if(milli > lastMillis+1000){
      lastMillis = milli;
      toggleColon();
    }
  }
}

