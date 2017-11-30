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
// flex����, ���θ����� ����
void Flex::flexStart()
{

  int flexVal;

  flexVal = analogRead(flexPin); // �Ƴ��α� ��ȣ �б�
  Serial.print("sensor: ");
  Serial.println(flexVal); 
  delay(200);

}
// led, on/off���� ǥ��
void Blink::blinkStart()
{
	if(!blink_pinMode_check){
		pinMode(blinkPin, OUTPUT);
		blink_pinMode_check=true;
		Serial.println("It's pinMode ON");
	}
  digitalWrite(blinkPin, HIGH); // ������ ��ȣ ���
  Serial.println("It's ON");
  delay(1000);
  digitalWrite(blinkPin, LOW);
  Serial.println("It's OFF");
  delay(1000);  
}
// ��������, ������ ����
void LightSensor::lightSensorStart()
{

  int lightVal;
	
  lightVal = analogRead(lightPin);
  Serial.print("cds: ");
  Serial.println(lightVal);
  delay(200);

}
// �з¼���, �з°� ����
void Pressure::pressureStart()
{

  int pressureVal;
  float Rfsr;

  pressureVal = analogRead(pressurePin);
  Rfsr = ((9.78 * pressureVal)/(1-(pressureVal/1023.0)));  // �з� ����
  Serial.print("Rfsr: ");
  Serial.println(Rfsr);
  delay(200);

}
// �����ļ���, �Ÿ�����
void UltrasonicWave::ultrasonicWaveStart()
{
	int UltrasonicWaveVal;
	if(!ultrasonic_pinMode_check){
		pinMode(ultrasonicWave_out_pin, OUTPUT); // ���� Trig ��
		pinMode(ultrasonicWave_in_pin, INPUT); // ���� Echo ��
		ultrasonic_pinMode_check=true;
		Serial.println("It's pinMode ON");
	}
	
	digitalWrite(ultrasonicWave_out_pin,HIGH); // ������ Trig ��ȣ �Է�
  delayMicroseconds(10); // 10us ���� ����
  digitalWrite(ultrasonicWave_out_pin,LOW); // Trig ��ȣ off
  
  UltrasonicWaveVal = pulseIn(ultrasonicWave_in_pin,HIGH)/58; // cm�� ��ȯ
  
  Serial.print(UltrasonicWaveVal);
  Serial.print("cm");
  Serial.println();
}
// �ǿ��� ����Ŀ, �� ���� ��� ���
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
// ���弾��, �ڼ��� �Ÿ��� ���� ���� ǥ��
void ReedSensor::reedSensorStart()
{
	if(!reedsensor_pinMode_check){
		pinMode(reedsensorPin, INPUT); 
		reedsensor_pinMode_check=true;
		Serial.println("It's pinMode ON");
	}
	
	if(digitalRead(reedsensorPin) == 1)// �ڼ��� ������ ���� ��
  {
    Serial.println("It's ReedSensor ON");
  }
  else
  {
    Serial.println("It's ReedSensor OFF");
  }
}
// �������׼���, ����ġ ȸ���� ���� �� ���
void Potentiometer::potentiometerStart()
{
	int potentiometerVal;
	potentiometerVal = analogRead(potentiometerPin);
	Serial.println(potentiometerVal);
}
// ���ܼ�����, ���ع� ������ ���� ���� ǥ��
void Infrared::infraredStart()
{
	if(!infrared_pinMode_check){
		pinMode(infraredPin, INPUT); 
		infrared_pinMode_check=true;
		Serial.println("It's pinMode ON");
	}
	
	if(digitalRead(infraredPin) == 0)// ���ع��� ���� ��
	{
		Serial.println("It's Infrared ON");
	}
	else
	{
		Serial.println("It's Infrared OFF");
	}
}

// ��Ʈ����ġ, ����ġ on/off���� ǥ��
void TactSwitch::tactSwitchStart()
{
	if(!tactSwitch_pinMode_check){
		pinMode(tactSwitchPin, INPUT); 
		tactSwitch_pinMode_check=true;
		Serial.println("It's pinMode ON");
	}
	
	if(digitalRead(tactSwitchPin) == 1)// ����ġ�� ������ ��
	{
		Serial.println("It's TactSwitch ON");
	}
	else
	{
		Serial.println("It's TactSwitch OFF");
	}
}

// ������ġ, ����ġ on/off���� ǥ��
void DipSwitch::dipSwitchStart()
{
	if(!dipSwitch_pinMode_check){
		pinMode(dipSwitchPin, INPUT); 
		dipSwitch_pinMode_check=true;
		Serial.println("It's pinMode ON");
	}
	
	if(digitalRead(dipSwitchPin) == 1)// ����ġ�� ������ ��
	{
		Serial.println("It's DipSwitch ON");
	}
	else
	{
		Serial.println("It's DipSwitch OFF");
	}
}

// ��������, 1�ʰ������� ����
void VibrationSensor::vibrationSensorStart()
{
	if(!vibrationSensor_pinMode_check){
		pinMode(vibrationSensorPin, OUTPUT); 
		vibrationSensor_pinMode_check=true;
		Serial.println("It's pinMode ON");
	}
	
	digitalWrite(vibrationSensorPin,HIGH);// ���� on
	delay(1000);
	digitalWrite(vibrationSensorPin,LOW);// ���� off
	delay(1000);
}

// �µ�����, ����,ȭ���µ� ǥ��
void TemperatureSensor::temperatureSensorStart()
{
	int tempReading = analogRead(temperatureSensorPin);
  float tempVolts = tempReading * 5.0 / 1024.0; // 0~5V�� ���� ���ϱ� ���� 5�� ���Ѵ�
  float tempC = (tempVolts - 0.5) * 100.0; //����
  float tempF = tempC * 9.0 / 5.0 + 32.0;  //ȭ��
  
  Serial.println(tempC);
  Serial.println(tempF);
}

//��ġ����, ��ġ ���� ǥ��
void TouchSensor::touchSensorStart()
{
	if(!touchSensor_pinMode_check){
		pinMode(touchSensorPin, INPUT); 
		touchSensor_pinMode_check=true;
		Serial.println("It's pinMode ON");
	}
	
	if(digitalRead(touchSensorPin) == 1)// ��ġ�� ������ ��
	{
		Serial.println("It's TouchSensor ON");
	}
	else
	{
		Serial.println("It's TouchSensor OFF");
	}
}
	
// dc���� on/off
void DCMotor::dcmotorStart()
{
	if(!dcmotor_pinMode_check){
		pinMode(dcmotorPin, OUTPUT); 
		dcmotor_pinMode_check=true;
		Serial.println("It's pinMode ON");
	}
	
	digitalWrite(dcmotorPin, HIGH); // ���� on
	delay(1000);
	digitalWrite(dcmotorPin, LOW); // ���� off
	delay(1000);
}