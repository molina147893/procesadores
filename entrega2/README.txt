Procesadores de Lenguajes - Práctica 2 
Autores: Iván Latasa Sancha y Alejandro Molina Puyuelo - Grupo 2 de prácticas
 
1. FUNCIONALIDADES IMPLEMENTADAS
- Gestión de declaraciones de variables entre var y fvar
- Gestión de la tabla de símbolos y tabla de cuádruplas
- Implementación de las expresiones aritméticas completas con sus operadores: +, -, *, div y mod, int2real ...
- Expresiones booleanas con operadores relacionales: <, >, <=, >= y <>.
- Las expresiones booleanas generan correctamente las cuádruplas y las listas TRUE/FALSE, la gestión de los goto no está completamente implementada
- Detección de errores semánticos (por ejemplo intentar convertir real a entero)
- Hemos iniciado las implementaciones de los marcadores M y N, los literales numéricos y booleanos, aunque estas partes han quedando incompletas por falta de tiempo

2. CARACTERÍSTICAS DEL LÉXICO Y LA GRAMÁTICA
- La gramática tiene conflictos S/R y R/R esperables, que han sido resueltos con precedencia y asociatividad en Bison
- Toda variable booleana empieza por la letra b o la letra B, debido a esto se han cambiado las variables "b" de los ejemplos por "d" ya que no eran de tipo booleano

3. FICHEROS DE PRUEBA
- programa1.alg: algoritmo sumacomb con alguna modificación
- programa2.alg: algoritmo orden3
- programa3.alg: uso de otros operadores y generación de errores semánticos.
-En los ficheros programa1.alg y programa3.alg se han dejado errores de tipos para comprobar que se detectan y se imprimen

4. COMPILACIÓN Y EJECUCIÓN
Compilar:
    make

Ejecutar:
    ./a.out programaX.alg

Limpiar:
    make clean

La salida por terminal imprime la tabla de símbolos y de cuádruplas, que también son guardadas en los ficheros tabla_simbolos.txt y tabla_cuadruplas.txt

