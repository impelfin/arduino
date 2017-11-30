int speedPin = 3;
int signal = 4;
int onoff;
int motor1APin = 6;
int motor2APin = 7;
int speed_value_motor1;

void setup() {
  pinMode(speedPin, OUTPUT);
  pinMode(motor1APin, OUTPUT);
  pinMode(motor2APin, OUTPUT);
}

void loop() {
  onoff = digitalRead(signal);
  if(onoff == 1)
  {
    digitalWrite(motor1APin, LOW);
    digitalWrite(motor2APin, HIGH);
  }
  else
  {
    digitalWrite(motor1APin, HIGH);
    digitalWrite(motor2APin, LOW);
  }
  speed_value_motor1 = 127;
  analogWrite(speedPin, speed_value_motor1);
}
