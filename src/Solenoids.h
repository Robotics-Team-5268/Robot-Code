#pragma once

#include "WPILib.h"
#include "RobotParameters.h"

/*
typedef enum ShooterCommandType
{
ShooterIn, ShooterOut
};


class Shooter
{
public:

Solenoid *sol;

explicit Shooter() { sol = new Solenoid( SHOOTER_SOLENOID ); }

void ShooterCommand( ShooterCommandType command )
{
switch(command)
{
case ShooterOut:
sol->Set( true );
break;
case ShooterIn:
sol->Set( false );
break;
}

}
void ShooterTeleOpPeriodic( Joystick * js )
{
if (js->GetRawButton ( SHOOTER_BUTTON ) )
{
ShooterCommand (ShooterOut);
}
else
{
ShooterCommand (ShooterIn);
}
}
};
*/
