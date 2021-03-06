#pragma once
#include "RobotParameters.h"
#include "AutonomousAction.h"
#include "PowerDistributionPanel.h"

class GrabArm: public AutonomousAction
{
public:
	enum
	{
		GOING_IN,
		GOING_OUT,
		STAYING_PUT
	} State;

	GrabArm(float itime);
	virtual ~GrabArm(){}
	virtual bool operator()(Robot& robot);
	void start();
	void stop();
	void printValues();
	//encoder.SetCurrentPerPulse(LIFT_CONST);
	int counter = 0;
private:
	float InputTime;

};
