#define BLYNK_TEMPLATE_ID   "TMPL30Jm3O2MQ"
#define BLYNK_TEMPLATE_NAME "Quickstart Template"
#define BLYNK_AUTH_TOKEN    "LHDA7qnS0H54c4LIJ3MvgTCqUeE_nLDS"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <SoftwareSerial.h>
#include <ArduinoJson.h>

SoftwareSerial s(D6, D5);

int humidity = 0; // Variable to store Sensor Output
int celsius = 0; // Variable to store Sensor Output
int kelvin = 0; // Variable to store Sensor Output

char ssid[] = "Pramoda";
char pass[] = "9036364437";

BlynkTimer timer;

void writeval()
{
  DynamicJsonDocument jsonDoc(1000);
  DeserializationError error = deserializeJson(jsonDoc, s);
  
  if (error) 
  {
    return;
  }

  JsonObject root = jsonDoc.as<JsonObject>();
  
  humidity = root["humidity"];
  celsius = root["celsius"];
  kelvin = root["kelvin"];
  Blynk.virtualWrite(V0, humidity);
  Blynk.virtualWrite(V1, celsius);
  Blynk.virtualWrite(V2, kelvin);
}

void setup() {
  // Initialize Serial port
  Serial.begin(115200);
  s.begin(115200);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  timer.setInterval(500L, writeval);
  while (!Serial) continue;
}

void loop() {
  DynamicJsonDocument jsonDoc(1000);
  DeserializationError error = deserializeJson(jsonDoc, s);
  
  if (error) 
  {
    return;
  }

  JsonObject root = jsonDoc.as<JsonObject>();
  
  humidity = root["humidity"];
  celsius = root["celsius"];
  kelvin = root["kelvin"];
  
  Serial.print("Humidity:");
  Serial.print(humidity);
  Serial.print(", Celsius:");
  Serial.print(celsius);
  Serial.print(", Kelvin:");
  Serial.println(kelvin);
  Blynk.run();
  timer.run();
}
