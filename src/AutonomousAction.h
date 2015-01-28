#pragma once

#include "WPILib.h"
#include "RobotBase.h"
#include "DriveSystem.h"
#include <PIDController.h>
#include "RobotParameters.h"
#include "SmartDashBoard\Smartdashboard.h"

class AutonomousAction {
   virtual bool operator()() = 0;
};
