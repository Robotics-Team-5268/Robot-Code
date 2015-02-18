#pragma once
#include "RobotParameters.h"
#include "AutonomousAction.h"


class Lift: public AutonomousAction
{
public:
	enum State
	{
		GOING_UP,
		GOING_DOWN
	};

	Lift(State s, int ltime);
	virtual ~Lift(){}
	virtual bool operator()(Robot& robot);
	void start();
	void stop();
	void printValues();
	//encoder.SetDistancePerPulse(LIFT_CONST);

private:
	State state;
	float LiftTime;
	float counter;

};
