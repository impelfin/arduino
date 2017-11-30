const int mg = 2;
const int button1 = 3; 
const int photo = 4;
const int qrd = 5;
const int buzzer = 10;
const int dc_m1 = 11;
const int dc_m2 = 12;
const int ledpin = 13;

const int cds = A0;
const int thresholdValue = 50;

int button1_s = 0;        

void setup() {
  Serial.begin(9600);
// pinMode(mg, INPUT);   
  pinMode(button1, INPUT); 
  pinMode(photo, INPUT); 
  pinMode(ledpin, OUTPUT);   
  pinMode(buzzer, OUTPUT);
  pinMode(dc_m1, OUTPUT);   
  pinMode(dc_m2, OUTPUT);   
}

void loop(){
  digitalWrite(ledpin, 0);
  digitalWrite(buzzer, 0);
  analogWrite(dc_m1, 0);
  analogWrite(dc_m2, 0);
 
  int cdsValue = 0;
  cdsValue = analogRead(A0);
//Serial.println(cdsValue);
    
  int mgValue = digitalRead(mg);
  Serial.println(mgValue);
  
  int photoValue = digitalRead(photo);
//Serial.println(photoValue);
  
  int qrdValue = digitalRead(qrd);
//Serial.println(qrdValue);

  button1_s = digitalRead(button1);

  if (button1_s == 1 || mgValue == 1 || qrdValue == 0 || photoValue == 0 || cdsValue < thresholdValue) {     
    Serial.println("Button1 Clicked~!!");
    digitalWrite(ledpin, 1);
    digitalWrite(buzzer, 1);
    analogWrite(dc_m1, 80);
    analogWrite(dc_m2, 0);
  } 
  delay(100);
}
