#include "Autonomous.h"
#include "Robot.h"
#include "Rotate.h"
#include "Move.h"
#include "Lift.h"

Autonomous::Autonomous(Robot &robotRef) :
	autoPeriodicLoops(0),
	commandCounter(0),
	robot(robotRef),
	//Gyro
	gyroOut(),
	PIDgyro(0.1, 0.001, 0.0, &robot.gyro, &gyroOut), //possibly need to change the numbers
	xDist(0),
	yDist(0),
	hypDist(0),
	actions
	{
		new Lift(10.0),
		new Rotate(0.0),
		new Rotate(0.0),
		new Move(0.0)
	}

{
	PIDgyro.SetOutputRange(-1.0, 1.0);
}

void Autonomous::autonomousPeriodic(void)
{
	autoPeriodicLoops++;
	if(commandCounter >= 0 && commandCounter < (sizeof(actions)/sizeof(actions[0])))
	{
		bool finished = (*actions[commandCounter])(robot);
		if(finished)
		{
			commandCounter++;
		}
	}
}

void Autonomous::autonomousReset(void)
{
	autoPeriodicLoops = 0;
	commandCounter = 0;
}
