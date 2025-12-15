Procesadores de Lenguajes - Práctica 2 
Autores: Iván Latasa Sancha y Alejandro Molina Puyuelo - Grupo 2 de prácticas
 
1. FUNCIONALIDADES IMPLEMENTADAS
- Gestión de declaraciones de variables entre var y fvar
- Gestión de la tabla de símbolos y tabla de cuádruplas
- Implementación de las expresiones aritméticas completas con sus operadores: +, -, *, div y mod, int2real ...
- Expresiones booleanas con operadores relacionales: <, >, <=, >= y <>.
- Las expresiones booleanas generan correctamente las cuádruplas, aunque la gestión completa de los goto no está terminada
- Detección de errores semánticos (por ejemplo intentar convertir real a entero)
- Hemos intentado implementar los marcadores M y N, los literales numéricos y booleanos, aunque estas partes han quedando incompletas por falta de tiempo

2. CARACTERÍSTICAS DEL LÉXICO Y LA GRAMÁTICA
- La gramática tiene conflictos S/R y R/R esperables, que han sido resueltos con precedencia y asociatividad en Bison

3. FICHEROS DE PRUEBA
- prueba1.txt: algoritmo sumacomb con alguna modificación
- prueba2.txt: algoritmo orden3
- prueba3.txt: uso de otros operadores y generación de errores semánticos.

4. COMPILACIÓN Y EJECUCIÓN
Compilar:
    make

Ejecutar:
    ./a.out pruebaX.txt

Limpiar:
    make clean

La salida por terminal imprime la tabla de símbolos y de cuádruplas, que también son guardadas en los ficheros tabla_simbolos.txt y tabla_cuadruplas.txt

