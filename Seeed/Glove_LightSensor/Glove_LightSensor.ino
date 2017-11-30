int ledPin = 6;
int thresholdValue = 400;

void setup() 
{
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}

void loop()
{
  int sensorValue = analogRead(A0);
  Serial.println(sensorValue);
  if(sensorValue < thresholdValue)
    digitalWrite(ledPin, HIGH);
  else
    digitalWrite(ledPin, LOW);
}
