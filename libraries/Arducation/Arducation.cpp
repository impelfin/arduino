#include "Arduino.h"
#include "Arducation.h"

bool blink_pinMode_check=false;
bool ultrasonic_pinMode_check=false;
bool piezo_pinMode_check=false;
bool reedsensor_pinMode_check=false;
bool infrared_pinMode_check=false;
bool tactSwitch_pinMode_check=false;
bool dipSwitch_pinMode_check=false;
bool vibrationSensor_pinMode_check=false;
bool touchSensor_pinMode_check=false;
bool dcmotor_pinMode_check=false;

Flex::Flex(int pin)
{  
	flexPin = pin;
}

Blink::Blink(int pin)
{  
	blinkPin = pin;
}

LightSensor::LightSensor(int pin)
{  
	lightPin = pin;
}

Pressure::Pressure(int pin)
{  
	pressurePin = pin;
}

Delay::Delay(long delay)
{
	delay_time = delay;
}

UltrasonicWave::UltrasonicWave(int in_pin,int out_pin)
{
	ultrasonicWave_in_pin = in_pin;
	ultrasonicWave_out_pin = out_pin;
}

Piezo::Piezo(int pin,int sound)
{
	piezoPin = pin;
	_sound = sound;
}

ReedSensor::ReedSensor(int pin)
{
	reedsensorPin = pin;
}

Potentiometer::Potentiometer(int pin)
{
	potentiometerPin = pin;
}

Infrared::Infrared(int pin)
{
	infraredPin = pin;
}

TactSwitch::TactSwitch(int pin)
{
	tactSwitchPin = pin;
}

DipSwitch::DipSwitch(int pin)
{
	dipSwitchPin = pin;
}

VibrationSensor::VibrationSensor(int pin)
{
	vibrationSensorPin = pin;
}

TemperatureSensor::TemperatureSensor(int pin)
{
	temperatureSensorPin = pin;
}

TouchSensor::TouchSensor(int pin)
{
	touchSensorPin = pin;
}

DCMotor::DCMotor(int pin)
{
	dcmotorPin = pin;
}

void Delay::delayStart()
{
	delay(delay_time);
}
// flex센서, 구부림정도 측정
void Flex::flexStart()
{

  int flexVal;

  flexVal = analogRead(flexPin); // 아날로그 신호 읽기
  Serial.print("sensor: ");
  Serial.println(flexVal); 
  delay(200);

}
// led, on/off상태 표시
void Blink::blinkStart()
{
	if(!blink_pinMode_check){
		pinMode(blinkPin, OUTPUT);
		blink_pinMode_check=true;
		Serial.println("It's pinMode ON");
	}
  digitalWrite(blinkPin, HIGH); // 디지털 신호 출력
  Serial.println("It's ON");
  delay(1000);
  digitalWrite(blinkPin, LOW);
  Serial.println("It's OFF");
  delay(1000);  
}
// 조도센서, 조도값 감지
void LightSensor::lightSensorStart()
{

  int lightVal;
	
  lightVal = analogRead(lightPin);
  Serial.print("cds: ");
  Serial.println(lightVal);
  delay(200);

}
// 압력센서, 압력값 감지
void Pressure::pressureStart()
{

  int pressureVal;
  float Rfsr;

  pressureVal = analogRead(pressurePin);
  Rfsr = ((9.78 * pressureVal)/(1-(pressureVal/1023.0)));  // 압력 공식
  Serial.print("Rfsr: ");
  Serial.println(Rfsr);
  delay(200);

}
// 초음파센서, 거리측정
void UltrasonicWave::ultrasonicWaveStart()
{
	int UltrasonicWaveVal;
	if(!ultrasonic_pinMode_check){
		pinMode(ultrasonicWave_out_pin, OUTPUT); // 센서 Trig 핀
		pinMode(ultrasonicWave_in_pin, INPUT); // 센서 Echo 핀
		ultrasonic_pinMode_check=true;
		Serial.println("It's pinMode ON");
	}
	
	digitalWrite(ultrasonicWave_out_pin,HIGH); // 센서에 Trig 신호 입력
  delayMicroseconds(10); // 10us 정도 유지
  digitalWrite(ultrasonicWave_out_pin,LOW); // Trig 신호 off
  
  UltrasonicWaveVal = pulseIn(ultrasonicWave_in_pin,HIGH)/58; // cm로 변환
  
  Serial.print(UltrasonicWaveVal);
  Serial.print("cm");
  Serial.println();
}
// 피에조 스피커, 한 음정 계속 출력
void Piezo::piezoStart()
{
	if(!piezo_pinMode_check){
		pinMode(piezoPin,OUTPUT);
		piezo_pinMode_check = true;
		Serial.println("It's pinMode ON");
	}
	
	digitalWrite(piezoPin,HIGH);
	delayMicroseconds(_sound);
	digitalWrite(piezoPin,LOW);
	delayMicroseconds(_sound);
}
// 리드센서, 자석의 거리에 따른 문구 표시
void ReedSensor::reedSensorStart()
{
	if(!reedsensor_pinMode_check){
		pinMode(reedsensorPin, INPUT); 
		reedsensor_pinMode_check=true;
		Serial.println("It's pinMode ON");
	}
	
	if(digitalRead(reedsensorPin) == 1)// 자석이 가까이 있을 때
  {
    Serial.println("It's ReedSensor ON");
  }
  else
  {
    Serial.println("It's ReedSensor OFF");
  }
}
// 가변저항센서, 스위치 회전에 따른 값 출력
void Potentiometer::potentiometerStart()
{
	int potentiometerVal;
	potentiometerVal = analogRead(potentiometerPin);
	Serial.println(potentiometerVal);
}
// 적외선센서, 방해물 유무에 따른 문구 표시
void Infrared::infraredStart()
{
	if(!infrared_pinMode_check){
		pinMode(infraredPin, INPUT); 
		infrared_pinMode_check=true;
		Serial.println("It's pinMode ON");
	}
	
	if(digitalRead(infraredPin) == 0)// 방해물이 있을 때
	{
		Serial.println("It's Infrared ON");
	}
	else
	{
		Serial.println("It's Infrared OFF");
	}
}

// 택트스위치, 스위치 on/off상태 표시
void TactSwitch::tactSwitchStart()
{
	if(!tactSwitch_pinMode_check){
		pinMode(tactSwitchPin, INPUT); 
		tactSwitch_pinMode_check=true;
		Serial.println("It's pinMode ON");
	}
	
	if(digitalRead(tactSwitchPin) == 1)// 스위치가 눌렸을 때
	{
		Serial.println("It's TactSwitch ON");
	}
	else
	{
		Serial.println("It's TactSwitch OFF");
	}
}

// 딥스위치, 스위치 on/off상태 표시
void DipSwitch::dipSwitchStart()
{
	if(!dipSwitch_pinMode_check){
		pinMode(dipSwitchPin, INPUT); 
		dipSwitch_pinMode_check=true;
		Serial.println("It's pinMode ON");
	}
	
	if(digitalRead(dipSwitchPin) == 1)// 스위치가 눌렸을 때
	{
		Serial.println("It's DipSwitch ON");
	}
	else
	{
		Serial.println("It's DipSwitch OFF");
	}
}

// 진동센서, 1초간격으로 진동
void VibrationSensor::vibrationSensorStart()
{
	if(!vibrationSensor_pinMode_check){
		pinMode(vibrationSensorPin, OUTPUT); 
		vibrationSensor_pinMode_check=true;
		Serial.println("It's pinMode ON");
	}
	
	digitalWrite(vibrationSensorPin,HIGH);// 진동 on
	delay(1000);
	digitalWrite(vibrationSensorPin,LOW);// 진동 off
	delay(1000);
}

// 온도센서, 섭씨,화씨온도 표시
void TemperatureSensor::temperatureSensorStart()
{
	int tempReading = analogRead(temperatureSensorPin);
  float tempVolts = tempReading * 5.0 / 1024.0; // 0~5V의 값을 구하기 위해 5를 곱한다
  float tempC = (tempVolts - 0.5) * 100.0; //섭씨
  float tempF = tempC * 9.0 / 5.0 + 32.0;  //화씨
  
  Serial.println(tempC);
  Serial.println(tempF);
}

//터치센서, 터치 여부 표시
void TouchSensor::touchSensorStart()
{
	if(!touchSensor_pinMode_check){
		pinMode(touchSensorPin, INPUT); 
		touchSensor_pinMode_check=true;
		Serial.println("It's pinMode ON");
	}
	
	if(digitalRead(touchSensorPin) == 1)// 터치가 눌렸을 때
	{
		Serial.println("It's TouchSensor ON");
	}
	else
	{
		Serial.println("It's TouchSensor OFF");
	}
}
	
// dc모터 on/off
void DCMotor::dcmotorStart()
{
	if(!dcmotor_pinMode_check){
		pinMode(dcmotorPin, OUTPUT); 
		dcmotor_pinMode_check=true;
		Serial.println("It's pinMode ON");
	}
	
	digitalWrite(dcmotorPin, HIGH); // 모터 on
	delay(1000);
	digitalWrite(dcmotorPin, LOW); // 모터 off
	delay(1000);
}