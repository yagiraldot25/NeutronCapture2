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

#ifndef N2DetectorConstruction_h
#define N2DetectorConstruction_h 1

// N2 Headers
#include "G4VUserDetectorConstruction.hh"
#include "globals.hh"

#include "N2DetectorMessenger.hh"

/// Detector construction class to define materials and geometry.

class N2DetectorConstruction : public G4VUserDetectorConstruction
{
public:
	N2DetectorConstruction();
	virtual ~N2DetectorConstruction();

	virtual G4VPhysicalVolume* Construct();
	virtual void ConstructSDandField();

    void SetConcentration (G4double aConcentration);
    inline G4double GetConcentration () { return fConcentration;};

private:
	void SetupGeometry(G4LogicalVolume* motherVolume);

	G4VPhysicalVolume* 	fPhantom_phys;
	G4VPhysicalVolume* 	fTarget_phys;
	G4double		 	fConcentration;
	G4UImessenger* 	 	fN2DetectorMessenger ;
};

#endif // N2DetectorConstruction_h
