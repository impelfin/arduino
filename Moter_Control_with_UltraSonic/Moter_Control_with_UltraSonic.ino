#include <SoftwareSerial.h>
#include <NewPing.h>

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
const char Speed0 = '0';
const char Speed1 = '1';
const char Speed2 = '2';
const char Speed3 = '3';
const char Speed4 = '4';
const char Speed5 = '5';
const char Speed6 = '6';
const char Speed7 = '7';
const char Speed8 = '8';
const char Speed9 = '9';
const char Speed10 = 'q';
SoftwareSerial BTSerial(TX, RX);    // Connect HC-06 TX, RX
int ENA = 5;
int IN1 = 7;
int IN2 = 8;
int ENB = 6;
int IN3 = 9;
int IN4 = 10;


#define TRIGGER_PIN  12
#define ECHO_PIN     11
#define MAX_DISTANCE 400
 
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
int uS;
int speed = 150;
int speed_r = 150;
long distance, duration;
int randNum = 0;
int break_distance = 30;
char data;

void setup(){
  BTSerial.begin(9600); 
  Serial.begin(9600); 
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  randomSeed(analogRead(0));
}


 
void sensor()
{
  uS = sonar.ping();
}

void loop(){
         if(BTSerial.available()) {    
		data = BTSerial.read();          
	}
	if(Serial.available()) {
		data = Serial.read();
	}  
    switch (data){
                case Speed0:
			speed = 0;
	        	break;
		case Speed1:
			speed = 100;
			break;
		case Speed2:
			speed = 117;
			break;
		case Speed3:
			speed = 134;
			break;
		case Speed4:
			speed = 151;
			break;
		case Speed5:
			speed = 168;
			break;		
		case Speed6:
			speed = 185;
			break;
		case Speed7:
			speed = 202;
			break;
		case Speed8:
			speed = 219;
			break;
		case Speed9:
			speed = 236;
			break;
		case Speed10:
			speed = 255;
			break;	  
    }
   sensor();
   Serial.println(uS / US_ROUNDTRIP_CM);
   if (uS / US_ROUNDTRIP_CM < break_distance && uS / US_ROUNDTRIP_CM!=0){
    Block();
   }
  else {

    Control();
   }
}
 
  
void Control(){

    switch (data){
            case Forward:
              Serial.println("Forward");
              digitalWrite(IN1,LOW);
              digitalWrite(IN2,LOW);
              analogWrite(ENA,250);
              digitalWrite(IN3,HIGH);
              digitalWrite(IN4,LOW);
              analogWrite(ENB,speed);
              break;
            case Back:
              Serial.println("Back");
              digitalWrite(IN1,LOW);
              digitalWrite(IN2,LOW);
              analogWrite(ENA,250);
              digitalWrite(IN3,LOW);
              digitalWrite(IN4,HIGH);
              analogWrite(ENB,speed_r);
              break;
            case Left:
              Serial.println("Left");
              digitalWrite(IN1,LOW);
              digitalWrite(IN2,HIGH);
              analogWrite(ENA,250);
              digitalWrite(IN3,LOW);
              digitalWrite(IN4,LOW);
              analogWrite(ENB,speed);  
              break;
            case Right:
              Serial.println("Right");
              digitalWrite(IN1,HIGH);
              digitalWrite(IN2,LOW);
              analogWrite(ENA,250);
              digitalWrite(IN3,LOW);
              digitalWrite(IN4,LOW);
              analogWrite(ENB,speed); 
              break;
            case ForwardRight:
              Serial.println("Forward Right");
              digitalWrite(IN1,HIGH);
              digitalWrite(IN2,LOW);
              analogWrite(ENA,250);
              digitalWrite(IN3,HIGH);
              digitalWrite(IN4,LOW);  
              analogWrite(ENB,speed);
              break;
            case ForwardLeft:
              Serial.println("Forward Left");
              digitalWrite(IN1,LOW);
              digitalWrite(IN2,HIGH);
              analogWrite(ENA,250);  
              digitalWrite(IN3,HIGH);
              digitalWrite(IN4,LOW);  
              analogWrite(ENB,speed);
              break;
            case BackRight:
              Serial.println("Back Right");
              digitalWrite(IN1,HIGH);
              digitalWrite(IN2,LOW);
              analogWrite(ENA,250);
              digitalWrite(IN3,LOW);
              digitalWrite(IN4,HIGH);  
              analogWrite(ENB,speed_r);
              break;                        
            case BackLeft:
              Serial.println("Back Left");
              digitalWrite(IN1,LOW);
              digitalWrite(IN2,HIGH);
              analogWrite(ENA,250);  
              digitalWrite(IN3,LOW);
              digitalWrite(IN4,HIGH);  
              analogWrite(ENB,speed_r);
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

void Block(){
      digitalWrite(IN1,LOW);
      digitalWrite(IN2,LOW);
      analogWrite(ENA,200);
      digitalWrite(IN3,LOW);
      digitalWrite(IN4,HIGH);
      analogWrite(ENB,speed_r);
      delay(100);
      randNum = random(300);  
      if (randNum > 150){
      digitalWrite(IN1,HIGH);
      digitalWrite(IN2,LOW);
      analogWrite(ENA,200);
      digitalWrite(IN3,LOW);
      digitalWrite(IN4,HIGH);  
      analogWrite(ENB,speed_r);
      delay(500);
      }
      else{
      digitalWrite(IN1,LOW);
      digitalWrite(IN2,HIGH);
      analogWrite(ENA,200);  
      digitalWrite(IN3,LOW);
      digitalWrite(IN4,HIGH);  
      analogWrite(ENB,speed_r);
      delay(500);
      }
      digitalWrite(IN1,LOW);
      digitalWrite(IN2,LOW);
      analogWrite(ENA,LOW);
      digitalWrite(IN3,LOW);
      digitalWrite(IN4,LOW);  
      analogWrite(ENA,LOW);
      delay(50);       
}





