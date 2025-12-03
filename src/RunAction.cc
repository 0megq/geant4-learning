#include "RunAction.hh"

RunAction::RunAction()
{
	G4AnalysisManager *analysisManager = G4AnalysisManager::Instance();

	// create 1 dimensional histogram; Edep for Energy deposited
	analysisManager->CreateH1("Edep", "Energy Deposit", 100, 0., 1.1 * MeV);

	analysisManager->CreateNtuple("Photons", "Photons");
	// I: integer, D: double
	analysisManager->CreateNtupleIColumn("iEvent");
	analysisManager->CreateNtupleDColumn("fX"); // store x position
	analysisManager->CreateNtupleDColumn("fY");
	analysisManager->CreateNtupleDColumn("fZ");
	analysisManager->CreateNtupleDColumn("fGlobalTime");
	analysisManager->CreateNtupleDColumn("fWlen"); // wavelength
	analysisManager->FinishNtuple(0);
}

RunAction::~RunAction()
{
}

void RunAction::BeginOfRunAction(const G4Run *run)
{
	G4AnalysisManager *analysisManager = G4AnalysisManager::Instance();

	G4int runID = run->GetRunID();

	std::stringstream strRunID;
	strRunID << runID;

	analysisManager->OpenFile("output" + strRunID.str() + ".root");
}

void RunAction::EndOfRunAction(const G4Run *run)
{
	G4AnalysisManager *analysisManager = G4AnalysisManager::Instance();

	analysisManager->Write();
	analysisManager->CloseFile();

	G4int runID = run->GetRunID();

	G4cout << "Finishing run " << runID << G4endl;
}