#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tablaSimbolos.h"

entradaTS* TS = NULL;
int contadorTemp = 0;   // para nombres temporales
int contadorSID = 0;    // para asignar un sid único a cada entrada

// Insertar un nuevo símbolo
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
    if (!nuevo) {
        printf("Error: sin memoria para nueva entradaTS\n");
        exit(1);
    }
    nuevo->nombre = strdup(nombre);
    nuevo->tipo = TIPO_INVALIDO; // enum
    nuevo->sid = contadorSID++;   // asignar SID único
    nuevo->sig = TS;
    TS = nuevo;
}

// Modificar tipo de un símbolo
void modificarTipoTS(char* nombre, NombreDeTipoT tipo) {
    entradaTS* actual = TS;
    while (actual != NULL) {
        if (strcmp(actual->nombre, nombre) == 0) {
            actual->tipo = tipo;
            return;
        }
        actual = actual->sig;
    }
    printf("Error: identificador %s no encontrado.\n", nombre);
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

// Crear nuevo temporal
char* newtemp() {
    char nombreTemp[20];
    sprintf(nombreTemp, "t%d", contadorTemp++);
    insertarTS(nombreTemp);
    // tipo se asignará después según la operación
    return strdup(nombreTemp);
}

// Imprimir tabla de símbolos
void imprimirTS() {
    entradaTS* actual = TS;
    printf("\n===== TABLA DE SÍMBOLOS =====\n");
    while (actual != NULL) {
        const char* nombreTipo;
        switch (actual->tipo) {
            case BOOLEANO: 
                nombreTipo = "booleano"; 
                break;
            case CADENA:   
                nombreTipo = "cadena"; 
                break;
            case CARACTER: 
                nombreTipo = "caracter"; 
                break;
            case ENTERO:   
                nombreTipo = "entero"; 
                break;
            case REAL:     
                nombreTipo = "real"; 
                break;
            default:       
                nombreTipo = "(sin tipo)";
        }

        printf("SID %d - %s : %s\n", actual->sid, actual->nombre, nombreTipo);
        actual = actual->sig;
    }
    printf("=============================\n");
}
