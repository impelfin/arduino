#include <Servo.h>
#include <SoftwareSerial.h>

 SoftwareSerial BTSerial(2,3); //rx, tx 
 Servo myservo; 
 char data;
 int led = 13;

void setup() {
  BTSerial.begin(9600);
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  myservo.attach(9);
}

void loop() {
  if(BTSerial.available()) {    
    data = BTSerial.read();
    Serial.println(data);
  }
  if(Serial.available()) {
    data = Serial.read();
    Serial.println(data);
  }
  if(data == 'L') {  
    Serial.println("LEFT");
    servorot(10);
  }
  if(data == 'R') {
    Serial.println("RIGHT");
    servorot(170);  
  }
    if(data == '1') {  
    Serial.println("LED On");
    analogWrite(led, 255);
  }
  if(data == '2') {
    Serial.println("LED Off");
    analogWrite(led, 0);
  }
}

void servorot(int x) {
    myservo.write(x);
}
