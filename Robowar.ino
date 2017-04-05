
/*
 Name:		Robowar.ino
 Created:	4/3/2017 1:03:48 PM
 Author:	Henrik
*/
#include "MotorDriver.h"
#include "joyStick.h"

//joystickRight
#define POWERPinRight 3
#define VRXPinRight 1
#define VRYPinRight 2
#define SWPinRight 13

//joystickLeft
#define POWERPinLeft 4
#define VRXPinLeft 1
#define VRYPinLeft 0
#define SWPinLeft 13

//Right motor
#define PWMPinLeft 5
#define fowardPinLeft 7
#define backwardsPinLeft 8

//Left motor
#define PWMPinRight 6
#define fowardPinRight 9
#define backwardsPinRight 10

joystick joyLeft(POWERPinLeft, VRXPinLeft, VRYPinLeft, SWPinLeft);
joystick joyRight(POWERPinRight, VRXPinRight, VRYPinRight, SWPinRight);
Motor motorRight(PWMPinRight, fowardPinRight, backwardsPinRight);
Motor motorLeft(PWMPinLeft, fowardPinLeft, backwardsPinLeft);
// the setup function runs once when you press reset or power the board
void setup() {
	Serial.begin(9600);
}

// the loop function runs over and over again until power down or reset
void loop() {
	motorLeft.setMotorGain(joyLeft.createAnalogWriteValueY());
	motorRight.setMotorGain(joyRight.createAnalogWriteValueY());
}
