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

#ifndef __7SEGMENT_H__
#define __7SEGMENT_H__

#include "time.h"
#include "config.h"
#include <TM1637Display.h>
#include "clock.h"

void initDisplay();
void displayTimeWait();
void displayWifiWait();
void displayTime(timev time);
void toggleColon();

#endif