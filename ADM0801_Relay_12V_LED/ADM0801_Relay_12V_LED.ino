int touch = 2;
int relayPin = 11;

unsigned char o_sw, n_sw;
int relay_state = 0;
int delayVal = 30;

void setup() {
  pinMode(touch, INPUT);
  pinMode(relayPin, OUTPUT);
  Serial.begin(9600);
  o_sw = 0;
}

void loop() {
  n_sw = digitalRead(touch);

  if (o_sw == 0 && n_sw == 1 && relay_state == 0) relay_state = 1;
  else if (o_sw == 0 && n_sw == 1 && relay_state == 1) relay_state = 0;

  if(relay_state == 0) digitalWrite(relayPin, 0);
  if(relay_state == 1) digitalWrite(relayPin, 1);

  Serial.print("relayPin_State : ");
  Serial.println(relay_state);

  delay(delayVal);
  
  o_sw = n_sw;
}
