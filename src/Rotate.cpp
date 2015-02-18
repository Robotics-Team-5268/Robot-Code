#include "Rotate.h"
#include "RobotParameters.h"
#include "Robot.h"
#include "DriveSystem.h"

Rotate::Rotate(float degreesToTurn):
	degrees(degreesToTurn)
	//finalAngle()
{

}

float Rotate::getAngle(Robot& robot)
{
	return robot.gyro.GetAngle() + degrees;//Return the difference

}

bool Rotate::operator()(Robot& robot){

	//check if PID is enabled
	/*if (robot.autonomous.PIDgyro.IsEnabled())//checks if PIDgyro is on
	{
		robot.drive->rotate(robot.autonomous.gyroOut.GetValue() / 360);//obtain actual angle
		if(robot.autonomous.PIDgyro.OnTarget())//checks if PID is finished and if so, disables PIDgyro
		{
			robot.autonomous.PIDgyro.Disable();//turns off PIDgyro
			return true;
		}

	}
	else {
		robot.autonomous.PIDgyro.SetSetpoint(getAngle(robot));//find the desired angle
		robot.autonomous.PIDgyro.Enable();//turn on PIDgyro
	}

	return false; //handle return
	*/

	float difference = degrees - robot.gyro.GetAngle();
	if(fabs(difference) < 5){
		robot.drive->rotate(0);
		return true;
	}
	float val = difference / 180.0;

	if(val < .2){
		val = .2;
	}

	robot.drive->rotate(val);
	return false;
}


void Rotate::stop(){
	//put nothing inside
	//delete later
}

void Rotate::printValues(){

}
