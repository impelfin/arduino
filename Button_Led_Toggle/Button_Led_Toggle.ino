const int buttonPin = 7;
const int ledPin =  8;

int buttonState = 0;
int current_btn = 0;
int last_btn = 0;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  current_btn = digitalRead(buttonPin);

  if(last_btn == 1 && current_btn == 0) {
    buttonState =! buttonState;
  }

  last_btn = current_btn;

  digitalWrite(ledPin, buttonState);
}
