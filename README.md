# Battery Management System using BQ76925
The repository includes - Circuit diagrams, Code for the hardware used (Arduino and ESP8266 module), Features and Specifications.
Battery Management System (BMS) is designed to ensure the optimal performance and safety of your energy storage solutions. This system combines precision monitoring with seamless IoT integration, providing real-time insights into crucial battery parameters.

****Team behind the project****:
1. **Nithin Purushothama**
2. **Pramoda S R**
 - ### Key Features 
   - Voltage, Current, and Temperature Monitoring
   - Fail-Safe Alerts
   - IoT Integration
   - User-Friendly Interface
   - Scalable Design
 - ### Applications
   - Electric Vehicles
   - Industrial Power Backup
   - Off-Grid Solutions

## Requirements
1. BQ76925 IC
2. Arduino UNO R3
3. NODEMCU ESP8266
4. Blynk Account
5. 3 - Li-Ion(3.7V,200 mAh) Batteries
6. 5V Power Supply
7. Resistors
     - 100Ω   - 5
     - 1kΩ    - 3
     - 4.7kΩ  - 2
8. Capacitors
     - 1µF    - 6
     - 1000pF - 2
     - 10µF   - 1
     - 0.1µF  - 1

## Circuit Diagram
![Circuit Diagram](https://github.com/chennakeshavadasa/Battery-Management-System-Using-BQ76925/raw/main/CircuitDiagram/CIRCUIT_DIAGRAM.png)
 
## Instructions
 - Connect the circuit as shown in the diagram.
 - Congratulate yourself for successfully making all the connections.
 - Make changes to [the ESP8266 Code](ESP8266/Blynk_IoT_clouding.ino) based on your Wifi credentials and Blynk profile.
 - Upload Arduino and Esp8266 code.
 - Wait for the connection.
 - Monitor and test your own BMS project.

## Dependencies
 - ESP8266WiFi.h
 - BlynkSimpleEsp8266.h
 - SoftwareSerial.h
 - ArduinoJson.h

## Links
- [BQ76925](https://www.ti.com/product/BQ76925)
- [Arduino UNO R3](https://docs.arduino.cc/hardware/uno-rev3)
- [ESp8266](https://www.make-it.ca/nodemcu-details-specifications/)
- [Blynk](https://blynk.io/)

## License
 - Coming Soon. (hopefully)
