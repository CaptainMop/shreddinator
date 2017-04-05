// 
// 
// 

#include "MotorDriver.h"


Motor::Motor(int PWMPin, int forwardPin, int backwardsPin) : PWMPin(PWMPin), DirForwardPin(forwardPin), DirBackwardPin(backwardsPin) {
	maxPWMValue = maxAnalogWriteValue * 0.9;
	minPWMValue = maxAnalogWriteValue * 0.1;
	PWMStopTreshold = maxAnalogWriteValue * 0.05;
	PWMStopValue = maxAnalogWriteValue / 2;
	pinMode(DirForwardPin, OUTPUT);
	pinMode(DirBackwardPin, OUTPUT);
}

void Motor::setMotorGain(int analogWriteValue){
	if (analogWriteValue > (PWMStopValue + PWMStopTreshold)) {
		setMotorDir(forward);

		if (analogWriteValue > maxPWMValue) {
			analogWrite(PWMPin, maxPWMValue);
		}
		else {
			analogWrite(PWMPin, analogWriteValue);
		}
	
	}
	else if (analogWriteValue < (PWMStopValue - PWMStopTreshold)) {
		setMotorDir(backwards);

		if (analogWriteValue < minPWMValue) {
			analogWrite(PWMPin, maxAnalogWriteValue - minPWMValue);
		}
		else {
			analogWrite(PWMPin, maxAnalogWriteValue - analogWriteValue);
		}
	}
	else {
		setMotorDir(stop);
	}
}

void Motor::setMotorDir(int dir){
	if (dir == forward) {
		digitalWrite(DirForwardPin, HIGH);
		digitalWrite(DirBackwardPin, LOW);
	}
	if (dir == backwards) {
		digitalWrite(DirForwardPin, LOW);
		digitalWrite(DirBackwardPin, HIGH);
	}
	if (dir == stop) {
		digitalWrite(DirForwardPin, LOW);
		digitalWrite(DirBackwardPin, LOW);
	}
}

float getYawValueLeft(int analogReadValueX) {
	if (analogReadValueX < maxAnalogWriteValue / 2 - maxAnalogWriteValue * 0.05) {
		float yawValueLeft = 1 - ( maxAnalogWriteValue - analogReadValueX) / maxAnalogWriteValue;
		return yawValueLeft;
	}
	else return 1;
}

float getYawValueRight(int analogReadValueX) {
	if (analogReadValueX > maxAnalogWriteValue / 2 + maxAnalogWriteValue * 0.05) {
		float yawValueRight = 1 - analogReadValueX / maxAnalogWriteValue;
	}
	else return 1;
}


void conntrolSpeed(Motor &motorRight, Motor &motorLeft, int analogReadValueY, int analogReadValueX) {
	motorRight.setMotorGain(analogReadValueY * getYawValueRight(analogReadValueX));
	motorLeft.setMotorGain(analogReadValueY * getYawValueLeft(analogReadValueX));
}