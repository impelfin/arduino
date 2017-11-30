#include <SoftwareSerial.h>

SoftwareSerial bluetooth(2,3);
char data;
int ledPin1 = 5;
int ledPin2 = 6;
int trPin1 = 10;
int trPin2 = 11;

void setup() {
  Serial.begin(9600); 
  bluetooth.begin(9600);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(trPin1, OUTPUT);
  pinMode(trPin2, OUTPUT);
}

void loop() {
   if(bluetooth.available()){
      data = bluetooth.read();     
      Serial.println(data);
      if(data=='a'){
        digitalWrite(trPin1, 1);
        digitalWrite(ledPin1, 1);
      }else if(data=='b'){
        digitalWrite(trPin1, 0);
        digitalWrite(ledPin1, 0);
      }else if(data=='c'){
        digitalWrite(trPin2, 1);
        digitalWrite(ledPin2, 1);
      }else if(data=='d'){
        digitalWrite(trPin2, 0);
        digitalWrite(ledPin2, 0);
      }      
   }    
}


