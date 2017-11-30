int signal = 4;
int onoff;

void setup() {
  Serial.begin(9600);
}

void loop() {
  onoff = digitalRead(signal);
  Serial.println(onoff);
}
