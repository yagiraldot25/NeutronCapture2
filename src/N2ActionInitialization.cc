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

#include "N2ActionInitialization.hh"
#include "N2PrimaryGeneratorAction.hh"
#include "N2EventAction.hh"

N2ActionInitialization::N2ActionInitialization():G4VUserActionInitialization()
{}

N2ActionInitialization::~N2ActionInitialization()
{}

void N2ActionInitialization::BuildForMaster() const
{}

void N2ActionInitialization::Build() const
{

  SetUserAction(new N2PrimaryGeneratorAction);
  SetUserAction(new N2EventAction);

}
