#pragma once

#include "WPILib.h"
#include "Robot.h"
#include "DriveSystem.h"

class Robot;

class MecanumDrive: DriveSystem {
public:
   explicit MecanumDrive(Robot&);
   virtual void DrivingCode();
   virtual void rotate(float pidOutput);
private:
   RobotDrive drive;
   Robot &robot;
};
