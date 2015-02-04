#include "Autonomous.h"
#include "Robot.h"

Autonomous::Autonomous(Robot &robotRef):
autoPeriodicLoops(0),
robot(robotRef),
moveOut(),
//PIDmove(0.1, 0.001, 0.0, , &moveOut),
gyroOut(),
PIDgyro(0.1, 0.001, 0.0, &robot.gyro, &gyroOut), //possibly need to change the numbers
xDist(0),
yDist(0),
hypDist(0)
//actions({Rotate(0.0)})
{
   PIDgyro.SetOutputRange(-1.0, 1.0);
}

void Autonomous::autonomousPeriodic(void) {

}

void Autonomous::autonomousReset(void) {
   autoPeriodicLoops = 0;
}

bool Autonomous::rotate(float degree) {
   //robot.drive.rotate(degree);

   return PIDgyro.OnTarget();
}

bool Autonomous::move(float distance) {
	//robot.drive.move(distance);

	return false;
}

/*
bool Autonomous::trackDist() {
	return false;
}
*/


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
