#include <SoftwareSerial.h>

int BTS_RX = 3;
int BTS_TX = 2;

SoftwareSerial BTSerial(BTS_TX,BTS_RX);

void setup(){
  Serial.begin(9600);
  BTSerial.begin(9600);
}

void loop(){
  if (BTSerial.available())
    Serial.write(BTSerial.read());
  if (Serial.available())
    BTSerial.write(Serial.read());
}
