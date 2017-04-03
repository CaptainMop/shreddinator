// joyStick.h

#ifndef _JOYSTICK_h
#define _JOYSTICK_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif


#endif

class joystick {
private:
	int powerPin;
	int vrxPin;
	int vryPin;
	int swPin;
	int createAnalogWriteValue(int readPin);
public:
	int getPowerpin() { return powerPin; }
	joystick(int PowerPin, int VRXpin, int VRYpin, int SWpin);
	bool readSW() { return !digitalRead(swPin); };
	int createAnalogWriteValueX() {return createAnalogWriteValue(vrxPin); }
	int createAnalogWriteValueY() {return createAnalogWriteValue(vryPin); }
};
