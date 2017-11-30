int pir = A0; //pin Analog 0
int lenPin = 13;

void setup() {
  pinMode(pir, INPUT);
  pinMode(lenPin, OUTPUT);
  Serial.begin(9600);

}

void loop() {
  int valSensor = analogRead(pir);
  Serial.print("Sensor value : ");
  Serial.println(valSensor);
  delay(100);
}
