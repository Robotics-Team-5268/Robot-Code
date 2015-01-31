#pragma once

#include "AutonomousAction.h"
#include "Autonomous.h"
#include "Robot.h"

class Rotate : public AutonomousAction {
public:

	Rotate(float degrees);
	virtual ~Rotate();
    virtual bool operator()(Robot& robot);
    void start();
    void stop();
};
