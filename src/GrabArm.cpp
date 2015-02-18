#include "GrabArm.h"
#include "RobotParameters.h"
#include "Robot.h"

GrabArm::GrabArm(float itime):
State(STAYING_PUT),
InputTime(itime)
{

}

bool GrabArm::operator()(Robot& robot)
{
	if(State == STAYING_PUT)
	{
		if(robot.GrabArmIn.Get())
		{
			State = GOING_IN; //move up code
			robot.GrabArmController.Set(-.2);
		}

	}
	else if (State == GOING_IN)
	{
		if(!robot.GrabArmIn.Get())
		{
			robot.GrabArmController.Set(0);
			if(counter == InputTime)
			{
			State = GOING_OUT;
			robot.GrabArmController.Set(-.2);
			}
			else
			{
				counter++;
			}
		}
	}
	else if (State == GOING_OUT)
	{
		if(robot.GrabArmOut.Get())
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
	SmartDashboard::PutString("GrabArm.State", State == GOING_IN ? "Going In" : State == GOING_OUT ? "Going Out" : "Staying Put");
}

