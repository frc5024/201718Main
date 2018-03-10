#include "MPRobotCenterSwitchRightCG.h"
#include "../RC2SRCommand.h"
#include "../SR2RCCommand.h"
#include "../RC2PY1Command.h"
#include "../PY12RCCommand.h"
#include "../../../Commands/Autonomous/MoveElevator.h"
#include "../../../Commands/Autonomous/ToggleIntake.h"
#include "../../../Commands/Autonomous/ToggleGripper.h"

/**
 *
 */MPRobotCenterSwitchRightCG::MPRobotCenterSwitchRightCG()
{
	AddSequential(new RC2SRCommand());
	AddSequential(new ToggleIntake( -1.00));

	AddParallel(new SR2RCCommand());
	AddSequential(new MoveElevator(  0.00));

	AddParallel(new RC2PY1Command());
	AddSequential(new ToggleGripper(-1.00));
	AddSequential(new ToggleIntake ( 1.00));

	AddParallel(new PY12RCCommand());
	AddSequential(new MoveElevator( 1.00));

	AddSequential(new RC2SRCommand());
	AddSequential(new ToggleIntake( -1.00));
}