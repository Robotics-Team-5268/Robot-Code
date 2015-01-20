#include "Robot.h"

static const string a("ENCODER_0_A_CHANNEL");

//TODO: see README.md
Robot::Robot():
gyro(GYRO_CHANNEL),
stickLeft(L_STICK_CHANNEL),
stickRight(R_STICK_CHANNEL),
driveControllerZero(DRIVE_CONTROLLER_0_CHANNEL),
driveControllerOne(DRIVE_CONTROLLER_1_CHANNEL),
driveControllerTwo(DRIVE_CONTROLLER_2_CHANNEL),
driveControllerThree(DRIVE_CONTROLLER_3_CHANNEL),
test1(ENCODER_0_A_CHANNEL,ENCODER_0_B_CHANNEL)
//replace any numbers with channel from RobotParameters
{
}

void Robot::RobotInit() {
	SmartDashboard::PutData( a, &test1);
}

void Robot::AutonomousInit() {
}

void Robot::AutonomousPeriodic() {
}

void Robot::TeleopInit() {
}

void Robot::TeleopPeriodic() {
}

void Robot::TestPeriodic() {
}

START_ROBOT_CLASS(Robot);
