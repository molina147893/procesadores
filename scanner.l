 //SECCION 1: DECLARACIONES
 //1.1 Constantes y codigo necesario.
%{
	//Importaciones necesarias
	#include <stdio.h> //Para poder escribir por terminal.
	#include <strings.h> //Para poder trabajar con cadenas de caracteres.
	#include <stdlib.h> //Para poder usar exit(), atof...
	#include <string.h>
	#include <stddef.h>
	
	void errorEnScanner(char*, char*);
%}

 //1. Definiciones.
digito_def [0-9] 
letra_def [A-Za-z]
op1_def [+-]
op2_def [*/]
 //Se podria meter ahi tambien div y mod
caracteres_espaciadores_def [ \t\n]
asignacion_def :=
comillas_dobles_def \"
comilla_simple_def '
barra_lateral_def \/
abrir_parentesis_def \(
cerrar_parentesis_def \)
igual_def =
inicio_array_def \[
fin_array_def \]
coma_def ,
punto_coma_def ;
punto_def \.
dos_puntos_def :
mayor_que_def >
menor_que_def <
subrango_def \.\. 
entonces_def ->
si_no_si_def \[\]
verdadero_def (?i:verdadero)
falso_def (?i:falso)
accion_def (?i:accion)
algoritmo_def (?i:algoritmo)
booleano_def (?i:booleano)
cadena_def (?i:cadena)
caracter_def (?i:caracter)
const_def (?i:const)
continuar_def (?i:continuar)
de_def (?i:de)
dev_def (?i:dev)
div_def (?i:div)
ent_def (?i:ent)
entero_def (?i:entero)
e_s_def (?i:e\/s)
faccion_def (?i:faccion)
falgoritmo_def (?i:falgoritmo)
fconst_def (?i:fconst)
ffuncion_def (?i:ffuncion)
fmientras_def (?i:fmientras)
fpara_def (?i:fpara)
fsi_def (?i:fsi)
ftipo_def (?i:ftipo)
ftupla_def (?i:ftupla)
funcion_def (?i:funcion)
fvar_def (?i:fvar)
hacer_def (?i:hacer)
hasta_def (?i:hasta)
mientras_def (?i:mientras)
mod_def (?i:mod)
no_def (?i:no)
o_def (?i:o)
para_def (?i:para)
real_def (?i:real)
ref_def (?i:ref)
sal_def (?i:sal)
si_def (?i:si)
tabla_def (?i:tabla)
tipo_def (?i:tipo)
tupla_def (?i:tupla)
var_def (?i:var)
y_def (?i:y)
letra_o_digito_def {digito_def}|{letra_def}
id_def {letra_def}{letra_o_digito_def}*
literal_entero_def ({op1_def})?{digito_def}({digito_def})*((e|E){digito_def}{digito_def}*)? 
literal_real_def ({op1_def}?{digito_def}{digito_def}*(\.{digito_def}{digito_def}*)?((e|E){digito_def}{digito_def}*)?)|({literal_entero_def}(r|R))
literal_booleano_def {verdadero_def}|{falso_def} //Teniendo las palabras reservadas verdadero y falso, hace falta este literal?
literal_caracter_def \".\"
 //Barras laterales para diferenciar entre su valor caracter y su valor reservado.
literal_cadena_def \'([^\']*(\/\')*[^\']*)\'
comentario_def \{([^\}]*(\/\})*[^\}]*)\}

%%

 //SECCION 2: REGLAS
 //2.1
 //Literales
{literal_entero_def}	{
	printf("Literal entero: %d\n", atoi(yytext));
}
{literal_real_def}	{
	size_t longitud = strlen(yytext);
	//Verificamos si se introduce la R al final, de ser asi vemos si hay espacio para almacenar y si no damos error
	if(yytext[longitud-1] == 'r' || yytext[longitud-1] == 'R'){
		char * cadena;
		if((cadena = strndup(yytext, longitud-1))==NULL){
			errorEnScanner("No hay memoria para realizar strndup() con la cadena: %s\n", yytext);
		}
		else{
			printf("Literal real: %f\n", atof(cadena));
			free(cadena); //Liberamos el espacio
		}
	}
	else{
		printf("Literal real: %f\n", atof(yytext));
	}
}
{literal_caracter_def}	{
	printf("Literal caracter: %s\n", yytext);
}
{literal_cadena_def}	{
	printf("Literal cadena: %s\n", yytext);
}
{verdadero_def}	{
	printf("Palabra reservada: VERDADERO\n");
}
{falso_def}	{
	printf("Palabra reservada: FALSO\n");
}
{accion_def}	{
	printf("Palabra reservada: ACCION\n");
}
{faccion_def}	{
	printf("Palabra reservada: FACCION\n");
}
{algoritmo_def}	{
	printf("Palabra reservada: ALGORITMO\n");
}
{falgoritmo_def}	{
	printf("Palabra reservada: FALGORITMO\n");
}
{booleano_def}	{
	printf("Palabra reservada: BOOLEANO\n");
}
{cadena_def}	{
	printf("Palabra reservada: CADENA\n");
}
{caracter_def}	{
	printf("Palabra reservada: CARACTER\n");
}
{const_def}	{
	printf("Palabra reservada: CONST\n");
}
{fconst_def}	{
	printf("Palabra reservada: FCONST\n");
}
{continuar_def}	{
	printf("Palabra reservada: CONTINUAR\n");
}
{de_def}	{
	printf("Palabra reservada: DE\n");
}
{dev_def}	{
	printf("Palabra reservada: DEV\n");
}
{div_def}	{
	printf("Palabra reservada: DIV\n");
}
{ent_def}	{
	printf("Palabra reservada: ENT\n");
}
{entero_def}	{
	printf("Palabra reservada: ENTERO\n");
}
{e_s_def}	{	
	printf("Palabra reservada: E/S\n");
}
{funcion_def}	{
	printf("Palabra reservada: FUNCION\n");
}
{ffuncion_def}	{
	printf("Palabra reservada: FFUNCION\n");
}
{mientras_def}	{	
	printf("Palabra reservada: MIENTRAS\n");
}
{fmientras_def}	{
	printf("Palabra reservada: FMIENTRAS\n");
}
{para_def}	{
	printf("Palabra reservada: PARA\n");
}
{fpara_def}	{
	printf("Palabra reservada: FPARA\n");
}
{si_def}	{
	printf("Palabra reservada: SI\n");
}
{fsi_def}	{
	printf("Palabra reservada: FSI\n");
}
{tipo_def}	{
	printf("Palabra reservada: TIPO\n");
}
{ftipo_def}	{	
	printf("Palabra reservada: FTIPO\n");
}
{tupla_def}	{
	printf("Palabra reservada: TUPLA\n");
}
{ftupla_def}	{
	printf("Palabra reservada: FTUPLA\n");
}
{var_def}	{
	printf("Palabra reservada: VAR\n");
}
{fvar_def}	{
	printf("Palabra reservada: FVAR\n");
}
{hacer_def}	{
	printf("Palabra reservada: HACER\n");
}
{hasta_def}	{
	printf("Palabra reservada: HASTA\n");
}
{mod_def}	{
	printf("Palabra reservada: MOD\n");
}
{no_def}	{
	printf("Palabra reservada: NO\n");
}
{o_def}	{
	printf("Palabra reservada: O\n");
}
{real_def}	{
	printf("Palabra reservada: REAL\n");
}
{ref_def}	{
	printf("Palabra reservada: REF\n");
}
{sal_def}	{
	printf("Palabra reservada: SAL\n");
}
{tabla_def}	{
	printf("Palabra reservada: TABLA\n");
}
{y_def}	{
	printf("Palbra reservada: Y\n");
}
{comentario_def}	{
	printf("Comentario: %s\n", yytext);
}
{id_def}	{
	printf("Identificador: %s\n", yytext);
}
{comillas_dobles_def}	{
	printf("Caracter especial comillas dobles: %s\n", yytext);
}
{comilla_simple_def}	{
	printf("Caracter especial comilla simple: %s\n", yytext);
}
{barra_lateral_def}	{
	printf("Caracter especial barra lateral: %s\n", yytext);
}
{abrir_parentesis_def}	{
	printf("Caracter especial abrir parentesis: %s\n", yytext);
}
{cerrar_parentesis_def}	{
	printf("Caracter especial cerrar parentesis: %s\n", yytext);
}
{igual_def}	{
	printf("Token creacion de tipo: %s\n", yytext);
}
{inicio_array_def}	{
	printf("Token inicio array: %s\n", yytext);
}
{fin_array_def}	{
	printf("Token fin array: %s\n", yytext);
}
{coma_def}	{
	printf("Token separador: %s\n", yytext);
}
{punto_coma_def}	{
	printf("Token composicion secuencial: %s\n", yytext);
}
{punto_def}	{
	printf("Caracter especial punto: %s\n", yytext);
}
{dos_puntos_def}	{
	printf("Token definidor tipo de variable: %s\n", yytext);
}
{mayor_que_def}	{
	printf("Caracter especial mayor que: %s\n", yytext);
}
{menor_que_def}	{
	printf("Caracter especial menor que: %s\n", yytext);
}
{subrango_def}	{
	printf("Token subrango: %s\n", yytext);
}
{asignacion_def}	{
	printf("Token asignacion: %s\n", yytext);
}
{entonces_def}	{
	printf("Token entonces: %s\n", yytext);
}
{si_no_si_def}	{
	printf("Token si no si: %s\n", yytext);
}
.	{

}

%%
 //SECCION 3: CODIGO ADICIONAL

void errorEnScanner(char* definicionDelError, char* variable){
	printf("\n\n\n\t%s %s \n", definicionDelError, variable);
	exit(EXIT_FAILURE);
}
