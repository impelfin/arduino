int controlPin = 9;
int redPin= 7;
int greenPin = 6;
int bluePin = 5;

int Delay_t = 30;
int brightness = 255;
int fadeAmount = 5;

void setup() {

}

void loop() {
    analogWrite(controlPin, brightness);
    setColor(0,0,0);
    brightness -= fadeAmount;
    if(brightness == 255 || brightness == 0) fadeAmount = -fadeAmount;
    delay(Delay_t);
/*
  setColor(0, 0, 0); // White Color
  delay(Delay_t);
  setColor(0, 255, 255); // Red Color
  delay(Delay_t);
  setColor(255, 0, 255); // Green Color
  delay(Delay_t);
  setColor(255, 255, 0); // Blue Color
  delay(Delay_t);
  setColor(125, 255, 0); // Purple Color
  delay(Delay_t);
*/
}

void setColor(int redValue, int greenValue, int blueValue) {
  analogWrite(redPin, redValue);
  analogWrite(greenPin, greenValue);
  analogWrite(bluePin, blueValue);
}
