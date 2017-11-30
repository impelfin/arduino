#include <Servo.h> 
Servo groveServo;  
int potentionmeter = 0;  
int shaft;
 
void setup() 
{ 
  groveServo.attach(3);
  Serial.begin(9600);
  pinMode(potentionmeter, INPUT);
} 
 
void loop() 
{ 
  shaft = analogRead(potentionmeter);
  shaft = map(shaft, 0, 1023, 0, 179);
  Serial.println(shaft);
  groveServo.write(shaft);
  delay(15); 
} 
