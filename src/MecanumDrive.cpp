#include "MecanumDrive.h"
#include "Autonomous.h"
#include "RobotParameters.h"

MecanumDrive::MecanumDrive(Robot &robotRef):
robot(robotRef),
drive(robot.driveControllerZero, robot.driveControllerOne, robot.driveControllerTwo, robot.driveControllerThree)
{
	drive.SetSafetyEnabled(false);
	drive.SetExpiration(0.1);
	drive.SetInvertedMotor(RobotDrive::MotorType::kFrontRightMotor, true);
	drive.SetInvertedMotor(RobotDrive::MotorType::kFrontLeftMotor, false);
	drive.SetInvertedMotor(RobotDrive::MotorType::kRearRightMotor, true);
	drive.SetInvertedMotor(RobotDrive::MotorType::kRearLeftMotor, false);
}

MecanumDrive::~MecanumDrive(){
}

void MecanumDrive::DrivingCode() {
	float rotateAmnt = (robot.stick.GetRawAxis(RIGHT_TRIGGER) - robot.stick.GetRawAxis(LEFT_TRIGGER)) * ROTATE_SCALE_FACTOR;
	float x = robot.stick.GetRawAxis(LEFT_JOYSTICK_X_AXIS);
	float y = robot.stick.GetRawAxis(LEFT_JOYSTICK_Y_AXIS);

	float slow_x = robot.stick.GetRawAxis(RIGHT_JOYSTICK_X_AXIS);
	float slow_y = robot.stick.GetRawAxis(RIGHT_JOYSTICK_Y_AXIS);

	if(fabs(x) < JOYSTICK_AXIS_THRESHOLD){
		x = 0;
	}

	if(fabs(y) < JOYSTICK_AXIS_THRESHOLD){
		y = 0;
	}

	if(fabs(slow_x) < JOYSTICK_AXIS_THRESHOLD){
		slow_x = 0;
	}

	if(fabs(slow_y) < JOYSTICK_AXIS_THRESHOLD){
		slow_y = 0;
	}

	x *= DRIVE_FAST_SCALE_FACTOR;
	y *= DRIVE_FAST_SCALE_FACTOR;

	slow_x *= DRIVE_SLOW_SCALE_FACTOR;
	slow_y *= DRIVE_SLOW_SCALE_FACTOR;

	drive.MecanumDrive_Cartesian(x + slow_x, y + slow_y, rotateAmnt /*robot.gyro.GetAngle()*/);
}

void MecanumDrive::rotate(float pidOutput) {
  drive.MecanumDrive_Cartesian(0, 0, pidOutput);
}
void MecanumDrive::move(float pidOutput)
{
	drive.MecanumDrive_Cartesian(0, pidOutput, 0);
}
