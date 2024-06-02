#include <DHT.h>
#include <Servo.h>

#define DHTPIN 2
#define DHTTYPE DHT11
#define LIGHT_PIN A0
#define FAN_PIN 8
#define SERVO_PIN 9

DHT dht(DHTPIN, DHTTYPE);
Servo doorServo;

void setup() {
  Serial.begin(9600);
  dht.begin();
  pinMode(LIGHT_PIN, INPUT);
  pinMode(FAN_PIN, OUTPUT);
  doorServo.attach(SERVO_PIN);
}

void loop() {
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();
  int lightLevel = analogRead(LIGHT_PIN);

  if (lightLevel < 500) {
    digitalWrite(FAN_PIN, HIGH);
  } else {
    digitalWrite(FAN_PIN, LOW);
  }

  if (temperature > 25) {
    doorServo.write(90);  // Open door
  } else {
    doorServo.write(0);   // Close door
  }

  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" *C");
  
  delay(2000);
}
