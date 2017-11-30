#include <SoftwareSerial.h>

SoftwareSerial xbee(2,3);
unsigned long time_previous, time_current;
byte count = 0;

void setup(){
  Serial.begin(9600);
  xbee.begin(9600);
  time_previous = millis();
}

void loop(){
  time_current = millis();

  if(time_current - time_previous > 1000){
    time_previous = time_current;
    count++;
  }

  if(xbee.available()){
    byte data = xbee.read();
    if(data == 'C')
    xbee.write(count);
    Serial.println(count);
  }
}
