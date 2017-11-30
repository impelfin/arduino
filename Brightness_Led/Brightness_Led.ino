int led = 3;
int brightness = 0;
int increment = 1;

void setup() {
 //
}

void loop() {
  if(brightness > 255)
    increment = -1;
  else if(brightness < 1)
    increment = 1;
  brightness += increment;
  analogWrite(led, brightness);
  delay(10);
}
