#include "ActionInitialization.hh"

ActionInitialization::ActionInitialization()
{
}

ActionInitialization::~ActionInitialization()
{
}

void ActionInitialization::BuildForMaster() const
{
	RunAction *runAction = new RunAction();
	SetUserAction(runAction); // this is important, because the histogram will be created in the master thread without thread number
}

void ActionInitialization::Build() const
{
	PrimaryGenerator *generator = new PrimaryGenerator();
	SetUserAction(generator);

	RunAction *runAction = new RunAction();
	SetUserAction(runAction);
}