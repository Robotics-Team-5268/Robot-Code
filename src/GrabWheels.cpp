/********************************************************************************
 *          GrabWheel takes 2 arguments: SameDirection and SpinTime.            *
 *          When SameDirection is 1, if the Spin Time is less than 0,           *
 *     The direction of the motors will turn left. If positive, the motors      *
 *   will turn right. The counter increments each period and when counter is    *
 *              equal to Time the operation is finished.		-Team 5268		*
 ********************************************************************************/
#include "GrabWheels.h"
#include "RobotParameters.h"
GrabWheel::GrabWheel(bool SameDirection, float SpinTime):
		GrabController_A(GRAB_WHEEL_CONTROLLER_A),
		GrabController_B(GRAB_WHEEL_CONTROLLER_B),
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
			GrabController_A.Set(.75);
			GrabController_B.Set(-.75);
			break;
		case STATIONARY:
			GrabController_A.Set(0);
			GrabController_B.Set(0);
			break;
		case ROTATING:
			if(Time > 0)
			{
				GrabController_A.Set(-.75);
				GrabController_B.Set(-.75);
			}
			else
			{
				GrabController_A.Set(.75);
				GrabController_B.Set(.75);
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
