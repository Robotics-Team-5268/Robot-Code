#pragma once
#include "RobotParameters.h"
#include "AutonomousAction.h"


class GrabArm: public AutonomousAction
{
public:
	enum
	{
		GOING_UP,
		GOING_DOWN,
		STAYING_PUT
	} State;

	AnalogPotentiometer potentiometer;

	GrabArm(float GrabArmDistance);
	virtual ~GrabArm(){}
	virtual bool operator()(Robot& robot);
	void start();
	void stop();
	void printValues();
	//encoder.SetDistancePerPulse(LIFT_CONST);

private:
	float distance;

};
