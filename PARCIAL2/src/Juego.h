/*
 * Juego.h
 *
 *  Created on: 27 jun. 2022
 *      Author: Alí Ansidey
 */

#ifndef JUEGO_H_
#define JUEGO_H_

#include "inputs.h"
#include "LinkedList.h"

#define PLATAFORMA 1
#define LABERINTO 2
#define AVENTURA 3
#define OTRO 4

typedef struct
{
	int idJuego;
	char nombreJuego[50];
	char empresa[50];
	int genero;
}Juego;

Juego* Juego_new();


Juego* Juego_newParametros(char* idJuego, char* nombreJuego, char* empresa,char* genero);

int Juego_setId(Juego* this,int id);
int Juego_getId(Juego* this,int* id);

int Juego_setNombre(Juego* this,char* nombreJuego);
int Juego_getNombre(Juego* this,char* nombreJuego);

int Juego_setEmpresa(Juego* this,char* empresa);
int Juego_getEmpresa(Juego* this,char* empresa);

int Juego_setGenero(Juego* this,int genero);
int Juego_getGenero(Juego* this,int* genero);

int Juego_searchById(LinkedList* listaJuegos, int id);

int mostrarJuego(Juego* this);

#endif /* JUEGO_H_ */
