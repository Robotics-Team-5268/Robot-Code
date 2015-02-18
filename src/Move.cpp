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
	x_accel = (robot.acclrmtr.GetX() - robot.accel_offset_x) * GRAVITY;
	//y_accel = (robot.acclrmtr.GetY() - robot.accel_offset_y) * GRAVITY;

	// Velocity is the change in position per second
	x_vel = last_x_vel + x_accel * AUTONOMOUS_PERIOD;
	//y_vel = last_y_vel + y_accel * AUTONOMOUS_PERIOD;


	x = last_x + x_vel * AUTONOMOUS_PERIOD;
	//y = last_y + y_vel * AUTONOMOUS_PERIOD;

	robot.autonomous.moveIn.SetValue(x);
	finished = fabs(move - x) < .01;

	counter++;
    if(counter == 10)
    {
	    printValues();
	    SmartDashboard::PutNumber("PIDOutput", robot.autonomous.moveOut.GetValue());
	    SmartDashboard::PutNumber("AccelX", robot.acclrmtr.GetX());
	    //SmartDashboard::PutNumber("AccelY", robot.acclrmtr.GetY());
	    counter = 0;
    }

    if(finished){
    	robot.drive->move(0);
    	stop(robot);
    }else{
    	float value = scaleValue(robot.autonomous.moveOut.GetValue());
    	robot.drive->move(value);
    }

    copyValues();

	return finished;
}

void Move::start(Robot& robot){
	started = true;

	zero();

	robot.autonomous.PIDmove.SetSetpoint(move);
	robot.autonomous.moveIn.SetValue(0.0);
	robot.autonomous.PIDmove.Enable();
}

void Move::stop(Robot& robot){
	started = false;

	zero();

	robot.autonomous.PIDmove.Reset(); //Disables the PID
}

void Move::copyValues(){
	last_x_accel = x_accel;
	//last_y_accel = y_accel;
	last_x_vel = x_vel;
	//last_y_vel = y_vel;
	last_x = x;
	//last_y = y;
}

void Move::zero(){
	last_x_accel = 0;
	//last_y_accel = 0;
	last_x_vel = 0;
	//last_y_vel = 0;
	last_x = 0;
	//last_y = 0;
	x_accel = 0;
	//y_accel = 0;
	x_vel = 0;
	//y_vel = 0;
	x = 0;
	//y = 0;
}

void Move::printValues(){
	SmartDashboard::PutNumber("Move.X.Acceleration", x_accel);
	SmartDashboard::PutNumber("Move.X.Velocity", x_vel);
	SmartDashboard::PutNumber("Move.X.Position", x);
	//SmartDashboard::PutNumber("Move.Y.Acceleration", y_accel);
	//SmartDashboard::PutNumber("Move.Y.Velocity", y_vel);
	//SmartDashboard::PutNumber("Move.Y.Position", y);
}

double Move::scaleValue(double pidOut){
	double out = pidOut / fabs(move);

	if(out < -1){
		out = -1;
	}

	if(out > 1){
		out = 1;
	}

	return out;
}
