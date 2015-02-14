/********************************************************************************
 *          GrabWheel takes 2 arguments: SameDirection and SpinTime.            *
 *          When SameDirection is 1, if the Spin Time is less than 0,           *
 *     The direction of the motors will turn left. If positive, the motors      *
 *   will turn right. The counter increments each period and when counter is    *
 *              equal to Time the operation is finished.		-Team 5268		*
 ********************************************************************************/
#include "GrabWheels.h"
#include "RobotParameters.h"
#include "Robot.h"

GrabWheel::GrabWheel(bool SameDirection, float SpinTime):
		State(STATIONARY),
		counter(0),
		Time(SpinTime),
		SD(SameDirection)
		{
			Time *= setMSPerPeriod(MS_PER_PERIOD);
		}
bool GrabWheel::operator()(Robot& robot)
{
	if(counter == 0)
	{
		if(SD == 1)
		{
			State = ROTATING;
		}
		else if(Time > 0)
		{
			State = GRABBING;
		}
		else
		{
			State = STATIONARY;
		}

		switch(State)
		{
		case GRABBING:
			robot.GrabController_A.Set(.75);
			robot.GrabController_B.Set(-.75);
			break;
		case STATIONARY:
			robot.GrabController_A.Set(0);
			robot.GrabController_B.Set(0);
			break;
		case ROTATING:
			if(Time > 0)
			{
				robot.GrabController_A.Set(-.75);
				robot.GrabController_B.Set(-.75);
			}
			else
			{
				robot.GrabController_A.Set(.75);
				robot.GrabController_B.Set(.75);
			}
			break;
		}

	}
	counter++;
	if(counter >= Time)
	{
		return true;
	}
	else
	{
		return false;
	}
}
void GrabWheel::start()
{

}

void GrabWheel::stop()
{

}
