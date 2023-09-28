//ESP8266 CODE VERSION 1.4 READY FOR TESTING

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
float sensor_value1 = 0; // Variable to store Sensor Output
float sensor_value2 = 0; // Variable to store Sensor Output
float sensor_value3 = 0; // Variable to store Sensor Output

//WiFi credentials
char ssid[] = "Pramoda";
char pass[] = "9036364437";

//declare and initialize safe values
safeCurrent = 0;  //Update to actual safe value
safeVoltage = 0;  //Update to actual safe value

//alert bool declaration
//bool alertSent = false;

void setup() 
{
  // Start the Serial communication for debugging
  Serial.begin(115200);
  // Start the SoftwareSerial communication
  s.begin(9600);
  //Blynk commmunication
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
}

void loop() 
{
  Blynk.run();
  // Check if there's data available to read
  if (s.available()) {
    // Read the incoming data
    String json = s.readStringUntil('\n')
    // Deserialize the JSON data
    DynamicJsonDocument dat(100);
    deserializeJson(dat, json);
    // Extract the floating-point numbers
    float sensor_value1 = dat["Current"];
    float sensor_value2 = dat["Voltage"];
    float sensor_value3 = dat["Temp"];
    // Send the values to Blynk virtual pins
    Blynk.virtualWrite(V1, sensor_value1);
    Blynk.virtualWrite(V2, sensor_value2);
    Blynk.virtualWrite(V3, sensor_value3);

    // Calculate and send uptime to Blynk V3
    long uptime = millis() / 1000;
    Blynk.virtualWrite(V0, uptime);
    //For Serial Monitor
    Serial.print("Current: ");
    Serial.println(sensor_value1);
    Serial.print("Voltage: ");
    Serial.println(sensor_value2);
    Serial.print("Temperature: ");
    Serial.println(sensor_value3);
  }
  // Check if values exceed safe limits (ALSO NOT A BAD IDEA TO IMPLEMENT A ALERT PIN CHECK FROM BQ76925)
  /*
  if (sensor_value1 > safeCurrent || sensor_value2 > safeVoltage || sensor_value3 >50)  //safevalues added but not set to actual values yet
  {
    if (!alertSent) {
      Blynk.notify("Alert: Voltage, Current, or Temperature exceeds safe limits!");
      alertSent = true; // Set alertSent to true to avoid sending multiple alerts
    }
  } else {
    alertSent = false; // Reset alertSent when values are within safe limits
  }
  */
}
