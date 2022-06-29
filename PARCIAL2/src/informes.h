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

int listarArcadesDelSalonInforme(LinkedList* pListaSalones, LinkedList* pListaArcades, int id);

int listarSalonesMasArcades(LinkedList* pListaSalones, LinkedList* pListaArcades);

int filtrarLinkedList(LinkedList* this, int (*pFunc)(void*,char*), char* filtro);

int listarArcadesMonoPlat(LinkedList* plistaArcades, LinkedList* plistaJuegos);

#endif /* INFORMES_H_ */
