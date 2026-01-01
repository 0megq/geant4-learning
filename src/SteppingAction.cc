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
	G4cout << "Energy deposited " << edep << G4endl;

	G4int secondariesCount = step->GetNumberOfSecondariesInCurrentStep();
	if (secondariesCount == 0)
		return;

	const std::vector<const G4Track *> *secondaries = step->GetSecondaryInCurrentStep();

	G4cout << secondariesCount << " Secondaries: ";

	for (int i = 0; i < secondaries->size(); i++)
	{
		const G4Track *track = (*secondaries)[i];
		G4String particleName = track->GetParticleDefinition()->GetParticleName();
		G4cout << particleName << ", ";
	}
	G4cout << G4endl;
}