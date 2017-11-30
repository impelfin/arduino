int s_pin = 3;
int r_pin = A0;
int r_value = 0;

void setup() {
  Serial.begin(9600);
  pinMode(s_pin, OUTPUT);
  pinMode(s_pin, OUTPUT);
}

void loop() {
  digitalWrite(s_pin, HIGH);
  r_value = analogRead(r_pin);
  Serial.println(r_value);
  delay(100);
}
