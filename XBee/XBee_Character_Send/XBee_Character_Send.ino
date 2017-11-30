#include <SoftwareSerial.h>

SoftwareSerial xbee(2, 3); // RX, TX
int ledPin = 13;
char c = 'A';
int pingPong = 1;
int delaytime = 1000;

void setup()  {
  Serial.begin(9600);
  Serial.println( "Arduino started sending bytes via XBee" );
  pinMode(ledPin, OUTPUT);
  xbee.begin( 9600 );
}

void loop()  {
  xbee.print( c );
  Serial.println( c );
  
  c = c + 1;
  if ( c>'Z' ) 
       c = 'A';
  
  if ( pingPong == 0 )
    digitalWrite(ledPin, LOW);
  else
    digitalWrite(ledPin, HIGH);
  pingPong = 1 - pingPong;
  delay( delaytime );
}
