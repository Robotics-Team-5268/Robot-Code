#include "GrabArm.h"
#include "RobotParameters.h"
#include "Robot.h"

GrabArm::GrabArm(float GrabArmCurrent):
State(STAYING_PUT),
Current(GrabArmCurrent)
{

}

bool GrabArm::operator()(Robot& robot)
{
	if(State == STAYING_PUT)
	{
		if(robot.GrabArm_PDP.GetCurrent(GRABARM_POWER_DISTRIBUTION_CHANNEL) < Current)
		{
			State = GOING_UP; //move up code
			robot.GrabArmController.Set(.75);
		}
		else
		{
		    State = GOING_DOWN;//move down code
		    robot.GrabArmController.Set(-.75);
		}
	}
	else if (State == GOING_UP)
	{
		if(robot.GrabArm_PDP.GetCurrent(GRABARM_POWER_DISTRIBUTION_CHANNEL) >= Current)
		{
			robot.GrabArmController.Set(0);
			State = STAYING_PUT;
			return true;
		}
	}
	else if (State == GOING_DOWN)
	{
		if(robot.GrabArm_PDP.GetCurrent(GRABARM_POWER_DISTRIBUTION_CHANNEL) <= Current)
		{
			robot.GrabArmController.Set(0);
			State = STAYING_PUT;
			return true;
		}
	}
	return false;
}

void GrabArm::start()
{

}

void GrabArm::stop()
{

}

void GrabArm::printValues(){
	SmartDashboard::PutString("GrabArm.State", State == GOING_UP ? "Going Up" : State == GOING_DOWN ? "Going Down" : "Staying Put");
}
