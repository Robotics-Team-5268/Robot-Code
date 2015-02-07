#pragma once

#include "WPILib.h"

class Robot;

class AutonomousAction {
public:
	virtual ~AutonomousAction() {
	}
	virtual bool operator()(Robot&) = 0;
	virtual void printValues(){}

	enum AATypes {
		MOVE,
		ROTATE,
		LIFT
	};
};
