#pragma once

#include "RobotBase.h"
#include "WPILib.h"
#include "Encoder.h"
#include "RobotParameters.h"
#include "Autonomous.h"
#include "BuiltInAccelerometer.h"
#include "PowerDistributionPanel.h"

class Robot: public IterativeRobot {
public:
	Robot();

	Gyro gyro;
	BuiltInAccelerometer acclrmtr;
	double accel_offset_x, accel_offset_y;

	//AnalogOutput ultrasonic;

	//Left: left joystick on controller, Right: right stick
	Joystick stick;

	//Talon controllers for the drive system
	//0: left front, 1: right front, 2: left back, 3: right back
	Talon driveControllerZero;
	Talon driveControllerOne;
	Talon driveControllerTwo;
	Talon driveControllerThree;

	//Lifter 1 or 2 motors
	Talon liftController_A;
	Talon liftController_B;
	DigitalInput liftHighLimit;
	DigitalInput liftLowLimit;

	//Grabey Wheels
	Victor GrabController_A;
	Victor GrabController_B;

	//Grabey Arms
	Victor GrabArmController;
	DigitalInput GrabArmIn;
	DigitalInput GrabArmOut;
	//AnalogPotentiometer potentiometer;


	//Autonomous
	Autonomous autonomous;

	//Power Distribution Panel
	PowerDistributionPanel GrabArm_PDP;

	virtual void RobotInit();
	virtual void AutonomousInit();
	virtual void AutonomousPeriodic();
	virtual void TeleopInit();
	virtual void TeleopPeriodic();
	virtual void TestInit();
	virtual void TestPeriodic();

	//Create drive system
	DriveSystem* drive;

	/********* TEST ONLY STUFF *********/
	AutonomousAction* currentAction;
	int counter;
	bool done;
	int GrabArmCounter;
	bool HitTheTop;      /* Hit the top and hit the bottom are checks so that if they hit the max on the counter, */
	bool HitTheBottom;   /* 		     They can still have the ability to go the other direction.				  */
	/***********************************/

};
