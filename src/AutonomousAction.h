#pragma once

#include "WPILib.h"
#include "RobotBase.h"
#include "DriveSystem.h"
#include <PIDController.h>
#include "RobotParameters.h"
#include "SmartDashBoard\Smartdashboard.h"
#include "Autonomous.h"
#include "Rotate.h"

class AutonomousAction {
	AutonomousAction();
	virtual ~AutonomousAction();
    virtual bool operator()(Robot&) = 0;
};
