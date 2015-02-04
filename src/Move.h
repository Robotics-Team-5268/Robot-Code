#pragma once

#include "AutonomousAction.h"

<<<<<<< HEAD
class Move: public AutonomousAction {
public:
	Move(float moveAmount);
	virtual ~Move(){}
	virtual bool operator()(Robot& robot);
	void start();
	void stop();
private:
	float move;
=======


class Move : public AutonomousAction {

    virtual bool operator()(Robot&);

>>>>>>> branch 'master' of https://github.com/Robotics-Team-5268/Robot-Code.git
};
