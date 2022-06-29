/*
 ============================================================================
 Name        : PARCIAL2.c
 Author      : Ali Ansidey
 Version     :1.0.2
 Copyright   : Utilicen lo que necesiten
 Description : Parcial 2 Laboratorio de Programacion 1
 ============================================================================
 */

#include "informes.h"

//agregar una funcion que filtre una lista y tenga una sublista filtrada (mirar el sort)

int main(void) {
	setbuf(stdout, NULL);
	//inicializo las listas de salones, arcades y juegos
	LinkedList* listaSalones = ll_newLinkedList();
	LinkedList* listaArcades = ll_newLinkedList();
	LinkedList* listaJuegos = ll_newLinkedList();

	int option,option2, idSalon, idArcade;
	char nacionalidad[50];//agregado para la nueva funcion
	Arcade* arcadePrueba;//agregado para la nueva funcion
	controller_salonLoadFromText("salon.csv", listaSalones);
	controller_arcadeLoadFromText("arcade.csv",listaArcades);
	controller_juegoLoadFromText("juego.csv",listaJuegos);

	mostrarMenuUno();
	utn_getNumero(&option,"Ingrese su opci�n\n","Reingrese su opci�n\n",0,10,3);
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
	            		utn_getNumero(&idSalon,"Ingrese el id a eliminar\n","Reingrese su opci�n\n",1,INT_MAX,3);
	            		if(eliminarSalon(listaSalones,listaArcades,listaJuegos,idSalon) == 0){
	            			printf("\nSe elimin� el salon con exito\n");
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
	            		utn_getNumero(&idArcade,"Ingrese el id a modificar\n","Reingrese su opci�n\n",1,INT_MAX,3);
	            		modificarArcade(listaArcades,listaJuegos,idArcade);
	            	break;

	            case 6: //eliminar arcade
	            		listarArcades(listaArcades);
	            		utn_getNumero(&idArcade,"Ingrese el id a eliminar\n","Reingrese su opci�n\n",1,INT_MAX,3);
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
	            	utn_getNumero(&option2,"Ingrese la opcion deseada:\n","Reingrese su opcion\n",1,8,3);
	            	switch(option2){

	            	case 1://Listar los salones con mas de 4 arcade. Indicando ID de salon, nombre, direccion y tipo de salon.
	            		listarSalonesMayoresAcuatroArcades(listaSalones,listaArcades);
	            		break;

	            	case 2://Listar los arcade para mas de 2 jugadores
	            		listarArcadeMayorDosJugadores(listaSalones,listaArcades,listaJuegos);
	            		break;

	            	case 3://Listar toda la informacion de un salon en especifico ingresado por el usuario
	            		utn_getNumero(&idSalon,"Ingrese el id del salon a buscar:\n","Reingrese su el id del salon:\n",1,INT_MAX,3);
	            		listarInfomacionSalon(listaSalones,idSalon);
	            		break;

	            	case 4://Listar salones completos (4 plataforma,3 laberinto, 5 aventura)
	            		listarSalonesCompletos(listaSalones, listaArcades,listaJuegos);
	            		break;

	            	case 5://Listar todos los arcades de un salón determinado ingresando su ID.
	            		utn_getNumero(&idSalon,"Ingrese el id del salon a buscar:\n","Reingrese su el id del salon:\n",1,INT_MAX,3);
	            		listarArcadesDelSalonInforme(listaSalones, listaArcades,idSalon);
	            		break;

	            	case 6://Imprimir el salón con más cantidad de arcade, ordenados de manera ascendente
	            		listarSalonesMasArcades(listaSalones, listaArcades);
	            		break;

	            	case 7://Listar los arcades que cumplan con sonido MONO y el género de su juego sea PLATAFORMA
	            		listarArcadesMonoPlat(listaArcades,listaJuegos);
	            		break;

	            	case 8://agregar una funcion que filtre una lista y tenga una sublista filtrada (mirar el sort)
	            		 filtrarLinkedList(listaArcades,Arcade_getNacionalidad(arcadePrueba,nacionalidad),"China");
	            		break;

	            	}

	            	break;
	        }
	        mostrarMenuUno();
	        utn_getNumero(&option,"Ingrese su opci�n\n","Reingrese su opci�n\n",0,10,3);
	    }while(option != 0);

	    //salvo todos los cambios en los archivos csv
	    controller_salonSaveAsText("salon.csv",listaSalones);
	    controller_arcadeSaveAsText("arcade.csv",listaArcades);
	    controller_juegoSaveAsText("juego.csv",listaJuegos);

	    printf("Ha salido del sistema\n");
	    return 0;
}
