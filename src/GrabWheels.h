#pragma once

#include "RobotParameters.h"
#include "SpeedController.h"
#include "AutonomousAction.h"

class GrabWheel: public AutonomousAction
{

	public:

		GrabWheel(bool SameDirection, float SpinTime);
		enum
		{
			GRABBING,
			STATIONARY,
			ROTATING
		}State;
		float setMSPerPeriod(float MSPerPeriod)
		{
			if(MSPerPeriod > 0)
			{
				PeriodsPerSecond = 1000 / MSPerPeriod;
				return PeriodsPerSecond;
			}
			else
			{
			return 0;
			}
		}
		virtual bool operator()(Robot& robot);
		virtual ~GrabWheel(){}
		void start();
		void stop();
	private:
		float counter;
		float Time;
		float PeriodsPerSecond;
		bool SD;
};
