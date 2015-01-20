#include "MecanumDrive.h"

   MecanumDrive::MecanumDrive(Robot &robotRef):
   robot(robotRef), drive(robot.driveControllerZero, robot.driveControllerOne, robot.driveControllerTwo, robot.driveControllerThree)
   {
   }

   void MecanumDrive::DrivingCode() {
      drive.MecanumDrive_Cartesian(robot.stickLeft.GetX(), robot.stickLeft.GetY(), robot.stickRight.GetX(), robot.gyro.GetAngle());
   }
