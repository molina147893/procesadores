#ifndef FFF_TRADUCCIONES_H
#define FFF_TRADUCCIONES_H

#include <stdbool.h>
#include "tablaSimbolos.h"
#include "nombresDeTipos.h"

// -------------------- CELDAS Y LISTAS DE NOMBRES --------------------
typedef struct celdaListaNombre {
    char* nombre;
    struct celdaListaNombre* sig;
} celdaListaNombre;

typedef struct tipoListaNombre {
    celdaListaNombre* ini;
} tipoListaNombre;

// Constructor de lista vacía
tipoListaNombre* nuevaLista();
void nuevaCelda(tipoListaNombre* l, char* id);

// Inserta todos los ids de la lista en la tabla de símbolos con su tipo
void insertarListaEnTS(tipoListaNombre* l, NombreDeTipoT tipo);

// Libera la lista de memoria
void liberarListaNombre(tipoListaNombre* l);

// Auxiliares
bool esNulaListaNombre(tipoListaNombre c);
void insertarNombre(tipoListaNombre* c, char* nombre);

#endif
