int led = 13;
int FSRpin = 0;
int Vo;
float Rfsr;

void setup() {
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if(Serial.available())
  {
    int c = Serial.read();
    if(c == '1')
      digitalWrite(led, HIGH);
    else if(c == '0')
      digitalWrite(led, LOW);
  }
  Vo = analogRead(FSRpin);
  Rfsr = ((9.78 * Vo) / (1 - (Vo / 1023.0)));
  Serial.println(Rfsr);
  delay(200);
}
