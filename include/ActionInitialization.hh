#ifndef ACTION_INITIALIZATION_HH
#define ACTION_INITIALIZATION_HH

#include "G4VUserActionInitialization.hh"

#include "PrimaryGenerator.hh"
#include "RunAction.hh"

class ActionInitialization : public G4VUserActionInitialization
{
public:
	ActionInitialization();
	~ActionInitialization();

	// for master thread, since we have multithreaded install
	virtual void BuildForMaster() const;
	// for the single thread
	virtual void Build() const;
};

#endif