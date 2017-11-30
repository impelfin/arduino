// PIR Sensor Tester 

int lenPin = 13;
int inputPin = 2;
int pirState = LOW;
int val = 0;

void setup() {
  pinMode(lenPin, OUTPUT);
  pinMode(inputPin, INPUT);
  
  Serial.begin(9600);
}

void loop() {
  val = digitalRead(inputPin);
  if(val == HIGH) {
    digitalWrite(lenPin, HIGH);
    if(pirState == LOW) {
      Serial.println("Motion Detected!");
      pirState = HIGH;
    }
  } else {
    digitalWrite(lenPin, LOW);
    if(pirState == HIGH) {
      Serial.println("Motion ended!");
      pirState = LOW;
    }
  }
}
