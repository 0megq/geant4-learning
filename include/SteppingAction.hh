#ifndef STEPPING_ACTION_HH
#define STEPPING_ACTION_HH

#include "G4UserSteppingAction.hh"
#include "G4UserEventAction.hh"
#include "G4Step.hh"

class SteppingAction : public G4UserSteppingAction
{
public:
	SteppingAction(G4UserEventAction *);
	~SteppingAction();

	virtual void UserSteppingAction(const G4Step *);

private:
};

#endif