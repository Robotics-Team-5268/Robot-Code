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
			robot.liftController_A.Set(.2);
			robot.liftController_B.Set(-.2);
		}
		else
		{
		    State = GOING_DOWN;//move down code
		    robot.liftController_A.Set(-.2);
		    robot.liftController_B.Set(.2);
		}
	}
	else if (State == GOING_UP)
	{
		if(potentiometer.Get() >= distance)
		{
			robot.liftController_A.Set(0);
			robot.liftController_B.Set(0);
			State = STAYING_PUT;
			return true;
		}
	}
	else if (State == GOING_DOWN)
	{
		if(potentiometer.Get() <= distance)
		{
			robot.liftController_A.Set(0);
			robot.liftController_B.Set(0);
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

void Lift::printValues(){
	SmartDashboard::PutString("Lift.State", State == GOING_UP ? "Going Up" : State == GOING_DOWN ? "Going Down" : "Staying Put");
}


