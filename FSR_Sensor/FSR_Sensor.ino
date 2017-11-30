int FSRpin = 0;
int Vo;
float Rfsr;

void setup() {
  Serial.begin(9600);
}

void loop() {
  Vo = analogRead(FSRpin);
  Rfsr = ((9.78 * Vo) / (1 - (Vo / 1023.0))); 
  Serial.print("Rfsr : ");
  Serial.println(Rfsr);
  delay(200);
}
