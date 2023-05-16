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