NPK Sensor with ESP32 (JXBS-3001-NPK-RS)
📌 Project Description

This project demonstrates how to interface the JXBS-3001-NPK-RS soil nutrient sensor with an ESP32 to measure the concentration of Nitrogen (N), Phosphorus (P), and Potassium (K) in soil. The sensor communicates using RS485 (Modbus RTU) protocol, and the ESP32 reads and displays the values via the Serial Monitor.

⚡ Hardware Requirements

ESP32 Development Board

JXBS-3001-NPK-RS Sensor (RS485 output)

RS485 to TTL Converter Module (e.g., MAX485)

Jumper wires

Power supply (12V for NPK sensor, 5V for ESP32)

🔌 Wiring Connections
RS485 Module	ESP32 Pin
RO	GPIO 16 (RX2)
DI	GPIO 17 (TX2)
RE	GPIO 4
DE	GPIO 5
VCC	5V
GND	GND
NPK Sensor	RS485 Module
A	A
B	B
VCC	12V
GND	GND

⚠️ Note: The NPK sensor requires a 12V DC supply.

🖥️ Software Requirements

Arduino IDE

ESP32 Board Support Package

No additional libraries required (uses built-in HardwareSerial or SoftwareSerial)

📜 How It Works

ESP32 sends Modbus query commands to request N, P, K values from the sensor.

The RS485 module handles communication between ESP32 and sensor.

The response is parsed, and nutrient values are extracted.

Results are printed on the Serial Monitor in mg/kg.

📂 Code Overview

nitrogen(): Reads Nitrogen value.

phosphorous(): Reads Phosphorus value.

potassium(): Reads Potassium value.

Results are updated every 5 seconds.

📊 Sample Output
Nitrogen: 25 mg/kg
Phosphorus: 12 mg/kg
Potassium: 43 mg/kg

🚀 Future Enhancements

Display results on OLED/LCD.

Send data to IoT platforms (MQTT, Blynk, ThingsBoard).

Store readings in SD card for long-term monitoring.