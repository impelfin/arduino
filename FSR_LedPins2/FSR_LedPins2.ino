nt ledPins[] = {4,5,6,7,8,9,10,11,12}; // LED
int push = 0; // choose the input pin (for a pushbutton)
int Vo;

void setup()
{
  for(int index = 0; index < 9; index++)
  {
    pinMode(ledPins[index], OUTPUT); // declare LED as output
  }  
  Serial.begin(9600);
}

void loop()
{ 
  Serial.println ("Press the Switch");
  
  int val = analogRead(push); // read input value
  int Lindex = map(val, 1023, 200, 0, 9);
  Serial.println(val);
  Serial.println(Lindex);
  
  if(val = HIGH);{
    for(int index = 0; index <= Lindex; index++)
    {
      digitalWrite(ledPins[index], HIGH); // turn LED on
    }
    delay(500);
  }
      for(int index = 0; index <= Lindex; index++)
    {
      digitalWrite(ledPins[index], LOW); // turn LED on
    }
}
