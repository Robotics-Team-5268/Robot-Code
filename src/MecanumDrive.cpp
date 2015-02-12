#include "MecanumDrive.h"
#include "Autonomous.h"
#include "RobotParameters.h"

MecanumDrive::MecanumDrive(Robot &robotRef):
robot(robotRef),
drive(robot.driveControllerZero, robot.driveControllerOne, robot.driveControllerTwo, robot.driveControllerThree)
{
	drive.SetSafetyEnabled(false);
	drive.SetExpiration(0.1);
	drive.SetInvertedMotor(RobotDrive::MotorType::kFrontRightMotor, false);
	drive.SetInvertedMotor(RobotDrive::MotorType::kFrontLeftMotor, false);
	drive.SetInvertedMotor(RobotDrive::MotorType::kRearRightMotor, true);
	drive.SetInvertedMotor(RobotDrive::MotorType::kRearLeftMotor, true);
}

MecanumDrive::~MecanumDrive(){
}

void MecanumDrive::DrivingCode() {
	float rotateAmnt = robot.stick.GetRawAxis(RIGHT_TRIGGER) + (robot.stick.GetRawAxis(LEFT_TRIGGER) * -1);

	drive.MecanumDrive_Cartesian(robot.stick.GetX(), robot.stick.GetY(), rotateAmnt, robot.gyro.GetAngle());
}

void MecanumDrive::rotate(float pidOutput) {
  drive.MecanumDrive_Cartesian(0, 0, pidOutput, robot.gyro.GetAngle());
}
void MecanumDrive::move(float pidOutput)
{
	drive.MecanumDrive_Cartesian(0, pidOutput, 0, robot.gyro.GetAngle());
}
