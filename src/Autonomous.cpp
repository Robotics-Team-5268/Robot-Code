#include "Autonomous.h"

Autonomous::Autonomous(Robot &robotRef)
robot(robotRef),

{

}

void Autonomous::autonomousPeriodic(void){
   //acceleration
   a = sqrt(pow(accel.GetX(), 2) + pow(accel.GetY(), 2));
   totalDistance += (1/2) * a * pow(20, 2);

   
}

void Autonomous::autonomousReset(void) {
   autoPeriodicLoops = 0;
}
