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

	//Left: left joystick on controller, Right: right stick
	Joystick stickLeft;
	Joystick stickRight;

	//Talon controllers for the drive system
	//0: left front, 1: right front, 2: left back, 3: right back
	Talon driveControllerZero;
	Talon driveControllerOne;
	Talon driveControllerTwo;
	Talon driveControllerThree;

	//Lifter 1 or 2 motors
	Talon liftMotor;

	//Grabey Wheels
	Talon grabWheels;

	//Autonomous
	Autonomous autonomous;

	//Encoders
	Encoder LiftEnc;
	Encoder test1;//Rename your mom

	virtual void RobotInit();
	virtual void AutonomousInit();
	virtual void AutonomousPeriodic();
	virtual void TeleopInit();
	virtual void TeleopPeriodic();
	virtual void TestPeriodic();

	//Create drive system
	DriveSystem* drive;
};
