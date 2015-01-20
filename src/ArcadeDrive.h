#pragma once

#include "WPILib.h"
#include "Robot.h"
#include "DriveSystem.h"

class ArcadeDrive: DriveSystem {
public:
   explicit ArcadeDrive(Robot &);
   virtual void DrivingCode();
private:
   RobotDrive drive;
   Robot &robot;
};