/*
 * informes.h
 *
 *  Created on: 28 jun. 2022
 *      Author: Al� Ansidey
 */

#ifndef INFORMES_H_
#define INFORMES_H_

#include "Controller.h"

int listarSalonesMayoresAcuatroArcades(LinkedList* pListaSalones, LinkedList* pListaArcades);

int listarArcadeMayorDosJugadores(LinkedList* pListaSalones, LinkedList* pListaArcades, LinkedList* pListaJuegos);

int listarInfomacionSalon(LinkedList* pListaSalones,int id);

int listarSalonesCompletos(LinkedList* pListaSalones, LinkedList* pListaArcades, LinkedList* pListaJuegos);

#endif /* INFORMES_H_ */
