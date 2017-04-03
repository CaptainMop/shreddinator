// MotorDriver.h

#ifndef _MOTORDRIVER_h
#define _MOTORDRIVER_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif


#endif

#define forward 1
#define backwards -1
#define stop 0
#define maxAnalogWriteValue 255

class Motor {
private:
	int PWMPin;
	int DirForwardPin;
	int DirBackwardPin;
	int PWMStopValue;
	int PWMStopTreshold;
	int maxPWMValue;
	int minPWMValue;
	void setMotorDir(int dir);

public:
	Motor(int PWMPin, int forwardPin, int backwardsPin);
	void setMotorGain(int analogWriteValue);
};


float getYawValueLeft(int analogReadValueY);
float getYawValueRight(int analogReadValueY);

void conntrolSpeed(Motor &motorRight, Motor &motorLeft, int analogReadValueY, int analogReadValueX);