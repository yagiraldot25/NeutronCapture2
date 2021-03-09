/*
 * Neutron Capture 1.0
 * Copyright (c) 2020
 * Universidad Nacional de Colombia
 * Servicio Geológico Colombiano
 * All Right Reserved.
 *
 * Developed by Andrea Giraldo Torres
 *              Andrés Camilo Sevilla Moreno
 *
 * Use and copying of these libraries and preparation of derivative works
 * based upon these libraries are permitted. Any copy of these libraries
 * must include this copyright notice.
 *
 * Bogotá, Colombia.
 *
 */

// Geant4 Headers
#include "G4UnitsTable.hh"
#include "G4SystemOfUnits.hh"
#include "G4PVReplica.hh"
#include "G4Colour.hh"
#include "G4LogicalVolume.hh"
#include "G4VisAttributes.hh"
#include "G4PVPlacement.hh"
#include "G4NistManager.hh"
#include "G4PhysicalConstants.hh"
#include "globals.hh"
#include "G4UserLimits.hh"
#include "G4Box.hh"
#include "G4Tubs.hh"
#include "G4RotationMatrix.hh"
#include "G4RunManager.hh"
#include "G4GeometryManager.hh"

// N2 Headers
#include "N2DetectorConstruction.hh"

#include "N2Material.hh"

N2DetectorConstruction::N2DetectorConstruction(): G4VUserDetectorConstruction(),

fPhantom_phys(0),
fTarget_phys(0)

{

	const G4double ug = 1.e-6*g;
	const G4double ppm = ug/g;
	new G4UnitDefinition("microgram", "ug" , "Mass", ug);
	new G4UnitDefinition("ppm", "ppm","Concentration", ppm);
	new G4UnitDefinition("miligram/gram", "mg/g","Concentration", mg/g);
	new G4UnitDefinition("microgram/gram", "ug/g","Concentration", ug/g);

	fN2DetectorMessenger = new N2DetectorMessenger(this) ;

	fConcentration = 150*ug/g;

}

N2DetectorConstruction::~N2DetectorConstruction()
{}

G4VPhysicalVolume* N2DetectorConstruction::Construct()
{  

	// Define materials
	G4Material* vacuum = N2Material::GetInstance()->GetMaterial("G4_Galactic");

	// General Attributes
	G4VisAttributes* simpleInvisibleSVisAtt;
	simpleInvisibleSVisAtt= new G4VisAttributes(G4Colour(0.,0.5,0.5,0.1));
	simpleInvisibleSVisAtt->SetVisibility(true);

	// Geometrical Volume =========================================================================================

	// World
	G4double world_size_X = (1/2.)*m;
	G4VSolid* world_geo = new G4Box("world_geo", world_size_X, world_size_X, world_size_X);


	//Logical Volume ==============================================================================================

	// World
	G4LogicalVolume* world_log = new G4LogicalVolume(world_geo,vacuum,"world_log");
	world_log -> SetVisAttributes(simpleInvisibleSVisAtt);

	//Physics Volume  =============================================================================================

	G4VPhysicalVolume* world_phys =
			new G4PVPlacement(0,                     	//no rotation
					G4ThreeVector(),       				//at (0,0,0)
					world_log,      					//its logical volume
					"world_phys",   					//its name
					0,                     				//its mother  volume
					false,                 				//no boolean operation
					0,                     				//copy number
					0);      			    			//overlaps checking

	SetupGeometry(world_log);

	//always return the physical World
	//
	return world_phys;

}

void N2DetectorConstruction::SetupGeometry(G4LogicalVolume* motherVolume){

	// Define materials

	G4Material* material;
	if(fConcentration>0){
		material = N2Material::GetInstance()->GetMaterial("H2O+B10",fConcentration);
	}else{
		material = N2Material::GetInstance()->GetMaterial("G4_WATER");
	}

	G4Material* water = N2Material::GetInstance()->GetMaterial("G4_WATER");


	// Visualization attributes
	G4VisAttributes* simplePhantomVisAtt;
	simplePhantomVisAtt= new G4VisAttributes(G4Colour(0.0,1.0,1.0,0.1));
	simplePhantomVisAtt->SetVisibility(true);

	G4VisAttributes* simpleLayerVisAtt;
	simpleLayerVisAtt= new G4VisAttributes(G4Colour(0.0,0.0,1.0,0.1));
	simpleLayerVisAtt->SetVisibility(true);

	// Geometrical Volume =========================================================================================


	G4cout<<"============================ Geometry Description ============================"<<G4endl;

	// Phantom
	G4double phantom_dx = (10/2.)*cm;
	G4VSolid* phantom_geo =new G4Box("phantom_geo",phantom_dx, phantom_dx, phantom_dx);

	// Target
	G4double target_dx = (5/2.)*cm;
	G4VSolid* target_geo =new G4Box("target_geo",target_dx, target_dx, target_dx);


	//Logical Volume ==============================================================================================

	// phantom
	G4LogicalVolume* phantom_log = new G4LogicalVolume(phantom_geo, water,"phantom_log");
	phantom_log -> SetVisAttributes(simplePhantomVisAtt);

	// target
	G4LogicalVolume* target_log = new G4LogicalVolume(target_geo, material,"target_log");
	target_log -> SetVisAttributes(simpleLayerVisAtt);




	//Physics Volume  =============================================================================================

	// phantom
	fPhantom_phys = new G4PVPlacement(0,
			G4ThreeVector(0,0,0),   		    //at (0,0,0)
			phantom_log,     					//its logical volume
			"phantom_phys", 	 				//its name
			motherVolume, 						//its mother  volume
			false,              				//no boolean operation
			0,                     				//copy number
			true);      			     		//overlaps checking

	// target
	fTarget_phys = new G4PVPlacement(0,
			G4ThreeVector(0,0,0),               //at (0,0,0)
			target_log,     					//its logical volume
			"target_phys", 	 				//its name
			phantom_log, 						//its mother  volume
			false,                 				//no boolean operation
			0,                     				//copy number
			true);      		     			//overlaps checking


}

void N2DetectorConstruction::ConstructSDandField()
{}

void N2DetectorConstruction::SetConcentration(G4double aConcentration){


	G4GeometryManager* geoman = G4GeometryManager::GetInstance() ;

	// Open geometry for the physical volume to be modified ...
	//
	geoman->OpenGeometry(fTarget_phys);

	fConcentration=aConcentration;
	G4Material* material;
	if(fConcentration>0){
		material = N2Material::GetInstance()->GetMaterial("H2O+B10",fConcentration);
	}else{
		material = N2Material::GetInstance()->GetMaterial("G4_WATER");

	}
	this->fTarget_phys->GetLogicalVolume()->SetMaterial(material);


	G4cout<<"================================================================================"<<fConcentration<<G4endl;

	// Close geometry for the portion modified ...
	//
	geoman->CloseGeometry(fTarget_phys);

	G4RunManager::GetRunManager()->PhysicsHasBeenModified();
	G4RunManager::GetRunManager()->ReinitializeGeometry();
}
