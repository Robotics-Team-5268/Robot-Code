#pragma once

#include "WPILib.h"
#include "RobotBase.h"
#include "DriveSystem.h"
#include <PIDController.h>
#include "RobotParameters.h"
#include "SmartDashBoard\Smartdashboard.h"
#include "Autonomous.h"

class Robot;

class AutonomousAction {
public:
	virtual ~AutonomousAction(){}
    virtual bool operator()(Robot&) = 0;
};
