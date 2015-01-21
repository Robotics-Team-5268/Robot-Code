#include "Robot.h"
#include "MecanumDrive.h"
#include "ArcadeDrive.h"

//TODO: see README.md
Robot::Robot():
gyro(GYRO_CHANNEL),
stickLeft(L_STICK_CHANNEL),
stickRight(R_STICK_CHANNEL),
driveControllerZero(DRIVE_CONTROLLER_0_CHANNEL),
driveControllerOne(DRIVE_CONTROLLER_1_CHANNEL),
driveControllerTwo(DRIVE_CONTROLLER_2_CHANNEL),
driveControllerThree(DRIVE_CONTROLLER_3_CHANNEL) //replace any numbers with channel from RobotParameters
{
   drive = new MecanumDrive(this); //Uses left joystick to move forward/backwards and left/right, and uses right stick to rotate/turn left/right
   //drive = new ArcadeDrive(this); //Uses left joystick to move forwards/backwards and rotate/turn left/right

   this->SetPeriod(0); 	//Set update period to sync with robot control packets (20ms nominal)
}

void Robot::RobotInit() {
}

void Robot::AutonomousInit() {
   gyro.Reset();
}

void Robot::AutonomousPeriodic() {
}

void Robot::TeleopInit() {
   gyro.Reset();
}

void Robot::TeleopPeriodic() {
   drive->DrivingCode();
}

void Robot::TestPeriodic() {
}

START_ROBOT_CLASS(Robot);
