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

#include "7segment.h"

TM1637Display display(CLK, DIO);

const uint8_t SEG_NOTIME[] = {
    SEG_G,   
	SEG_G,   
	SEG_G,  
	SEG_G  
	};

const uint8_t SEG_CONN[] = {
	SEG_D | SEG_E | SEG_G,           // c
	SEG_C | SEG_D | SEG_E | SEG_G,   // o
	SEG_C | SEG_E | SEG_G,           // n
	SEG_C | SEG_E | SEG_G            // n
	};

const uint8_t COLON_MASK = 0x80>>1;

volatile uint8_t dots = 0;
uint32_t numericaltime = 0;

void initDisplay(){
    display.clear();
    display.setBrightness(0x0f);
}

void displayTime(timev time ){
    numericaltime = time.localtime.tm_hour*100 +time.localtime.tm_min;
    display.showNumberDecEx(numericaltime,dots,true,4);

}

void displayTimeWait(){
     #ifdef DEBUG
  Serial.println("displaying time_wait");
  #endif
    display.clear();
    display.setSegments(SEG_NOTIME);
     #ifdef DEBUG
  Serial.println("done displaying time_wait");
  #endif
}
void displayWifiWait(){
    #ifdef DEBUG
  Serial.println("displaying wifi_wait");
  #endif
    display.setSegments(SEG_CONN);
    #ifdef DEBUG
  Serial.println("done displaying wifi_wait");
  #endif
}

void toggleColon(){
    dots = dots ^ COLON_MASK;
    display.showNumberDecEx(numericaltime,dots,true,4);
}
