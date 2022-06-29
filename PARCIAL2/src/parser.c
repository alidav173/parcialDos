/*
 * parser.c
 *
 *  Created on: 25 jun. 2022
 *      Author: Al� Ansidey
 */

#include "parser.h"

/** \brief Parsea los datos los datos de los salones desde el archivo salon.csv (modo texto).
 *
 * \param path char*
 * \param plistaSalones LinkedList*
 * \return int
 *
 */
int parser_SalonFromText(FILE* pFile , LinkedList* plistaSalones)
{
		Salon* pSalon;
		char id[5];
		char nombre[50];
		char direccion[50];
		char tipoSalon[2];
		int primerElemento = 1;
		int retorno  = -1;

		if(pFile !=NULL){
			while(!feof(pFile)){
				  if(primerElemento){ //Leo la primera linea del archivo (header)
					fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,direccion,tipoSalon);
					primerElemento = 0;
					}

		         //leo las siguientes lineas del archivo csv
					fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,direccion,tipoSalon);
					pSalon = Salon_newParametros(id,nombre,direccion,tipoSalon);
					if(pSalon !=NULL){
					ll_add(plistaSalones,(Salon*)pSalon);
					retorno = 0;
					}
	     	}

		}
	    return retorno;
}



/** \brief Parsea los datos los datos de los arcades desde el archivo arcade.csv (modo texto).
 *
 * \param path char*
 * \param plistaArcades LinkedList*
 * \return int
 *
*/
int parser_ArcadeFromText(FILE* pFile , LinkedList* plistaArcades)
{
		Salon* pArcade;
		char idArcade[5];
		char nacionalidad[50];
		char tipoSonido[2];
		char cantidadJugadores[2];
		char canMaxFichas[2];
		char idSalon[5];
		char idJuego[5];
		int primerElemento = 1;
		int retorno  = -1;

		if(pFile !=NULL){
			while(!feof(pFile)){
				  if(primerElemento){ //Leo la primera linea del archivo (header)
					fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",idArcade,nacionalidad,tipoSonido,cantidadJugadores,canMaxFichas,idSalon,idJuego);
					primerElemento = 0;
					}

		         //leo las siguientes lineas del archivo csv
				  fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",idArcade,nacionalidad,tipoSonido,cantidadJugadores,canMaxFichas,idSalon,idJuego);
				  pArcade = Arcade_newParametros(idArcade,nacionalidad,tipoSonido,cantidadJugadores,canMaxFichas,idSalon,idJuego);
					if(pArcade !=NULL){
					ll_add(plistaArcades,(Arcade*)pArcade);
					retorno = 0;
					}
	     	}

		}
	    return retorno;
}


/** \brief Parsea los datos los datos de los juegos desde el archivo juego.csv (modo texto).
 *
 * \param path char*
 * \param plistaJuegos LinkedList*
 * \return int
 *
 */
int parser_JuegoFromText(FILE* pFile , LinkedList* plistaJuegos)
{
		Juego* pJuego;
		char idJuego[5];
		char nombreJuego[50];
		char empresa[50];
		char genero[2];
		int primerElemento = 1;
		int retorno  = -1;

		if(pFile !=NULL){
			while(!feof(pFile)){
				  if(primerElemento){ //Leo la primera linea del archivo (header)
					fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",idJuego,nombreJuego,empresa,genero);
					primerElemento = 0;
					}

		         //leo las siguientes lineas del archivo csv
					fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",idJuego,nombreJuego,empresa,genero);
					pJuego = Juego_newParametros(idJuego,nombreJuego,empresa,genero);
					if(pJuego !=NULL){
					ll_add(plistaJuegos,(Juego*)pJuego);
					retorno = 0;
					}
	     	}

		}
	    return retorno;
}

/*
int parser_SalonFromBinary(FILE* pFile, LinkedList listaSalones){
	int retorno = -1;
	Salon* pSalon;
	if(pFile != NULL && listaSalones != NULL){
		while(!feof(pFile)){ //mientras no sea el final del archivo, entro al bucle
			pSalon = Salon_new();
		}

	}
}
*/
