//ARDUINO CODE VERSION 1.1

#include <SoftwareSerial.h>
#include <ArduinoJson.h>

SoftwareSerial s(5,6);
//defines for alert pin and I2C address
#define PWR_I2C_ADDRESS 1
#define ALERT_PIN 2
//sensor values
int a,b,c,d,e,f ;
//JSON object creation
DynamicJsonDocument jsonDoc(1000); // Create a JSON document with a capacity of 1000 bytes
JsonObject root = jsonDoc.to<JsonObject>(); // Get a JsonObject reference from the document

void setup()
{
  //Wire.begin();
  Serial.begin(115200);
  s.begin(115200);
}

void loop()
{  
  //reads A0 and maps the value between desired limits
  Serial.print("Current :" );
  a =analogRead(A0);
  b=map(a,0,310,0,3);
  root["sensor1"]= b;
  Serial.print(b); 
  Serial.print("(");
  Serial.print(a);
  Serial.print(")");
  //reads A1 and maps the value between desired limits
  Serial.print("  Voltage :" );
  c=analogRead(A1);
  d=map(c,0,370,0,12);
  root["sensor2"]= d;
  Serial.print(d);
  Serial.print("(");
  Serial.print(c);
  Serial.print(")");
  //reads A2 and maps the value between desired limits
  Serial.print("  Temp :" );
  e=analogRead(A2); 
  f=map(e,0,500,-45,45);
  root["sensor3"]= f;
  if(s.available()>0)
  {
    root.printTo(s);
  }
  Serial.print(f);
  Serial.print("(");
  Serial.print(e);
  Serial.println(")"); 
  delay(500);
}

//work in progress
//alert functionality not yet implemented
int accessAddress(int regAddress)
{
  return (PWR_I2C_ADDRESS<<5)+regAddress;
}
