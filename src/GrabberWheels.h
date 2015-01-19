#pragma once

#include "WPILib.h"
#include "RobotParameters.h"

/*
class Gate
{
public:

Solenoid *sol1, *sol2;

typedef enum GateCommandType {GateUp, GateDown} GateCommandThing;

explicit Gate() { sol1 = new Solenoid( GATE_SOLENOID_ONE ); sol2 = new Solenoid( GATE_SOLENOID_TWO); }

void GateCommand( GateCommandType command )
{
switch(command)
{
case GateUp:
sol1->Set( false );
sol2->Set( true );
break;
case GateDown:
sol1->Set( true );
sol2->Set( false );
break;
}

}
void GateTeleOpPeriodic( Joystick * js )
{
if (js->GetRawButton ( GATE_BUTTON ) )
{
GateCommand (GateDown);
}
else
{
GateCommand (GateUp);
}
}
};

#endif
TODO program and comment way better!
*/
