#ifndef CUADRUPLAS_H
#define CUADRUPLAS_H

#include "tablaSimbolos.h"

typedef struct {
	char op[1];
	char arg1[10]; 
	char arg2[10];
	char resultado[20];
} Cuadrupla;

typedef struct	{
	Cuadrupla* cuadrupla;
	int contador;
	int capacidad; //Para no tener que hacer realloc cada vez que insertamos y solo hacerlo si se supera esta capacidad
} TablaCuadruplas;

TablaCuadruplas crearTabla(int capacidad);
void insertarCuadrupla(TablaCuadruplas* t, char* op, char* arg1, char* arg2, char* resultado); //gen()
void liberarTabla(TablaCuadruplas* t);
void imprimirTabla(TablaCuadruplas* t);

#endif
