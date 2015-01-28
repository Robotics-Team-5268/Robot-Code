#pragma once

#include "WPILib.h"

class DriveSystem {
public:
  virtual void DrivingCode() = 0;
  virtual void rotate() = 0;
};
