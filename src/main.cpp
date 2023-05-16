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

