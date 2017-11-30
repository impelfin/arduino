int tempPin = 0;
float V, C;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  int reading = analogRead(tempPin);
  V = reading * 5;
  V = V / 1024;
  C = 100 * (V - 0.5);
  Serial.print("voltage : ");
  Serial.print(V);
  Serial.print("  deg: ");
  Serial.print(C);
  Serial.print("\n");
  delay(1000);
}
