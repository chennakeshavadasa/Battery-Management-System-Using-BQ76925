//ARDUINO CODE VERSION 1.2

#include <SoftwareSerial.h>
#include <ArduinoJson.h>

SoftwareSerial s(5,6);
//defines for the alert pin and I2C address
#define PWR_I2C_ADDRESS 1
#define ALERT_PIN 2
//sensor values
int a,b,c,d,e,f ;

void setup()
{
  //Wire.begin();
  Serial.begin(9600);
  s.begin(9600);
}

void loop()
{  
  // Create a JSON document
  StaticJsonDocument<100> doc;
  //reads A0 and maps the value between desired limits
  a =analogRead(A0);
  b=map(a,0,310,0,3);
  doc["Current"] = b;
  //reads A1 and maps the value between desired limits
  c=analogRead(A1);
  d=map(c,0,370,0,12);
  doc["Voltage"] = d;
  //reads A2 and maps the value between desired limits
  e=analogRead(A2); 
  f=map(e,0,500,-45,45);
  doc["Temp"] = f;
  // Serialize the JSON document to a char array
  char jsonBuffer[100];
  serializeJson(doc, jsonBuffer);
  // Print the JSON data through SoftwareSerial
  s.println(jsonBuffer);
  delay(500);
}

//work in progress
//alert functionality not yet implemented
int accessAddress(int regAddress)
{
  return (PWR_I2C_ADDRESS<<5)+regAddress;
}
