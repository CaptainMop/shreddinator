// 
// 
// 

#include "joyStick.h"

joystick::joystick(int PowerPin, int VRXpin, int VRYpin, int SWpin) : powerPin(PowerPin), vrxPin(VRXpin), vryPin(VRYpin), swPin(SWpin) {

	pinMode(powerPin, OUTPUT);
	pinMode(swPin, INPUT);
	digitalWrite(powerPin, HIGH);
}

int joystick::createAnalogWriteValue(int readPin) {
	int readValue = analogRead(readPin);
	readValue = map(readValue, 0, 1023, 0, 255);
	return readValue;
}