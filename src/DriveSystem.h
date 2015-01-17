#ifndef DRIVE_SYSTEM_H
#define DRIVE_SYSTEM_H

#include "WPILib.h"

class DriveSystem {
public:
   virtual void TeleopPeriodic() = 0;
};

#endif
