#include "Rotate.h"
#include "RobotParameters.h"
#include "Robot.h"

Rotate::Rotate(float degreesToTurn):
	degrees(degreesToTurn),
	finalAngle()
{

}

float Rotate::getAngle(Robot& robot)
{
	return robot.gyro.GetAngle() - degrees;

}

bool Rotate::operator()(Robot& robot){

	//check if PID is enabled
	if (robot.autonomous.PIDgyro.IsEnabled())
	{
		robot.drive->rotate(robot.autonomous.gyroOut.GetValue());
		if(robot.autonomous.PIDgyro.OnTarget())
		{
			robot.autonomous.PIDgyro.Disable();
			return true;
		}

	}
	else{
		robot.autonomous.PIDgyro.SetSetpoint(getAngle(robot));
		robot.autonomous.PIDgyro.Enable();
	}

	return true; //handle return
}

void Rotate::start(){
	//put nothing inside
	//delete later
}

void Rotate::stop(){
	//put nothing inside
	//delete later
}

void Rotate::printValues(){

}
