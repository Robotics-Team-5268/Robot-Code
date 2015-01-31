#pragma once

#include "WPILib.h"

class DriveSystem {
public:
    virtual ~DriveSystem(){}
    virtual void DrivingCode() = 0;
    virtual void rotate(float) = 0;
};
