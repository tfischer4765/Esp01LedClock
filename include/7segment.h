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