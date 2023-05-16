#ifndef __WIFI_H__
#define __WIFI_H__
#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include "config.h"

void initWifi(const char* ssid, const char* password);


#endif