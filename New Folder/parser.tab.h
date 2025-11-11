/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    literal_entero_tk = 258,       /* literal_entero_tk  */
    literal_real_tk = 259,         /* literal_real_tk  */
    literal_caracter_tk = 260,     /* literal_caracter_tk  */
    literal_cadena_tk = 261,       /* literal_cadena_tk  */
    verdadero_tk = 262,            /* verdadero_tk  */
    falso_tk = 263,                /* falso_tk  */
    accion_tk = 264,               /* accion_tk  */
    faccion_tk = 265,              /* faccion_tk  */
    algoritmo_tk = 266,            /* algoritmo_tk  */
    falgoritmo_tk = 267,           /* falgoritmo_tk  */
    booleano_tk = 268,             /* booleano_tk  */
    cadena_tk = 269,               /* cadena_tk  */
    caracter_tk = 270,             /* caracter_tk  */
    const_tk = 271,                /* const_tk  */
    fconst_tk = 272,               /* fconst_tk  */
    continuar_tk = 273,            /* continuar_tk  */
    de_tk = 274,                   /* de_tk  */
    dev_tk = 275,                  /* dev_tk  */
    ent_tk = 276,                  /* ent_tk  */
    entero_tk = 277,               /* entero_tk  */
    e_s_tk = 278,                  /* e_s_tk  */
    funcion_tk = 279,              /* funcion_tk  */
    ffuncion_tk = 280,             /* ffuncion_tk  */
    mientras_tk = 281,             /* mientras_tk  */
    fmientras_tk = 282,            /* fmientras_tk  */
    para_tk = 283,                 /* para_tk  */
    fpara_tk = 284,                /* fpara_tk  */
    si_tk = 285,                   /* si_tk  */
    fsi_tk = 286,                  /* fsi_tk  */
    tipo_tk = 287,                 /* tipo_tk  */
    ftipo_tk = 288,                /* ftipo_tk  */
    tupla_tk = 289,                /* tupla_tk  */
    ftupla_tk = 290,               /* ftupla_tk  */
    var_tk = 291,                  /* var_tk  */
    fvar_tk = 292,                 /* fvar_tk  */
    hacer_tk = 293,                /* hacer_tk  */
    hasta_tk = 294,                /* hasta_tk  */
    no_tk = 295,                   /* no_tk  */
    o_tk = 296,                    /* o_tk  */
    real_tk = 297,                 /* real_tk  */
    ref_tk = 298,                  /* ref_tk  */
    sal_tk = 299,                  /* sal_tk  */
    tabla_tk = 300,                /* tabla_tk  */
    y_tk = 301,                    /* y_tk  */
    comentario_tk = 302,           /* comentario_tk  */
    id_tk = 303,                   /* id_tk  */
    id_bool_tk = 304,              /* id_bool_tk  */
    abrir_parentesis_tk = 305,     /* abrir_parentesis_tk  */
    cerrar_parentesis_tk = 306,    /* cerrar_parentesis_tk  */
    igual_tk = 307,                /* igual_tk  */
    inicio_array_tk = 308,         /* inicio_array_tk  */
    fin_array_tk = 309,            /* fin_array_tk  */
    coma_tk = 310,                 /* coma_tk  */
    punto_coma_tk = 311,           /* punto_coma_tk  */
    punto_tk = 312,                /* punto_tk  */
    dos_puntos_tk = 313,           /* dos_puntos_tk  */
    subrango_tk = 314,             /* subrango_tk  */
    asignacion_tk = 315,           /* asignacion_tk  */
    entonces_tk = 316,             /* entonces_tk  */
    si_no_si_tk = 317,             /* si_no_si_tk  */
    op1_tk = 318,                  /* op1_tk  */
    op2_tk = 319,                  /* op2_tk  */
    div_mod_tk = 320,              /* div_mod_tk  */
    oprel_tk = 321                 /* oprel_tk  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
