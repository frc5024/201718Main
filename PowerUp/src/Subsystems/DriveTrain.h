#ifndef _DRIVETRAIN_HG_
#define _DRIVETRAIN_HG_

#include <WPILib.h>
#include <Commands/Subsystem.h>
#include <ctre/Phoenix.h>
#include <Drive/DifferentialDrive.h>
#include <AHRS.h>

/**
 *
 */

class DriveTrain: public frc::Subsystem, PIDOutput
{
public:
	DriveTrain();
	~DriveTrain();
	void InitAutonomous();
	void InitDefaultCommand() override;
	void Drive(XboxController* joystick);
	void Drive(double position);
	void Turn(double setpoint);

	// These are the same as the DifferentialDrive class:
	void ArcadeDrive( double xSpeed, double zRotation );
	void CurvatureDrive( double xSpeed, double zRotation, bool isQuickTurn );
	void TankDrive( double leftSpeed, double rightSpeed );

	double GetAngle();
	double GetPosition();
	bool IsDriving();
	bool IsTurning();

	void ResetDrive();
	void ResetGyro();

	virtual void PIDWrite(double output);


private:
	can::WPI_TalonSRX* pLeftFrontMotor;
	can::WPI_TalonSRX* pLeftRearMotor;
	can::WPI_TalonSRX* pRightFrontMotor;
	can::WPI_TalonSRX* pRightRearMotor;

	frc::DifferentialDrive* pRobotDrive;

	AHRS* pGyro; // navX MXP
	PIDController* pTurnController;
	double dRotateToAngleRate;
}
;

#endif
