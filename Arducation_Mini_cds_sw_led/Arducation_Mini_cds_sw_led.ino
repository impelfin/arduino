
const int buttonPin = 5;    
const int ledPin =  10;      
const int cds = A0;

int buttonState = 0;    
int cdsValue = A0;     
const int thresholdValue = 50;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
  pinMode(cds, INPUT);
  
}

void loop() {
  buttonState = digitalRead(buttonPin);
  cdsValue = analogRead(A0);
  Serial.println(buttonState);
  Serial.println(cdsValue);

  if (buttonState == 11 || cdsValue < thresholdValue) {
    digitalWrite(ledPin, 1);
  } else {
    digitalWrite(ledPin, 0);
  }
}
