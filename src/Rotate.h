#pragma once

#include "AutonomousAction.h"

class Rotate: public AutonomousAction {
public:
	Rotate(float degreesToTurn);
	virtual ~Rotate(){}
	virtual bool operator()(Robot& robot);
	void start();
	void stop();
	void printValues();
	float getAngle(Robot& robot);//obtain angle for movement

private:
	float degrees;//The amount of distance between the wanted direction and the actual direction
	float finalAngle;//Difference -possible link to degrees
};
