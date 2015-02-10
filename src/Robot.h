#pragma once

#include "RobotBase.h"
#include "WPILib.h"
#include "Encoder.h"
#include "RobotParameters.h"
#include "SmartDashBoard\Smartdashboard.h"
#include "Autonomous.h"
#include "BuiltInAccelerometer.h"

class Robot: public IterativeRobot {
public:
	Robot();

	Gyro gyro;
	BuiltInAccelerometer acclrmtr;

	AnalogOutput ultrasonic;

	//Left: left joystick on controller, Right: right stick
	Joystick stick;

	//Talon controllers for the drive system
	//0: left front, 1: right front, 2: left back, 3: right back
	Talon driveControllerZero;
	Talon driveControllerOne;
	Talon driveControllerTwo;
	Talon driveControllerThree;

	//Lifter 1 or 2 motors
	Talon liftController;

	//Grabey Wheels
	Talon GrabController_A;
	Talon GrabController_B;

	//Grabey Arms
	Talon GrabArmController;

	//Autonomous
	Autonomous autonomous;

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

	/***********************************/

};
