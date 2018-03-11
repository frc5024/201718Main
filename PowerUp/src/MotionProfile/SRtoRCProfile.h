#ifndef _SRTORCPROFILE_HG_
#define _SRTORCPROFILE_HG_

#include "WPILib.h"
#include "ctre/Phoenix.h"
#include "../RobotMap.h"
#include "Instrumentation.h"

#include "Paths/SRtoRCPath.h"

/**
 *
 */
class SRtoRCProfile
{
public:
	SRtoRCProfile(TalonSRX & talon);
	void control();
	SetValueMotionProfile getSetValue();
	TrajectoryDuration GetTrajectoryDuration(int durationMs);
	void PeriodicTask();
	void reset();
	void start();
	void startFilling();
	void startFilling(const double profile[][3], int totalCnt);

private:
	MotionProfileStatus _status;
	double _pos = 0, _vel = 0, _heading = 0;
	TalonSRX & _talon;
	int _state = 0;
	int _loopTimeout = 30;
	bool _bStart = false;
	SetValueMotionProfile _setValue;
	static const int kMinPointsInTalon = 5;
	static const int kNumLoopsTimeout = 10;
	Notifier _notifer;
};

#endif