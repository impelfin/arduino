#include <SoftwareSerial.h>

#define TX    3
#define RX    2
const char Forward = 'F';
const char Back = 'B';
const char Right = 'R';
const char Left = 'L';
const char ForwardRight = 'I';
const char ForwardLeft = 'G';
const char BackRight = 'J';
const char BackLeft = 'H';
const char Stop = 'S';
SoftwareSerial BTSerial(TX, RX);    // Connect HC-06 TX, RX
int ENA = 5;
int IN1 = 7;
int IN2 = 8;
int ENB = 6;
int IN3 = 9;
int IN4 = 10;
int trigPin = 12;
int echoPin = 11;
long distance, duration, randNumber;
void setup(){
  BTSerial.begin(9600); 
  Serial.begin(9600); 
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  randNumber = random(1,40);

}
void sensor()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2); // Added this line 
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10); // Added this line 
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
}

void loop(){


   
      Control();
    
}
 
void Block(){
    
      Serial.println(distance);
      Serial.println("distance <= 35");
      digitalWrite(IN1,LOW);
      digitalWrite(IN2,LOW);
      analogWrite(ENA,LOW);
      digitalWrite(IN3,LOW);
      digitalWrite(IN4,HIGH);
      analogWrite(ENB,5);
      delay(500);
      if (randNumber % 2 == 1){
      digitalWrite(IN1,HIGH);
      digitalWrite(IN2,LOW);
      analogWrite(ENA,200);
      digitalWrite(IN3,LOW);
      digitalWrite(IN4,HIGH);  
      analogWrite(ENB,100);
      delay(500);
      }
      else{
      digitalWrite(IN1,LOW);
      digitalWrite(IN2,HIGH);
      analogWrite(ENA,200);  
      digitalWrite(IN3,LOW);
      digitalWrite(IN4,HIGH);  
      analogWrite(ENB,100);
      delay(500);
      }
      
}  
   
void Control(){
       switch (BTSerial.read()){
            case Forward:
              Serial.println("Forward");
              digitalWrite(IN1,LOW);
              digitalWrite(IN2,LOW);
              analogWrite(ENA,200);
              digitalWrite(IN3,HIGH);
              digitalWrite(IN4,LOW);
              analogWrite(ENB,200);
              break;
            case Back:
              Serial.println("Back");
              digitalWrite(IN1,LOW);
              digitalWrite(IN2,200);
              analogWrite(ENA,200);
              digitalWrite(IN3,LOW);
              digitalWrite(IN4,HIGH);
              analogWrite(ENB,100);
              break;
            case Left:
              Serial.println("Left");
              digitalWrite(IN1,LOW);
              digitalWrite(IN2,HIGH);
              analogWrite(ENA,200);
              digitalWrite(IN3,LOW);
              digitalWrite(IN4,LOW);
              analogWrite(ENB,200);  
              break;
            case Right:
              Serial.println("Right");
              digitalWrite(IN1,HIGH);
              digitalWrite(IN2,LOW);
              analogWrite(ENA,200);
              digitalWrite(IN3,LOW);
              digitalWrite(IN4,LOW);
              analogWrite(ENB,200); 
              break;
            case ForwardRight:
              Serial.println("Forward Right");
              digitalWrite(IN1,HIGH);
              digitalWrite(IN2,LOW);
              analogWrite(ENA,200);
              digitalWrite(IN3,HIGH);
              digitalWrite(IN4,LOW);  
              analogWrite(ENB,200);
              break;
            case ForwardLeft:
              Serial.println("Forward Left");
              digitalWrite(IN1,LOW);
              digitalWrite(IN2,HIGH);
              analogWrite(ENA,200);  
              digitalWrite(IN3,HIGH);
              digitalWrite(IN4,LOW);  
              analogWrite(ENB,200);
              break;
            case BackRight:
              Serial.println("Back Right");
              digitalWrite(IN1,HIGH);
              digitalWrite(IN2,LOW);
              analogWrite(ENA,200);
              digitalWrite(IN3,LOW);
              digitalWrite(IN4,HIGH);  
              analogWrite(ENB,100);
              break;                        
            case BackLeft:
              Serial.println("Back Left");
              digitalWrite(IN1,LOW);
              digitalWrite(IN2,HIGH);
              analogWrite(ENA,200);  
              digitalWrite(IN3,LOW);
              digitalWrite(IN4,HIGH);  
              analogWrite(ENB,100);
              break;
            case Stop:
              Serial.println("Stop");            
              digitalWrite(IN1,LOW);
              digitalWrite(IN2,LOW);
              analogWrite(ENA,LOW);
              digitalWrite(IN3,LOW);
              digitalWrite(IN4,LOW);  
              analogWrite(ENA,LOW);
              break;
         }   
}



