#include <NewPing.h>

int ledPin = 12;
int trigPin = 3;  // TrigPin 설정
int echoPin = 4;  // EchoPin 설정

#define MAX_DISTANCE 200 // 최대 거리 설정

NewPing sonar(trigPin, echoPin, MAX_DISTANCE); 
 
void setup() {
  Serial.begin (9600); // 시리얼 통신 설정
  pinMode(ledPin, OUTPUT);
}

void loop(){
  unsigned int uS = sonar.ping();
  unsigned int dist = uS / US_ROUNDTRIP_CM;
  if( dist == 0) { 
    Serial.println("distance over!!");
  } else {
    Serial.print("Ping: ");
    Serial.print(dist); 
    Serial.println("cm");
  }
  if(dist != 0 && dist < 30) {
    digitalWrite(ledPin, 1);
    delay(3000);
  } else {
    digitalWrite(ledPin, 0);
  }
  delay(50); // 딜레이 설정
}
