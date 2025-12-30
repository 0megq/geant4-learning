#include "SteppingAction.hh"

SteppingAction::SteppingAction(G4UserEventAction *eventAction)
{
}

SteppingAction::~SteppingAction()
{
}

void SteppingAction::UserSteppingAction(const G4Step *step)
{
	G4LogicalVolume *volume = step->GetPreStepPoint()->GetTouchableHandle()->GetVolume()->GetLogicalVolume();

	G4double edep = step->GetTotalEnergyDeposit();
	G4int secondaries = step->GetNumberOfSecondariesInCurrentStep();
	G4cout << "Energy deposited this " << edep << ", secondaries " << secondaries << G4endl;
}