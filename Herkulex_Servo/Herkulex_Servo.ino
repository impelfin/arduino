#include <HerkuleX.h>

#define RX 10
#define TX 11
#define MOTORID 253

void setup() 
{
  Serial.begin(9600);
  HerkuleX.begin(115200, RX, TX);
  delay(10);
  HerkuleX.torqueOn(MOTORID);
}

void loop()
{
  unsigned char incomingbyte = 0;
  
  if (HerkuleX.getStatus(MOTORID) != HERKULEX_STATUS_OK) {
    HerkuleX.clear(MOTORID);
  }
  
  if (Serial.available() > 0) {
    incomingbyte = Serial.read();
    
    if (incomingbyte == '1') {
      Serial.println("Move angle");
      HerkuleX.moveAngle(MOTORID, -30, 10, HERKULEX_LED_BLUE);
    }
 
    if (incomingbyte == 'a') {
      Serial.println("Current angle");
      Serial.println(HerkuleX.getAngle(MOTORID));
    }

    if (incomingbyte == '2') {
      Serial.println("Move pos");
      HerkuleX.moveAngle(MOTORID, 512, 200, HERKULEX_LED_RED);
    }
 
    if (incomingbyte == 'p') {
      Serial.println("Current pos");
      Serial.println(HerkuleX.getPos(MOTORID));
    }   
    
    if (incomingbyte == '3') {
      Serial.println("Turn");
      HerkuleX.turn(MOTORID, 600, 10, HERKULEX_LED_GREEN | HERKULEX_LED_BLUE | HERKULEX_LED_RED);
    }
 
    if (incomingbyte == 't') {
      Serial.println("Turn Speed");
      Serial.println(HerkuleX.getTurnSpeed(MOTORID));
    }
    
    if (incomingbyte == 'q') {
      Serial.println("Finish");
      HerkuleX.torqueOff(MOTORID);
    }      
  }
}
