/*
 * Arcade.c
 *
 *  Created on: 26 jun. 2022
 *      Author: Alí Ansidey
 */


#include "Arcade.h"


Arcade* Arcade_new(){
	Arcade *arcadeNuevo;
	arcadeNuevo = (Arcade*) malloc(sizeof(Arcade));
	return arcadeNuevo;
}

Arcade* Arcade_newParametros(char* idArcade, char* nacionalidad, char* tipoSonid,char* cantJug,char* canMaxFichas,char* idSalon, char* idJuego){
	Arcade* arcadeNuevo = Arcade_new();
	int idArcadeF;
	char nacionalidadF[50];
	int tipoSonidoF;
	int cantidadJugadoresF;
	int canMaxFichasF;
	int idSalonF;
	int idJuegoF;

	//parseo el id si viene tipo String
	idArcadeF = atoi(idArcade);
	strcpy(nacionalidadF,nacionalidad);
	tipoSonidoF = atoi(tipoSonid);
	cantidadJugadoresF = atoi(cantJug);
	canMaxFichasF = atoi(canMaxFichas);
	idSalonF = atoi(idSalon);
	idJuegoF = atoi(idJuego);

	//Si los parametros son correctos, se setean los datos
	if(nacionalidad!=NULL && idArcadeF >0 && (tipoSonidoF >0 ||tipoSonidoF <3) && (canMaxFichasF >0 ||canMaxFichasF <5) && idSalonF > 0 && idJuegoF >0 ){
		Arcade_setId(arcadeNuevo,idArcadeF);
		Arcade_setNacionalidad(arcadeNuevo,nacionalidadF);
		Arcade_setTipoSonido(arcadeNuevo,tipoSonidoF);
		Arcade_setCantidadJugadores(arcadeNuevo,cantidadJugadoresF);
		Arcade_setCantidadMaxFichas(arcadeNuevo,canMaxFichasF);
		Arcade_setIdSalon(arcadeNuevo,idSalonF);
		Arcade_setIdJuego(arcadeNuevo,idJuegoF);
	}
	return arcadeNuevo;
}

int Arcade_setId(Arcade* this,int id){
	int retorno = -1;
	if(this !=NULL && id >0){
		this->idArcade = id;
		retorno = 0;
	}
	return retorno;
}

int Arcade_getId(Arcade* this,int* id){
	int retorno = -1;
	if(this !=NULL && id !=NULL){
		*id = this->idArcade;
		retorno = 0;
	}
	return retorno;
}

int Arcade_setNacionalidad(Arcade* this,char* nacionalidad){
	int retorno = -1;
	if(this != NULL && nacionalidad != NULL){
		strcpy(this->nacionalidad,nacionalidad);
		retorno = 0;
	}
	return retorno;
}

int Arcade_getNacionalidad(Arcade* this,char* nacionalidad){
	int retorno = -1;
	if(this != NULL && nacionalidad != NULL){
		strcpy(nacionalidad,this->nacionalidad);
		retorno = 0;
	}
	return retorno;
}

int Arcade_setTipoSonido(Arcade* this,int tipoSonido){
	int retorno = -1;
	if(this !=NULL && (tipoSonido >0 || tipoSonido <3)){
		this->tipoSonido = tipoSonido;
		retorno = 0;
	}
	return retorno;
}
int Arcade_getTipoSonido(Arcade* this,int* tipoSonido){
	int retorno = -1;
		if(this !=NULL && tipoSonido !=NULL){
			*tipoSonido = this->tipoSonido;
			retorno = 0;
		}
		return retorno;
}

int Arcade_setCantidadJugadores(Arcade* this,int cantidadJugadores){
	int retorno = -1;
	if(this !=NULL && (cantidadJugadores >0 || cantidadJugadores <5)){
		this->cantidadJugadores = cantidadJugadores;
		retorno = 0;
	}
	return retorno;
}

int Arcade_getCantidadJugadores(Arcade* this,int* cantidadJugadores){
	int retorno = -1;
	if(this !=NULL && cantidadJugadores !=NULL){
		*cantidadJugadores = this->cantidadJugadores;
		retorno = 0;
	}
	return retorno;
}

int Arcade_setCantidadMaxFichas(Arcade* this,int canMaxFichas){
	int retorno = -1;
	if(this !=NULL && canMaxFichas >0 ){
		this->canMaxFichas = canMaxFichas;
		retorno = 0;
	}
	return retorno;
}

int Arcade_getCantidadMaxFichas(Arcade* this,int* canMaxFichas){
	int retorno = -1;
	if(this !=NULL && canMaxFichas !=NULL){
		*canMaxFichas = this->canMaxFichas;
		retorno = 0;
	}
	return retorno;
}


int Arcade_setIdSalon(Arcade* this,int idSalon){
	int retorno = -1;
	if(this !=NULL && idSalon >0 ){
		this->idSalon = idSalon;
		retorno = 0;
	}
	return retorno;
}

int Arcade_getIdSalon(Arcade* this,int* idSalon){
	int retorno = -1;
	if(this !=NULL && idSalon !=NULL){
		*idSalon = this->idSalon;
		retorno = 0;
	}
	return retorno;
}

int Arcade_setIdJuego(Arcade* this,int idJuego){
	int retorno = -1;
	if(this !=NULL && idJuego >0 ){
		this->idJuego = idJuego;
		retorno = 0;
	}
	return retorno;
}


int Arcade_getIdJuego(Arcade* this,int* idJuego){
	int retorno = -1;
	if(this !=NULL && idJuego !=NULL){
		*idJuego = this->idJuego;
		retorno = 0;
	}
	return retorno;
}

int Arcade_searchById(LinkedList* listaArcades, int id){
	   int retorno = -1;
	    int i;
	    int idArcade;
	    Arcade* pArcade;
	    int len = ll_len(listaArcades);
	    for(i= 0; i < len; i++){
	    	pArcade = ll_get(listaArcades, i);
	    	if(Arcade_getId(pArcade,&idArcade) == 0 && (idArcade == id)){
	    		retorno = i;
	    		break;
	    	}
	    }
	    return retorno;
}

int mostrarArcade(Arcade* this){
	int retorno = -1;
	if(this !=NULL){
		char nacionalidad[50];
		int idArcade,tipoSonido, cantidadJugadores, canMaxFichas,idSalon,idJuego;

		//obtengo todos los datos del Arcade
		Arcade_getId(this,&idArcade);
		Arcade_getNacionalidad(this,nacionalidad);
		Arcade_getTipoSonido(this,&tipoSonido);
		Arcade_getCantidadJugadores(this,&cantidadJugadores);
		Arcade_getCantidadMaxFichas(this,&canMaxFichas);
		Arcade_getIdSalon(this,&idSalon);
		Arcade_getIdJuego(this,&idJuego);

		printf("id: %d - nacionalidad: %s - tipo de sonido: %d - Cantidad de Jugadores: %d - Cantidad Max fichas: %d - id del salon: %d - "
				"id del juego: %d\n",idArcade,nacionalidad,tipoSonido,cantidadJugadores,canMaxFichas,idSalon,idJuego);
		retorno = 0;
	}
	return retorno;
}
