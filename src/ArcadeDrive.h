#pragma once

#include "WPILib.h"
#include "Robot.h"
#include "DriveSystem.h"

class ArcadeDrive: public DriveSystem {
public:
   explicit ArcadeDrive(Robot &);
   virtual ~ArcadeDrive();
   virtual void DrivingCode();
   virtual void rotate(float);
   virtual void move(float);
private:
   Robot &robot;
   RobotDrive drive;
};
