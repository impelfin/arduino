#include <Servo.h>

Servo motor1;
int flexpin = 0;
int motorangle;

void setup() {
  motor1.attach(9);
  Serial.begin(9600);
}

void loop() {
  int flexVal;
  flexVal = analogRead(flexpin);
  Serial.print("Sensor : ");
  Serial.println(flexVal);
  motorangle = map(flexVal, 0, 1023, 0, 180);
  motor1.write(motorangle);
  delay(100);
}
