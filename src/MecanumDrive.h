#pragma once

#include "WPILib.h"
#include "Robot.h"
#include "DriveSystem.h"

class MecanumDrive: public DriveSystem {
public:
   explicit MecanumDrive(Robot&);
   virtual ~MecanumDrive();
   virtual void DrivingCode();
   virtual void rotate(float pidOutput);
   virtual void move(float pidOutput);
private:
   Robot &robot;
   RobotDrive drive;
};
