void setup() {
  for(int i=9; i<=13; i++)
    pinMode(i, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  for(int i=9; i<=13; i++)  
    digitalWrite(i, HIGH);
  delay(1000);
  for(int i=9; i<=13; i++)
    digitalWrite(i, LOW);
  delay(1000);
}
