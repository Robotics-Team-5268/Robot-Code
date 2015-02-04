#include "Move.h"

Move::Move(float moveAmount):
	move(moveAmount)
{

}

bool Move::operator()(Robot&) {
	return true;
}

void Move::start(){

}

void Move::stop(){

}
