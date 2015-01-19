#pragma once

#include "WPILib.h"
#include "RobotBase.h"
#include "DriveSystem.h"
#include "RobotParameters.h"
#include "SmartDashBoard\Smartdashboard.h"

class Autonomous {
  //TODO SOMEBODY BETTER FIGURE OUT WHAT THIS IS AND COMMENT IT!!!!!!!!!
  unsigned int autoPeriodicLoops;
  const float Kp = 0.03;

  public:
    Autonomous();

    void autonomousReset(void);

    void autonomousPeriodic(void);
};
