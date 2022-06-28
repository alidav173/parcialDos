/*
 * Salon.h
 *
 *  Created on: 24 jun. 2022
 *      Author: Alí Ansidey
 */

#ifndef SALON_H_
#define SALON_H_

#include "inputs.h"
#include "LinkedList.h"

#define SHOPPING 1
#define LOCAL 2

typedef struct
{
	int id;
	char nombre[50];
	char direccion[50];
	int tipoSalon;

}Salon;



Salon* Salon_new();

Salon* Salon_newParametros(char* id, char* nombre, char* direccion, char* tipoSalon);


int Salon_setId(Salon* this,int id);
int Salon_getId(Salon* this,int* id);

int Salon_setNombre(Salon* this,char* nombre);
int Salon_getNombre(Salon* this,char* nombre);

int Salon_setDireccion(Salon* this,char* direccion);
int Salon_getDireccion(Salon* this,char* direccion);

int Salon_setTipoSalon(Salon* this,int tipoSalon);
int Salon_getTipoSalon(Salon* this,int* tipoSalon);

int Salon_searchById(LinkedList* listaSalones, int id);

int mostrarSalon(Salon* this);


#endif /* SALON_H_ */
