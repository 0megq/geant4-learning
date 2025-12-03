#include "SensitiveDetector.hh"

SensitiveDetector::SensitiveDetector(G4String name) : G4VSensitiveDetector(name)
{
	fTotalEnergyDeposited = 0.;
}

SensitiveDetector::~SensitiveDetector()
{
}

void SensitiveDetector::Initialize(G4HCofThisEvent *)
{
	fTotalEnergyDeposited = 0.;
}

void SensitiveDetector::EndOfEvent(G4HCofThisEvent *)
{
	G4cout << "Deposited Energy: " << fTotalEnergyDeposited << "MeV" << G4endl; // MeV is the standard unit of energy in G4
}

G4bool SensitiveDetector::ProcessHits(G4Step *aStep, G4TouchableHistory *)
{
	G4double fEnerygDeposited = aStep->GetTotalEnergyDeposit();

	if (fEnerygDeposited > 0)
	{
		fTotalEnergyDeposited += fEnerygDeposited;
	}

	return true;
}