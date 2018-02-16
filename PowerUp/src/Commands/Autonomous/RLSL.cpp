#include "RLSL.h"
#include "../../Utilities/Log.h"
#include "../DriveByPosition.h"
#include "../RotateToAngle.h"

/**
 * Robot Left/Switch Left
 */

RLSL::RLSL()
{
	LOG("[RLSL] Constructed");

	AddSequential(new DriveByPosition(60.0, 1.0));
	AddSequential(new RotateToAngle(90.0f));
	AddSequential(new DriveByPosition(24.0, 0.5));
}
