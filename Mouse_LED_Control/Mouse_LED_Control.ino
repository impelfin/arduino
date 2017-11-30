int rightLED = 12;
int leftLED = 13;

void setup() 
{
  Serial.begin(9600);
}

void loop () 
{
  if (Serial.available() > 0) 
  {
    int inByte = Serial.read();
    int recievedData = map(inByte, 0, 255, 0, 255);
    if(recievedData > 125)
    {
      digitalWrite(rightLED, HIGH);
      digitalWrite(leftLED, LOW);
    } else {
      digitalWrite(rightLED, LOW);
      digitalWrite(leftLED, HIGH);
    }
  }
}

