#include <SoftwareSerial.h>

SoftwareSerial bluetooth(2,3);
char data;
int pin = 5;

void setup() {
  bluetooth.begin(9600);
  Serial.begin(9600);
}

void loop() {
   if(bluetooth.available()){
      data = bluetooth.read();     
      Serial.println(data);
      if(data=='a'){
        analogWrite(pin, 80);
      }else if(data=='b'){
        analogWrite(pin, 160);
      } else if(data=='c'){
        analogWrite(pin, 255);
      } else if(data=='s'){
        analogWrite(pin, 0);
      }
   }    
}
