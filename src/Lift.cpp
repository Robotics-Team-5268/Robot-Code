#include "Lift.h"
#include "RobotParameters.h"
#include "Robot.h"

Lift::Lift(State s, int ltime):
state(s),
LiftTime(ltime),
counter(0)
{

}


bool Lift::operator()(Robot& robot)
{
	if(state == GOING_UP)
	{
		if(robot.liftHighLimit.Get() || counter == LiftTime)
		{
			robot.liftController_A.Set(0);
			robot.liftController_B.Set(0);
			return true;

		}
		else
		{
			robot.liftController_A.Set(LIFT_UP_SPEED);
			robot.liftController_B.Set(LIFT_UP_SPEED);
		}
	}
	else if(state == GOING_DOWN)
	{
		if(robot.liftLowLimit.Get() || counter == LiftTime)
		{
			robot.liftController_A.Set(0);
			robot.liftController_B.Set(0);
			return true;
		}
		else
		{
			robot.liftController_A.Set(LIFT_DOWN_SPEED);
			robot.liftController_B.Set(LIFT_DOWN_SPEED);
		}
	}
	counter++;
	return false;

}

void Lift::start()
{

}

void Lift::stop()
{

}

void Lift::printValues(){
	//SmartDashboard::PutString("Lift.State", State == GOING_UP ? "Going Up" : State == GOING_DOWN ? "Going Down" : "Staying Put");
}


