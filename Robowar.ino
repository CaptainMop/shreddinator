
/*
 Name:		Robowar.ino
 Created:	4/3/2017 1:03:48 PM
 Author:	Henrik
*/
#include "MotorDriver.h"
#include "joyStick.h"

//joystick
#define POWERPin 12
#define VRXPin 0
#define VRYPin 2
#define SWPin 11

//Right motor
#define PWMPinLeft 5
#define fowardPinLeft 7
#define backwardsPinLeft 8

//Left motor
#define PWMPinRight 6
#define fowardPinRight 9
#define backwardsPinRight 10

joystick joy(POWERPin, VRXPin, VRYPin, SWPin);
Motor motorRight(PWMPinRight, fowardPinRight, backwardsPinRight);
Motor motorLeft(PWMPinLeft, fowardPinLeft, backwardsPinLeft);
// the setup function runs once when you press reset or power the board
void setup() {
	Serial.begin(9600);
}

// the loop function runs over and over again until power down or reset
void loop() {
	conntrolSpeed(motorRight, motorLeft, joy.createAnalogWriteValueY(), joy.createAnalogWriteValueX());
}
