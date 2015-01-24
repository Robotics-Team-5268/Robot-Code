#pragma once

#include "RobotBase.h"
#include "WPILib.h"
#include "Encoder.h"
#include "RobotParameters.h"
#include "SmartDashBoard\Smartdashboard.h"
#include "Autonomous.h"

class Robot: public IterativeRobot {
public:
   Robot();

   Gyro gyro;

   Joystick stickLeft;
   Joystick stickRight;
   //Left: left joystick on controller, Right: right stick

   //Talon controllers for the drive system
   Talon driveControllerZero;
   Talon driveControllerOne;
   Talon driveControllerTwo;
   Talon driveControllerThree;
   //0: left front, 1: right front, 2: left back, 3: right back

   //Encoders
   Encoder test1; //RENAME VARIABLE!!!!

   virtual void RobotInit();
   virtual void AutonomousInit();
   virtual void AutonomousPeriodic();
   virtual void TeleopInit();
   virtual void TeleopPeriodic();
   virtual void TestPeriodic();

   //Create drive system
   DriveSystem* drive;
};
