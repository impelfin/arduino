int sersorPin = A0; //pin Analog 0
int lenPin = 13;
int valSensor = 0;

void setup() {
  pinMode(sersorPin, INPUT);
  pinMode(lenPin, OUTPUT);
  Serial.begin(9600);

}

void loop() {
  int valSensor = analogRead(sersorPin);
  Serial.print("Sensor value : ");
  Serial.println(valSensor);
  delay(100);
}
