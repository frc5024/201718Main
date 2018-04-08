#include "PY2toRCCommand.h"
#include "../../Utilities/Log.h"

/**
 *
 */
PY2toRCCommand::PY2toRCCommand(Height::Type height)
{
	LOG("[PY2toRCCommand] Constructed");

	if ( CommandBase::pDriveTrain != nullptr )
	{
		Requires(CommandBase::pDriveTrain);
		this->pMotionProfiler = new PY2toRCProfile(*CommandBase::pDriveTrain->GetLeftFrontMotor(), *CommandBase::pDriveTrain->GetRightFrontMotor());
		this->htHeight = height;
	}
	else
	{
		LOG("[PY2toRCCommand] driveTrain is NULL");
	}

	this->pTimer = new Timer();

	return;
}

/**
 *
 */
PY2toRCCommand::~PY2toRCCommand()
{
	delete this->pTimer;
	delete this->pMotionProfiler;

	return;
}

/**
 *
 */
void PY2toRCCommand::Initialize()
{
	LOG("[PY2toRCCommand] Initializing" );

	this->pTimer->Reset();
	this->pTimer->Start();

	CommandBase::pDriveTrain->InitMotionProfilingMode();

	return;
}

/**
 *
 */
void PY2toRCCommand::Execute()
{
	this->pMotionProfiler->control();
	this->pMotionProfiler->PeriodicTask();

	SetValueMotionProfile setOutput = this->pMotionProfiler->getSetValue();

	LOG("[PY2toRCCommand] Set Output: " << setOutput);

	CommandBase::pDriveTrain->GetLeftFrontMotor()->Set(ControlMode::MotionProfile, setOutput);
	CommandBase::pDriveTrain->GetRightFrontMotor()->Set(ControlMode::MotionProfile, setOutput);

	this->pMotionProfiler->start();

	// ask elevator service to move to our set height
	gElevatorHeight = this->htHeight;

	return;
}

/**
 *
 */
bool PY2toRCCommand::IsFinished()
{
	if (this->pMotionProfiler->isFinished())
	{
		LOG("[PY1toRCCommand] MP Finished");

		return true;
	}

	return false;
}

/**
 *
 */
void PY2toRCCommand::End()
{
	LOG("[PY2toRCCommand] Ending" );

	this->pMotionProfiler->reset();
	CommandBase::pDriveTrain->ResetDrive();

	return;
}

/**
 *
 */
void PY2toRCCommand::Interrupted()
{
	LOG("[PY2toRCCommand] Interrupted" );

	this->pMotionProfiler->reset();
	CommandBase::pDriveTrain->ResetDrive();

	return;
}
