/*
 * Juego.c
 *
 *  Created on: 27 jun. 2022
 *      Author: Alí Ansidey
 */

#include "Juego.h"

Juego* Juego_new(){
	Juego *juegoNuevo;
	juegoNuevo = (Juego*)malloc(sizeof(Juego));
	return juegoNuevo;
}


Juego* Juego_newParametros(char* idJuego, char* nombreJuego, char* empresa,char* genero){
	Juego* juegoNuevo = Juego_new();
	int idJuegoF;
	char nombreJuegoF[50];
	char empresaF[50];
	int generoF;

	//parseo el id y el genero del juego
	idJuegoF = atoi(idJuego);
	strcpy(nombreJuegoF,nombreJuego);
	strcpy(empresaF,empresa);
	generoF = atoi(genero);

	if(nombreJuegoF != NULL && empresaF != NULL && idJuegoF >0 && (generoF >0 || generoF < 5)){
		//seteo los datos
		Juego_setId(juegoNuevo,idJuegoF);
		Juego_setNombre(juegoNuevo,nombreJuegoF);
		Juego_setEmpresa(juegoNuevo,empresaF);
		Juego_setGenero(juegoNuevo,generoF);

	}
	return juegoNuevo;
}

int Juego_setId(Juego* this,int id){
	int retorno =-1;
	if(this != NULL){
		this->idJuego = id;
		retorno = 0;
	}
	return retorno;
}

int Juego_getId(Juego* this,int* id){
	int retorno =-1;
	if(this != NULL && id != NULL){
		*id = this->idJuego;
		retorno = 0;
	}

	return retorno;
}

int Juego_setNombre(Juego* this,char* nombreJuego){
	int retorno =-1;
	if(this !=NULL && nombreJuego != NULL){
		strcpy(this->nombreJuego,nombreJuego);
		retorno = 0;
	}
	return retorno;
}

int Juego_getNombre(Juego* this,char* nombreJuego){
	int retorno =-1;
	if(this != NULL && nombreJuego != NULL){
		strcpy(nombreJuego,this->nombreJuego);
		retorno = 0;
	}
	return retorno;
}

int Juego_setEmpresa(Juego* this,char* empresa){
	int retorno =-1;
	if(this !=NULL && empresa != NULL){
		strcpy(this->empresa,empresa);
		retorno = 0;
	}
	return retorno;
}

int Juego_getEmpresa(Juego* this,char* empresa){
	int retorno =-1;
	if(this != NULL && empresa != NULL){
		strcpy(empresa,this->empresa);
		retorno = 0;
	}
	return retorno;
}

int Juego_setGenero(Juego* this,int genero){
	int retorno =-1;
	if(this != NULL && (genero >0 || genero <5)){
		this->genero = genero;
		retorno = 0;
	}
	return retorno;
}

int Juego_getGenero(Juego* this,int* genero){
	int retorno =-1;
	if(this != NULL && genero != NULL){
		*genero = this->genero;
		retorno = 0;
	}
	return retorno;
}


int Juego_searchById(LinkedList* listaJuegos, int id){
	   int retorno = -1;
	    int i;
	    int idJuego;
	    Juego* pJuego;
	    int len = ll_len(listaJuegos);
	    for(i= 0; i < len; i++){
	    	pJuego = ll_get(listaJuegos, i);
	    	if(Juego_getId(pJuego,&idJuego) == 0 && (idJuego == id)){
	    		retorno = i;
	    		break;
	    	}
	    }
	    return retorno;
}

int mostrarJuego(Juego* this){
	int retorno = -1;
	if(this != NULL){
		int id, genero;
		char nombreJuego[50];
		char empresa[50];

		//obtengo los datos del juego
		Juego_getId(this,&id);
		Juego_getNombre(this,nombreJuego);
		Juego_getEmpresa(this,empresa);
		Juego_getGenero(this,&genero);
		printf("id: %d - nombre: %s - empresa: %s - genero: %d\n",id,nombreJuego,empresa,genero);
		retorno = 0;
	}
	return retorno;

}
