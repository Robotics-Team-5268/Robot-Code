#pragma once

#include "WPILib.h"
#include <string>

class Robot;

class AutonomousAction {
public:
	/*static std::string AANames[] = {
		"Move",
		"Rotate",
		"Lift"
	};*/

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
