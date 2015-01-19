#include "Autonomous.h"

void Autonomous::autonomousPeriodic(void){
}

void Autonomous::autonomousReset(void) {
   autoPeriodicLoops = 0;
}

void Autonomous::autonomous(RobotDrive *robotdrive) {
   autoPeriodicLoops = 0;
}
