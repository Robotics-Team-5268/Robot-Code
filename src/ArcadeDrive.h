#ifndef ARCADE_DRIVE_H
#define ARCADE_DRIVE_H

#include "WPILib.h"
#include "Robot.h"
#include "DriveSystem.h"

class ArcadeDrive: DriveSystem {
public:
   explicit ArcadeDrive(Robot &);
   virtual void TeleopPeriodic();
private:
   RobotDrive drive;
   Robot &robot;
};

#endif
