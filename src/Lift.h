#pragma once
#include "RobotParameters.h"
#include "AutonomousAction.h"


class Lift: public AutonomousAction
{
public:
	enum
	{
		GOING_UP,
		GOING_DOWN,
		STAYING_PUT
	} State;

	AnalogPotentiometer potentiometer;

	Lift(float liftDistance);
	virtual ~Lift(){}
	virtual bool operator()(Robot& robot);
	void start();
	void stop();
	//encoder.SetDistancePerPulse(LIFT_CONST);

private:
	float distance;

};
