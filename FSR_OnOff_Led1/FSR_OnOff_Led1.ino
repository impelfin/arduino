int ledPins[] = {2,3,4,5,6};
int FSRpin = 0;
int Vo;
float Rfsr;

void setup() {
  for(int i = 0; i <= 5; i++)
    pinMode(ledPins[i], OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int n;
  Vo = analogRead(FSRpin);
  Serial.println(Vo);
  n = Vo/100; 
  Serial.println(n);
  if(n == 10) {
    for(int i = 0; i <= 5; i++)
      digitalWrite(ledPins[i], LOW);
  } else if(n == 8) {
    digitalWrite(ledPins[0], HIGH);   
  } else if(n == 7) {
    digitalWrite(ledPins[1], HIGH);    
  } else if(n == 6) {
    digitalWrite(ledPins[2], HIGH);
  } else if(n == 5) {
    digitalWrite(ledPins[3], HIGH);
  } else if(n == 4){
    digitalWrite(ledPins[4], HIGH);
  }
  delay(100);
}
