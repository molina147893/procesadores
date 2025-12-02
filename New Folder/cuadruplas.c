#include <stdio.h>
#include <string.h>
#include "cuadruplas.h"

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

void gen(TablaCuadruplas* t, char op, char* arg1, char* arg2, char* resultado){ //gen()
	//Comprobamos si la tabla esta llena
	if(t->n >= t->capacidad){
		t->capacidad *= 2;
		t->datos = realloc(t->datos, t->capacidad * sizeof(Cuadrupla));
		
		//Comprobamos si habia espacio suficiente para la nueva tabla
		if(!t->datos){
			printf("Error: sin memoria para aumentar la tabla\n");
			exit(1);
		}
	}
	
	//Añadimos los datos de la nueva cuadrupla a la tabla
	strcpy(t->datos[t->n].op, op);
	strcpy(t->datos[t->n].arg1, arg1);
	strcpy(t->datos[t->n].arg2, arg2);
	strcpy(t->datos[t->n].resultado, resultado);
	
	//Aumentamos el contador
	t->n++;
}

void liberarTabla(TablaCuadruplas* t){
	free(t->datos);
	t->datos = NULL;
	t->n = 0;
	t->capacidad = 0; //?
}

void imprimirTabla(TablaCuadruplas* t){
	printf("\n===== TABLA DE CUADRUPLAS =====\n");
	
	for(int i = 0; i <= t->n; i++){
		printf("CUADRUPLA %d: (%s, %s, %s, %s)\n", i, t->datos[i].op, t->datos[i].arg1, t->datos[i].arg2, t->datos[i].result);
	}
	
	printf("=============================\n");
}
