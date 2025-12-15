%{
	#include <stdio.h>
	#include <stdbool.h>
	#include <string.h>
	#include <stdlib.h>
	
	#include "nombresDeTipos.h"    
	#include "traducciones.h"   
	#include "tablaSimbolos.h"     
	#include "cuadruplas.h"
	
	int yylex();
	extern FILE* yyin;
	void yyerror(char * s);

%}


%union {
    int ent; 
    float real; 
    char car; 
    int booleano; 
    char* cad; 
    NombreDeTipoT tipo; 
    tipoListaNombre* lista; // para lista de ids
    OpInfo op;	//Operador exacto
    AtributosExpresion atr; // atributos .place .type
    AuxM auxM;
    AuxN auxN;
}


%token <ent> literal_entero_tk
%token <real> literal_real_tk
%token <car> literal_caracter_tk
%token <cad> literal_cadena_tk
%token <booleano> verdadero_tk
%token <booleano> falso_tk
%token <op> op1_tk op2_tk div_mod_tk

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
%token no_tk
%token o_tk
%token real_tk
%token ref_tk
%token sal_tk
%token tabla_tk
%token y_tk
%token <cad> comentario_tk
%token <cad> id_tk
%token <cad> id_bool_tk //b mayus/minus seguido de lo que sea
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
%token subrango_tk
%token <op> asignacion_tk
%token entonces_tk
%token si_no_si_tk

%token <op> oprel_tk


%left o_tk y_tk
%right no_tk
%nonassoc oprel_tk //?
%left op1_tk
%left op2_tk div_mod_tk

%type <tipo> d_tipo tipo_base
%type <lista> lista_d_var lista_id
%type <atr> expresion exp_a operando_a literal_numerico
%type <atr> exp_b operando_b 
%type <auxM> M
%type <auxN> N lista_opciones instrucciones instruccion


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
| tabla_tk inicio_array_tk expresion_t subrango_tk expresion_t fin_array_tk de_tk d_tipo	{
}
| id_tk	{
}
| expresion_t subrango_tk expresion_t	{
}
| ref_tk d_tipo	{
}
| tipo_base	{
	$$ = $1;
};

//Esto lo hemos añadido nosotros
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
| literal_caracter_tk	{
};

lista_campos : id_tk dos_puntos_tk d_tipo punto_coma_tk lista_campos	{
}
| %empty	{
};

//Declaraciones: Constantes y Variables

lista_d_cte : id_tk igual_tk literal punto_coma_tk lista_d_cte	{
}
|	%empty	{
}; 

literal : literal_entero_tk	{
}
| literal_real_tk	{
}
| verdadero_tk	{
}
| falso_tk	{
}
| literal_cadena_tk	{
}
| literal_caracter_tk	{
};

lista_d_var : lista_id dos_puntos_tk d_tipo punto_coma_tk lista_d_var{
	insertarListaEnTS($1, $3); 
	liberarListaNombre($1); 
	$$ = $5;
}
|%empty	{
	$$ = NULL;
};

lista_id : id_tk coma_tk lista_id	{
	nuevaCelda($3, $1); 
	$$ = $3;
}
|	id_bool_tk coma_tk lista_id	{
	nuevaCelda($3, $1);
	$$ = $3;
}
| id_tk	{
	$$ = nuevaLista();
	nuevaCelda($$, $1);
}
| id_bool_tk{
	$$ = nuevaLista();
	nuevaCelda($$, $1);
};

decl_ent_sal : decl_ent {
}
| decl_ent decl_salida	{
}
| decl_salida	{
};

decl_ent : ent_tk lista_d_var	{
};

decl_salida : sal_tk lista_d_var	{
};


//EXPRESIONES

exp_a : exp_a op1_tk exp_a	{
	entradaTS* t = insertarTemp(); 
	$$.place = t->sid;
	if(($1.type == ENTERO) && ($3.type == ENTERO)){
		modificarTipoTS(t, ENTERO);
		$$.type = ENTERO;
		gen($2.operador, $3.place, $1.place, $$.place);
	}
	else{
		modificarTipoTS(t, REAL);
		$$.type = REAL;
		if(($1.type == ENTERO) && ($3.type == REAL)){
			gen(OP_INT2REAL, $1.place, -1, $$.place);
			gen($2.operador, $$.place, $3.place, $$.place);
		}
		else if(($1.type == REAL) && ($3.type == ENTERO)){
			gen(OP_INT2REAL, $3.place, -1, $$.place);
			gen($2.operador, $1.place, $$.place, $$.place);
		}
		else if(($1.type == REAL) && ($3.type == REAL)){
			gen($2.operador, $1.place, $3.place, $$.place);
		}
	}
}
| exp_a op2_tk exp_a{
	entradaTS* t = insertarTemp();
	$$.place = t->sid;
	if(($1.type == ENTERO) && ($3.type == ENTERO)){
		if($2.operador == OP_DIV){
			printf("ERROR: Estas haciendo una division con tipos imposibles\n");
		}
		else{
			modificarTipoTS(t, ENTERO);
			$$.type = ENTERO;
			gen($2.operador, $1.place, $3.place, $$.place);
		}
	}
	else{
		modificarTipoTS(t, REAL);
		$$.type = REAL;
		if(($1.type == ENTERO) && ($3.type == REAL)){
			gen(OP_INT2REAL, $1.place, -1, $$.place);
			gen($2.operador, $$.place, $3.place, $$.place);
		}
		else if(($1.type == REAL) && ($3.type == ENTERO)){
			gen(OP_INT2REAL, $3.place, -1, $$.place);
			gen($2.operador, $1.place, $$.place, $$.place);
		}
		else if(($1.type == REAL) && ($3.type == REAL)){
			gen($2.operador, $1.place, $3.place, $$.place);
		}
	}
}
| exp_a div_mod_tk exp_a{
	entradaTS* t = insertarTemp();
	$$.place = t->sid;
	if(($1.type == ENTERO) && ($3.type == ENTERO)){
		modificarTipoTS(t,ENTERO);
		$$.type = ENTERO;
		gen($2.operador, $3.place, $1.place, $$.place);
	}else{
		printf("ERROR: Estas haciendo un div/mod con tipos incompatibles\n");
	}
}
| abrir_parentesis_tk exp_a cerrar_parentesis_tk{
	$$.place = $2.place;
	$$.type  = $2.type;
}
| operando_a	{
	if(($1.type == ENTERO) || ($1.type == REAL)){ 
		$$.type = $1.type;
		$$.place = $1.place;
	}
	else{
		printf("ERROR: Tipo no permitido en operaciones aritmeticas\n");
	}
}
| literal_numerico	{
	$$.type = $1.type;
	$$.place = $1.place;
}
| op1_tk exp_a	{
	if ($1.operador != OP_REST) {
		printf("Error: operador unario no soportado\n");
	}
	entradaTS* t = insertarTemp();
	$$.place = t->sid;
	modificarTipoTS(t, $2.type);
	$$.type = $2.type;
	gen($1.operador, $2.place, -1, $$.place); // resta = negación unaria
};

literal_numerico : literal_entero_tk	{
	$$.place = $1;
	$$.type  = ENTERO;
	$$.esLiteral = 1; 
}
|literal_real_tk{
	$$.place = $1;
	$$.type  = REAL;
	$$.esLiteral = 1;
};

exp_b : exp_b y_tk M exp_b {
	backpatch(&($1.TRUE), $3.QUAD);
	$$.TRUE = $4.TRUE;
	$$.FALSE = merge($1.FALSE, $4.FALSE);
}
| exp_b o_tk M exp_b {
	backpatch(&($1.FALSE), $3.QUAD);
	$$.TRUE = merge($1.TRUE, $4.TRUE);
	$$.FALSE = $4.FALSE;
}
| no_tk exp_b {
	$$.FALSE = $2.TRUE;
	$$.TRUE = $2.FALSE;
}
| operando_b {
	$$.TRUE = $1.TRUE;
	$$.FALSE = $1.FALSE;
}
| verdadero_tk {
	int q = nextQuad();
    	gen(GOTO, -1, -1, -1);
    	$$.TRUE  = makelist(q);
    	$$.FALSE = (ListaCuads){ NULL };
}
| falso_tk {
	int q = nextQuad();
    	gen(GOTO, -1, -1, -1);
    	$$.FALSE = makelist(q);
    	$$.TRUE  = (ListaCuads){ NULL };
}
| expresion oprel_tk expresion {
	
	int qTrue = nextQuad();
	gen($2.operador, $1.place, $3.place, -1); // salto condicional
	int qFalse = nextQuad();
	gen(GOTO, -1, -1, -1); // salto incondicional
	$$.TRUE  = makelist(qTrue);
	$$.FALSE = makelist(qFalse);
}
| abrir_parentesis_tk exp_b cerrar_parentesis_tk {
	$$.TRUE = $2.TRUE;
	$$.FALSE = $2.FALSE;
};

M : %empty 	{
	$$.QUAD = nextQuad();
};

N : %empty	{
	$$.NEXT = makelist(nextQuad());
	gen(GOTO, -1, -1, -1);
};

expresion : exp_a	{
	$$.type = $1.type;
	$$.place = $1.place;
}
| exp_b	{
	$$.type = BOOLEANO;
	$$.TRUE = $1.TRUE;
	$$.FALSE = $1.FALSE;
}
| funcion_ll	{
};

operando_a : id_tk	{
	entradaTS* t = buscarPorNombre($1);
	if (!t) {
		printf("Error: variable %s no declarada\n", $1);
	}
	$$.place = t->sid;
	$$.type  = t->tipo;
	t = NULL;
}
| operando_a punto_tk operando_a	{
}
| operando_a inicio_array_tk expresion fin_array_tk	{
}
| operando_a ref_tk	{
};

operando_b : id_bool_tk	{
	entradaTS* t = buscarPorNombre($1);
	if(!t){
		printf("ERROR: variable %s no declarada\n", $1);
	}
	$$.place = t->sid;
	$$.type = BOOLEANO;
	int qTrue  = nextQuad();
    	gen(OP_IF_TRUE, t->sid, -1, -1);
    	int qFalse = nextQuad();
    	gen(GOTO, -1, -1, -1);
    	$$.TRUE  = makelist(qTrue);
    	$$.FALSE = makelist(qFalse);
}
| operando_b punto_tk operando_b	{
}
| operando_b inicio_array_tk expresion fin_array_tk	{
}
| operando_b ref_tk	{
};


//INSTRUCCIONES

instrucciones : instruccion punto_coma_tk instrucciones	{
}
|	instruccion	{
};

instruccion : continuar_tk N{
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
	if($1.type == $3.type){
		gen($2.operador, $3.place, -1, $1.place);
	}
	else if($1.type == REAL && $3.type == ENTERO){
		entradaTS* t = insertarTemp();
		modificarTipoTS(t, $1.type);
		gen(OP_INT2REAL, $3.place, -1, t->sid); // conversion
		gen($2.operador, t->sid, -1, $1.place); // asignacion
	}
	else if($1.type == ENTERO && $3.type == REAL){
		printf("ERROR: no se puede asignar REAL a ENTERO\n");
	}
	else{
		printf("ERROR: Tipos incompatibles en asignacion\n");
	}
}
|	operando_b asignacion_tk expresion	{
	if ($1.type != BOOLEANO || $3.type != BOOLEANO) {
        	printf("ERROR: Tipos incompatibles en asignacion booleana\n");
    	} 
    	else {
		backpatch(&($3.TRUE), nextQuad());
		gen($2.operador, $3.place, -1, $1.place);   // TRUE
		backpatch(&($3.FALSE), nextQuad());
		gen($2.operador, 0, -1, $1.place);   // FALSE
    }
};

alternativa : si_tk expresion entonces_tk M instrucciones lista_opciones fsi_tk	{

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
	++argv, --argc;
	if (argc > 0)
		yyin = fopen(argv[0], "r");
	else
		yyin = stdin;
	TS = NULL;       // Inicializa la TS
	tQuad = crearTabla(10); // inicializa tabla global de cuadruplas
	
	yyparse();
	
	// Salida por pantalla
	imprimirTS();
	imprimirTC(&tQuad);
	
	// Salida a ficheros
	FILE *fts = fopen("tabla_simbolos.txt", "w");
    FILE *ftc = fopen("tabla_cuadruplas.txt", "w");

    if (!fts || !ftc) {
        fprintf(stderr, "ERROR: no se pudieron crear los ficheros de salida\n");
    } else {
        imprimirTS_en(fts);
        imprimirTC_en(ftc, &tQuad);
    }

    if (fts)
		fclose(fts);
    if (ftc)
		fclose(ftc);

    return 0;
}

void yyerror(char *s){
    fprintf(stderr, "BISON, ERROR: %s\n", s);
}

