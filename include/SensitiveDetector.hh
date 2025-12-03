#ifndef SENSITIVE_DETECTOR_HH
#define SENSITIVE_DETECTOR_HH

#include "G4VSensitiveDetector.hh"

#include "G4RunManager.hh"
#include "G4AnalysisManager.hh"
#include "G4SystemOfUnits.hh"
#include "G4UnitsTable.hh"

class SensitiveDetector : public G4VSensitiveDetector
{
public:
	SensitiveDetector(G4String); // pass in the detector name
	~SensitiveDetector();

private:
	G4double fTotalEnergyDeposited;

	virtual void Initialize(G4HCofThisEvent *) override; // HC - hit collections, for analysis, but we won't use it here
	virtual void EndOfEvent(G4HCofThisEvent *) override;

	virtual G4bool ProcessHits(G4Step *, G4TouchableHistory *); // main function that controls what happens for every step that a particle is inside
};

#endif