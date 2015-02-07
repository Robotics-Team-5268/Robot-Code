#pragma once


#include "AutonomousAction.h"

class UltraSonic : public AutonomousAction
{
	public:
		double getDistance(Robot &);//Get the distance

		float range;

	private:
		const float SCALE_VALUE = (4.88/5); //~1 Volt per meter
};
