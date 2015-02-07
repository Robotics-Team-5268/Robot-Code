#pragma once

#include "AutonomousAction.h"
#include "RobotParameters.h"

class Move: public AutonomousAction {
public:
	Move(float moveAmount);
	virtual ~Move(){}
	virtual bool operator()(Robot& robot);
	void start(Robot& robot);
	void stop(Robot& robot);
	void copyValues();
	void printValues();

private:
	float move;
	bool started;

	double last_x_accel, last_y_accel;
	double last_x_vel, last_y_vel;
	double last_x, last_y;

	double x_accel, y_accel;
	double x_vel, y_vel;
	double x, y;

	int counter;	// Counter to stop from updating
					// Smart dashboard every time the
					// operator() function is called
};
