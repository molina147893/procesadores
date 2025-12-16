#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "cuadruplas.h"
#include "traducciones.h"

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

char* nombreOperador(Operador o) {
    switch (o) {
		case OP_ASIG: return ":=";
        case OP_SUM: return "+";
        case OP_REST: return "-";
        case OP_MULT: return "*";
        case OP_DIV: return "div";
		case OP_IDIV: return "/";
		case OP_MOD: return "mod";
		case OP_INT2REAL: return "int2real";
		
		case OP_MAYQ: return ">";
		case OP_MENQ: return "<";
		case OP_MAYIQ: return ">=";
		case OP_MENIQ: return "<=";
		case OP_IGU: return "==";
		case OP_DIST: return "<>";
		case GOTO: return "goto";
        default: return "invalido";
    }
}

void imprimirTC(TablaCuadruplas* t){
	imprimirTC_en(stdout, t);
}

void imprimirTC_en(FILE *out, TablaCuadruplas* t){
	fprintf(out, "\n===== TABLA DE CUADRUPLAS =====\n");
	
	for(int i = 0; i < t->n; i++){
		fprintf(out, "CUADRUPLA %d:\t (%s, %d, %d, %d)\n", i, nombreOperador(t->datos[i].op), t->datos[i].arg1, t->datos[i].arg2, t->datos[i].resultado);
	}
	
	fprintf(out, "=============================\n");
}
