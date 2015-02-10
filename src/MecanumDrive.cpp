#include "MecanumDrive.h"
#include "Autonomous.h"
#include "RobotParameters.h"

MecanumDrive::MecanumDrive(Robot &robotRef):
robot(robotRef),
drive(robot.driveControllerZero, robot.driveControllerOne, robot.driveControllerTwo, robot.driveControllerThree)
{
	drive.SetInvertedMotor(RobotDrive::MotorType::kFrontRightMotor, true);
	drive.SetInvertedMotor(RobotDrive::MotorType::kFrontLeftMotor, false);
	drive.SetInvertedMotor(RobotDrive::MotorType::kRearRightMotor, true);
	drive.SetInvertedMotor(RobotDrive::MotorType::kRearLeftMotor, false);
}

MecanumDrive::~MecanumDrive(){
}

void MecanumDrive::DrivingCode() {
	float rotateAmnt = robot.stick.GetAxis(RIGHT_TRIGGER) + (robot.stick.GetAxis(LEFT_TRIGGER) * -1);
  drive.MecanumDrive_Cartesian(robot.stick.GetX(), robot.stick.GetY(), rotateAmnt, robot.gyro.GetAngle());
}

void MecanumDrive::rotate(float pidOutput) {
  drive.MecanumDrive_Cartesian(0, 0, pidOutput, robot.gyro.GetAngle());
}
void MecanumDrive::move(float pidOutput)
{
	drive.MecanumDrive_Cartesian(0, pidOutput, 0, robot.gyro.GetAngle());
}
