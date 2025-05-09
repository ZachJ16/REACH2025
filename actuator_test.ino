#include <Servo.h>

Servo actuator;
int cycleCount = 0;
const int maxCycles = 5;

void setup() {
  actuator.attach(9); // Actuator signal wire to pin 9
  delay(500);         // Startup delay
}

void loop() {
  if (cycleCount < maxCycles) {
    // Extend actuator
    actuator.writeMicroseconds(1000);
    delay(3000); // Allow time to move

    // Retract actuator
    actuator.writeMicroseconds(2000);
    delay(3000);

    cycleCount++;
  } else {
    // Final position: retracted
    actuator.writeMicroseconds(2000);
    delay(500); // Hold for a bit
    actuator.detach(); // Optional: stop signal

    while (1); // Stop running the loop
  }
}

