int flexpin = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int flexVal;
  flexVal = analogRead(flexpin);
  Serial.print("Sensor : ");
  Serial.println(flexVal);
  delay(200);
}
