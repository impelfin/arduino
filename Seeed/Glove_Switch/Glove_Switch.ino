int led = 7;
int button = 3;

void setup() {                
  pinMode(led, OUTPUT);
  pinMode(button, INPUT);  
}

void loop() {
  int buttonState  = digitalRead(button);
  if(buttonState == 1)
    digitalWrite(led, 1);
  else
    digitalWrite(led, 0);
}
