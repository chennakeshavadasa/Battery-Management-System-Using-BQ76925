### About files
- A.sensor
  - Arduino code for a humidity and temperature sensor.
  - Creates a JSON packet of humidity, celsius temperature and kelvin temperature.
  - Sends it over to ESP8266 using D5 and D6.
- E.sensor
  - Recieves JSON packets from D6 and D5.
  - Deserializes them.
  - Sends data over to Blynk for IoT.  
