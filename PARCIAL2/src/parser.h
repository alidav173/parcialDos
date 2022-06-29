/*
 * parser.h
 *
 *  Created on: 25 jun. 2022
 *      Author: Al� Ansidey
 */

#ifndef PARSER_H_
#define PARSER_H_

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Salon.h"
#include "Arcade.h"
#include "Juego.h"

int parser_SalonFromText(FILE* pFile , LinkedList* listaSalones);

int parser_ArcadeFromText(FILE* pFile , LinkedList* listaArcades);

int parser_JuegoFromText(FILE* pFile , LinkedList* listaJuegos);

/*
int parser_SalonFromBinary(FILE* pFile, LinkedList listaSalones);

int parser_ArcadeFromBinary(FILE* pFile , LinkedList* listaArcades);

int parser_JuegoFromBinary(FILE* pFile , LinkedList* listaJuegos);*/

#endif /* PARSER_H_ */
