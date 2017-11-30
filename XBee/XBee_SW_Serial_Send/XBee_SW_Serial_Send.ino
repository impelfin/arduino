#include <SoftwareSerial.h>

SoftwareSerial xbee(2, 3);
const int ledPin = 13;
int delaytime = 300;

void setup()
{
    Serial.begin(9600);
    xbee.begin(9600);
    pinMode(ledPin, OUTPUT);
}

void loop()
{
    digitalWrite(ledPin, HIGH);
    xbee.print('H');
    delay(delaytime);

    digitalWrite(ledPin, LOW);
    xbee.print('L');
    delay(delaytime);
}

