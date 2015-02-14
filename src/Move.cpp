#include "Move.h"
#include "Robot.h"
#include <math.h>

Move::Move(float moveAmount):
	move(moveAmount),
	started(false),
	last_x_accel(0.0),
	last_y_accel(0.0),
	last_x_vel(0.0),
	last_y_vel(0.0),
	last_x(0.0),
	last_y(0.0),
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
		start(robot);
	}

	bool finished = false;

	// Acceleration is the change in velocity per second
	// Acceleration = G_Fore * Gravity
	// Scale the acceleration to handle being called every AUTONOMOUS_PERIOD of a second
	x_accel = (robot.acclrmtr.GetX() - robot.accel_offset_x) * GRAVITY * AUTONOMOUS_PERIOD;
	y_accel = (robot.acclrmtr.GetY() - robot.accel_offset_y) * GRAVITY * AUTONOMOUS_PERIOD;

	// Velocity is the change in position per second
	x_vel = last_x_vel + ((last_x_accel + x_accel) / 2) * AUTONOMOUS_PERIOD;
	y_vel = last_y_vel + ((last_y_accel + y_accel) / 2) * AUTONOMOUS_PERIOD;


	x = last_x + last_x_vel * AUTONOMOUS_PERIOD + .5 * last_x_accel * AUTONOMOUS_PERIOD * AUTONOMOUS_PERIOD;
	y = last_y + last_y_vel * AUTONOMOUS_PERIOD + .5 * last_y_accel * AUTONOMOUS_PERIOD * AUTONOMOUS_PERIOD;

	robot.autonomous.moveIn.SetValue(sqrt(x * x + y * y));
	finished = robot.autonomous.PIDmove.OnTarget();

	counter++;
    if(counter == 10)
    {
	    printValues();
	    SmartDashboard::PutNumber("AccelX", robot.acclrmtr.GetX());
	    SmartDashboard::PutNumber("AccelY", robot.acclrmtr.GetY());
	    counter = 0;
    }

    if(finished){
    	robot.drive->move(0);
    	stop(robot);
    }else{
    	float value = robot.autonomous.moveOut.GetValue();
    	value *= move > 0 ? 1 : -1;
    	robot.drive->move(value);
    }

    copyValues();

	return finished;
}

void Move::start(Robot& robot){
	started = true;

	zero();

	robot.autonomous.PIDmove.SetSetpoint(abs(move));
	robot.autonomous.PIDmove.Enable();
}

void Move::stop(Robot& robot){
	started = false;

	zero();

	robot.autonomous.PIDmove.Reset(); //Disables the PID
}

void Move::copyValues(){
	last_x_accel = x_accel;
	last_y_accel = y_accel;
	last_x_vel = x_vel;
	last_y_vel = y_vel;
	last_x = x;
	last_y = y;
}

void Move::zero(){
	last_x_accel = 0;
	last_y_accel = 0;
	last_x_vel = 0;
	last_y_vel = 0;
	last_x = 0;
	last_y = 0;
	x_accel = 0;
	y_accel = 0;
	x_vel = 0;
	y_vel = 0;
	x = 0;
	y = 0;
}

void Move::printValues(){
	SmartDashboard::PutNumber("Move.X.Acceleration", x_accel);
	SmartDashboard::PutNumber("Move.X.Velocity", x_vel);
	SmartDashboard::PutNumber("Move.X.Position", x);
	SmartDashboard::PutNumber("Move.Y.Acceleration", y_accel);
	SmartDashboard::PutNumber("Move.Y.Velocity", y_vel);
	SmartDashboard::PutNumber("Move.Y.Position", y);
}
