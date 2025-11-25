#include "traducciones.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "tablaSimbolos.h"

// -------------------- LISTA DE NOMBRES --------------------

tipoListaNombre* nuevaLista() {
    tipoListaNombre* l = malloc(sizeof(tipoListaNombre));
    if (!l) {
        fprintf(stderr, "No hay memoria para crear lista de nombres\n");
        exit(1);
    }
    l->ini = NULL;
    return l;
}

void nuevaCelda(tipoListaNombre* l, char* id) {
    celdaListaNombre* nuevo = malloc(sizeof(celdaListaNombre));
    if (!nuevo) {
        fprintf(stderr, "No hay memoria para crear celda\n");
        exit(1);
    }
    nuevo->nombre = strdup(id);
    if (!nuevo->nombre) {
        fprintf(stderr, "No hay memoria para el nombre de la celda\n");
        exit(1);
    }
    nuevo->sig = l->ini;
    l->ini = nuevo;
}

bool esNulaListaNombre(tipoListaNombre c) {
    return c.ini == NULL;
}

void insertarNombre(tipoListaNombre* c, char* nombre) {
    nuevaCelda(c, nombre);
}

void insertarListaEnTS(tipoListaNombre* l, NombreDeTipoT tipo) {
    celdaListaNombre* nodo = l->ini;
    while (nodo) {
        insertarTS(nodo->nombre);
        modificarTipoTS(nodo->nombre, tipo);
        nodo = nodo->sig;
    }
}

void liberarListaNombre(tipoListaNombre* l) {
    celdaListaNombre* aux = l->ini;
    while (aux) {
        celdaListaNombre* temp = aux;
        aux = aux->sig;
        free(temp->nombre);
        free(temp);
    }
    free(l);
}
