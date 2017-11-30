#include <SoftwareSerial.h>
#include <elapsedMillis.h>

SoftwareSerial BTSerial(2,3); //rx, tx 

//const char Break = 'X';
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

int ENA = 5;
int IN1 = 7;
int IN2 = 8;
int ENB = 6;
int IN3 = 9;
int IN4 = 10;
int echoPin = 11;
int trigPin = 12;

char data;
int speed = 100;
int speed_r = 80;
long duration, distance;
int break_distance = 20;
int randnum = 0;
elapsedMillis timeElapsed;
unsigned int interval = 500;

void setup() {
	BTSerial.begin(9600);
  	Serial.begin (9600); 
  	pinMode(ENA,OUTPUT);
  	pinMode(IN1,OUTPUT);
  	pinMode(IN2,OUTPUT);
  	pinMode(ENB,OUTPUT);
  	pinMode(IN3,OUTPUT);
  	pinMode(IN4,OUTPUT);
  	pinMode(trigPin,OUTPUT);
  	pinMode(echoPin,INPUT);
        randomSeed(analogRead(0));  
}

void loop() {
	if(BTSerial.available()) {    
		data = BTSerial.read();          
	}
	if(Serial.available()) {
		data = Serial.read();
	}  
        switch (data) {				
		case Speed0:
			speed = 0;
			speed_r = 0;
			break;
		case Speed1:
			speed = 100;
			speed_r = 0;
			break;
		case Speed2:
			speed = 117;
			speed_r = 17;
			break;
		case Speed3:
			speed = 134;
			speed_r = 34;
			break;
		case Speed4:
			speed = 151;
			speed_r = 51;
			break;
		case Speed5:
			speed = 168;
			speed_r = 80;
			break;		
		case Speed6:
			speed = 185;
			speed_r = 85;
			break;
		case Speed7:
			speed = 202;
			speed_r = 100;
			break;
		case Speed8:
			speed = 219;
			speed_r = 100;
			break;
		case Speed9:
			speed = 236;
			speed_r = 100;
			break;
		case Speed10:
			speed = 255;
			speed_r = 100;	
			break;	          	                
		case Forward:
			R_Forward(speed,speed_r);
			break;
		case Back:
			R_Back(speed,speed_r);
			break;
		case Left:
			R_Left(speed,speed_r);
			break;
		case Right:
			R_Right(speed,speed_r);
			break;
		case ForwardRight:
			R_ForwardRight(speed,speed_r);
			break;
		case ForwardLeft:
			R_ForwardLeft(speed,speed_r);
			break;
		case BackRight:
			R_BackRight(speed,speed_r);
			break;                        
		case BackLeft:
			R_BackLeft(speed,speed_r);
			break;
		case Stop:
			R_Stop();
			break;                      
	}
}

int DistanceCheck() {
	digitalWrite(trigPin, LOW); // Added this line
	delayMicroseconds(2); // Added this line
	digitalWrite(trigPin, HIGH);
	delayMicroseconds(10); // Added this line
	digitalWrite(trigPin, LOW);
	duration = pulseIn(echoPin, HIGH);
	distance = (duration/2) / 29.1;  
        return distance;
}
  
void R_Forward(int speed,int speed_r) {
        timeElapsed = 0;
	int i = DistanceCheck();
	Serial.println(i);
	if(i <= break_distance) {  
                while(!timeElapsed > interval) {
                  R_Stop();
                  timeElapsed = 0;
                }                    
                while(!timeElapsed > interval) {       
                  R_Back(speed,speed_r);
                  timeElapsed = 0;
                }
/*		randnum = random(300);
		if(randnum > 150) {
			R_Right(speed,speed_r);
                        delay(50);
		} else {
			R_Left(speed,speed_r);
                        delay(50);
		} */
	} else {
		digitalWrite(IN1,0);
		digitalWrite(IN2,1);
		analogWrite(ENA,speed);
		digitalWrite(IN3,1);
		digitalWrite(IN4,0);
		analogWrite(ENB,speed);
	}
}

void R_Back(int speed,int speed_r) {
	digitalWrite(IN1,1);
	digitalWrite(IN2,0);
	analogWrite(ENA,speed);
	digitalWrite(IN3,0);
	digitalWrite(IN4,1);
	analogWrite(ENB,speed);
}

void R_Right(int speed, int speed_r) {
	digitalWrite(IN1,0);
	digitalWrite(IN2,1);
	analogWrite(ENA,speed);
	digitalWrite(IN3,0);
	digitalWrite(IN4,1);
	analogWrite(ENB,speed);  
}

void R_Left(int speed, int speed_r) {
	digitalWrite(IN1,1);
	digitalWrite(IN2,0);
	analogWrite(ENA,speed);
	digitalWrite(IN3,1);
	digitalWrite(IN4,0);
	analogWrite(ENB,speed);  
}

void R_ForwardRight(int speed, int speed_r) {
	digitalWrite(IN1,0);
	digitalWrite(IN2,1);
	analogWrite(ENA,speed);
	digitalWrite(IN3,1);
	digitalWrite(IN4,0);  
	analogWrite(ENB,speed_r);
}

void R_ForwardLeft(int speed, int speed_r) {
	digitalWrite(IN1,0);
	digitalWrite(IN2,1);
	analogWrite(ENA,speed_r);  
	digitalWrite(IN3,1);
	digitalWrite(IN4,0);  
	analogWrite(ENB,speed);
}

void R_BackRight(int speed, int speed_r) {
	digitalWrite(IN1,1);
	digitalWrite(IN2,0);
	analogWrite(ENA,speed);
	digitalWrite(IN3,0);
	digitalWrite(IN4,1);  
	analogWrite(ENB,speed_r);
}

void R_BackLeft(int speed, int speed_r) {
	digitalWrite(IN1,1);
	digitalWrite(IN2,0);
	analogWrite(ENA,speed_r);  
	digitalWrite(IN3,0);
	digitalWrite(IN4,1);  
	analogWrite(ENB,speed);
}

void R_Stop() {
	digitalWrite(IN1,0);
	digitalWrite(IN2,0);
	analogWrite(ENA,0);
	digitalWrite(IN3,0);
	digitalWrite(IN4,0);  
	analogWrite(ENB,0);
}
