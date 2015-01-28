#pragma once

#include "WPILib.h"
#include "RobotBase.h"
#include "DriveSystem.h"
#include <PIDController.h>
#include "RobotParameters.h"
#include "SmartDashBoard\Smartdashboard.h"

class Autonomous {
   //TODO SOMEBODY BETTER FIGURE OUT WHAT THIS IS AND COMMENT IT!!!!!!!!!
   int autoPeriodicLoops;

public:
   Autonomous(Robot &);
   void autonomousReset(void);
   void autonomousPeriodic(void);
private:
   PIDOutput output;
   PIDController PIDgyro;

   bool trackDist();
   bool rotate(int degree);

   double xDist;
   double yDist;
   double hypDist;
};
