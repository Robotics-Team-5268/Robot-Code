#include "Move.h"
#include "Robot.h"

Move::Move(float moveAmount):
	move(moveAmount),
	started(false),
	x_offset(0.0),
	y_offset(0.0),
	x_accel(0.0),
	y_accel(0.0),
	x_vel(0.0),
	y_vel(0.0),
	x(0.0),
	y(0.0),
	counter(0)
{

}

bool Move::operator()(Robot& robot) {
	if(!started){
		start();
	}

	bool finished = false;

	// Acceleration is the change in velocity per second
	// Acceleration = G_Fore * Gravity
	// Scale the acceleration to handle being called every AUTONOMOUS_PERIOD of a second
	x_accel = robot.acclrmtr.GetX() * GRAVITY * AUTONOMOUS_PERIOD;
	y_accel = robot.acclrmtr.GetY() * GRAVITY * AUTONOMOUS_PERIOD;

	// Velocity is the change in position per second
	x_vel += x_accel;
	y_vel += y_accel;


	x += x_vel;
	y += y_vel;

	//NEED TO HANDLE MOTORS!!!!

	counter++;
    if(counter == 50)
    {
	    SmartDashboard::PutNumber("x", x);
	    SmartDashboard::PutNumber("y", y);
	    SmartDashboard::PutNumber("x_vel", x_vel);
	    SmartDashboard::PutNumber("y_vel", y_vel);
	    SmartDashboard::PutNumber("x_accel", x_accel);
	    SmartDashboard::PutNumber("y_accel", y_accel);
	    counter = 0;
    }

	return finished;
}

void Move::start(){
	started = true;
}

void Move::stop(){
	started = false;
}
