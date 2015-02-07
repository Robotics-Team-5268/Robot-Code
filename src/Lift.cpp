#include "Lift.h"
#include "RobotParameters.h"
#include "Robot.h"

Lift::Lift(float liftDistance):
State(STAYING_PUT),
potentiometer(LIFT_POTENTIOMETER_CHANNEL, 48),
distance(liftDistance)
{

}


bool Lift::operator()(Robot& robot)
{
	if(State == STAYING_PUT)
	{
		if(potentiometer.Get() < distance)
		{
			State = GOING_UP; //move up code
			robot.liftController.Set(.75);
		}
		else
		{
		    State = GOING_DOWN;//move down code
		    robot.liftController.Set(-.75);
		}
	}
	else if (State == GOING_UP)
	{
		if(potentiometer.Get() >= distance)
		{
			robot.liftController.Set(0);
			State = STAYING_PUT;
			return true;
		}
	}
	else if (State == GOING_DOWN)
	{
		if(potentiometer.Get() <= distance)
		{
			robot.liftController.Set(0);
			State = STAYING_PUT;
			return true;
		}
	}
	return false;
}

void Lift::start()
{

}

void Lift::stop()
{

}




