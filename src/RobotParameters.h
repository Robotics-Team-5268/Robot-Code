#pragma once

#include "WPILib.h"
#include "RobotBase.h"
#include "RobotParameters.h"


#define GYRO_CHANNEL 0
#define JOYSTICK_CHANNEL 0
#define JOYSTICK_AXIS_THRESHOLD .05
#define JOYSTICK_DEBUG false
//Buttons
#define GRAB_ARM_BUTTON_IN 4
#define GRAB_WHEEL_BUTTON_IN 1
#define GRAB_WHEEL_BUTTON_OUT 2
#define GRAB_ARM_BUTTON_OUT 3
#define LIFT_BUTTON_DOWN 5
#define LIFT_BUTTON_UP 6

#define LIFT_POTENTIOMETER_CHANNEL 1

//0: Left front, 1: Left Back, 2: Right Front , 3: Right Back
#define DRIVE_CONTROLLER_0_CHANNEL 1
#define DRIVE_CONTROLLER_1_CHANNEL 2
#define DRIVE_CONTROLLER_2_CHANNEL 3
#define DRIVE_CONTROLLER_3_CHANNEL 4

#define ROTATE_SCALE_FACTOR .5

//Motor Controls
#define LIFT_MOTOR_CHANNEL_A 5
#define LIFT_MOTOR_CHANNEL_B 8
#define LIFT_HIGH_LIMIT_CHANNEL 0
#define LIFT_LOW_LIMIT_CHANNEL 1
#define LIFT_UP_SPEED -.5
#define LIFT_DOWN_SPEED .3

#define LIFT_CONST .0278
//#define LIFT_ENCODER_A_CHANNEL 5
//#define LIFT_ENCODER_B_CHANNEL 6

//Grabey Arms
//#define GRAB_ARM_POTENTIOMETER_CHANNEL 7
#define GRAB_ARM_POTENTIOMETER_RANGE 4
#define GRAB_ARM_SPEED .75
#define GRAB_ARM_CHANNEL 6
#define GRAB_ARM_LIMIT_SWITCH_IN_CHANNEL 2
#define GRAB_ARM_LIMIT_SWITCH_OUT_CHANNEL 3

//Grabey Wheels
#define GRAB_WHEEL_CONTROLLER_A 7
#define GRAB_WHEEL_CONTROLLER_B 9
#define GRAB_WHEEL_SPEED .75

#define USING_LIMIT_SWITCH TRUE

#define ENCODER_ARM_A_CHANNEL 16//Arm Lift Encoder
#define ENCODER_ARM_B_CHANNEL 17//Arm Lift Encoder
//-----------------------------------------

#define GRAVITY 9.81 //  m / (s^2)
#define AUTONOMOUS_PERIOD 1/50  // 50 times a second
#define MS_PER_PERIOD 20 //(better than ^) 20 Milliseconds in a period

//Channel_Output Channel Out_Put UltraSonic
//#define ULTRASONIC_CHANNEL 5

//Power Distribution Panels
#define GRABARM_POWER_DISTRIBUTION_CHANNEL 4

//Triggers to Axis Rotate
#define LEFT_TRIGGER 2
#define RIGHT_TRIGGER 3
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
