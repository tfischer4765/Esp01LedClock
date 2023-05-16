#ifndef __MAIN_H__
#define __MAIN_H__

#include <Arduino.h>

#include "config.h"
#include "wifi.h"
#include "7segment.h"

#include <string.h>
#include "wifiCredentials.h"
#include "clock.h"

#ifndef SSID
#error "Wifi credentials not found. Be sure to create a wifiCredentials.h file in the include path defining an SSID and a PASSWORD"
#endif

#endif