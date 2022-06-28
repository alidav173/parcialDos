/*
 * informes.c
 *
 *  Created on: 28 jun. 2022
 *      Author: Al� Ansidey
 */

#include "informes.h"


int listarSalonesMayoresAcuatroArcades(LinkedList* pListaSalones, LinkedList* pListaArcades){
	int retorno = -1;
	int contador = 0;
	int idSalon = 1;
	int lenArcade,lenSalon,i,j;
	if(pListaSalones != NULL && pListaArcades != NULL){//compruebo que no sea null
		lenArcade = ll_len(pListaArcades);
		lenSalon = ll_len(pListaSalones);
		for(i =0; i<lenSalon;i++){
			for(j =0; j< lenArcade; j++){
				Arcade* arcadeBuscado = Arcade_new();
				arcadeBuscado = (Arcade*)ll_get(pListaArcades,j);
					if(idSalon == arcadeBuscado->idSalon){//compruebo que el id sea igual al id en el arcade
						contador++;
					}
			}
			if(contador >4){
			Salon* salonAimprimir = Salon_new();
			salonAimprimir = (Salon*)ll_get(pListaSalones,i);
			mostrarSalon(salonAimprimir);
			contador=0;
			free(salonAimprimir);
			retorno =0;
		}
			idSalon++;
	}
  }
	return retorno;
}

int listarArcadeMayorDosJugadores(LinkedList* pListaSalones, LinkedList* pListaArcades, LinkedList* pListaJuegos){
	int retorno =-1;
	if(pListaArcades != NULL && pListaSalones != NULL && pListaJuegos !=NULL ){
		Arcade* arcadeBuscado = Arcade_new();
		int lenArcade = ll_len(pListaArcades);
		printf("Arcades para mas de 2 jugadores:\n");
		for(int i =0; i< lenArcade;i++){
			arcadeBuscado = (Arcade*) ll_get(pListaArcades,i);
			if(arcadeBuscado->cantidadJugadores >2){
				int idArcade,idJuego,idSalon,indexJuego,indexSalon,cantJugadores,generoJuego;
				char nombreJuego[50];
				char nombreSalon[50];
				idJuego = arcadeBuscado->idJuego;
				idSalon = arcadeBuscado->idSalon;
				Salon* salonBuscado = Salon_new();
				Juego* juegoBuscado = Juego_new();
				//busco los indices donde estan ubicados los id del salon y el juego
				indexJuego = Juego_searchById(pListaJuegos, idJuego);
				indexSalon = Salon_searchById(pListaSalones, idSalon);
				salonBuscado =(Salon*) ll_get(pListaSalones,indexSalon);
				juegoBuscado =(Juego*) ll_get(pListaJuegos,indexJuego);
				//ahora con los gets obtengo los datos solicitados
				Arcade_getId(arcadeBuscado,&idArcade);
				Arcade_getCantidadJugadores(arcadeBuscado,&cantJugadores);
				Juego_getNombre(juegoBuscado,nombreJuego);
				Juego_getGenero(juegoBuscado,&generoJuego);
				Salon_getNombre(salonBuscado,nombreSalon);
				printf("id: %d - Jugadores: %d - nombre del juego: %s - genero: %d - salon: %s\n",idArcade,cantJugadores,nombreJuego,generoJuego,nombreSalon);
				retorno = 0;
			}
		}
	}
	return retorno;
}

int listarInfomacionSalon(LinkedList* pListaSalones,int id){
	int retorno = -1;
	if(pListaSalones != NULL && id > 0){
		//busco el indice del elemento que busco
		Salon* salonBuscado = Salon_new();
		int index = Salon_searchById(pListaSalones,id);
		salonBuscado = (Salon*)ll_get(pListaSalones,index);
		mostrarSalon(salonBuscado);
		retorno =0;
	}
	return retorno;
}

int listarSalonesCompletos(LinkedList* pListaSalones, LinkedList* pListaArcades, LinkedList* pListaJuegos){
	int retorno = -1;
	int lenSalon,lenArcade, lenJuego, i, j,idJuego, genero;
	int contadorPlat =0;
	int contadorLab =0;
	int contadorAven =0;
	int idSalon = 1;
	if(pListaArcades != NULL && pListaSalones != NULL && pListaJuegos !=NULL ){
		lenArcade = ll_len(pListaArcades);
		lenSalon = ll_len(pListaSalones);
		for(i =0; i<lenSalon;i++){
			for(j =0; j< lenArcade; j++){
				Arcade* arcadeBuscado = Arcade_new();
				arcadeBuscado = (Arcade*)ll_get(pListaArcades,j);
					if(idSalon == arcadeBuscado->idSalon){//compruebo que el id sea igual al id en el arcade
						Arcade_getIdJuego(arcadeBuscado,&idJuego);
						Juego* juegoBuscado = Juego_new();
						int indexJuego = Juego_searchById(pListaJuegos, idJuego);
						juegoBuscado = (Juego*)ll_get(pListaJuegos,indexJuego);
						Juego_getGenero(juegoBuscado,&genero);

						switch(genero){
						case 1:
							contadorPlat++;
							break;
						case 2:
							contadorLab++;
							break;
						case 3:
							contadorAven++;
							break;
						}
						//Con los contadores busco alguno que cumpla la condición y lo muestro
						if(contadorPlat>= 4 && contadorLab>=3 && contadorAven >=5){
							Salon* salonAmostrar = Salon_new();
							int indexSalon = Salon_searchById(pListaSalones,idSalon);
							salonAmostrar = (Salon*)ll_get(pListaSalones,indexSalon);
							mostrarSalon(salonAmostrar);
							retorno = 0;
						}

					}
			}
			idSalon++;
	}
	}
	return retorno;
}


