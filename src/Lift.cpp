#include "Lift.h"
#include "RobotParameters.h"
#include "Robot.h"

Lift::Lift(float liftDistance):
State(STAYING_PUT),
encoder(LIFT_ENCODER_A_CHANNEL, LIFT_ENCODER_B_CHANNEL, true, Encoder::k4X),
distance(liftDistance)

	{
		encoder.SetDistancePerPulse(LIFT_CONST);
	}


bool Lift::operator()(Robot& robot)
{
	if(State == STAYING_PUT)
	{
		if(encoder.GetDistance() < distance)
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
		if(encoder.GetDistance() >= distance)
		{
			robot.liftController.Set(0);
			State = STAYING_PUT;
		}
	}
	else if (State == GOING_DOWN)
	{
		if(encoder.GetDistance() <= distance)
		{
			robot.liftController.Set(0);
			State = STAYING_PUT;
		}
	}

	return true;
}

void Lift::start()
{

}

void Lift::stop()
{

}




