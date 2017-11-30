#include <SoftwareSerial.h>
SoftwareSerial xbee(2,3);
unsigned long time_previous, time_current;
void setup() {
  Serial.begin(9600);
  xbee.begin(9600);
  time_previous = millis();
}

void loop() {
  time_current = millis();

  if(time_current - time_previous > 2000){
    time_previous = time_current;
    xbee.write('C');
  }

  if(xbee.available()){
    Serial.println(xbee.read());
  }
}
