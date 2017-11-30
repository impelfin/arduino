int a;
int del = 1000;
float temperature;
int B = 3975;
float resistance;

void setup() 
{
  Serial.begin(9600);
}

void loop()
{
  a = analogRead(A0);
  resistance = (float)(1023 - 1) * 10000 / a;
  temperature = 1/(log(resistance / 10000) / B + 1 / 298.15) - 273.15;
  delay(del);
  Serial.println(temperature);
}
