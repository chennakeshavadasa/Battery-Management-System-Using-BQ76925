#include "DHT.h"
#include <SoftwareSerial.h>  // adds the ability to customize pins for serial data transmission
#include <ArduinoJson.h>    //JSON document/ packages for efficient data transfer

SoftwareSerial s(5,6);  // adds pin 5 and 6 as RX and TX respectively

#define DHTPIN 2
#define DHTTYPE DHT11

DHT dht(DHTPIN,DHTTYPE);

DynamicJsonDocument doc(1000);  //creating a JSON document of size 1000 bytes
JsonObject root = doc.to<JsonObject>();  //get a root object that points to the JSON Document

void setup()
{
  Serial.begin(115200);
  s.begin(115200);
  Serial.println("Humidity and Temperature ");
  dht.begin();
}

void loop() 
{
  delay(3000);
  float h = dht.readHumidity();
  root["humidity"] = h;  //sets the humidity section of the JSON document to the value of h
  float t = dht.readTemperature();
  root["celsius"] = t;  //sets the celsius section of the JSON document to the value of t
  float k = t + 273.16 ;
  root["kelvin"] = k;  //sets the kelvin section of the JSON document to the value of k
  Serial.print("\n Humidity\n");
  Serial.print(h);
  Serial.print("\n Temperature in Celsius \n ");
  Serial.print(t);
  Serial.println(" C");
  Serial.print("\n Temperature in kelvin \n ");
  Serial.print(k);
  Serial.println(" K");
}
