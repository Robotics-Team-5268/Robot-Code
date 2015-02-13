#include "Robot.h"
#include "MecanumDrive.h"
#include "ArcadeDrive.h"
#include "DriveSystem.h"
#include "Lift.h"
#include "Move.h"
#include "Rotate.h"
#include "AutonomousAction.h"

static const std::string strgyro("GYRO_CHANNEL");
bool AorM; //1 (true) Arcade and 0 (false) Mecanum

//TODO: see README.md
//0 all the way down, 1 all the way up
Robot::Robot():
	gyro(GYRO_CHANNEL),
	acclrmtr(BuiltInAccelerometer::Range::kRange_8G),
	//ultrasonic(ULTRASONIC_CHANNEL),
	stick(JOYSTICK_CHANNEL),
	driveControllerZero(DRIVE_CONTROLLER_0_CHANNEL),
	driveControllerOne(DRIVE_CONTROLLER_1_CHANNEL),
	driveControllerTwo(DRIVE_CONTROLLER_2_CHANNEL),
	driveControllerThree(DRIVE_CONTROLLER_3_CHANNEL),//replace any numbers with channel from RobotParameters
	liftController_A(LIFT_MOTOR_CHANNEL_A),
	liftController_B(LIFT_MOTOR_CHANNEL_B),
	//liftHighLimit(LIFT_HIGH_LIMIT_CHANNEL),//Error
	//liftLowLimit(LIFT_LOW_LIMIT_CHANNEL),//Error
	GrabController_A(GRAB_WHEEL_CONTROLLER_A),
	GrabController_B(GRAB_WHEEL_CONTROLLER_B),
	GrabArmController(GRAB_ARM_CHANNEL),
	autonomous(*this), //RENAME VARIABLE!!!!
	GrabArm_PDP(),
	currentAction(),
	counter(0),
	done(false)
{
	drive = new MecanumDrive(*this); //Uses left joystick to move forward/backwards and left/right, and uses right stick to rotate/turn left/right
	//drive = new ArcadeDrive(this); //Uses left joystick to move forwards/backwards and rotate/turn left/right


	//this->SetPeriod(0); 	//Set update period to sync with robot control packets (20ms nominal)

}

void Robot::RobotInit() {
}

void Robot::AutonomousInit() {
	gyro.Reset();
	autonomous.autonomousReset();
}

void Robot::AutonomousPeriodic() {
	autonomous.autonomousPeriodic();
}

void Robot::TeleopInit() {

	gyro.Reset();
}

void Robot::TeleopPeriodic() {
	drive->DrivingCode();

	bool grabWheelInPressed = stick.GetRawButton(GRAB_WHEEL_BUTTON_IN);
	bool grabWheelOutPressed = stick.GetRawButton(GRAB_WHEEL_BUTTON_OUT);
	bool grabArmInPressed = stick.GetRawButton(GRAB_ARM_BUTTON_IN);
	bool grabArmOutPressed = stick.GetRawButton(GRAB_ARM_BUTTON_OUT);
	bool liftUpPressed = stick.GetRawButton(LIFT_BUTTON_UP);
	bool liftDownPressed = stick.GetRawButton(LIFT_BUTTON_DOWN);
	//bool canLiftUp = !liftHighLimit->Get();
	//bool canLiftDown = !liftLowLimit->Get();

	if(JOYSTICK_DEBUG){
		//Axis start at 0 while buttons start at 1
		for(int i = 1; i <= stick.GetButtonCount(); i++){
			char str[20];
			sprintf(str, "Button %d", i);
			SmartDashboard::PutBoolean(str, stick.GetRawButton(i));
		}
		for(int i = 0; i < stick.GetAxisCount(); i++){
			char str[20];
			sprintf(str, "Axis %d", i);
			SmartDashboard::PutNumber(str, stick.GetRawAxis(i));
		}
	}


	//Grab Wheels
	if(grabWheelInPressed == TRUE && grabWheelOutPressed == FALSE){

		GrabController_A.Set(GRAB_WHEEL_SPEED);
		GrabController_B.Set(-GRAB_WHEEL_SPEED);
	}
	else if(grabWheelInPressed == FALSE && grabWheelOutPressed == TRUE){
		GrabController_A.Set(-GRAB_WHEEL_SPEED);
		GrabController_B.Set(GRAB_WHEEL_SPEED);
	}
	else if(grabWheelInPressed && grabWheelOutPressed){
		GrabController_A.Set(-GRAB_WHEEL_SPEED);
		GrabController_B.Set(-GRAB_WHEEL_SPEED);
	}
	else{
		GrabController_A.Set(0);
		GrabController_B.Set(0);
	}

	//Arm
	//if (GrabArm_PDP.GetCurrent(GRABARM_POWER_DISTRIBUTION_CHANNEL) <= 3) /*TODO: Arm value max*/  {
		if(grabArmInPressed && !grabArmOutPressed){
			GrabArmController.Set(GRAB_ARM_SPEED);
		}
		else if(!grabArmInPressed && grabArmOutPressed){
			GrabArmController.Set(-GRAB_ARM_SPEED);
		}
		else{
			GrabArmController.Set(0);
		}
	//}
	//else{
	//	GrabArmController.Set(0);
	//}
	//Lift
	if(liftUpPressed && !liftDownPressed /*&& canLiftUp*/){//DOing something wrong with canLiftUp
		liftController_A.Set(LIFT_UP_SPEED);
		liftController_B.Set(LIFT_UP_SPEED);
	}
	else if(!liftUpPressed && liftDownPressed /*&& canLiftDown*/){//Doing something wrong with canLiftDown
		liftController_A.Set(LIFT_DOWN_SPEED);
		liftController_B.Set(LIFT_DOWN_SPEED);
	}
	else{
		liftController_A.Set(0);
		liftController_B.Set(0);
	}
	SmartDashboard::PutData(strgyro, &gyro);
}

void Robot::TestInit() {
	SendableChooser sc;

	sc.AddDefault("None", NULL);
	sc.AddObject("Move", (AutonomousAction::AATypes*) (AutonomousAction::AATypes::MOVE));
	sc.AddObject("Rotate", (AutonomousAction::AATypes*) (AutonomousAction::AATypes::ROTATE));
	sc.AddObject("Lift", (AutonomousAction::AATypes*) (AutonomousAction::AATypes::LIFT));

	SmartDashboard::PutString("Autonomous State", "None");
	SmartDashboard::PutData("Autonomous Action", &sc);
	SmartDashboard::PutNumber("Parameter", 0.0);
}

void Robot::TestPeriodic() {
	counter++;

	//If we dont have an action lets look for one
	if(currentAction == NULL){

		//Only check every second
		if(counter == 50){
			//Get the new state if we dont have a current action.
			SendableChooser* sc = (SendableChooser*) (SmartDashboard::GetData("Autonomous Action"));

			AutonomousAction::AATypes* type = (AutonomousAction::AATypes*) sc->GetSelected();

			if(type == NULL){
				currentAction = NULL;
				done = true;
				SmartDashboard::PutString("Autonomous State", "None");
				return;
			}

			if(done){
				double para = SmartDashboard::GetNumber("Parameter");

				switch(*type){
				case AutonomousAction::AATypes::MOVE:
					currentAction = new Move(para);
					break;
				case AutonomousAction::AATypes::ROTATE:
					currentAction = new Rotate(para);
					break;
				case AutonomousAction::AATypes::LIFT:
					//currentAction = new Lift(para);
					break;
				}

				done = false;
				//SmartDashboard::PutString("Autonomous State", AutonomousAction::AANames[(*type)]);
			}
		}
	}else{//We have an action so lets update the action
		bool finished = (*currentAction)(*this);

		if(finished){
			currentAction = NULL;
		}

		//Update every 1/2 second
		if(counter % 25 == 0){
			currentAction->printValues();
		}
	}

	//Reset every second
	if(counter == 50){
		counter = 0;
		SmartDashboard::PutBoolean("Ready", done);
	}
}

START_ROBOT_CLASS(Robot);
