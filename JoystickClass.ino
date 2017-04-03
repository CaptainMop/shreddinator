/*
 Name:		JoystickClass.ino
 Created:	1/22/2017 3:59:43 PM
 Author:	hakon
*/
#include "MotorDriver.h"
#include "joyStick.h"
joystick joy(2, 2, 0, 3);
Motor motorRight(6,9,10);
Motor motorLeft(5,7,8);

// the setup function runs once when you press reset or power the board
void setup() {
}

// the loop function runs over and over again until power down or reset
void loop() {
	conntrolSpeed(motorRight,motorLeft, joy.createAnalogWriteValueY(), joy.createAnalogWriteValueX());
	/*// debug:

	// slutt debug*/
}
