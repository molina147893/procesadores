#ifndef TABLA_SIMBOLOS_H
#define TABLA_SIMBOLOS_H

#include "nombresDeTipos.h"

typedef struct entradaTS {
    char* nombre;
    NombreDeTipoT tipo;      // ahora es enum
    int sid;         // identificador único
    struct entradaTS* sig;
} entradaTS;

extern entradaTS* TS;

void insertarTS(char* nombre, NombreDeTipoT tipo);

NombreDeTipoT consultarTipoTS(char* nombre);

void imprimirTS();                   // opcional

#endif
