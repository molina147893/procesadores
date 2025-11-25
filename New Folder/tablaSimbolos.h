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

void insertarTS(char* nombre);       // Inserta sin tipo (declaración inmediata)

void modificarTipoTS(char* nombre, NombreDeTipoT tipo);

NombreDeTipoT consultarTipoTS(char* nombre);

char* newtemp();                     // Crea un temporal y lo mete en TS

void imprimirTS();                   // opcional

#endif
