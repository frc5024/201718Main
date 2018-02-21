#include "CommandBase.h"
#include "Subsystems/DriveTrain.h"

// static variables in C++ have to be declared here
// (not in the .h file)
DriveTrain* CommandBase::pDriveTrain = NULL;
OI* CommandBase::pOI = NULL;
Intake* CommandBase::pIntake = NULL;
Elevator* CommandBase::pElevator = NULL;
ClimbSystem* CommandBase::pClimbSystem = NULL;

CommandBase::CommandBase() : Command()
{
	std::cout << "[CommandBase] Constructed" << std::endl;

	this->init();

	return;
}


CommandBase::~CommandBase()
{
	delete this->pDriveTrain;
	delete this->pIntake;
	delete this->pOI;
	delete this->pElevator;
	delete this->pClimbSystem;

	return;
}


CommandBase::CommandBase(char const *name) : Command(name)
{
	std::cout << "[CommandBase] Constructed with name: " << name << std::endl;

	return;
}


void CommandBase::init()
{
	std::cout << "[CommandBase] Initialized" << std::endl;

	// Note: These aren't "this" because they are static,
	//	so there is only one instance of these variables in
	//	the CommandBase class. "this" pointers refer to
	//	regular variables that are created (and are unique)
	//	to the 'instance' of the object.

	if (CommandBase::pOI == nullptr)
	{
		CommandBase::pOI = new OI();
	}

	if (CommandBase::pDriveTrain == nullptr)
	{
		CommandBase::pDriveTrain = new DriveTrain();
	}

	if (CommandBase::pIntake == nullptr)
	{
		CommandBase::pIntake = new Intake();
	}

	if (CommandBase::pElevator == nullptr)
	{
		CommandBase::pElevator = new Elevator();
	}

	if (CommandBase::pClimbSystem == nullptr)
	{
		CommandBase::pClimbSystem = new ClimbSystem();
	}


	return;
}


