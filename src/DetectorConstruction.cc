#include "DetectorConstruction.hh"

DetectorConstruction::DetectorConstruction()
{
}

DetectorConstruction::~DetectorConstruction()
{
}

G4VPhysicalVolume *DetectorConstruction::Construct()
{
	G4bool checkOverlaps = true;

	G4NistManager *nist = G4NistManager::Instance();
	G4Material *worldMat = nist->FindOrBuildMaterial("G4_AIR");

	G4double xWorld = 1. * m;
	G4double yWorld = 1. * m;
	G4double zWorld = 1. * m;

	// solid is the definition of the shape
	G4Box *solidWorld = new G4Box("solidWorld", 0.5 * xWorld, 0.5 * yWorld, 0.5 * zWorld);
	G4LogicalVolume *logicWorld = new G4LogicalVolume(solidWorld, worldMat, "logicWorld");
	// 0 for no rotation, G4ThreeVector is the position
	G4VPhysicalVolume *physWorld = new G4PVPlacement(0, G4ThreeVector(0., 0., 0.), logicWorld, "physWorld", 0, false, 0, checkOverlaps);

	return physWorld;
}