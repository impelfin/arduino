#include <SoftwareSerial.h>

SoftwareSerial xbee(2, 3); // RX, TX
int ledPin = 13;
byte message = 0;
int pingPong = 1;
int delaytime = 1000;

void setup() {
  Serial.begin(9600);
  Serial.println( "Arduino started receiveing bytes via XBee" );  
  pinMode(ledPin, OUTPUT);
  xbee.begin( 9600 );  
}

void loop() {
  xbeeEvent();
  if (message != 0){
      char inChar = (char)message;
      Serial.println(inChar); 
  }
  if ( pingPong == 0 )
    digitalWrite(ledPin, LOW);
  else
    digitalWrite(ledPin, HIGH);
  pingPong = 1 - pingPong;  
  delay( delaytime );
}


void xbeeEvent() {
  while (xbee.available()) {
    message = xbee.read();
  }
}


