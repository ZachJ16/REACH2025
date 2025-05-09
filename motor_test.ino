const int MOTOR_PIN = 9;  // Motor black (GND) wire connected to this pin

void setup() {
  pinMode(MOTOR_PIN, OUTPUT);
  digitalWrite(MOTOR_PIN, HIGH);  // Initially OFF (disconnect GND)
}

void loop() {
  // Turn motor ON
  digitalWrite(MOTOR_PIN, LOW);   // Connect GND, motor turns on
  delay(1000);                    // Motor on for 1 second

  // Turn motor OFF
  digitalWrite(MOTOR_PIN, HIGH);  // Disconnect GND, motor off
  delay(1000);                    // Motor off for 1 second
}
