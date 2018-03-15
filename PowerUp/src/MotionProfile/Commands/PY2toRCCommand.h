#ifndef _PY2TORCCOMMAND_HG_
#define _PY2TORCCOMMAND_HG_

#include <Timer.h>
#include <WPILib.h>
#include "../Profiles/PY2toRCProfile.h"
#include "../../CommandBase.h"

/**
 *
 */
class PY2toRCCommand : public CommandBase
{
public:
	PY2toRCCommand();
	~PY2toRCCommand();
	void Initialize() override;
	void Execute() override;
	bool IsFinished() override;
	void End() override;
	void Interrupted() override;

private:
	Timer* pTimer;
	PY2toRCProfile* pMotionProfiler;
};

#endif