#include <Servo.h>

Servo motor1;

void setup() {
  motor1.attach(9);
}

void loop() {
  for(int position = 0; position < 180; position += 2)
  {
    motor1.write(position);
    delay(20);
  }
  for(int position = 180; position >= 0; position -= 2)
  {
    motor1.write(position);
    delay(20);
  }  
}
