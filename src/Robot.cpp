#include "Robot.h"
#include "MecanumDrive.h"
#include "ArcadeDrive.h"
#include "DriveSystem.h"

static const std::string strgyro("GYRO_CHANNEL");
bool AorM;//1 (true) Arcade and 0 (false) Mecanum

//TODO: see README.md
Robot::Robot():
gyro(GYRO_CHANNEL),
acclrmtr(BuiltInAccelerometer::Range::kRange_8G),
stickLeft(L_STICK_CHANNEL),
stickRight(R_STICK_CHANNEL),
driveControllerZero(DRIVE_CONTROLLER_0_CHANNEL),
driveControllerOne(DRIVE_CONTROLLER_1_CHANNEL),
driveControllerTwo(DRIVE_CONTROLLER_2_CHANNEL),
driveControllerThree(DRIVE_CONTROLLER_3_CHANNEL),//replace any numbers with channel from RobotParameters
liftMotor(LIFT_CHANNEL_MOTOR),
grabWheels(GRAB_ARMS),
LiftEnc(LIFT_ENCODER_A_CHANNEL, LIFT_ENCODER_B_CHANNEL, true, Encoder::k4X),
test1(ENCODER_0_A_CHANNEL, ENCODER_0_B_CHANNEL, false, Encoder::k4X), //RENAME VARIABLE!!!!
x_offset(0),
y_offset(0),
x(0),
y(0),
x_vel(0),
y_vel(0),
x_accel(0),
y_accel(0),
counter(0)
{
	drive = new MecanumDrive(*this); //Uses left joystick to move forward/backwards and left/right, and uses right stick to rotate/turn left/right
   //drive = new ArcadeDrive(this); //Uses left joystick to move forwards/backwards and rotate/turn left/right

   //this->SetPeriod(0); 	//Set update period to sync with robot control packets (20ms nominal)

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
   SmartDashboard::PutNumber("Encoder 08", test1.GetRate());

   SmartDashboard::PutData(strgyro, &gyro);

   	   x_accel = acclrmtr.GetX() + x_offset;
       y_accel = acclrmtr.GetY() + y_offset;
       x_vel += x_accel;
       y_vel += y_accel;
       x += x_vel;
       y += y_vel;
       counter++;
       ; //counter += 1 or counter = counter + 1 would work as well
       if(counter == 50)
       {
           SmartDashboard::PutNumber("x", x);
           SmartDashboard::PutNumber("y", y);
           SmartDashboard::PutNumber("x_vel", x_vel);
           SmartDashboard::PutNumber("y_vel", y_vel);
           SmartDashboard::PutNumber("x_accel", x_accel);
           SmartDashboard::PutNumber("y_accel", y_accel);
           counter = 0;
       }

}

void Robot::TestPeriodic() {
}

START_ROBOT_CLASS(Robot);
