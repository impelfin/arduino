int led = 3;
int brightness = 0;
int increment = 1;
int FSRpin = 0;
int Vo;
float Rfsr;

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  Vo = analogRead(FSRpin);
  brightness = map(Vo, 0, 1023, 0, 255);
  analogWrite(led, brightness);
  delay(10);  
}
