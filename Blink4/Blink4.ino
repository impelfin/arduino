int timer = 100;
int ledPins[] = {2, 3, 4, 5};  
int pinCount = 4; 

void setup() {
  for (int thisPin = 0; thisPin < pinCount; thisPin++) {
    pinMode(ledPins[thisPin], OUTPUT);
  }
  Serial.begin(9600);
}

void loop() {
  for (int thisPin = 0; thisPin < pinCount; thisPin++) {
    digitalWrite(ledPins[thisPin], HIGH);
    Serial.print(ledPins[thisPin]);
    Serial.println(" Pin On");
    delay(timer);
    digitalWrite(ledPins[thisPin], LOW);
  }
}
