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

#ifndef N2EventAction_h
#define N2EventAction_h 1

// Geant4 Headers
#include "G4UserEventAction.hh"
#include "globals.hh"
#include "G4Event.hh"
#include "G4SystemOfUnits.hh"
#include "G4THitsMap.hh"

class N2RunAction;

using namespace std;

/// Event action class
///

class N2EventAction : public G4UserEventAction
{
public:
	N2EventAction();
	virtual ~N2EventAction();

	virtual void BeginOfEventAction(const G4Event* event);
	virtual void EndOfEventAction(const G4Event* event);

};

#endif // N2EventAction_h


