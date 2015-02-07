#pragma once

#include "WPILib.h"
#include "RobotBase.h"
#include "RobotParameters.h"
#include "SmartDashBoard\Smartdashboard.h"


#define GYRO_CHANNEL 0
#define L_STICK_CHANNEL 0
#define R_STICK_CHANNEL 1

//0: Left front, 1: Right front, 2: Left back, 3: Right back
#define DRIVE_CONTROLLER_0_CHANNEL 0
#define DRIVE_CONTROLLER_1_CHANNEL 1
#define DRIVE_CONTROLLER_2_CHANNEL 2
#define DRIVE_CONTROLLER_3_CHANNEL 3
//Encoders-------------------------------
#define ENCODER_0_A_CHANNEL 8
#define ENCODER_0_B_CHANNEL 9

//Motor Controls
#define LIFT_MOTOR_CHANNEL 4

#define LIFT_CONST .0278
#define LIFT_ENCODER_A_CHANNEL 5
#define LIFT_ENCODER_B_CHANNEL 6

//Grabey Arms
#define GRAB_ARMS 7
#define GRAB_ARMS_SPEED .3

#define ENCODER_ARM_A_CHANNEL 16//Arm Lift Encoder
#define ENCODER_ARM_B_CHANNEL 17//Arm Lift Encoder
//-----------------------------------------

#define GRAVITY 9.81 //  m / (s^2)
#define AUTONOMOUS_PERIOD 1/50  // 50 times a second

/*
#define GATE_BUTTON 5 //LB top trigger
#define GATE_SOLENOID_ONE 8
#define GATE_SOLENOID_TWO 6
#define SHOOTER_BUTTON 6 //RB top trigger
#define SHOOTER_SOLENOID 2
#define ArmUpAxes 3
#define ArmDownAxes 3
#define DriveAxesUpDown 2
#define DriveAxesLeftRight 1
#define PistonButton 1
#define ARM_1_MOTOR_CHANNEL 3
#define ARM_1_HI_SWITCH 13
#define ARM_1_LO_SWITCH 14
#define SCOOPER_UP_BUTTON 2
#define SCOOPER_DOWN_BUTTON 3
#define SCOOPER_STAY_UP 4
#define SCOOPER_STAY_DOWN 1
#define COMP_LIMIT_SWITCH	6		// compressor stuff
#define COMP_RELAY_CHANNEL	7		// more compressor stuff
#define ULTRASONIC_INPUT_CHANNEL 2
#define TOGGLE_DRIVE_BUTTON 8
#define FORWARD_LIGHT_SOL 3
#define BACK_LIGHT_SOL 4
#define GYRO_CHANNEL 1

TODO organize and comment way better for this years stuff
*/
