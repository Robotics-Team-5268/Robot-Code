#pragma once

#include "AutonomousAction.h"

class Rotate: public AutonomousAction {
public:
	Rotate(float degreesToTurn);
	virtual ~Rotate(){}
	virtual bool operator()(Robot& robot);
	void start();
	void stop();
private:
	float degrees;
};
