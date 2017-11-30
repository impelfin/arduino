int led = 13;
int motorA = 5;
int motorB = 6;
int motorSpeed = 200;

void Forward(int x, int motorSpeed);
void mStop(int x);
void Backward(int x, int motorSpeed);

void setup() {
  pinMode(led, OUTPUT);
  pinMode(motorA, OUTPUT);
  pinMode(motorB, OUTPUT);  
}

void loop() {
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
