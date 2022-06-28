/*
 * Controller.h
 *
 *  Created on: 25 jun. 2022
 *      Author: Alí Ansidey
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include "limits.h"
#include "unistd.h"
#include "parser.h"
#include "menu.h"

int controller_salonLoadFromText(char* path , LinkedList* pListaSalones);

int controller_arcadeLoadFromText(char* path , LinkedList* pListaArcades);

int controller_juegoLoadFromText(char* path , LinkedList* pListaJuegos);

int obtainIdSalon(LinkedList* pListaSalones);

int obtainIdArcade(LinkedList* listaArcades);

int obtainIdJuego(LinkedList* listaJuegos);

int listarSalones(LinkedList* pListaSalones);

int listarArcades(LinkedList* pListaArcades);

int listarJuegos(LinkedList* pListaJuegos);

int eliminarSalon(LinkedList* pListaSalones,LinkedList* pListaArcades,LinkedList* pListaJuegos, int id);

int eliminarArcade(LinkedList* pListaArcades,LinkedList* pListaJuegos, int id);

int eliminarArcadeConIndexSalon(LinkedList* pListaArcades,LinkedList* pListaJuegos, int idSalon);

int eliminarJuego(LinkedList* pListaJuegos, int id);

int altaSalon(LinkedList* pListaSalones);

int incorporarArcade(LinkedList* pListaArcades);

int agregarJuego(LinkedList* pListaJuegos);

int modificarArcade(LinkedList* pListaArcades,LinkedList* pListaJuegos, int idArcade);

int controller_salonSaveAsText(char* path , LinkedList* pListaSalones);

int controller_arcadeSaveAsText(char* path , LinkedList* pListaArcades);

int controller_juegoSaveAsText(char* path , LinkedList* pListaJuegos);

#endif /* CONTROLLER_H_ */
