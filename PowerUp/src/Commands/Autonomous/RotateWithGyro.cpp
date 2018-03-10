#include "RotateWithGyro.h"
#include "../Utilities/Log.h"
#include <math.h>

/**
 *
 */
RotateWithGyro::RotateWithGyro(double setpoint)
{
	LOG("[RotateWithGyro] Constructed");

	if (CommandBase::pDriveTrain != nullptr)
	{
		Requires(CommandBase::pDriveTrain);
		this->dSetPoint = setpoint;
	}
	else
	{
		LOG("[RotateWithGyro] driveTrain is null!");
	}

	this->pTimer = new Timer();

	return;
}

/**
 *
 */
void RotateWithGyro::Initialize()
{
	LOG("[RotateWithGyro] Initalized");

	this->pTimer->Reset();
	this->pTimer->Start();

	CommandBase::pDriveTrain->ResetGyro();
	CommandBase::pDriveTrain->Turn(dSetPoint);

	return;
}

/**
 *
 */
void RotateWithGyro::Execute()
{

	if (iCounter++ == 10)
	{
		CommandBase::pDriveTrain->Trace();

		double dCurrentAngle = CommandBase::pDriveTrain->GetAngle();

		LOG("[RotateWithGyro] Set Point: " << dSetPoint << " Angle: " << dCurrentAngle);

		iCounter = 0;
	}

	return;
}

/**
 *
 */
bool RotateWithGyro::IsFinished()
{
	if (this->pTimer->Get() > 4.0) // stop after 2 seconds no matter what
	{
		LOG("[RotateWithEncoders] Timed out");

		return true;
	}

	double dCurrentAngle = CommandBase::pDriveTrain->GetAngle();

	if (fabs(dCurrentAngle) >= fabs(dSetPoint))
	{
		return true;
	}

	return false;
}

/**
 *
 */
void RotateWithGyro::End()
{
	LOG("[RotateWithGyro] Ended");

	return;
}

/**
 *
 */
void RotateWithGyro::Interrupted()
{
	LOG("[RotateWithGyro] Interrupted");

	return;
}