#pragma once

#include "RobotParameters.h"
#include "Robot.h"
#include "SpeedController.h"
#include "RobotParameters.h"

class GrabMotors
{

	public:
		Talon speed;

	 GrabMotors::GrabMotors():
		speed(GRAB_ARMS_SPEED)
	 {
		 speed.Set(GRAB_ARMS_SPEED);
	 }




};
