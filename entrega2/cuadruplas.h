#ifndef CUADRUPLAS_H
#define CUADRUPLAS_H

#include "tablaSimbolos.h"

typedef struct {
    int op;     // +, -, *, /, 'i' para int2real
    int arg1;    // SID TS
    int arg2;    // SID TS o -1 si no aplica
    int resultado;     // SID TS donde se guarda resultado
} Cuadrupla;

typedef struct	{
	Cuadrupla* datos;
	int n;
	int capacidad; //Para no tener que hacer realloc cada vez que insertamos y solo hacerlo si se supera esta capacidad
} TablaCuadruplas;

extern TablaCuadruplas tQuad; // declaramos la variable global

TablaCuadruplas crearTabla(int capacidad);
void gen(int op, int arg1, int arg2, int resultado);
void liberarTC(TablaCuadruplas* t);
void imprimirTC(TablaCuadruplas* t);

#endif
