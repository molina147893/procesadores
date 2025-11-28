 //SECCION 1: DECLARACIONES
 //1.1 Constantes y codigo necesario.
%{
	//Importaciones necesarias
	#include <stdio.h> //Para poder escribir por terminal.
	#include <strings.h> //Para poder trabajar con cadenas de caracteres.
	#include <stdlib.h> //Para poder usar exit(), atof...
	#include <string.h>
	#include <stddef.h>
	
	#include "nombresDeTipos.h"    // Para NombreDeTipoT
	#include "traducciones.h"      // Para tipoListaNombre
	#include "parser.tab.h"        // Tokens de Bison
	#include "operadores.h"
	#include "cuadruplas.h"
	
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
mayor_igual_def >=
menor_igual_def <=
distinto_def <>
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
literal_entero_def {digito_def}({digito_def})*((e|E){digito_def}{digito_def}*)? 
literal_real_def ({digito_def}{digito_def}*(\.{digito_def}{digito_def}*)?((e|E){digito_def}{digito_def}*)?)|({literal_entero_def}(r|R))
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
	return literal_entero_tk;
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
			return literal_real_tk;
			free(cadena); //Liberamos el espacio
		}
	}
	else{
		printf("Literal real: %f\n", atof(yytext));
		return literal_real_tk;
	}
}
{literal_caracter_def}	{
	yylval.car = yytext[1];
	return literal_caracter_tk;
}
{literal_cadena_def}	{
	yylval.cad = strdup(yytext);
	return literal_cadena_tk;
}
{verdadero_def}	{
	return verdadero_tk;
}
{falso_def}	{
	return falso_tk;
}
{accion_def}	{
	return accion_tk;
}
{faccion_def}	{
	return faccion_tk;
}
{algoritmo_def}	{
	return algoritmo_tk;
}
{falgoritmo_def}	{
	return falgoritmo_tk;
}
{booleano_def}	{
	return booleano_tk;
}
{cadena_def}	{
	return cadena_tk;
}
{caracter_def}	{
	return caracter_tk;
}
{const_def}	{
	return const_tk;
}
{fconst_def}	{
	return fconst_tk;
}
{continuar_def}	{
	return continuar_tk;
}
{de_def}	{
	return de_tk;
}
{dev_def}	{
	return dev_tk;
}
{div_def}	{
	return div_mod_tk;
}
{ent_def}	{
	return ent_tk;
}
{entero_def}	{
	return entero_tk;
}
{e_s_def}	{	
	return e_s_tk;
}
{funcion_def}	{
	return funcion_tk;
}
{ffuncion_def}	{
	return ffuncion_tk;
}
{mientras_def}	{	
	return mientras_tk;
}
{fmientras_def}	{
	return fmientras_tk;
}
{para_def}	{
	return para_tk;
}
{fpara_def}	{
	return fpara_tk;
}
{si_def}	{
	return si_tk;
}
{fsi_def}	{
	return fsi_tk;
}
{tipo_def}	{
	return tipo_tk;
}
{ftipo_def}	{	
	return ftipo_tk;
}
{tupla_def}	{
	return tupla_tk;
}
{ftupla_def}	{
	return ftupla_tk;
}
{var_def}	{
	return var_tk;
}
{fvar_def}	{
	return fvar_tk;
}
{hacer_def}	{
	return hacer_tk;
}
{hasta_def}	{
	return hasta_tk;
}
{mod_def}	{
	return div_mod_tk;
}
{no_def}	{
	return no_tk;
}
{o_def}	{
	return o_tk;
}
{real_def}	{
	return real_tk;
}
{ref_def}	{
	return ref_tk;
}
{sal_def}	{
	return sal_tk;
}
{tabla_def}	{
	return tabla_tk;
}
{y_def}	{
	return y_tk;
}
{comentario_def}	{
	yylval.cad = strdup(yytext);
	return comentario_tk;
}
{id_def}	{
	yylval.cad = strdup(yytext);
    return id_tk;
}
{abrir_parentesis_def}	{
	return abrir_parentesis_tk;
}
{cerrar_parentesis_def}	{
	return cerrar_parentesis_tk;
}
{igual_def}	{
	return igual_tk;
}
{inicio_array_def}	{
	return inicio_array_tk;
}
{fin_array_def}	{
	return fin_array_tk;
}
{coma_def}	{
	return coma_tk;
}
{punto_coma_def}	{
	return punto_coma_tk;
}
{punto_def}	{
	return punto_tk;
}
{dos_puntos_def}	{
	return dos_puntos_tk;
}
{mayor_que_def}	{
	return oprel_tk;
}
{menor_que_def}	{
	return oprel_tk;
}
{mayor_igual_def}	{
	return oprel_tk;
}
{menor_igual_def}	{
	return oprel_tk;
}
{distinto_def}	{
	return oprel_tk;
}
{subrango_def}	{
	return subrango_tk;
}
{asignacion_def}	{
	return asignacion_tk;
}
{entonces_def}	{
	return entonces_tk;
}
{si_no_si_def}	{
	return si_no_si_tk;
}
{op1_def}	{
	yylval.op.operador = yytext[0];  //Guardamos si es + o -
	return op1_tk;
}
{op2_def}	{
	yylval.op.operador = yytext[0];  //Guardamos si es * o /
	return op2_tk;
}
.	{

}

%%
 //SECCION 3: CODIGO ADICIONAL
  //{comillas_dobles_def}	{
	//return comillas_dobles_tk;
 //}
 //{comilla_simple_def}	{
	//return comilla_simple_tk;
 //}
 //{barra_lateral_def}	{
	//return barra_lateral_tk;
 //}

void errorEnScanner(char* definicionDelError, char* variable){
	printf("\n\n\n\t%s %s \n", definicionDelError, variable);
	exit(EXIT_FAILURE);
}
