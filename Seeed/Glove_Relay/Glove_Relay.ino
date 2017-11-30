const int buttonPin = 3;
const int relayPin = 6;
int buttonState = 0;

void setup() 
{
  pinMode(relayPin, OUTPUT);
  pinMode(buttonPin, OUTPUT);
}

void loop()
{
  buttonState = digitalRead(buttonPin);
  if (buttonPin == 1)
    digitalWrite(relayPin, HIGH);
  else
    digitalWrite(relayPin, LOW);
  delay(10);
}
