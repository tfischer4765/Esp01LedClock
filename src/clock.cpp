#include "clock.h"

const char *ntpServer1 = NTP_SERVER1;
const char *ntpServer2 = NTP_SERVER2;
const char *tz_info = TZ_INFO;

bool timeSet = false;
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

// initialize the snpt thread. Goes BEFORE wifi connect
void initSntp()
{
#ifdef DEBUG
  Serial.println("configuring sntp");
  #endif
  sntp_servermode_dhcp(1); // I think this does nothing at the moment, too deep for my coding lungs atm.

  configTzTime(tz_info, ntpServer1, ntpServer2);
  #ifdef DEBUG
  Serial.println("done setting up sntp");
  #endif
}

boolean hasTime(){
  struct timeval tv;
  gettimeofday(&tv, NULL);
  if(tv.tv_sec != 0)
    return true;
  else
    return false;
}


struct timev getLocalizedTime()
{
  struct timeval tv;
  struct timev x;
  tm t;
  gettimeofday(&tv, NULL);
  localtime_r(&tv.tv_sec, &t);
  x.localtime = t;
  x.tv_usec = tv.tv_usec;

  return x;
}