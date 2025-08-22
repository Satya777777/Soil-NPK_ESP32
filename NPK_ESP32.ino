#include <SoftwareSerial.h>

#define RE 4  
#define DE 5  

const byte nitro[] = {0x01, 0x03, 0x00, 0x1E, 0x00, 0x01, 0xB5, 0xCC}; 
const byte phos[] = {0x01, 0x03, 0x00, 0x1F, 0x00, 0x01, 0xE4, 0x0C};  
const byte pota[] = {0x01, 0x03, 0x00, 0x20, 0x00, 0x01, 0x85, 0xC0};   

// Store received values
byte values[11];

void setup() {
  Serial.begin(9600); 
  pinMode(RE, OUTPUT);
  pinMode(DE, OUTPUT);

  
  digitalWrite(DE, LOW);
  digitalWrite(RE, LOW);
  
  delay(1000);
}

void loop() {
  byte val1 = nitrogen();
  byte val2 = phosphorous();
  byte val3 = potassium();

  Serial.print("Nitrogen: ");
  Serial.print(val1);
  Serial.println(" mg/kg");

  Serial.print("Phosphorus: ");
  Serial.print(val2);
  Serial.println(" mg/kg");

  Serial.print("Potassium: ");
  Serial.print(val3);
  Serial.println(" mg/kg");

  Serial.println();
  delay(5000); 

byte nitrogen() {
  return readSensor(nitro);
}

byte phosphorous() {
  return readSensor(phos);
}

byte potassium() {
  return readSensor(pota);
}

byte readSensor(const byte* command) {
  // Clear the receive buffer
  digitalWrite(DE, HIGH);
  digitalWrite(RE, HIGH);
  delay(10);

  // Send the command to the sensor
  for (uint8_t i = 0; i < sizeof(nitro); i++) {
    Serial.write(command[i]);
  }
  Serial.flush(); 

  // Switch to receive mode
  digitalWrite(DE, LOW);
  digitalWrite(RE, LOW);
  delay(100); 

  // Read the response
  for (byte i = 0; i < 7; i++) {
    values[i] = Serial.read();
  }
  
  
  return values[4]; 
}
