#pragma once

#include "AutonomousAction.h"

class Rotate: public AutonomousAction {
public:
	Rotate(float degreesToTurn);
	virtual ~Rotate(){}
	virtual bool operator()(Robot& robot);
	float getAngle(Robot& robot);
	void start();
	void stop();
	void printValues();
private:
	float degrees;
	float finalAngle;
};
