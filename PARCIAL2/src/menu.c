/*
 * menu.c
 *
 *  Created on: 24 jun. 2022
 *      Author: Al� Ansidey
 */


#include "menu.h"

void mostrarMenuUno(){

	printf("1. Alta de salon\n");
	printf("2. Eliminar salon\n");
	printf("3. Listar salones\n");
	printf("4. Incorporar arcade\n");
	printf("5. Modificar arcade\n");
	printf("6. Eliminar arcade\n");
	printf("7. Imprimir arcade\n");
	printf("8. Agregar juego\n");
	printf("9. Imprimir juego\n");
	printf("10. Informes\n");
	printf("0. Salir del sistema\n");
}

void mostrarMenuDos(){
	printf("1. Listar salones con mas de 4 arcades\n");
	printf("2. Listar arcades para mas de 2 jugadores\n");
	printf("3. Listar informacion de un salon especifico\n");
	printf("4. Listar salones completos[4 Plataforma, 3 laberinto, 5 aventura]\n");
	printf("5. Listar todos los arcades de un salon\n");
	printf("6. Imprimir salon con mas arcades\n");
	printf("7. Listar los arcades con sonido MONO\n");
	printf("8.agregar una funcion que filtre una lista y tenga una sublista filtrada (mirar el sort)");//nueva funcion 28-06

}

void mostrarMenuTres(){
	printf("1. Cantidad de jugadores\n");
	printf("2. Id del juego\n");
	printf("3. Volver al menu\n");

}
