/*
 * Arcade.h
 *
 *  Created on: 26 jun. 2022
 *      Author: Alí Ansidey
 */

#ifndef ARCADE_H_
#define ARCADE_H_

#include "inputs.h"
#include "LinkedList.h"

#define MONO 1
#define STEREO 2
#define CANT_MAX_JUG 4

typedef struct
{
	int idArcade;
	char nacionalidad[50];
	int tipoSonido;
	int cantidadJugadores;
	int canMaxFichas;
	int idSalon; //FK de la estructura Salon
	int idJuego; //FK de la estructura Juego

}Arcade;

Arcade* Arcade_new();


Arcade* Arcade_newParametros(char* idArcade, char* nacionalidad, char* tipoSonid,char* cantJug,char* canMaxFichas,char* idSalon, char* idJuego);

int Arcade_setId(Arcade* this,int id);
int Arcade_getId(Arcade* this,int* id);

int Arcade_setNacionalidad(Arcade* this,char* nacionalidad);
int Arcade_getNacionalidad(Arcade* this,char* nacionalidad);

int Arcade_setTipoSonido(Arcade* this,int tipoSonido);
int Arcade_getTipoSonido(Arcade* this,int* tipoSonido);

int Arcade_setCantidadJugadores(Arcade* this,int cantidadJugadores);
int Arcade_getCantidadJugadores(Arcade* this,int* cantidadJugadores);

int Arcade_setCantidadMaxFichas(Arcade* this,int canMaxFichas);
int Arcade_getCantidadMaxFichas(Arcade* this,int* canMaxFichas);

int Arcade_setIdSalon(Arcade* this,int idSalon);
int Arcade_getIdSalon(Arcade* this,int* idSalon);

int Arcade_setIdJuego(Arcade* this,int idJuego);
int Arcade_getIdJuego(Arcade* this,int* idJuego);

int Arcade_searchById(LinkedList* listaArcades, int id);

int mostrarArcade(Arcade* this);

#endif /* ARCADE_H_ */
