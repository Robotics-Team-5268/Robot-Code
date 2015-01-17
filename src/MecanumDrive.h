#ifndef MECANUM_DRIVE_H
#define MECANUM_DRIVE_H

#include "WPILib.h"
#include "Robot.h"
#include "DriveSystem.h"

class MecanumDrive: DriveSystem {
public:
   explicit MecanumDrive(Robot &);
   virtual void TeleopPeriodic();
private:
   RobotDrive drive;
   Robot &robot;
};

#endif
