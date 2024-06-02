#include <Servo.h>

#define soilMoisturePin A0
#define waterPumpPin 7
#define servoPin 9

Servo waterServo;

void setup() {
  Serial.begin(9600);
  pinMode(soilMoisturePin, INPUT);
  pinMode(waterPumpPin, OUTPUT);
  waterServo.attach(servoPin);
  waterServo.write(0); // Initial position
}

void loop() {
  int moistureLevel = analogRead(soilMoisturePin);
  Serial.print("Soil Moisture Level: ");
  Serial.println(moistureLevel);
  Serial.print("Made By Rishmika Sandanu");

  if (moistureLevel < 300) {
    digitalWrite(waterPumpPin, HIGH);
    waterServo.write(90); // Open the water valve
    delay(5000); // Water for 5 seconds
    digitalWrite(waterPumpPin, LOW);
    waterServo.write(0); // Close the water valve
  }

  delay(10000); // Check every 10 seconds
}
