//version 1
#define WIFI_SSID       "your_ssid"
#define WIFI_PASS       "your_password"
#define SERVER_IP       "your_server_ip" // or domain name
#define SERVER_PORT     80

#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <SoftwareSerial.h>
#include <ArduinoJson.h>

SoftwareSerial s(D6, D5);

float sensor_value1 = 0;
float sensor_value2 = 0;
float sensor_value3 = 0;

char ssid[] = "Pramoda";
char pass[] = "9036364437";

void setup() 
{
  Serial.begin(115200);
  s.begin(9600);

  // Connect to Wi-Fi
  WiFi.begin(WIFI_SSID, WIFI_PASS);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
}

void loop() 
{
  if (s.available()) {
    String json = s.readStringUntil('\n');
    DynamicJsonDocument dat(100);
    deserializeJson(dat, json);

    float sensor_value1 = dat["Current"];
    float sensor_value2 = dat["Voltage"];
    float sensor_value3 = dat["Temp"];

    // Send data to the website
    sendSensorData(sensor_value1, sensor_value2, sensor_value3);
    
    Serial.print("Current: ");
    Serial.println(sensor_value1);
    Serial.print("Voltage: ");
    Serial.println(sensor_value2);
    Serial.print("Temperature: ");
    Serial.println(sensor_value3);
  }
}

void sendSensorData(float current, float voltage, float temp) {
  HTTPClient http;

  String url = "http://" + String(SERVER_IP) + ":" + String(SERVER_PORT) + "/update";
  String postData = "current=" + String(current) + "&voltage=" + String(voltage) + "&temperature=" + String(temp);

  http.begin(url);
  http.addHeader("Content-Type", "application/x-www-form-urlencoded");

  int httpCode = http.POST(postData);

  if (httpCode > 0) {
    String payload = http.getString();
    Serial.println(httpCode);
    Serial.println(payload);
  }

  http.end();
}