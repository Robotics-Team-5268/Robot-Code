#pragma once

#include "AutonomousAction.h"
#include "RobotParameters.h"

class Move: public AutonomousAction {
public:
	Move(float moveAmount);
	virtual ~Move(){}
	virtual bool operator()(Robot& robot);
	void start();
	void stop();
private:
	float move;
	bool started;

	double x_offset, y_offset;
	double x_accel, y_accel;
	double x_vel, y_vel;
	double x, y;

	int counter;	// Counter to stop from updating
					// Smart dashboard every time the
					// operator() function is called
};
