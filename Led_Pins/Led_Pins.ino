int ledPins[] = {2,3,4,5,6,7,8,9,10,11};

void setup() {
   for(int i = 0; i <= 9; i++)
     pinMode(ledPins[i], OUTPUT);
     Serial.begin(9600);
}

void loop() {
  for(int i = 0; i <= 9; i++)
  {
    digitalWrite(ledPins[i], HIGH);
    delay(100);
  }
  for(int i = 9; i >= 0; i--)
  {
    digitalWrite(ledPins[i], LOW);
    delay(100);    
  }
  for(int i = 0; i <= 9; i++)
  {
    digitalWrite(ledPins[i], HIGH);
    digitalWrite(ledPins[i-1],LOW);
    delay(100);
  }
  for(int i = 9; i >= 0; i--)
  {
    digitalWrite(ledPins[i], HIGH);
    delay(100);    
  }
  for(int i = 0; i <= 9; i++)
  {
    digitalWrite(ledPins[i], LOW);
    delay(100);
  }  
  for(int i = 9; i >= 0; i--)
  {
    digitalWrite(ledPins[i], LOW);
    digitalWrite(ledPins[i-1],HIGH);
    delay(100);    
  }  
}
