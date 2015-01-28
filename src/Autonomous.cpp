#include "Autonomous.h"

Autonomous::Autonomous(Robot &robotRef)
robot(robotRef),
drive(robot.driveControllerZero,
robot.driveControllerOne, robot.driveControllerTwo, robot.driveControllerThree),
output(),
PIDgyro(0.1, 0.001, 0.0, robot.gyro, output) //possibly need to change the numbers
{
   PIDgyro.SetOutputRange(-1.0, 1.0);
   PIDgyro.SetSetpoint(degree);
   PIDgyro.Enable();
}

void Autonomous::autonomousPeriodic(void) {

}

void Autonomous::autonomousReset(void) {
   autoPeriodicLoops = 0;
}

bool Autonomous::rotate(int degree) {
   robot.drive.rotate(&output);

   return PIDgyro.OnTarget();
}

bool Autonomous::trackDist() {

}


/*
States Execute[] = {
   rotate,
   move
};
void func(){
   for(int i = 0; i < (sizeof(Execute)/sizeof(Execute[0])); i++) {
      Execute[i];
   }
}

int i

void func2() {
   bool finish
   if(i >= 0 && i < (sizeof(Execute)/sizeof(Execute[0])))
      switch(Execute[i]) {
      case rotate:
         finish = rotate(180)
         break
      case move:
         finish = move(someamoiunt)
         break
      }
   if(finish){
      i++
   }
}*/
