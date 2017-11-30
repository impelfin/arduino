#include <SoftwareSerial.h>

SoftwareSerial xbee(2, 3);
const int ledPin = 13;
int incomingByte;     

void setup() {
  Serial.begin(9600);
  xbee.begin(9600);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  if (xbee.available() > 0) {
    incomingByte = xbee.read();
    if (incomingByte == 'H') {
      digitalWrite(ledPin, HIGH);
      Serial.println(char(incomingByte));
    } 

    if (incomingByte == 'L') {
      digitalWrite(ledPin, LOW);
      Serial.println(char(incomingByte));
    }
  }  
}

