/*
 * informes.c
 *
 *  Created on: 28 jun. 2022
 *      Author: Alí Ansidey
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

