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
#include "G4RunManager.hh"
#include "G4EventManager.hh"
#include "G4Run.hh"
#include "G4UnitsTable.hh"

// N2 Headers
#include "N2EventAction.hh"
#include "N2Analysis.hh"

N2EventAction::N2EventAction():G4UserEventAction()
{}

N2EventAction::~N2EventAction()
{}

void N2EventAction::BeginOfEventAction(const G4Event* anEvent)
{

	G4int nEvents = G4RunManager::GetRunManager()->GetCurrentRun()->GetNumberOfEventToBeProcessed() ;
	if(nEvents>10){
		G4int 	fraction 	= G4int(nEvents/100) ;
		if(anEvent->GetEventID()%fraction == 0)
			G4cout<<"("<<(anEvent->GetEventID()/(nEvents*1.0)*100)<<" %)"<<G4endl ;

	}else {
		G4int 	fraction 	= G4int(nEvents/1) ;
		if(anEvent->GetEventID()%fraction == 0)
			G4cout<<"("<<(anEvent->GetEventID()/(nEvents*1.0)*100)<<" %)"<<G4endl ;
	}

}

void N2EventAction::EndOfEventAction(const G4Event* /*anEvent*/)
{}





