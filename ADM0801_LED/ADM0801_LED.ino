int touch = 2;
int ledPin = 11;

unsigned char o_sw, n_sw;
int led_state = -1;
int delayVal = 30;

void setup() {
  pinMode(touch, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
  o_sw = 0;
}

void loop() {
  n_sw = digitalRead(touch);

  if(led_state == -1) led_state = 0;
  else if(o_sw == 0 && n_sw == 1 && led_state < 4) led_state++;
  
  if (o_sw == 0 && n_sw == 1 && led_state == 4) led_state = 0;

  if(led_state == 0) analogWrite(ledPin, 0);
  if(led_state == 1) analogWrite(ledPin, 80);
  if(led_state == 2) analogWrite(ledPin, 160);
  if(led_state == 3) analogWrite(ledPin, 255);

  Serial.print("Led_State : ");
  Serial.println(led_state);

  delay(delayVal);
  
  o_sw = n_sw;
}
