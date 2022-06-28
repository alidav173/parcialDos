/*
 ============================================================================
 Name        : PARCIAL2.c
 Author      : Alí Ansidey
 Version     :1.0.1
 Copyright   : Utilicen lo que necesiten
 Description : Parcial 2 Laboratorio de Programación 1
 ============================================================================
 */

#include "informes.h"

int main(void) {
	setbuf(stdout, NULL);
	//inicializo las listas de salones, arcades y juegos
	LinkedList* listaSalones = ll_newLinkedList();
	LinkedList* listaArcades = ll_newLinkedList();
	LinkedList* listaJuegos = ll_newLinkedList();

	int option,option2, idSalon, idArcade;
	controller_salonLoadFromText("salon.csv", listaSalones);
	controller_arcadeLoadFromText("arcade.csv",listaArcades);
	controller_juegoLoadFromText("juego.csv",listaJuegos);

	mostrarMenuUno();
	utn_getNumero(&option,"Ingrese su opción\n","Reingrese su opción\n",0,10,3);
	    do{
	        switch(option)
	        {
	            case 1://alta de salon
	            	if(altaSalon(listaSalones) != -1){
	            		printf("\nSe agrego el salon con exito\n");
	            	}
	            	else{
	            		printf("\n No se agrego el salon\n");
	            	}
	                break;

	            case 2://eliminar salon
	            	if(listarSalones(listaSalones)!= -1){
	            		utn_getNumero(&idSalon,"Ingrese el id a eliminar\n","Reingrese su opción\n",1,INT_MAX,3);
	            		if(eliminarSalon(listaSalones,listaArcades,listaJuegos,idSalon) == 0){
	            			printf("\nSe eliminó el salon con exito\n");
	            		}
	            		else{
	            			printf("\nNo se pudo eliminar\n");
	            		}
	            	}
	            	else{
	            		printf("\nError en el listado de salones\n");
	            	}
	            	break;

	            case 3://listar salones
	            	listarSalones(listaSalones);
	             	break;

	            case 4://incorporar arcade
	            	if(incorporarArcade(listaArcades)== 0){
	            		printf("Se ha agregado al arcade con exito\n");
	            	}
	            	else{
	            		printf("No se ha podido agregar el arcade\n");
	            	}
	            	break;

	            case 5://modificar arcade
	            		listarArcades(listaArcades);
	            		utn_getNumero(&idArcade,"Ingrese el id a modificar\n","Reingrese su opción\n",1,INT_MAX,3);
	            		modificarArcade(listaArcades,listaJuegos,idArcade);
	            	break;

	            case 6: //eliminar arcade
	            		listarArcades(listaArcades);
	            		utn_getNumero(&idArcade,"Ingrese el id a eliminar\n","Reingrese su opción\n",1,INT_MAX,3);
	            		eliminarArcade(listaArcades,listaJuegos,idArcade);
	            	break;

	            case 7: //imprime arcade
	            		listarArcades(listaArcades);
	            	break;

	            case 8://agregar juego
	            	if(agregarJuego(listaJuegos)==0){
	            		printf("Se agrego el juego con exito\n");
	            	}
	            	else{
	            		printf("No se ha podido agregar el juego\n");
	            	}
	            	break;

	            case 9://imprimir juego
	            	listarJuegos(listaJuegos);
	            	break;

	            case 10: //informes
	            	mostrarMenuDos();
	            	utn_getNumero(&option2,"Ingrese la opción deseada:\n","Reingrese su opción\n",1,6,3);
	            	switch(option2){

	            	case 1://Listar los salones con más de 4 arcade. Indicando ID de salón, nombre, dirección y tipo de salón.
	            		listarSalonesMayoresAcuatroArcades(listaSalones,listaArcades);
	            		break;

	            	case 2://Listar los arcade para más de 2 jugadores
	            		break;

	            	case 3://Listar toda la información de un salón en específico ingresado por el usuario
	            		break;

	            	case 4:
	            		break;

	            	case 5:
	            		break;

	            	case 6:
	            		break;
	            	}
	            	break;
	        }
	        mostrarMenuUno();
	        utn_getNumero(&option,"Ingrese su opción\n","Reingrese su opción\n",0,10,3);
	    }while(option != 0);

	    //salvo todos los cambios en los archivos csv
	    controller_salonSaveAsText("salon.csv",listaSalones);
	    controller_arcadeSaveAsText("arcade.csv",listaArcades);
	    controller_juegoSaveAsText("juego.csv",listaJuegos);

	    printf("Ha salido del sistema\n");
	    return 0;
}
