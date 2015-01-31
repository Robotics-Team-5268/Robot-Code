#pragma once

#include "AutonomousAction.h"

class Move : public AutonomousAction {
   virtual bool operator()();
};
