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

entradaTS* insertarTS(char* nombre);        // crea símbolo normal
entradaTS* insertarTemp();                  // crea temporal t0, t1, t2...
entradaTS* buscarPorNombre(char* nombre);
entradaTS* buscarPorSID(int sid);
void modificarTipoTS(entradaTS* e, NombreDeTipoT tipo);
NombreDeTipoT consultarTipoTS(char* nombre);
void imprimirTS(); // opcional

#endif
