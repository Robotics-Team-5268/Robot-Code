#pragma once

#include "AutonomousAction.h"

class Move: public AutonomousAction {
public:
	Move(float moveAmount);
	virtual ~Move(){}
	virtual bool operator()(Robot& robot);
	void start();
	void stop();
private:
	float move;
};
