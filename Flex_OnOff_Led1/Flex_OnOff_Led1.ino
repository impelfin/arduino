int ledPins[] = {2,3,4,5,6};
int flexpin = 0;

void setup() {
  for(int i = 0; i <= 5; i++)
    pinMode(ledPins[i], OUTPUT);
  Serial.begin(9600);
}

void loop() {
    int flexVal, n;
  flexVal = analogRead(flexpin);
//  Serial.println(flexVal);
  n = flexVal/10; 
  Serial.println(n);
  if(n < 80) {
    for(int i = 0; i <= 5; i++)
      digitalWrite(ledPins[i], LOW);
  } else if(n <= 81) {
      digitalWrite(ledPins[0], HIGH);   
  } else if(n <= 83) {
    digitalWrite(ledPins[1], HIGH);    
  } else if(n <= 85) {
    digitalWrite(ledPins[2], HIGH);
  } else if(n <= 87) {
    digitalWrite(ledPins[3], HIGH);
  } else if(n > 90){
    digitalWrite(ledPins[4], HIGH);
  }
  delay(100);
}
