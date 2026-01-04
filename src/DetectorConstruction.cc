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
	G4Material *worldMat = nist->FindOrBuildMaterial("G4_Galactic");
	G4Material *detMat = nist->FindOrBuildMaterial("G4_SODIUM_IODIDE");

	G4double xWorld = 40. * km;
	G4double yWorld = 40. * km;
	G4double zWorld = 20. * km;

	// solid is the definition of the shape
	G4Box *solidWorld = new G4Box("solidWorld", xWorld, yWorld, zWorld);
	G4LogicalVolume *logicWorld = new G4LogicalVolume(solidWorld, worldMat, "logicWorld");
	// 0 for no rotation, G4ThreeVector is the position
	G4VPhysicalVolume *physWorld = new G4PVPlacement(0, G4ThreeVector(0., 0., 0.), logicWorld, "physWorld", 0, false, 0, checkOverlaps);

	// construct atmosphere
	{
		G4double density0 = 1.29 * kg / m3;
		G4double aN = 14.01 * g / mole;
		G4double aO = 16.00 * g / mole;

		G4Element *elN = new G4Element("Nitrogen", "N", 7, aN);
		G4Element *elO = new G4Element("Oxygen", "O", 8, aO);

		G4double f = 3;
		G4double R = 8.3144626181532;
		G4double g0 = 9.81;
		G4double kappa = (f + 2) / f;
		G4double T = 293.15;
		G4double M = (0.3 * 14.01 + 0.7 * 16.0) / 1000.;

		G4Material *Air[10];
		for (G4int i = 0; i < 10; i++)
		{
			std::stringstream stri;
			stri << i;
			G4double h = 40e3 / 10. * i;
			G4double density = density0 * pow((1 - (kappa - 1) / kappa * M * g0 * h / (R * T)), (1 / (kappa - 1)));
			Air[i] = new G4Material("G4_AIR_" + stri.str(), density, 2);
			Air[i]->AddElement(elN, 70 * perCent);
			Air[i]->AddElement(elO, 30 * perCent);
		}

		solidAir = new G4Box("solidAir", xWorld, yWorld, zWorld / 10.);

		G4VisAttributes *airVisAtt = new G4VisAttributes(G4Color(1.0, 1.0, 0.0, 0.3));
		airVisAtt->SetForceSolid(true);

		for (G4int i = 0; i < 10; i++)
		{
			logicAir[i] = new G4LogicalVolume(solidAir, Air[i], "logicAir");

			physAir[i] = new G4PVPlacement(0, G4ThreeVector(0, 0, zWorld / 10. * 2 * i - zWorld + zWorld / 10.), logicAir[i], "physAir", logicWorld, false, i, true);

			logicAir[i]->SetVisAttributes(airVisAtt);
		}
	}

	// G4double detectorSize = 10. * cm;
	// G4Box *solidDetector = new G4Box("solidDetector", 0.5 * detectorSize, 0.5 * detectorSize, 0.5 * detectorSize);
	// logicDetector = new G4LogicalVolume(solidDetector, detMat, "logicDetector");
	// G4VPhysicalVolume *physDetector = new G4PVPlacement(0, G4ThreeVector(0., 0., 10.5 * cm), logicDetector, "physDetector", logicWorld, false, checkOverlaps);

	// G4VisAttributes *detVisAtt = new G4VisAttributes(G4Color(1.0, 1.0, 0.0, 0.5));
	// detVisAtt->SetForceSolid(true);
	// logicDetector->SetVisAttributes(detVisAtt);

	return physWorld;
}

void DetectorConstruction::ConstructSDandField()
{
	// SensitiveDetector *sensDet = new SensitiveDetector("Sensitive Detector YAY!");
	// logicDetector->SetSensitiveDetector(sensDet);
	// G4SDManager::GetSDMpointer()->AddNewDetector(sensDet); // want to make sure our functions Initialize and EndOfEvent are called
}