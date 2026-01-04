#include "PrimaryGenerator.hh"

PrimaryGenerator::PrimaryGenerator()
{
	fParticleGun = new G4ParticleGun(1);

	// Particle position and direction
	G4ThreeVector pos(0., 0., -20. * km);
	G4ThreeVector mom(0., 0., 1.);

	// Particle type
	G4ParticleTable *particleTable = G4ParticleTable::GetParticleTable();
	G4ParticleDefinition *particle = particleTable->FindParticle("proton");

	fParticleGun->SetParticlePosition(pos);
	fParticleGun->SetParticleMomentumDirection(mom);
	fParticleGun->SetParticleMomentum(100. * GeV);
	// shifted our particle definition to GeneratePrimaries function
}

PrimaryGenerator::~PrimaryGenerator()
{
	delete fParticleGun;
}

// function that "shoots the particle"
void PrimaryGenerator::GeneratePrimaries(G4Event *anEvent)
{
	// Particle type (a radeoactive isotope of fluoride)
	// Beta + source (positrons) -> interact with atomic shell -> emits two gammas at energy of the rest mass ~511keV
	// G4int Z = 9;
	// G4int A = 18;

	// G4double charge = 0. * eplus;
	// G4double energy = 0. * keV; // no intial kinetic energy

	// // despite no charge, still considered an ion by G4
	// G4ParticleDefinition *ion = G4IonTable::GetIonTable()->GetIon(Z, A, energy);
	// fParticleGun->SetParticleDefinition(ion);
	// fParticleGun->SetParticleCharge(charge);
	// fParticleGun->SetParticleEnergy(energy);

	// Create vertex
	fParticleGun->GeneratePrimaryVertex(anEvent);
}