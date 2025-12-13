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

// inserta la lista de declaraciones de variables
void insertarListaEnTS(tipoListaNombre* l, NombreDeTipoT tipo) {
    celdaListaNombre* nodo = l->ini;
    while (nodo) {
        entradaTS* t = insertarTS(nodo->nombre); // Crear simbolo
        modificarTipoTS(t, tipo);               // Asignar el tipo correcto
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

// Crear lista vacía
void nuevaListaCuads(ListaCuads* l) {
    l->ini = NULL;
}

// Crear una lista con un único índice
ListaCuads makelist(int quad) {
    ListaCuads l;
    nuevaListaCuads(&l);
    NodoIndice* n = malloc(sizeof(NodoIndice));
    n->quad = quad;
    n->sig = NULL;
    l.ini = n;
    return l;
}

// Concatenar 2 listas
ListaCuads merge(ListaCuads l1, ListaCuads l2) {
    ListaCuads nueva;
    nuevaListaCuads(&nueva);
    NodoIndice* aux;
    
    for(aux = l1.ini; aux != NULL; aux = aux->sig) { // Copiar l1
        NodoIndice* n = malloc(sizeof(NodoIndice));
        n->quad = aux->quad;
        n->sig = nueva.ini;
        nueva.ini = n;
    }
    
    for(aux = l2.ini; aux != NULL; aux = aux->sig) { // Copiar l2
        NodoIndice* n = malloc(sizeof(NodoIndice));
        n->quad = aux->quad;
        n->sig = nueva.ini;
        nueva.ini = n;
    }
    return nueva;
}

// Backpatch: poner la cuádrupla de destino a todos los índices
void backpatch(ListaCuads* l, int destino) {
    NodoIndice* aux;
    for(aux = l->ini; aux != NULL; aux = aux->sig) {
        tQuad.datos[aux->quad].resultado = destino;
    }
}

// Devuelve la posición de la siguiente cuádrupla
int nextQuad() {
    return tQuad.n; // tQuad.n es el número de cuádruplas ya generadas
}
