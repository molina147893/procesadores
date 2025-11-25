#ifndef TABLA_SIMBOLOS_H
#define TABLA_SIMBOLOS_H

typedef struct entradaTS {
    char* nombre;
    char* tipo;      // "entero", "real", "booleano"
    struct entradaTS* sig;
} entradaTS;

extern entradaTS* TS;

void insertarTS(char* nombre);       // Inserta sin tipo (declaración inmediata)

void modificarTipoTS(char* nombre, char* tipo);

char* consultarTipoTS(char* nombre);

char* newtemp();                     // Crea un temporal y lo mete en TS

void imprimirTS();                   // opcional

#endif
