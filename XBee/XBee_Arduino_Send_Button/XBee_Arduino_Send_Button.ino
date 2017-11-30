/*
  DigitalReadSerial
 Reads a digital input on pin 2, prints the result to the serial monitor 
 
 This example code is in the public domain.
 */

// digital pin 2 has a pushbutton attached to it. Give it a name:
int pushButton = A0;

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  // make the pushbutton's pin an input:
  pinMode(pushButton, INPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input pin:
  int buttonState = digitalRead(pushButton);
  // print out the state of the button:
  if (buttonState == HIGH){
    //Serial.print("a");
  //Serial.print(buttonState, DEC);
    Serial.println(buttonState, DEC);
  }
  if (buttonState == LOW){
    Serial.println(buttonState, DEC);
  //Serial.print("b");
  //Serial.write(buttonState);
  //Serial.write(35);
  }
  delay(1);        // delay in between reads for stability

}


