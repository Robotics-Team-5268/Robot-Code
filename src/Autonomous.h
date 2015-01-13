#include "WPILib.h"
#include "RobotBase.h"
#include "RobotParameters.h"
#include "SmartDashBoard\Smartdashboard.h"

class autonomous {
  //initiate robot drive
  RobotDrive *m_robotDrive;

  //TODO SOMEBODY BETTER FIGURE OUT WHAT THIS IS AND COMMENT IT!!!!!!!!!
  UINT32 m_autoPeriodicLoops;
  //static const float Kp = 0.03;

  public:
    autonomous(RobotDrive *robotdrive) {
      m_autoPeriodicLoops = 0;
      m_robotDrive = robotdrive;
      m_robotDrive->SetSafetyEnabled(false);
    }

    void autonomousReset(void) {
      m_autoPeriodicLoops = 0;
    }

    void autonomousPeriodic(void){
      //TODO program this junk

      /*#define Kp 0.0000005
      #define time 0.6
      float turn;
      turn = m_gyro->GetAngle() * Kp;
      //turn = 0.0;
      m_autoPeriodicLoops++;
      m_robotDrive->SetSafetyEnabled(false);
      */
}
