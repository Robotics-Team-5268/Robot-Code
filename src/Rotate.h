#pragma once

#include "AutonomousAction.h"
#include "Autonomous.h"

class Rotate: public AutonomousAction{
public:

	Rotate(float degrees);
	virtual ~Rotate();
    virtual bool operator()(Robot&);
    void start();
    void stop();
};
