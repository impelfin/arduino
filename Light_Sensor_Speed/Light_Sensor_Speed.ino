int sensorPin = 0;
int speedPin = 3;
int motor1APin = 6;
int motor2APin = 7;
int speed_value_motor1;
int lightLevel;

void setup() {
  pinMode(speedPin, OUTPUT);
  pinMode(motor1APin, OUTPUT);
  pinMode(motor2APin, OUTPUT);
}

void loop() {
  lightLevel = analogRead(sensorPin);
  digitalWrite(motor1APin, LOW);
  digitalWrite(motor2APin, HIGH);
  lightLevel = map(lightLevel,0, 1023, 0, 255);
  analogWrite(speedPin, lightLevel);
}
