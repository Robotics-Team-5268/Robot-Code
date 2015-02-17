#pragma once
#include "RobotParameters.h"
#include "AutonomousAction.h"
#include "PowerDistributionPanel.h"

class GrabArm: public AutonomousAction
{
public:
	enum
	{
		GOING_UP,
		GOING_DOWN,
		STAYING_PUT
	} State;

	GrabArm(bool UpOrDown);
	virtual ~GrabArm(){}
	virtual bool operator()(Robot& robot);
	void start();
	void stop();
	void printValues();
	//encoder.SetCurrentPerPulse(LIFT_CONST);

private:

};
