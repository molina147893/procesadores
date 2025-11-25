#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tablaSimbolos.h"

entradaTS* TS = NULL;
int contadorTemp = 0;

void insertarTS(char* nombre) {
    entradaTS* actual = TS;
    while (actual != NULL) {
        if (strcmp(actual->nombre, nombre) == 0) {
            printf("Error: identificador %s ya declarado.\n", nombre);
            return;
        }
        actual = actual->sig;
    }

    entradaTS* nuevo = malloc(sizeof(entradaTS));
    nuevo->nombre = strdup(nombre);
    nuevo->tipo = NULL;     // tipo se pondrá después
    nuevo->sig = TS;
    TS = nuevo;
}

void modificarTipoTS(char* nombre, char* tipo) {
    entradaTS* actual = TS;
    while (actual != NULL) {
        if (strcmp(actual->nombre, nombre) == 0) {
            actual->tipo = strdup(tipo);
            return;
        }
        actual = actual->sig;
    }
    printf("Error: identificador %s no encontrado.\n", nombre);
}

char* consultarTipoTS(char* nombre) {
    entradaTS* actual = TS;
    while (actual != NULL) {
        if (strcmp(actual->nombre, nombre) == 0)
            return actual->tipo;
        actual = actual->sig;
    }
    printf("Error: identificador %s no declarado.\n", nombre);
    return NULL;
}

char* newtemp() {
    char nombreTemp[20];
    sprintf(nombreTemp, "t%d", contadorTemp++);

    insertarTS(nombreTemp);
    // tipo se asignará según operación (como dice la teoría)
    return strdup(nombreTemp);
}

void imprimirTS() {
    entradaTS* actual = TS;
    printf("\n===== TABLA DE SÍMBOLOS =====\n");
    while (actual != NULL) {
        printf("%s : %s\n",
               actual->nombre,
               actual->tipo ? actual->tipo : "(sin tipo)");
        actual = actual->sig;
    }
    printf("=============================\n");
}
