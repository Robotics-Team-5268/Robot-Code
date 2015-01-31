#pragma once



#include "AutonomousAction.h"
#include "Autonomous.h"


class Rotate: public AutonomousAction, public Autonomous {
public:
   virtual bool operator()(Robot&);
   void start();
   void stop();
};
