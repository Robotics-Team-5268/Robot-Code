#include "Rotate.h"
#include "RobotParameters.h"

Rotate::Rotate(float degreesToTurn):
	degrees(degreesToTurn)
{

}

bool Rotate::operator()(Robot& robot){
	return true;
}

void Rotate::start(){

}

void Rotate::stop(){

}
