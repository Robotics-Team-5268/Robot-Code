#include "ArcadeDrive.h"

   ArcadeDrive::ArcadeDrive(Robot &robotRef)
   : robot(robotRef), drive(robot.driveControllerZero, robot.driveControllerOne, robot.driveControllerTwo, robot.driveControllerThree)
   {
      drive.SetInvertedMotor(RobotDrive::kFrontLeftMotor, true);
      drive.SetInvertedMotor(RobotDrive::kFrontRightMotor, false);
      drive.SetInvertedMotor(RobotDrive::kRearLeftMotor, true);
      drive.SetInvertedMotor(RobotDrive::kRearRightMotor, false);
   }

   void ArcadeDrive::TeleopPeriodic() {
      drive.ArcadeDrive(((robot.stickLeft.GetY()*4)/4), -((robot.stickLeft.GetX()*3)/4), false);
   }
