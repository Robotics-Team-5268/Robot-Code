#include "MecanumDrive.h"
#include "Autonomous.h"

   MecanumDrive::MecanumDrive(Robot &robotRef):
   robot(robotRef),
   drive(robot.driveControllerZero, robot.driveControllerOne, robot.driveControllerTwo, robot.driveControllerThree)
   {
   }

   void MecanumDrive::DrivingCode() {
      drive.MecanumDrive_Cartesian(robot.stickLeft.GetX(), robot.stickLeft.GetY(), robot.stickRight.GetX(), robot.gyro.GetAngle());
   }

   void MecanumDrive::rotate(float pidOutput) {
      drive.MecanumDrive_Cartesian(0, 0, pidOutput, robot.gyro.GetAngle());
   }
