A very simple LED desk clock
===

This project is intended to bring a simple, traditional-looking LED 7-Segment desk clock into the 21st century by using simple network time protocol to obtain the correct time. It was born out of necessity, when my trusty old radio controlled night clock died of old age and I found plain, old-fashioned 7-segment radio controlled LED clocks are pretty much unobtanium these days. Anything with Wifi invariably has one of the annoying TFT displays which either keep you awake all night with their glow or are completely dark until you fumble for the right button in the darkness. So, in the best maker tradition, I went and rolled my own.

Hardware
---
The circuitry requires only an ESP-01, some sort of TM1637-based LED display of the 7-segment variety, and a power source capable of supplying 3.3V, which generally the display modules seem to work well enough on. 

The code as it is currently written assumes a four-figure display with a single colon. It assumes GPIO0 is connected to CLK and GPIO2 is connected to DATA.

The circuit draws little enough power that it is possible to run it off USB power packs, though not necessarily off USB ports. MacBooks tend to go into sulk mode if a device draws significant power without proper negotiation.


Configuring and building
---
This project is configured to be built on Platformio.

The wifi credentials are currently hardcoded for simplicity, because adding a wifiManager would require an additional GPIO pin for a reset button, which the ESP-01 can only provide with considerable complications. Since Wifi credentials seldom change and this project is really only for ambitious makers, this will not pose a problem. 

Create a file named wifiCredentials.h in the include folder (the default .gitignore will protect you from accidentially committing it), which contains definitions for SSID and PASSWORD, like so:

```
#define SSID "whatever";
#define PASSWORD "supersecretpasswordnobodywilleverguess";
````

Adjust the time zone and ntp servers in config.h if you need to. An useful list of time zone strings can be found on this site: https://remotemonitoringsystems.ca/time-zone-abbreviations.php


