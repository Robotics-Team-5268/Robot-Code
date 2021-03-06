#include "ArcadeDrive.h"

ArcadeDrive::ArcadeDrive(Robot &robotRef):
robot(robotRef),
drive(robot.driveControllerZero, robot.driveControllerOne, robot.driveControllerTwo, robot.driveControllerThree)
{
    drive.SetInvertedMotor(RobotDrive::kFrontLeftMotor, true);
    drive.SetInvertedMotor(RobotDrive::kFrontRightMotor, false);
    drive.SetInvertedMotor(RobotDrive::kRearLeftMotor, true);
    drive.SetInvertedMotor(RobotDrive::kRearRightMotor, false);
}

ArcadeDrive::~ArcadeDrive(){
}

void ArcadeDrive::DrivingCode() {
    drive.ArcadeDrive(((robot.stick.GetY()*4)/4), -((robot.stick.GetX()*3)/4), false);
}

void ArcadeDrive::rotate(float pidOutput) {
    drive.ArcadeDrive(0, pidOutput, true);
}

void ArcadeDrive::move(float pidOutput){
	drive.ArcadeDrive(pidOutput, 0, true);
}
