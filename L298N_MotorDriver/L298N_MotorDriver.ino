int IN1 = 5;
int IN2 = 6;
int speed = 0;

void setup() {
	Serial.begin(9600);
	pinMode(IN1, OUTPUT);
	pinMode(IN2, OUTPUT);
}

void loop() {	
	Forward(200, 2000);
	Stop(500);
	Backward(200, 2000);
	Stop(500);
}	

void Forward(int speed, int x) {
	analogWrite(IN1, speed);
	analogWrite(IN2, 0);
	Serial.println("Forward~!!");
	Serial.println(speed);
	delay(x);
}

void Stop(int x) {
	analogWrite(IN1, 0);
	analogWrite(IN2, 0);	
	Serial.println("Stop~!!");	
	delay(x);
}

void Backward(int speed, int x) {
	analogWrite(IN1, 0);
	analogWrite(IN2, speed);
	Serial.println("Backward~!!");	
	Serial.println(speed);
	delay(x);	
}


