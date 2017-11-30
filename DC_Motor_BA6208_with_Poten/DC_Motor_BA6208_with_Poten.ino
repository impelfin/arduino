int led = 13;
int motorA = 5;
int motorB = 6;
int SensorPin = A0;
int SensorValue = 0;
int motorSpeed = 0;

void Forward(int x, int motorSpeed);
void mStop(int x);
void Backward(int x, int motorSpeed);

void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(motorA, OUTPUT);
  pinMode(motorB, OUTPUT);  
}

void loop() {
  SensorValue = analogRead(SensorPin);
  motorSpeed = map(SensorValue, 0, 1023, 0, 255);
  Serial.println(motorSpeed);
  Forward(2000, motorSpeed);
  mStop(1000);
  Backward(2000, motorSpeed);
  mStop(1000);
}

void Forward(int x, int motorSpeed)
{
  if(motorSpeed >= 0) 
  {
    analogWrite(motorA, motorSpeed);
    analogWrite(motorB, 0);
    digitalWrite(led, 1);
  }
  delay(x);
}

void Backward(int x, int motorSpeed)
{
  if(motorSpeed >= 0) 
  {
    analogWrite(motorA, 0);
    analogWrite(motorB, motorSpeed);
    digitalWrite(led, 1);
  }
  delay(x);
}

void mStop(int x)
{
    digitalWrite(motorA, 0);
    digitalWrite(motorB, 0);
    digitalWrite(led, 1);
    delay(x);
}
