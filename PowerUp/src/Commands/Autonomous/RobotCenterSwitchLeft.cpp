#include "Commands/Autonomous/RobotCenterSwitchLeft.h"
#include "../../Utilities/Log.h"
#include "../DriveWithEncoders.h"
#include "../RotateWithEncoders.h"
#include "../RotateWithGyro.h"

/**
 *
 */
RobotCenterSwitchLeft::RobotCenterSwitchLeft()
{
	LOG("[RobotCenterSwitchLeft] Constructed");

	AddSequential(new DriveWithEncoders ( 60.0,   1.0));
//	AddSequential(new RotateWithGyro    (-90.0f      ));
	AddSequential(new RotateWithEncoders( 15.51, -0.5));
	AddSequential(new DriveWithEncoders (120.0 ,  1.0));
//	AddSequential(new RotateWithGyro    ( 90.0f      ));
	AddSequential(new RotateWithEncoders( 15.51,  0.5));
	AddSequential(new DriveWithEncoders ( 60.0 ,  0.8));
}
