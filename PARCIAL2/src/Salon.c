/*
 * Salon.c
 *
 *  Created on: 24 jun. 2022
 *      Author: Alí Ansidey
 */

#include "Salon.h"
#include "Arcade.h"



Salon* Salon_new(){
	Salon *salonNuevo;
	salonNuevo = (Salon*) malloc(sizeof(Salon));
	return salonNuevo;
}

Salon*  Salon_newParametros(char* id, char* nombre, char* direccion, char* tipoSalon){
	Salon* salonNuevo = Salon_new();
	char nombreSalon[50];
	char direccionSalon[50];
	int tipoSalonFun, idFun;

	//parseo el id si viene tipo string
	idFun = atoi(id);
	strcpy(nombreSalon,nombre);
	strcpy(direccionSalon,direccion);
	tipoSalonFun = atoi(tipoSalon);

	if(nombreSalon !=NULL && direccionSalon !=NULL && idFun >0  && (tipoSalonFun >0 || tipoSalonFun <3)){
		Salon_setId(salonNuevo,idFun);
		Salon_setNombre(salonNuevo,nombreSalon);
		Salon_setDireccion(salonNuevo,direccionSalon);
		Salon_setTipoSalon(salonNuevo,tipoSalonFun);
	}

	return salonNuevo;
}



int Salon_setId(Salon* this,int id){
	int retorno = -1;
	if(this !=NULL && id >0){
		this->id = id;
		retorno = 0;
	}

	return retorno;
}

int Salon_getId(Salon* this,int* id){
	int retorno = -1;
	if(this !=NULL && id !=NULL){
		*id = this->id;
		retorno = 0;
	}
	return retorno;
}


int Salon_setNombre(Salon* this,char* nombre){
	int retorno = -1;
	if(this != NULL && nombre != NULL){
		strcpy(this->nombre,nombre);
		retorno = 0;
	}
	return retorno;
}

int Salon_getNombre(Salon* this,char* nombre){
	int retorno = -1;
	if(this != NULL && nombre != NULL){
		strcpy(nombre,this->nombre);
		retorno = 0;
	}
	return retorno;
}

int Salon_setDireccion(Salon* this,char* direccion){
	int retorno = -1;
	if(this != NULL && direccion != NULL){
		strcpy(this->direccion,direccion);
		retorno = 0;
	}
	return retorno;
}

int Salon_getDireccion(Salon* this,char* direccion){
	int retorno = -1;
	if(this != NULL && direccion != NULL){
		strcpy(direccion,this->direccion);
		retorno = 0;
	}
	return retorno;
}

int Salon_setTipoSalon(Salon* this,int tipoSalon){
	int retorno = -1;
	if(this != NULL && tipoSalon > -1 ){
		this->tipoSalon = tipoSalon;
		retorno = 0;
}
	return retorno;
}

int Salon_getTipoSalon(Salon* this,int* tipoSalon){
	int retorno = -1;
	if(this !=NULL && tipoSalon !=NULL){
		*tipoSalon = this->tipoSalon;
		retorno = 0;
	}
	return retorno;
}

int Salon_searchById(LinkedList* listaSalones, int id){
    int retorno = -1;
    int i;
    int idSalon;
    Salon* pSalon;
    int len = ll_len(listaSalones);
    for(i= 0; i < len; i++){
    	pSalon = ll_get(listaSalones, i);
    	if(Salon_getId(pSalon,&idSalon) == 0 && (idSalon == id)){
    		retorno = i;
    		break;
    	}
    }
    return retorno;
}


int mostrarSalon(Salon* this){
	int retorno = -1;
	if(this !=NULL){
		int id,tipoSalon;
		char nombre[50];
		char direccion[50];
		char tipoSalonLiteral[10];
		//obtengo todos los datos del salon
		Salon_getId(this,&id);
		Salon_getNombre(this,nombre);
		Salon_getDireccion(this,direccion);
		Salon_getTipoSalon(this,&tipoSalon);
		//paso como literal el tipo de salon
		if(tipoSalon == SHOPPING){
			strcpy(tipoSalonLiteral,"SHOPPING");
		}
		else{
			strcpy(tipoSalonLiteral,"LOCAL");
		}
		printf("id: %d - nombre: %s - direccion: %s - tipoSalon: %s\n",id,nombre,direccion,tipoSalonLiteral);
		retorno = 0;
	}
	return retorno;
}


