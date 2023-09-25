//ESP8266 CODE VERSION 1.3 READY FOR TESTING

//defines need to be before header for smooth operation (DO NOT CHANGE THIS POSITION)
#define BLYNK_TEMPLATE_ID   "TMPL30Jm3O2MQ"
#define BLYNK_TEMPLATE_NAME "Quickstart Template"
#define BLYNK_AUTH_TOKEN    "LHDA7qnS0H54c4LIJ3MvgTCqUeE_nLDS"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <SoftwareSerial.h>
#include <ArduinoJson.h>

//declare D6 as RX and D5 as TX
SoftwareSerial s(D6, D5);

//declare and initialize sensor values
int sensor_value1 = 0; // Variable to store Sensor Output
int sensor_value2 = 0; // Variable to store Sensor Output
int sensor_value3 = 0; // Variable to store Sensor Output

//WiFi credentials
char ssid[] = "Pramoda";
char pass[] = "9036364437";

//declare and initialize safe values
safeCurrent = 0;  //Update to actual safe value
safeVoltage = 0;  //Update to actual safe value

//alert bool declaration
bool alertSent = false;

// Blynk functions may take over here (TIMER INSTANCE MADE)
BlynkTimer timer;

//function call to write the value to virtual memories of Blynk
void writetocloud()
{
  //updated ArduinoJson version 5 to version 6 
  DynamicJsonDocument jsonDoc(1000);
  DeserializationError error = deserializeJson(jsonDoc, s);
  //checks for errors in JSON file
  if (error) 
  {
    return;
  }
  //retrieves back data
  JsonObject root = jsonDoc.as<JsonObject>();
  //reads JSON file for specified entries
  sensor_value1 = root["sensor1"];
  sensor_value2 = root["sensor2"];
  sensor_value3 = root["sensor3"];
  //writes data to cloud virtual memory
  Blynk.virtualWrite(V0, sensor_value1);
  Blynk.virtualWrite(V1, sensor_value2);
  Blynk.virtualWrite(V2, sensor_value3);
}

void setup() 
{
  // Initialize Serial port and SoftwareSerial port
  Serial.begin(115200);
  s.begin(115200);
  //connects to Blynk cloud and connects ESP to wifi
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  //calls writetocloud every 0.5 seconds (CUSTOMIZABLE)
  timer.setInterval(500L, writetocloud);
  //waits for serial connection
  while (!Serial) continue;
  // Work in progress... main components aren't included yet (ONLY PIN INITIALIZATIONS IF THEY EXIST)
  
}

void loop() 
{
  //updated ArduinoJson version 5 to version 6 
  DynamicJsonDocument jsonDoc(1000);
  DeserializationError error = deserializeJson(jsonDoc, s);
  //checks for errors in JSON file
  if (error) 
  {
    return;
  }
  //retrieves back data
  JsonObject root = jsonDoc.as<JsonObject>();
  //reads JSON file for specified entries
  sensor_value1 = root["sensor1"];
  sensor_value2 = root["sensor2"];
  sensor_value3 = root["sensor3"];
  //serial monitor output
  Serial.print("Current:");
  Serial.print(sensor_value1);
  Serial.print(", voltage:");
  Serial.print(sensor_value2);
  Serial.print(", Temp:");
  Serial.println(sensor_value3);

  // Check if values exceed safe limits (ALSO NOT A BAD IDEA TO IMPLEMENT A ALERT PIN CHECK FROM BQ76925)
  if (sensor_value1 > safeCurrent || sensor_value2 > safeVoltage || sensor_value3 >50)  //safevalues added but not set to actual values yet
  {
    if (!alertSent) {
      Blynk.notify("Alert: Voltage, Current, or Temperature exceeds safe limits!");
      alertSent = true; // Set alertSent to true to avoid sending multiple alerts
    }
  } else {
    alertSent = false; // Reset alertSent when values are within safe limits
  }
