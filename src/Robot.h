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
	Joystick stickLeft;
	Joystick stickRight;
	//Left: left joystick on controller, Right: right stick

	//Talon controllers for the drive system
	Talon driveControllerZero;
	Talon driveControllerOne;
	Talon driveControllerTwo;
	Talon driveControllerThree;

	//0: left front, 1: right front, 2: left back, 3: right back

	//Lifter 1 or 2 motors
	Talon liftMotor;

	//Encoders
	Encoder test1; //RENAME VARIABLE!!!!

	//Grabey Wheels
	Talon grabWheels;

	//Autonomous
	Autonomous autonomous;

	//Create drive system
	DriveSystem* drive;

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
	double x_offset, y_offset;
	double x, y;
	double x_vel, y_vel;
	double x_accel, y_accel;
	int counter;
};
