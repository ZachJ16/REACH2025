void setup() {
  
  pinMode(33, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  
  digitalWrite(33, HIGH);
  delay(1000);

  float SensorV =  analogRead(A14);
  float voltage = SensorV * (3.3/4095.0);
  //float weight = (voltage-0.151)/0.07;

  digitalWrite(33, LOW);
  delay(500);

  Serial.print("Sensor: ");
  Serial.print (SensorV, 3);
  Serial.print ("Output V: ");
  Serial.print(voltage, 3);
  Serial.println ("V");

  delay(1000);

}
