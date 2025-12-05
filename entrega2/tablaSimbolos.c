#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tablaSimbolos.h"
#include "nombresDeTipos.h"

entradaTS* TS = NULL;
int contadorTemp = 0;   // para nombres temporales
int contadorSID = 0;    // para asignar un sid único a cada entrada

// INSERTAR NUEVO SIMBOLO
entradaTS* insertarTS(char* nombre) {
    entradaTS* existe = buscarPorNombre(nombre);
    if (existe != NULL) {
        printf("Error: identificador %s ya declarado.\n", nombre);
        return existe;
    }

    entradaTS* nuevo = malloc(sizeof(entradaTS));
    if (!nuevo) {
        printf("Error: sin memoria para nueva entradaTS\n");
        exit(1);
    }
    nuevo->nombre = strdup(nombre);
    nuevo->tipo = TIPO_INVALIDO;
    nuevo->sid = contadorSID++;    // SID consecutivo
    nuevo->sig = TS;               // insertar al principio
    TS = nuevo;
    return nuevo;
}


// INSERTAR TEMPORAL
entradaTS* insertarTemp() {
    char buffer[32];
    sprintf(buffer, "t%d", contadorTemp++);

    entradaTS* nuevo = malloc(sizeof(entradaTS));
    nuevo->nombre = strdup(buffer);
    nuevo->tipo = TIPO_INVALIDO; // lo asignaremos despues
    nuevo->sid = contadorSID++;
    nuevo->sig = TS;
    TS = nuevo;

    return nuevo;
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

// BUSQUEDAS
entradaTS* buscarPorNombre(char* nombre) {
    entradaTS* actual = TS;
    while (actual) {
        if (actual->nombre && strcmp(actual->nombre, nombre) == 0)
            return actual;
        actual = actual->sig;
    }
    return NULL;
}

entradaTS* buscarPorSID(int sid) {
    entradaTS* actual = TS;
    while (actual) {
        if (actual->sid == sid)
            return actual;
        actual = actual->sig;
    }
    return NULL;
}


// TIPO
void modificarTipoTS(entradaTS* e, NombreDeTipoT tipo) {
    if (e){
        e->tipo = tipo;
    }
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
        printf("SID: %d   Nombre: %s   Tipo: %s\n",
               actual->sid,
               actual->nombre,
               nombreTipo(actual->tipo)); // convierte enum → cadena
        actual = actual->sig;
    }
    printf("=============================\n");
}


