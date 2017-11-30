#include "pins_Arduino.h"

int a=0;
int b=0;
int c=0;
int d=0;
int e=0;
int f=0;
int g=0;
int h=0;



void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(5, INPUT);
  pinMode(6, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:


    Serial.print(" 도 : "); Serial.print(analogRead(A0));
    Serial.print(" 래 : "); Serial.print(analogRead(A1));
    Serial.print(" 미 : "); Serial.print(analogRead(A2));
    Serial.print(" 파 : "); Serial.print(analogRead(A3));
    Serial.print(" 솔 : "); Serial.print(analogRead(A4));
    Serial.print(" 라 : "); Serial.print(analogRead(A5));
    Serial.print(" 시 : "); Serial.print(analogRead(A6));
    Serial.print(" 높은도 : "); Serial.print(analogRead(A7));
    Serial.print(" \n\n ");

    delay(1000);

}
