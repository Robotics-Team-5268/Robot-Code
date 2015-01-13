#include "WPILib.h"
#include "RobotParameters.h"
#include "SmartDashBoard\Smartdashboard.h"
#include "Autonomous.h"


//TODO: see README.md



/**
 * This is a demo program showing the use of the RobotDrive class.
 * The SampleRobot class is the base of a robot application that will automatically call your
 * Autonomous and OperatorControl methods at the right time as controlled by the switches on
 * the driver station or the field controls.
 *
 * WARNING: While it may look like a good choice to use for your code if you're inexperienced,
 * don't. Unless you know what you are doing, complex code will be much more difficult under
 * this system. Use IterativeRobot or Command-Based instead if you're new.
 */
class Robot: public IterativeRobot {
	RobotDrive *myRobot; // robot drive system
	Joystick stick; // only joystick

	//old code for gyro
	//AnalogChannel *m_gyrochannel;

public:
	Robot() :
			//may need to be commented out like in last years code
			myRobot(0, 1),	//initialize the RobotDrive to use motor controllers on ports 0 and 1
			stick(0)
	{
		//initiate robot
		myRobot.SetExpiration(0.1);
		myRobot = new RobotDrive(m_left, m_right);

		//Set update period to sync with robot control packets (20ms nominal)
		this->SetPeriod(0);

		//set motors
		m_left = new Talon(1);
		m_right = new Talon(2);

		myRobot->SetInvertedMotor(RobotDrive::kFrontLeftMotor, true);
		myRobot->SetInvertedMotor(RobotDrive::kFrontRightMotor, false);
		myRobot->SetInvertedMotor(RobotDrive::kRearLeftMotor, true);
		myRobot->SetInvertedMotor(RobotDrive::kRearRightMotor, false);

		//old code for gyro
		//m_gyrochannel = new AnalogChannel(_CHANNEL);
		//m_gyro = new Gyro(m_gyrochannel);
	}

	private:
		//look into this more, may not need it
		//LiveWindow *lw;

		void RobotInit() {
			//see above: LiveWindow *lw;
			//lw = LiveWindow::GetInstance();
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
			//see above: LiveWindow *lw;
			//lw->Run();
		}
};

START_ROBOT_CLASS(Robot);
