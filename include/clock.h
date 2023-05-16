/*
    ESP32 Fritz!Box call monitor
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

#ifndef __CLOCK_H__
#define __CLOCK_H__

#include <Arduino.h>

#include "config.h"
#include "sntp.h"
#include "time.h"

struct timev{
    tm localtime;
    suseconds_t	tv_usec;
};

void initSntp();
struct timev getLocalizedTime();

boolean hasTime();

#endif