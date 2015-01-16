#include "RobotBase.h"
#include "WPILib.h"
#include "RobotParameters.h"
#include "SmartDashBoard\Smartdashboard.h"
#include "Autonomous.h"

//TODO: see README.md

class Robot: public IterativeRobot {
	RobotDrive *myRobot; // robot drive system
	Joystick stick; // only joystick


	Talon *m_right;
	Talon *m_left;
	//old code for gyro
	//AnalogChannel *m_gyrochannel;

	//Accelerometer
	Accelerometer *accel;
	double xVal;
	double yVal;
	double zVal;


public:
	Robot() :
			//may need to be commented out like in last years code
			//myRobot(0, 1),	//initialize the RobotDrive to use motor controllers on ports 0 and 1
			stick(0)
	{
		//initiate robot
		m_left = new Talon(1);
		m_right = new Talon(2);
		myRobot = new RobotDrive(m_left, m_right);
		myRobot->SetExpiration(0.1);


		//Set update period to sync with robot control packets (20ms nominal)
		//this->SetPeriod(0);

		//set motors


		myRobot->SetInvertedMotor(RobotDrive::kFrontLeftMotor, true);
		myRobot->SetInvertedMotor(RobotDrive::kFrontRightMotor, false);
		myRobot->SetInvertedMotor(RobotDrive::kRearLeftMotor, true);
		myRobot->SetInvertedMotor(RobotDrive::kRearRightMotor, false);

		//old code for gyro
		//m_gyrochannel = new AnalogChannel(_CHANNEL);
		//m_gyro = new Gyro(m_gyrochannel);

		//Accelerometer
		accel = new BuiltInAccelerometer(Accelerometer::kRange_4G);
		xVal = accel->GetX();
		yVal = accel->GetY();
		zVal = accel->GetZ();
	}

	private:
		//look into this more, may not need it
		LiveWindow *lw;
		void RobotInit() {
			lw = LiveWindow::GetInstance();
		}

		void AutonomousInit() {
			//old code
			//m_autonomous->autonomousReset();
			//m_gyro->Reset();
		}

		void AutonomousPeriodic() {
			//old code
			//m_autonomous->autonomousPeriodic();
		}

		void TeleopInit() {
			//old code for gyro
			//m_gyro->Reset();
		}

		void TeleopPeriodic() {
			myRobot->ArcadeDrive(stick); // drive with arcade style

			//may need this, comment above if using this
			//myRobot->ArcadeDrive(((stick.GetY()*4)/4), -((stick.GetX()*3)/4), false);
		}

		void TestPeriodic() {
			lw->Run();
		}
};

START_ROBOT_CLASS(Robot);
