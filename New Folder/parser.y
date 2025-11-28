%{
	#include <stdio.h>
	#include <stdbool.h>
	#include <string.h>
	
	#include "nombresDeTipos.h"    // Para NombreDeTipoT
	#include "traducciones.h"      // Para tipoListaNombre
	#include "tablaSimbolos.h"     // Para las rutinas de TS
	#include "literal.h"
	#include "operadores.h"		//Para poder saber el operador exacto
	#include "cuadruplas.h"
	
	int yylex();
	extern FILE* yyin;
	void yyerror(char * s);
	//TablaDeConstantes tc;
	#define YYDEBUG 1
%}


%union {
    int ent; // literal entero
    float real; // literal real
    char car; // literal caracter
    int booleano; // verdadero 1 /falso 0 ??
    char* cad; // literal cadena
    NombreDeTipoT tipo;         // para d_tipo / tipo_base
    tipoListaNombre* lista; // para lista de ids
    OpInfo op;	//Operador exacto
}


%token <ent> literal_entero_tk
%token <real> literal_real_tk
%token <car> literal_caracter_tk
%token <cad> literal_cadena_tk
%token <booleano> verdadero_tk	// también podrías tratarlas como tokens sin valor y crear booleanos en el parser
%token <booleano> falso_tk

%token accion_tk
%token faccion_tk
%token algoritmo_tk
%token falgoritmo_tk
%token booleano_tk
%token cadena_tk
%token caracter_tk
%token <cad> const_tk
%token fconst_tk
%token continuar_tk
%token de_tk
%token dev_tk
//%token div_tk
%token ent_tk
%token entero_tk
%token e_s_tk
%token funcion_tk
%token ffuncion_tk
%token mientras_tk
%token fmientras_tk
%token para_tk
%token fpara_tk
%token si_tk
%token fsi_tk
%token tipo_tk
%token ftipo_tk
%token tupla_tk
%token ftupla_tk
%token var_tk
%token fvar_tk
%token hacer_tk
%token hasta_tk
//%token mod_tk
%token no_tk
%token o_tk
%token real_tk
%token ref_tk
%token sal_tk
%token tabla_tk
%token y_tk
%token <cad> comentario_tk
%token <cad> id_tk
%token id_bool_tk //b mayus/minus seguido de lo que sea
//%token comillas_dobles_tk
//%token comilla_simple_tk
//%token barra_lateral_tk
%token abrir_parentesis_tk
%token cerrar_parentesis_tk
%token igual_tk
%token inicio_array_tk
%token fin_array_tk
%token coma_tk
%token punto_coma_tk
%token punto_tk
%token dos_puntos_tk
//%token mayor_que_tk
//%token menor_que_tk
%token subrango_tk
%token asignacion_tk
%token entonces_tk
%token si_no_si_tk

%token op1_tk
%token op2_tk
%token div_mod_tk
%token oprel_tk


%left o_tk y_tk
%right no_tk
%nonassoc oprel_tk //?
%left op1_tk
%left op2_tk div_mod_tk

%type <tipo> d_tipo tipo_base
%type <lista> lista_d_var lista_id
%type <tipo> exp_a exp_b expresion operando_a operando_b literal_numerico
%type <op> op_1_tk op_2_tk

%%

//ProAlg

desc_algoritmo : algoritmo_tk id_tk punto_coma_tk cabecera_alg bloque_alg falgoritmo_tk punto_tk	{
};

cabecera_alg : decl_globales decl_a_f decl_ent_sal comentario_tk	{
};

bloque_alg : bloque comentario_tk	{
};

decl_globales : declaracion_tipo decl_globales	{
}
|	declaracion_const decl_globales	{
}
|	%empty	{
};

decl_a_f : accion_d decl_a_f	{
}
|	funcion_d decl_a_f	{
}
|	%empty	{
};

bloque : declaraciones instrucciones	{
};

declaraciones : declaracion_tipo declaraciones	{
}
|	declaracion_const declaraciones	{
}
|	declaracion_var declaraciones	{
}
|	%empty	{
};


//DECLARACIONES


declaracion_tipo : tipo_tk lista_d_tipo ftipo_tk punto_coma_tk	{
};

declaracion_const : const_tk lista_d_cte fconst_tk punto_coma_tk	{
};

declaracion_var : var_tk lista_d_var fvar_tk punto_coma_tk	{
};

//Declaraciones: Tipos

lista_d_tipo : id_tk igual_tk d_tipo punto_coma_tk lista_d_tipo	{
}
|	%empty	{
};

d_tipo : tupla_tk lista_campos ftupla_tk	{
}
|	tabla_tk inicio_array_tk expresion_t subrango_tk expresion_t fin_array_tk de_tk d_tipo	{
}
| id_tk	{
}
|	expresion_t subrango_tk expresion_t	{
}
|	ref_tk d_tipo	{
}
|	tipo_base	{
	$$ = $1;
};

//Esto lo hemos añadido nosotros, esta bien o hay que meterlo directamente en lista_d_tipo
tipo_base : entero_tk { 
	$$ = ENTERO; 
}
| real_tk    { 
	$$ = REAL; 
}
| booleano_tk { 
	$$ = BOOLEANO; 
}
| cadena_tk  { 
	$$ = CADENA; 
}
| caracter_tk { 
	$$ = CARACTER; 
};

expresion_t : expresion	{
}
|	literal_caracter_tk	{
};

lista_campos : id_tk dos_puntos_tk d_tipo punto_coma_tk lista_campos	{
}
|	%empty	{
};

//Declaraciones: Constantes y Variables

lista_d_cte : id_tk igual_tk literal punto_coma_tk lista_d_cte	{
}
|	%empty	{
}; //En algunas instalaciones de bison puede no reconocer, cambiar por un comentario del tipo /*empty*/ seria correcto

//Verdadero y falso correcto?
literal : literal_entero_tk	{
}
|	literal_real_tk	{
}
|	verdadero_tk	{
}
|	falso_tk	{
}
|	literal_cadena_tk	{
}
|	literal_caracter_tk	{
};

lista_d_var : lista_id dos_puntos_tk d_tipo punto_coma_tk lista_d_var	{
	insertarListaEnTS($1, $3); 
	liberarListaNombre($1); 
	$$ = $5;
}
|	%empty	{
	$$ = NULL;
};

lista_id : id_tk coma_tk lista_id	{
	nuevaCelda($3, $1); 
	$$ = $3;
}
|	id_tk	{
	$$ = nuevaLista();
	nuevaCelda($$, $1);
};

decl_ent_sal : decl_ent {
}
|	decl_ent decl_salida	{
}
| decl_salida	{
};

decl_ent : ent_tk lista_d_var	{
};

decl_salida : sal_tk lista_d_var	{
};


//EXPRESIONES

//Literal numerico??
exp_a : exp_a op1_tk exp_a	{
}
| 	exp_a op2_tk exp_a	{
}
| 	exp_a div_mod_tk exp_a	{
}
|	abrir_parentesis_tk exp_a cerrar_parentesis_tk	{
}
|	operando_a	{
}
|	literal_numerico	{
}
|	op1_tk exp_a	{
};

//Literal numerico es entero y real?
literal_numerico : literal_entero_tk	{
	$$ = ENTERO;
}
|	literal_real_tk	{
	$$ = REAL;
};

//oprel?? añadir al scanner mayor igual menor igual y distinto y juntarlos en comparadores
exp_b : exp_b y_tk exp_b	{
}
|	exp_b o_tk exp_b	{
}
|	no_tk exp_b	{
}
|	operando_b	{
}
|	verdadero_tk	{
}
|	falso_tk	{
}
|	expresion oprel_tk expresion	{
}
|	abrir_parentesis_tk exp_b cerrar_parentesis_tk	{
};

expresion : exp_a	{
}
|	exp_b	{
}
|	funcion_ll	{
};

operando_a : id_tk	{
}
|	operando_a punto_tk operando_a	{
}
|	operando_a inicio_array_tk expresion fin_array_tk	{
}
|	operando_a ref_tk	{
};

operando_b : id_bool_tk	{
}
|	operando_b punto_tk operando_b	{
}
|	operando_b inicio_array_tk expresion fin_array_tk	{
}
|	operando_b ref_tk	{
};

/*operando : id_tk	{

}
|	operando punto_tk operando	{

}
|	operando inicio_array_tk expresion fin_array_tk	{

}
|	operando ref_tk	{

};*/


//INSTRUCCIONES

instrucciones : instruccion punto_coma_tk instrucciones	{
}
|	instruccion	{
};

instruccion : continuar_tk	{
}
|	asignacion	{
}
|	alternativa	{
}
|	iteracion	{
}
|	accion_ll	{
};

asignacion : operando_a asignacion_tk expresion	{
}
|	operando_b asignacion_tk expresion	{
};

alternativa : si_tk expresion entonces_tk instrucciones lista_opciones fsi_tk	{
};

lista_opciones : si_no_si_tk expresion entonces_tk instrucciones lista_opciones	{
}
| %empty	{
};

iteracion : it_cota_fija	{
}
|	it_cota_exp	{
};

it_cota_exp : mientras_tk expresion hacer_tk instrucciones fmientras_tk	{
};

it_cota_fija : para_tk id_tk asignacion_tk expresion hasta_tk expresion hacer_tk instrucciones fpara_tk	{
};


//ACCIONES Y FUNCIONES

accion_d : accion_tk a_cabecera bloque faccion_tk	{
};

funcion_d : funcion_tk f_cabecera bloque dev_tk expresion ffuncion_tk	{
};

a_cabecera : id_tk abrir_parentesis_tk d_par_form cerrar_parentesis_tk punto_coma_tk	{
};

f_cabecera : id_tk abrir_parentesis_tk lista_d_var cerrar_parentesis_tk dev_tk d_tipo punto_coma_tk	{
};

d_par_form : d_p_form punto_coma_tk d_par_form	{
}
|	%empty	{
};

d_p_form : ent_tk lista_id dos_puntos_tk d_tipo	{
}
|	sal_tk lista_id dos_puntos_tk d_tipo	{
}
| e_s_tk lista_id dos_puntos_tk d_tipo	{
};

accion_ll : id_tk abrir_parentesis_tk l_ll cerrar_parentesis_tk	{
};

funcion_ll : id_tk abrir_parentesis_tk l_ll cerrar_parentesis_tk	{
};

l_ll : expresion coma_tk l_ll	{
}
|	expresion	{
};

%%

int main(int argc, char **argv){
	#if defined YYDEBUG
	yydebug=1;
	#endif
	++argv, --argc;
	if (argc > 0)
		yyin = fopen(argv[0], "r");
	else
		yyin = stdin;
	TS = NULL;       // Inicializa la TS
	yyparse();
	imprimirTS();    // solo para debug
}

void yyerror(char * s){
	printf("\tBISON: ERROR, %s\n", s);
}
