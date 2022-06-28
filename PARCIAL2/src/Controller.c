/*
 * Controller.c
 *
 *  Created on: 25 jun. 2022
 *      Author: Alí Ansidey
 */

#include "Controller.h"


/** \brief Carga los datos de los salones desde el archivo salon.csv (modo texto).
 *
 * \param path char*
 * \param pListaSalones LinkedList*
 * \return int
 *
 */
int controller_salonLoadFromText(char* path , LinkedList* pListaSalones)
{
	int retorno = -1;

	FILE* pArchivo;

	if(access(path,F_OK)==0){
	pArchivo = fopen(path,"r");
	parser_SalonFromText(pArchivo,pListaSalones);
	retorno = 0;
	}
	else{
		pArchivo =fopen(path,"w");
		retorno = 0;
	}
	fclose(pArchivo);
    return retorno;
}


/**
 * @brief  genera un id de salon nuevo
 *
 * @return	Retorna un id si pudo, sino 0.
 */
int obtainIdSalon(LinkedList* listaSalones){
	int id = 0;

	if(listaSalones != NULL){
		Salon* lastElement = Salon_new();
		int len = ll_len(listaSalones);
		lastElement = ll_get(listaSalones,len-1);
		if(lastElement != NULL){
			Salon_getId(lastElement,&id);
			id++;
		}
		else{
			 id = 1;
		}
	}
	return id;
}

/**
 * @brief  genera un id de arcade nuevo
 *
 * @return	Retorna un id si pudo, sino 0.
 */
int obtainIdArcade(LinkedList* listaArcades){
	int id = 0;

	if(listaArcades != NULL){
		Arcade* lastElement = Arcade_new();
		int len = ll_len(listaArcades);
		lastElement = ll_get(listaArcades,len-1);
		if(lastElement != NULL){
			Arcade_getId(lastElement,&id);
			id++;
		}
		else{
			 id = 1;
		}
	}
	return id;
}

/**
 * @brief  genera un id de juego nuevo
 *
 * @return	Retorna un id si pudo, sino 0.
 */
int obtainIdJuego(LinkedList* listaJuegos){
	int id = 0;

	if(listaJuegos != NULL){
		Juego* lastElement = Juego_new();
		int len = ll_len(listaJuegos);
		lastElement = ll_get(listaJuegos,len-1);
		if(lastElement != NULL){
			Juego_getId(lastElement,&id);
			id++;
		}
		else{
			 id = 1;
		}
	}
	return id;
}



/** \brief Carga los datos de los arcades desde el archivo arcade.csv (modo texto).
 *
 * \param path char*
 * \param pListaArcades LinkedList*
 * \return int
 *
 */
int controller_arcadeLoadFromText(char* path , LinkedList* pListaArcades)
{
	int retorno = -1;

	FILE* pArchivo;

	if(access(path,F_OK)==0){
	pArchivo = fopen(path,"r");
	parser_ArcadeFromText(pArchivo,pListaArcades);
	retorno = 0;
	}
	else{
		pArchivo =fopen(path,"w");
		retorno = 0;
	}
	fclose(pArchivo);
    return retorno;
}


/** \brief Carga los datos de los juegos desde el archivo juego.csv (modo texto).
 *
 * \param path char*
 * \param pListaJuegos LinkedList*
 * \return int
 *
 */
int controller_juegoLoadFromText(char* path , LinkedList* pListaJuegos)
{
	int retorno = -1;

	FILE* pArchivo;

	if(access(path,F_OK)==0){
	pArchivo = fopen(path,"r");
	parser_JuegoFromText(pArchivo,pListaJuegos);
	retorno = 0;
	}
	else{
		pArchivo =fopen(path,"w");
		retorno = 0;
	}
	fclose(pArchivo);
    return retorno;
}


int listarSalones(LinkedList* pListaSalones){
	int retorno = -1;
	int i;
	if(pListaSalones != NULL){
		Salon* pSalonNuevo;
		int len = ll_len(pListaSalones);
		for(i=0; i < len; i++){
		pSalonNuevo = ll_get(pListaSalones,i);
		mostrarSalon(pSalonNuevo);
		retorno = 0;
		}
	}
	return retorno;
}


int eliminarSalon(LinkedList* pListaSalones,LinkedList* pListaArcades,LinkedList* pListaJuegos, int id){
	int retorno = -1;
	char respuesta[3];
	int index, idbuscado;
	Salon* salonBuscado;
	if(pListaSalones != NULL){
		int len = ll_len(pListaSalones);
		for(index =0; index < len; index++){
			salonBuscado= ll_get(pListaSalones, index);
			Salon_getId(salonBuscado,&idbuscado);
			if(id == idbuscado){
					printf("Los arcades asociados a este salón son: \n");
				 listarArcadesDelSalon(pListaArcades,idbuscado);
				utn_getCadena(respuesta,3,"Esta seguro de eliminar: [si/no]\n","Reingrese respuesta [si/no]\n",3);
				if(strcmp(respuesta,"si")== 0){
					eliminarArcadeConIndexSalon(pListaArcades,pListaJuegos,idbuscado);//elimino el arcade con el id del salon
					ll_remove(pListaSalones,index);
					retorno = 0;
					break;
				}
		}
	}
	}
	return retorno;
}


int altaSalon(LinkedList* pListaSalones){
	int retorno = -1;
	char nombre[50];
	char direccion[50];
	int tipoSalon, id;
	Salon* salonNuevo;
	salonNuevo = Salon_new();

	if(pListaSalones != NULL){
		//seteo el id
		id = obtainIdSalon(pListaSalones);
		Salon_setId(salonNuevo,id);

		// seteo el nombre
		utn_getCadena(nombre,50,"Ingrese el nombre del salon:\n","Reingrese el nombre: \n",3);
		Salon_setNombre(salonNuevo,nombre);

		//seteo la direccion
		utn_getCadena(direccion,50,"Ingrese la direccion: \n","Reingrese la direccion: \n", 3);
		Salon_setDireccion(salonNuevo,direccion);

		//seteo el tipo de salon
		utn_getNumero(&tipoSalon,"Ingrese el tipo de salon [1- shopping/ 2- local]\n","Reigrese el tipo de salon [1- shopping/ 2- local] \n",1, 2, 3);
		Salon_setTipoSalon(salonNuevo,tipoSalon);

	    //agrego el salon a lista de salones
	    ll_add(pListaSalones,salonNuevo);
	    retorno = 0;

		}

	return retorno;
}


int listarArcades(LinkedList* pListaArcades){
	int retorno = -1;
	int i;
	if(pListaArcades != NULL){
		Arcade* pArcadeNuevo;
		int len = ll_len(pListaArcades);
		for(i=0; i < len; i++){
			pArcadeNuevo = ll_get(pListaArcades,i);
			mostrarArcade(pArcadeNuevo);
		retorno = 0;
		}
	}
	return retorno;
}


int listarArcadesDelSalon(LinkedList* pListaArcades, int idSalon){
	int retorno = -1;
	int i;
	if(pListaArcades != NULL){
		Arcade* pArcadeNuevo;
		int len = ll_len(pListaArcades);
		for(i=0; i < len; i++){
			pArcadeNuevo = ll_get(pListaArcades,i);
			if(pArcadeNuevo->idSalon == idSalon){
				mostrarArcade(pArcadeNuevo);
				retorno = 0;
			}
		}
	}
	return retorno;
}


int listarJuegos(LinkedList* pListaJuegos){
	int retorno = -1;
	int i;
	if(pListaJuegos != NULL){
		Juego* pJuegoNuevo;
		int len = ll_len(pListaJuegos);
		for(i=0; i < len; i++){
			pJuegoNuevo = ll_get(pListaJuegos,i);
			mostrarJuego(pJuegoNuevo);
		retorno = 0;
		}
	}
	return retorno;
}


int incorporarArcade(LinkedList* pListaArcades){
	int retorno = -1;
	char nacionalidad[50];
	int tipoSonido, idArcade,cantidadJugadores,canMaxFichas, idSalon, idJuego;
	Arcade* arcadeNuevo;
	arcadeNuevo = Arcade_new();

	if(pListaArcades != NULL){
		//seteo el id del arcade
		idArcade = obtainIdArcade(pListaArcades);
		Arcade_setId(arcadeNuevo,idArcade);

		// seteo la nacionalidad
		utn_getNombre(nacionalidad,50,"Ingrese la nacionalidad:\n","Reingrese la nacionalidad: \n", 3);
		Arcade_setNacionalidad(arcadeNuevo,nacionalidad);

		//seteo el tipo de sonido
		utn_getNumero(&tipoSonido,"Ingrese el tipo de sonido [1- MONO/ 2- STEREO]\n","Reigrese el tipo de salon [1- MONO/ 2- STEREO]\n",1, 2, 3);
		Arcade_setTipoSonido(arcadeNuevo,tipoSonido);

		//seteo la cantidad de jugadores
		utn_getNumero(&cantidadJugadores,"Ingrese la cantidad de jugadores [maximo 4]\n","Reingrese la cantidad de jugadores [maximo 4]\n",1, 4, 3);
		Arcade_setCantidadJugadores(arcadeNuevo,cantidadJugadores);

		//seteo la cantidad maxima de fichas
		utn_getNumero(&canMaxFichas,"Ingrese la cantidad maxima de fichas\n","Reingrese la cantidad:\n",1,INT_MAX, 3);
		Arcade_setCantidadMaxFichas(arcadeNuevo, canMaxFichas);

		//seteo el id del Salon
		utn_getNumero(&idSalon,"Ingrese el id del salon:\n","Reingrese el id del salon:\n",1,INT_MAX, 3);
		Arcade_setIdSalon(arcadeNuevo, idSalon);

		//seteo el id del Juego
		utn_getNumero(&idJuego,"Ingrese el id del juego:\n","Reingrese el id del juego:\n",1,INT_MAX, 3);
		Arcade_setIdJuego(arcadeNuevo, idJuego);

		//agrego el arcade a lista de arcades
	    ll_add(pListaArcades,arcadeNuevo);
	    retorno = 0;

		}

	return retorno;
}

int agregarJuego(LinkedList* pListaJuegos){
	int retorno = -1;
	char nombreJuego[50];
	char empresa[50];
	int idJuego,genero;
	Juego* juegoNuevo;
	juegoNuevo = Juego_new();

	if(pListaJuegos != NULL){
		//seteo el id del juego
		idJuego = obtainIdJuego(pListaJuegos);
		Juego_setId(juegoNuevo,idJuego);

		// seteo el nombre del juego
		utn_getCadena(nombreJuego,50,"Ingrese el nombre del juego:\n","Reingrese el nombre: \n", 3);
		Juego_setNombre(juegoNuevo,nombreJuego);

		//seteo la empresa de desarrollo
		utn_getCadena(empresa,50,"Ingrese la empresa: \n","Reingrese la empresa: \n", 3);
		Juego_setEmpresa(juegoNuevo,empresa);

		//seteo el genero
		utn_getNumero(&genero,"Ingrese el genero del juego [1 - PLATAFORMA, 2 - LABERINTO, 3 - AVENTURA, 4 -OTRO]\n",
				"Reingrese el genero: [1 - PLATAFORMA, 2 - LABERINTO, 3 - AVENTURA, 4 -OTRO]\n",1, 4, 3);
		Juego_setGenero(juegoNuevo,genero);

		//agrego el juego a lista de juegos
	    ll_add(pListaJuegos,juegoNuevo);
	    retorno = 0;

		}
	return retorno;
}



int modificarArcade(LinkedList* pListaArcades,LinkedList* pListaJuegos, int idArcade){
	int retorno = -1;
	int index, opcion, cantJugadores,idJuego;
	Arcade* arcadeBuscado;
	if(pListaArcades != NULL){
		index = Arcade_searchById(pListaArcades, idArcade);
		arcadeBuscado = ll_get(pListaArcades, index);
		if(arcadeBuscado != NULL){
			mostrarMenuTres();
			utn_getNumero(&opcion,"Ingrese la opcion:\n","Reingrese su opción\n",1,3,3);
			switch(opcion){
			case 1:
				utn_getNumero(&cantJugadores,"Ingrese la cantidad de jugadores: [maximo 4]:\n","Ingrese la cantidad de jugadores: [maximo 4]:\n",1,4,3);
				Arcade_setCantidadJugadores(arcadeBuscado,cantJugadores);
				retorno = 0;
				break;
			case 2:
				listarJuegos(pListaJuegos);
				utn_getNumero(&idJuego,"Ingrese el id del juego:\n","Reingrese el id del juego:\n",1,INT_MAX,3);
				Arcade_setIdJuego(arcadeBuscado,idJuego);
				retorno = 0;
				break;
			case 3:
				break;
			}
		}
	}
	return retorno;
}


int eliminarArcade(LinkedList* pListaArcades,LinkedList* pListaJuegos, int id){
	int retorno = -1;
	char respuesta[3];
	int index, idbuscado, idJuego;
	Arcade* arcadeBuscado;
	if(pListaArcades != NULL){
		int len = ll_len(pListaArcades);
		for(index =0; index < len; index++){
			arcadeBuscado= ll_get(pListaArcades, index);
			Arcade_getId(arcadeBuscado,&idbuscado);
			if(id == idbuscado){
				utn_getCadena(respuesta,3,"Esta seguro de eliminar: [si/no]\n","Reingrese respuesta [si/no]\n",3);
				if(strcmp(respuesta,"si")== 0){
					idJuego = arcadeBuscado->idJuego;
					eliminarJuego(pListaJuegos,idJuego);
					ll_remove(pListaArcades,index);
					retorno = 0;
					break;
				}
		}
	}
	}
	return retorno;
}


int eliminarArcadeConIndexSalon(LinkedList* pListaArcades,LinkedList* pListaJuegos, int idSalon){
	int retorno = -1;
	int index, idbuscado, idJuego;
	Arcade* arcadeBuscado;
	if(pListaArcades != NULL){
		int len = ll_len(pListaArcades);
		for(index =0; index < len; index++){
			arcadeBuscado= ll_get(pListaArcades, index);
			Arcade_getIdSalon(arcadeBuscado,&idbuscado);
			if(idSalon == idbuscado){
					idJuego = arcadeBuscado->idJuego;
					eliminarJuego(pListaJuegos,idJuego);
					ll_remove(pListaArcades,index);
					retorno = 0;
					break;
		}
	}
	}
	return retorno;
}


int eliminarJuego(LinkedList* pListaJuegos, int id){
	int retorno = -1;
	int index, idbuscado;
	Juego* juegoBuscado;
	if(pListaJuegos != NULL){
		int len = ll_len(pListaJuegos);
		for(index =0; index < len; index++){
			juegoBuscado= ll_get(pListaJuegos, index);
			Juego_getId(juegoBuscado,&idbuscado);
			if(id == idbuscado){
					ll_remove(pListaJuegos,index);
					retorno = 0;
					break;
		}
	}
	}
	return retorno;
}

/** \brief Guarda los datos de los arcades desde la lista de arcades al archivo arcade.csv (modo texto).
 *
 * \param path char*
 * \param pListaArcades LinkedList*
 * \return int
 *
 */
int controller_arcadeSaveAsText(char* path , LinkedList* pListaArcades)
{
	int retorno = -1;

	FILE* pArchivo;
	Arcade* arcadeNuevo = NULL;
	int idArcade;
	char nacionalidad[50];
	int tipoSonido,cantidadJugadores,canMaxFichas,idSalon,idJuego,len,index;

	if(path != NULL && pListaArcades != NULL){
		pArchivo = fopen(path,"w"); //abro el archivo en modo escritura
		if(pArchivo != NULL){
			fprintf(pArchivo,"id,nacionalidad,tipoSonido,jugadores,fichas,idSalon,idJuego\n");
			len = ll_len(pListaArcades);
			for(index = 0; index < len; index++){
				arcadeNuevo = (Arcade*)ll_get(pListaArcades,index);//busco cada uno de los elementos de la lista
				if(arcadeNuevo !=NULL){
					//obtengo los datos del arcade
					Arcade_getId(arcadeNuevo,&idArcade);
					Arcade_getNacionalidad(arcadeNuevo,nacionalidad);
					Arcade_getTipoSonido(arcadeNuevo,&tipoSonido);
					Arcade_getCantidadJugadores(arcadeNuevo,&cantidadJugadores);
					Arcade_getCantidadMaxFichas(arcadeNuevo,&canMaxFichas);
					Arcade_getIdSalon(arcadeNuevo,&idSalon);
					Arcade_getIdJuego(arcadeNuevo,&idJuego);
					fprintf(pArchivo,"%d,%s,%d,%d,%d,%d,%d\n",idArcade,nacionalidad,tipoSonido,cantidadJugadores,canMaxFichas,idSalon,idJuego);
				}
			}
			retorno = 0;
		}
	}
    return retorno;
}


/** \brief Guarda los datos de los salones desde la lista de salones al archivo salon.csv (modo texto).
 *
 * \param path char*
 * \param pListaSalones LinkedList*
 * \return int
 *
 */
int controller_salonSaveAsText(char* path , LinkedList* pListaSalones)
{
	int retorno = -1;

	FILE* pArchivo;
	Salon* salonNuevo = NULL;
	int idSalon;
	char nombre[50];
	char direccion[50];
	int tipoSalon,len,index;

	if(path != NULL && pListaSalones != NULL){
		pArchivo = fopen(path,"w"); //abro el archivo en modo escritura
		if(pArchivo != NULL){
			fprintf(pArchivo,"idSalon,nombre,direccion,tipoSalon\n");
			len = ll_len(pListaSalones);
			for(index = 0; index < len; index++){
				salonNuevo = (Salon*)ll_get(pListaSalones,index);//busco cada uno de los elementos de la lista
				if(salonNuevo !=NULL){
					//obtengo los datos del salon
					Salon_getId(salonNuevo,&idSalon);
					Salon_getNombre(salonNuevo,nombre);
					Salon_getDireccion(salonNuevo,direccion);
					Salon_getTipoSalon(salonNuevo,&tipoSalon);
					fprintf(pArchivo,"%d,%s,%s,%d\n",idSalon,nombre,direccion,tipoSalon);
				}
			}
			retorno = 0;
		}
	}
    return retorno;
}

/** \brief Guarda los datos de los juegos desde la lista de juegos al archivo juego.csv (modo texto).
 *
 * \param path char*
 * \param pListaSalones LinkedList*
 * \return int
 *
 */
int controller_juegoSaveAsText(char* path , LinkedList* pListaJuegos)
{
	int retorno = -1;

	FILE* pArchivo;
	Juego* juegoNuevo = NULL;
	int idJuego;
	char nombreJuego[50];
	char empresa[50];
	int genero,len,index;

	if(path != NULL && pListaJuegos != NULL){
		pArchivo = fopen(path,"w"); //abro el archivo en modo escritura
		if(pArchivo != NULL){
			fprintf(pArchivo,"idJuego,nombreJuego,empresa,genero\n");
			len = ll_len(pListaJuegos);
			for(index = 0; index < len; index++){
				juegoNuevo = (Juego*)ll_get(pListaJuegos,index);//busco cada uno de los elementos de la lista
				if(juegoNuevo !=NULL){
					//obtengo los datos del juego
					Juego_getId(juegoNuevo,&idJuego);
					Juego_getNombre(juegoNuevo,nombreJuego);
					Juego_getEmpresa(juegoNuevo,empresa);
					Juego_getGenero(juegoNuevo,&genero);
					fprintf(pArchivo,"%d,%s,%s,%d\n",idJuego,nombreJuego,empresa,genero);
				}
			}
			retorno = 0;
		}
	}
    return retorno;
}

