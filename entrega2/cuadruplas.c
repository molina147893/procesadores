#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "cuadruplas.h"

TablaCuadruplas tQuad; // definición de la variable global

TablaCuadruplas crearTabla(int capacidad) {
	TablaCuadruplas t;
	t.n = 0; //Todavia no hay cuadruplas
	t.capacidad = capacidad; //El tamaño inicial que queremos para la tabla
	t.datos = malloc(capacidad * sizeof(Cuadrupla)); //Guardamos memoria suficiente para capacidad cuadruplas
	
	//Comprobamos si habia memoria suficiente para crear la tabla
	if(!t.datos){
		printf("Error: sin memoria para la tabla de cuadruplas\n");
		exit(1);
	}
	
	return t;
}

void gen(int op, int arg1, int arg2, int resultado) {
	//Comprobamos si la tabla esta llena
    if(tQuad.n >= tQuad.capacidad){
        tQuad.capacidad *= 2;
        tQuad.datos = realloc(tQuad.datos, tQuad.capacidad * sizeof(Cuadrupla));
		//Comprobamos si habia espacio suficiente para la nueva tabla
        if(!tQuad.datos) { 
			fprintf(stderr,"Sin memoria para tQuad\n"); 
			exit(1); 			
		}
    }
    //Añadimos los datos de la nueva cuadrupla a la tabla
    tQuad.datos[tQuad.n].op = op;
    tQuad.datos[tQuad.n].arg1 = arg1;
    tQuad.datos[tQuad.n].arg2 = arg2;
    tQuad.datos[tQuad.n].resultado = resultado;
    tQuad.n++; //Aumentamos el contador
}


void liberarTC(TablaCuadruplas* t){
	free(t->datos);
	t->datos = NULL;
	t->n = 0;
	t->capacidad = 0; //?
}

void imprimirTC(TablaCuadruplas* t){
	printf("\n===== TABLA DE CUADRUPLAS =====\n");
	
	for(int i = 0; i < t->n; i++){
		printf("CUADRUPLA %d: (%d, %d, %d, %d)\n", i, t->datos[i].op, t->datos[i].arg1, t->datos[i].arg2, t->datos[i].resultado);
	}
	
	printf("=============================\n");
}
