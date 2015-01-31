#pragma once


#include "WPILib.h"
#include "RobotBase.h"
#include "DriveSystem.h"
#include <PIDController.h>
#include "RobotParameters.h"
#include "AutonomousAction.h"
#include "SmartDashBoard\Smartdashboard.h"
//Want to keep track of time and distance


class Robot;


class Autonomous {
   //TODO SOMEBODY BETTER FIGURE OUT WHAT THIS IS AND COMMENT IT!!!!!!!!!
   int autoPeriodicLoops;
   Robot& robot;

public:
   Autonomous(Robot&);
   void autonomousReset(void);
   void autonomousPeriodic(void);

   	   class AutoPIDOut : public PIDOutput {
	   public:
	   	   float GetValue()
	   	   {
	   		   return value;
	   	   }
	   	   void PIDWrite(float num)
	   	   {
	   		   value = num;
	   	   }
   	   private:
	   	   float value;
   	   };
   	   AutoPIDOut gyroOut;
private:


   //PIDOutput output;
   PIDController PIDgyro;


   bool trackDist();
   bool rotate(float degree);


   double xDist;
   double yDist;
   double hypDist;

   //AutonomousAction actions[9];
};

