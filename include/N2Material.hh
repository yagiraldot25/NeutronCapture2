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

#ifndef N2Material_hh
#define N2Material_hh 1

// Geant4 Headers
#include "G4Material.hh"

using namespace std ;

typedef map <G4String,G4Material*> MaterialsCollection ;

class N2Material {

public:

	/// Static method returning an instance of Control.
	static N2Material* GetInstance() ;
	/// Static method killing the instance.
	static void Kill() ;
	G4Material* GetMaterial(const G4String materialName);
	G4Material* GetMaterial(const G4String materialName, G4double concentration);
	G4Material* otherMaterials(const G4String materialName);
	G4Material* otherMaterials(const G4String materialName, G4double concentration);

private:

	// Constructor
	N2Material();

	//Destructor
	virtual ~N2Material();

	// Singleton material instance.
	static N2Material* instance;

	/// Collection of materials.
	MaterialsCollection		fMaterialsCollection ;


};

#endif // N2Material_hh
