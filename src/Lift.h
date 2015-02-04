#pragma once
#include "Encoder.h"
#include "RobotParameters.h"



class LiftMotor
{
public:
	Encoder encoder;

	LiftMotor::LiftMotor():
		encoder(LIFT_ENCODER_A_CHANNEL, LIFT_ENCODER_B_CHANNEL, true, Encoder::k4X)
	{
		encoder.SetDistancePerPulse(LIFT_CONST);
	}



		//encoder.SetDistancePerPulse(LIFT_CONST);




};
