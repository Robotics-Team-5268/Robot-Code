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

Robot::Robot():
	gyro(GYRO_CHANNEL),
	acclrmtr(BuiltInAccelerometer::Range::kRange_8G),
	ultrasonic(ULTRASONIC_CHANNEL),
	stick(JOYSTICK_CHANNEL),
	driveControllerZero(DRIVE_CONTROLLER_0_CHANNEL),
	driveControllerOne(DRIVE_CONTROLLER_1_CHANNEL),
	driveControllerTwo(DRIVE_CONTROLLER_2_CHANNEL),
	driveControllerThree(DRIVE_CONTROLLER_3_CHANNEL),//replace any numbers with channel from RobotParameters
	liftController(LIFT_MOTOR_CHANNEL),
	GrabController_A(GRAB_WHEEL_CONTROLLER_A),
	GrabController_B(GRAB_WHEEL_CONTROLLER_B),
	GrabArmController(GRAB_ARM_CHANNEL),
	potentiometer(GRAB_ARM_POTENTIOMETER_CHANNEL, GRAB_ARM_POTENTIOMETER_RANGE),
	autonomous(*this), //RENAME VARIABLE!!!!
	currentAction(),
	counter(0),
	GrabArm_PDP(),
	done(true)
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
	bool inPressed = stick.GetRawButton(GRAB_WHEEL_BUTTON_IN);
	bool outPressed = stick.GetRawButton(GRAB_WHEEL_BUTTON_OUT);
	bool armInPressed = stick.GetRawButton(GRAB_ARM_BUTTON_IN);
	bool armOutPressed = stick.GetRawButton(GRAB_ARM_BUTTON_OUT);
	bool liftUpPressed = stick.GetRawButton(LIFT_BUTTON_UP);
	bool liftDownPressed = stick.GetRawButton(LIFT_BUTTON_DOWN);

	//Grab Wheels
	if(inPressed == TRUE && outPressed == FALSE){
		GrabController_A.Set(.75);
		GrabController_B.Set(-.75);
	}
	else if(inPressed == FALSE && outPressed == TRUE){
		GrabController_A.Set(-.75);
		GrabController_B.Set(.75);
	}
	else if(inPressed && outPressed){
		GrabController_A.Set(-.75);
		GrabController_B.Set(-.75);
	}
	else{
		GrabController_A.Set(0);
		GrabController_B.Set(0);
	}

	//Arm
	if (GrabArm_PDP.GetCurrent(GRABARM_POWER_DISTRIBUTION_CHANNEL) <= 3) /*TODO: Arm value max*/  {
		if(armInPressed && !armOutPressed){
			GrabArmController.Set(.75);
		}
		else if(!armInPressed && armOutPressed){
			GrabArmController.Set(-.75);
		}
		else{
			GrabArmController.Set(0);
		}
	}
	else{
		GrabArmController.Set(0);
	}
	//Lift
	if(liftUpPressed && !liftDownPressed){
		liftController.Set(.75);
	}
	else if(!liftUpPressed && liftDownPressed){
		liftController.Set(-.75);
	}
	else{
		liftController.Set(0);
	}
	SmartDashboard::PutData(strgyro, &gyro);
}

void Robot::TestInit() {
	SendableChooser sc;

	sc.AddDefault("None", NULL);
	sc.AddObject("Move", (AutonomousAction::AATypes*) (AutonomousAction::AATypes::MOVE));
	sc.AddObject("Rotate", (AutonomousAction::AATypes*) (AutonomousAction::AATypes::ROTATE));
	sc.AddObject("Lift", (AutonomousAction::AATypes*) (AutonomousAction::AATypes::LIFT));

	SmartDashboard::PutData("Autonomous Action", &sc);
	SmartDashboard::PutNumber("Parameter", 0.0);
	SmartDashboard::PutBoolean("Ready", done);
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
				SmartDashboard::PutBoolean("Ready", done);
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
					currentAction = new Lift(para);
					break;
				}

				done = false;
				SmartDashboard::PutBoolean("Ready", done);
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
