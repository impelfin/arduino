#include "MsTimer2.h"

byte LED1 = 2;
byte LED2 = 3;
byte SW1 = 8;
byte SW2 = 9;

volatile byte Count01 = 0; //SW1
volatile byte Count02 = 0;

volatile byte Count1 = 0;
volatile byte Count2 = 0;

boolean sw1state1 = false;
boolean sw2state1 = false;
boolean sw1state = false;
boolean sw2state = false;

void TimerExec() { 
   Count01++;       
   Count02++;       
   Count1++;      
   Count2++;   
}

void setup() {
   Serial.begin(9600);
   pinMode(LED1, OUTPUT);
   pinMode(LED2, OUTPUT);
   pinMode(SW1, INPUT_PULLUP);
   pinMode(SW2, INPUT_PULLUP);
        
   MsTimer2::set(10,TimerExec);
   MsTimer2::start();         
}  

void loop() {
   if(digitalRead(SW1) == LOW) {  
      if(sw1state1 == true) { 
          if(Count01 >= 1) {
             sw1state1 = false;
             if(sw1state) {
                sw1state = false;
                digitalWrite(LED1, LOW);
             } else {
                sw1state = true; 
                Count1 = 0;
             }
          }
      } else {
         sw1state1 = true; 
         Count01 = 0;
      }
   }
   
   if(digitalRead(SW2) == LOW) {
      if(sw2state1 == true) {
         if(Count02 >= 1) {
            sw2state1 = false;
            if(sw2state) {
               sw2state = false;
               digitalWrite(LED2, LOW);
            } else {
               sw2state = true; 
               Count2 = 0;
            }
         }
      } else {
         sw2state1 = true; 
         Count02 = 0;
      }
   }
   
   if(sw1state == true) {
      if(Count1 < 40)  digitalWrite(LED1, HIGH);
      if(Count1 > 40)  digitalWrite(LED1, LOW);
      if(Count1 > 80)  Count1 = 0;
   } 

   if(sw2state == true) { 
      if(Count2 < 30)  digitalWrite(LED2, HIGH);
      if(Count2 > 30)  digitalWrite(LED2, LOW);
      if(Count2 > 60)  Count2 = 0;
   } 
}
