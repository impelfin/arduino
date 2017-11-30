#ifndef Arducation_h
#define Arducation_h

#include "Arduino.h"

class Flex
{
  public:
    Flex(int pin);
    void flexStart();
  private:
    int flexPin;
};

class Blink
{
  public:
    Blink(int pin);   
    void blinkStart();
  private:
    int blinkPin;
};

class LightSensor
{
  public:
    LightSensor(int pin);  
    void lightSensorStart();
  private:
    int lightPin;
};

class Pressure
{
  public:
    Pressure(int pin);
    void pressureStart();
  private:
    int pressurePin;
};

class Delay
{
  public:
    Delay(long delay);
    void delayStart();
  private:
  	long delay_time;
};

class UltrasonicWave
{
	public:
		UltrasonicWave(int in_pin,int out_pin);
		void ultrasonicWaveStart();
	private:
		int ultrasonicWave_in_pin;
		int ultrasonicWave_out_pin;	
};

class Piezo
{
	public:
		Piezo(int pin,int sound);
		void piezoStart();
	private:
		int piezoPin;
		int _sound;
};

class ReedSensor
{
	public:
		ReedSensor(int pin);
		void reedSensorStart();
	private:
		int reedsensorPin;
};

class Potentiometer
{
	public:
		Potentiometer(int pin);
		void potentiometerStart();
	private:
		int potentiometerPin;
};

class Infrared
{
	public:
		Infrared(int pin);
		void infraredStart();
	private:
		int infraredPin;
};

class TactSwitch
{
	public:
		TactSwitch(int pin);
		void tactSwitchStart();
	private:
		int tactSwitchPin;
};

class DipSwitch
{
	public:
		DipSwitch(int pin);
		void dipSwitchStart();
	private:
		int dipSwitchPin;
};

class VibrationSensor
{
	public:
		VibrationSensor(int pin);
		void vibrationSensorStart();
	private:
		int vibrationSensorPin;
};

class TemperatureSensor
{
	public:
		TemperatureSensor(int pin);
		void temperatureSensorStart();
	private:
		int temperatureSensorPin;
};

class TouchSensor
{
	public:
		TouchSensor(int pin);
		void touchSensorStart();
	private:
		int touchSensorPin;
};

class DCMotor
{
	public:
		DCMotor(int pin);
		void dcmotorStart();
	private:
		int dcmotorPin;
};
#endif