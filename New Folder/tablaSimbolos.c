#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tablaSimbolos.h"
#include "nombresDeTipos.h"

entradaTS* TS = NULL;
int contadorTemp = 0;   // para nombres temporales
int contadorSID = 0;    // para asignar un sid único a cada entrada

// Insertar un nuevo símbolo
void insertarTS(char* nombre, NombreDeTipoT tipo) {
    entradaTS* actual = TS;
    while (actual != NULL) {
        if (strcmp(actual->nombre, nombre) == 0) {
            printf("Error: identificador %s ya declarado.\n", nombre);
            return;
        }
        actual = actual->sig;
    }

    entradaTS* nuevo = malloc(sizeof(entradaTS));
    if (!nuevo) {
        printf("Error: sin memoria para nueva entradaTS\n");
        exit(1);
    }

    nuevo->nombre = strdup(nombre);
    nuevo->tipo = tipo;            // ahora asignamos tipo directamente
    nuevo->sid = contadorSID++;    // SID consecutivo
    nuevo->sig = TS;               // insertar al principio
    TS = nuevo;
}


// Consultar tipo de un símbolo
NombreDeTipoT consultarTipoTS(char* nombre) {
    entradaTS* actual = TS;
    while (actual != NULL) {
        if (strcmp(actual->nombre, nombre) == 0)
            return actual->tipo;
        actual = actual->sig;
    }
    printf("Error: identificador %s no declarado.\n", nombre);
    return TIPO_INVALIDO;
}

char* nombreTipo(NombreDeTipoT t) {
    switch (t) {
        case ENTERO: return "entero";
        case REAL: return "real";
        case CARACTER: return "caracter";
        case BOOLEANO: return "booleano";
        case CADENA: return "cadena";
        default: return "invalido";
    }
}

// Imprimir tabla de símbolos
void imprimirTS() {
    entradaTS* actual = TS;
    printf("\n===== TABLA DE SÍMBOLOS =====\n");
    while (actual != NULL) {
        printf("SID %d - %s : %s\n",
               actual->sid,
               actual->nombre,
               nombreTipo(actual->tipo)); // convierte enum → cadena
        actual = actual->sig;
    }
    printf("=============================\n");
}


