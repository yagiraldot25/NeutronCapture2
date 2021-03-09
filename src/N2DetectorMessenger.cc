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

// N2 Headers
#include "N2DetectorMessenger.hh"

N2DetectorMessenger::N2DetectorMessenger(N2DetectorConstruction* aN2DetectorConstruction){

	fN2DetectorConstruction = aN2DetectorConstruction ;

	fUIDirectoryCollection["N2Geometry"] = new G4UIdirectory("/N2/geometry/") ;
	fUIDirectoryCollection["N2Geometry"] -> SetGuidance("Geometry construction commands") ;

	fUIcmdWithADoubleAndUnitCollection["SetConcentration"] = new G4UIcmdWithADoubleAndUnit("/N2/geometry/SetConcentration",this) ;
	fUIcmdWithADoubleAndUnitCollection["SetConcentration"] -> SetGuidance("Set particles concentration in the medium");
	fUIcmdWithADoubleAndUnitCollection["SetConcentration"] -> SetParameterName("Concentration",false);
	fUIcmdWithADoubleAndUnitCollection["SetConcentration"] -> SetUnitCategory("Concentration");
	fUIcmdWithADoubleAndUnitCollection["SetConcentration"] -> AvailableForStates(G4State_PreInit, G4State_Idle);

}


N2DetectorMessenger::~N2DetectorMessenger(){

	// UI Directory Collection
	for(size_t i = 0; i < fUIDirectoryCollection.size(); i++){
		delete fUIDirectoryCollection[i] ;
	}

	// UI cmd With a String Collection
	for(size_t i = 0; i < fUIcmdWithAStringCollection.size(); i++){
		delete fUIcmdWithAStringCollection[i] ;
	}

	// UI cmd With a Bool Collection
	for(size_t i = 0; i < fUIcmdWithABoolCollection.size(); i++){
		delete fUIcmdWithABoolCollection[i] ;
	}

	// UI cmd With a Double and Unit Collection
	for(size_t i = 0; i < fUIcmdWithADoubleAndUnitCollection.size(); i++){
		delete fUIcmdWithADoubleAndUnitCollection[i] ;
	}

	// UI cmd With a Int Collection
	for(size_t i = 0; i < fUIcmdWithAIntCollection.size(); i++){
		delete fUIcmdWithAIntCollection[i] ;
	}
}

void N2DetectorMessenger::SetNewValue(G4UIcommand* command,G4String aValue ){

	if( command == fUIcmdWithADoubleAndUnitCollection["SetConcentration"] ) { fN2DetectorConstruction->SetConcentration(fUIcmdWithADoubleAndUnitCollection["SetConcentration"]->GetNewDoubleValue(aValue)); }

}

