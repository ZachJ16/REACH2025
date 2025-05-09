#include <SPI.h>

const int CS_PIN = 10;  // Chip select pin for MAX31855

void setup() {
  Serial.begin(9600);
  SPI.begin();
  pinMode(CS_PIN, OUTPUT);
  digitalWrite(CS_PIN, HIGH);  // Disable device initially
}

void loop() {
  // Read temperature data from MAX31855
  uint32_t rawData = readMax31855();
  
  // Check if there’s a thermocouple connection error
  if (rawData & 0x00010000) {
    Serial.println("Thermocouple connection error");
  } else {
    // Extract temperature in Celsius from rawData
    float temperature = extractTemperature(rawData);
    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.println(" °C");
  }
  
  delay(500);  // Wait for 1 second before next reading
}

// Function to read 32-bit data from MAX31855
uint32_t readMax31855() {
  uint32_t value = 0;
  
  digitalWrite(CS_PIN, LOW);  // Select the MAX31855 chip
  delayMicroseconds(1);
  
  // Read 4 bytes from SPI
  for (int i = 3; i >= 0; i--) {
    value |= SPI.transfer(0x00) << (i * 8);
  }
  
  digitalWrite(CS_PIN, HIGH);  // Deselect the chip
  return value;
}

// Function to extract temperature in Celsius from raw data
float extractTemperature(uint32_t rawData) {
  // Get the 14-bit temperature data
  int16_t tempData = (rawData >> 18) & 0x3FFF;
  
  // Sign-extend if the temperature is negative
  if (tempData & 0x2000) {
    tempData |= 0xC000;
  }
  
  // Convert to Celsius
  return tempData * 0.25;
}
