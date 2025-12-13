#ifndef FFF_TRADUCCIONES_H
#define FFF_TRADUCCIONES_H

#include <stdbool.h>
#include "tablaSimbolos.h"
#include "nombresDeTipos.h"
#include "cuadruplas.h"

// -------------------- OPERADORES --------------------
typedef enum {
    OP_ASIG = 1,
    OP_SUM,
    OP_REST,
    OP_MULT,
    OP_DIV,    // dividir real
    OP_IDIV,   // div entero
    OP_MOD,
    OP_INT2REAL,
    
    OP_MAYQ,     // >
    OP_MENQ,     // <
    OP_MAYIQ,     // >=
    OP_MENIQ,     // <=
    OP_IGU,     // ==
    OP_DIST,      // <>
    OP_IF_TRUE, //Para booleanas
    GOTO
} Operador;

// -------------------- CELDAS Y LISTAS DE NOMBRES --------------------
typedef struct celdaListaNombre {
    char* nombre;
    struct celdaListaNombre* sig;
} celdaListaNombre;

typedef struct tipoListaNombre {
    celdaListaNombre* ini;
} tipoListaNombre;

typedef struct {
    Operador operador; // Guardamos que operador es exactamente
} OpInfo;

// ---------------------- Lista de índices de cuádruplas ----------------------
typedef struct nodoIndice {
    int quad;                  // índice en tQuad
    struct nodoIndice* sig;
} NodoIndice;

typedef struct {
    NodoIndice* ini;           // lista enlazada de índices
} ListaCuads;

// ---------------------- Expresiones (ariméticas y booleanas) ----------------
typedef struct {
    int place;          // el SID en la TS
    NombreDeTipoT type; // tipo de la expresión
    int esLiteral;  // 0 = variable/temp, 1 = literal
    
    ListaCuads TRUE; // lista de cuadruplas pendientes si la expr es true (Saltos)
    ListaCuads FALSE; // lista de cuadruplas pendientes si la expr es false (Saltos)
} AtributosExpresion;

typedef struct {
	int QUAD;
}AuxM;

typedef struct {
	TablaCuadruplas NEXT;
}AuxN;

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

//Para booleanas
void nuevaListaCuads(ListaCuads* l);
ListaCuads makelist(int quad);
ListaCuads merge(ListaCuads l1, ListaCuads l2);
void backpatch(ListaCuads* l, int destino);
int nextQuad(); // Habria que pasarle aqui un id? Si no supongo que seria meterlo a cuadruplas.h y coger el id de la global y sumarle 1?




#endif
