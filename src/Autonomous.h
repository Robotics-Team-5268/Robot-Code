#pragma once


#include "WPILib.h"
#include "RobotBase.h"
#include "DriveSystem.h"
#include <PIDController.h>
#include "RobotParameters.h"
#include "AutonomousAction.h"
#include "SmartDashBoard\Smartdashboard.h"
//Want to keep track of time and distance

class Robot;

class Autonomous {
private:
	//How many times the periodic periodic has been called
	int autoPeriodicLoops;
	//What step are we through the array of commands
	unsigned int commandCounter;
	Robot& robot;

public:
    Autonomous(Robot&);
    void autonomousReset(void);
    void autonomousPeriodic(void);

    class AutoPIDOut : public PIDOutput {
    public:
	    float GetValue()
	   	{
	    	return value;
	   	}
	   	void PIDWrite(float num)
	   	{
	   		value = num;
	   	}
   	private:
	   	float value;
   	};


    AutoPIDOut gyroOut;
	PIDController PIDgyro;

private:

	double xDist;
	double yDist;
	double hypDist;

    //PIDOutput output;

    // PIDController PIDmove;

	AutonomousAction* actions[4];

};

