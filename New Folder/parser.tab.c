/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

	#include <stdio.h>
	#include <stdbool.h>
	#include <string.h>
	
	#include "nombresDeTipos.h"    // Para NombreDeTipoT
	#include "traducciones.h"      // Para tipoListaNombre
	#include "tablaSimbolos.h"     // Para las rutinas de TS
	#include "literal.h"
	
	int yylex();
	extern FILE* yyin;
	void yyerror(char * s);
	//TablaDeConstantes tc;
	#define YYDEBUG 1

#line 88 "parser.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_literal_entero_tk = 3,          /* literal_entero_tk  */
  YYSYMBOL_literal_real_tk = 4,            /* literal_real_tk  */
  YYSYMBOL_literal_caracter_tk = 5,        /* literal_caracter_tk  */
  YYSYMBOL_literal_cadena_tk = 6,          /* literal_cadena_tk  */
  YYSYMBOL_verdadero_tk = 7,               /* verdadero_tk  */
  YYSYMBOL_falso_tk = 8,                   /* falso_tk  */
  YYSYMBOL_accion_tk = 9,                  /* accion_tk  */
  YYSYMBOL_faccion_tk = 10,                /* faccion_tk  */
  YYSYMBOL_algoritmo_tk = 11,              /* algoritmo_tk  */
  YYSYMBOL_falgoritmo_tk = 12,             /* falgoritmo_tk  */
  YYSYMBOL_booleano_tk = 13,               /* booleano_tk  */
  YYSYMBOL_cadena_tk = 14,                 /* cadena_tk  */
  YYSYMBOL_caracter_tk = 15,               /* caracter_tk  */
  YYSYMBOL_const_tk = 16,                  /* const_tk  */
  YYSYMBOL_fconst_tk = 17,                 /* fconst_tk  */
  YYSYMBOL_continuar_tk = 18,              /* continuar_tk  */
  YYSYMBOL_de_tk = 19,                     /* de_tk  */
  YYSYMBOL_dev_tk = 20,                    /* dev_tk  */
  YYSYMBOL_ent_tk = 21,                    /* ent_tk  */
  YYSYMBOL_entero_tk = 22,                 /* entero_tk  */
  YYSYMBOL_e_s_tk = 23,                    /* e_s_tk  */
  YYSYMBOL_funcion_tk = 24,                /* funcion_tk  */
  YYSYMBOL_ffuncion_tk = 25,               /* ffuncion_tk  */
  YYSYMBOL_mientras_tk = 26,               /* mientras_tk  */
  YYSYMBOL_fmientras_tk = 27,              /* fmientras_tk  */
  YYSYMBOL_para_tk = 28,                   /* para_tk  */
  YYSYMBOL_fpara_tk = 29,                  /* fpara_tk  */
  YYSYMBOL_si_tk = 30,                     /* si_tk  */
  YYSYMBOL_fsi_tk = 31,                    /* fsi_tk  */
  YYSYMBOL_tipo_tk = 32,                   /* tipo_tk  */
  YYSYMBOL_ftipo_tk = 33,                  /* ftipo_tk  */
  YYSYMBOL_tupla_tk = 34,                  /* tupla_tk  */
  YYSYMBOL_ftupla_tk = 35,                 /* ftupla_tk  */
  YYSYMBOL_var_tk = 36,                    /* var_tk  */
  YYSYMBOL_fvar_tk = 37,                   /* fvar_tk  */
  YYSYMBOL_hacer_tk = 38,                  /* hacer_tk  */
  YYSYMBOL_hasta_tk = 39,                  /* hasta_tk  */
  YYSYMBOL_no_tk = 40,                     /* no_tk  */
  YYSYMBOL_o_tk = 41,                      /* o_tk  */
  YYSYMBOL_real_tk = 42,                   /* real_tk  */
  YYSYMBOL_ref_tk = 43,                    /* ref_tk  */
  YYSYMBOL_sal_tk = 44,                    /* sal_tk  */
  YYSYMBOL_tabla_tk = 45,                  /* tabla_tk  */
  YYSYMBOL_y_tk = 46,                      /* y_tk  */
  YYSYMBOL_comentario_tk = 47,             /* comentario_tk  */
  YYSYMBOL_id_tk = 48,                     /* id_tk  */
  YYSYMBOL_id_bool_tk = 49,                /* id_bool_tk  */
  YYSYMBOL_abrir_parentesis_tk = 50,       /* abrir_parentesis_tk  */
  YYSYMBOL_cerrar_parentesis_tk = 51,      /* cerrar_parentesis_tk  */
  YYSYMBOL_igual_tk = 52,                  /* igual_tk  */
  YYSYMBOL_inicio_array_tk = 53,           /* inicio_array_tk  */
  YYSYMBOL_fin_array_tk = 54,              /* fin_array_tk  */
  YYSYMBOL_coma_tk = 55,                   /* coma_tk  */
  YYSYMBOL_punto_coma_tk = 56,             /* punto_coma_tk  */
  YYSYMBOL_punto_tk = 57,                  /* punto_tk  */
  YYSYMBOL_dos_puntos_tk = 58,             /* dos_puntos_tk  */
  YYSYMBOL_subrango_tk = 59,               /* subrango_tk  */
  YYSYMBOL_asignacion_tk = 60,             /* asignacion_tk  */
  YYSYMBOL_entonces_tk = 61,               /* entonces_tk  */
  YYSYMBOL_si_no_si_tk = 62,               /* si_no_si_tk  */
  YYSYMBOL_op1_tk = 63,                    /* op1_tk  */
  YYSYMBOL_op2_tk = 64,                    /* op2_tk  */
  YYSYMBOL_div_mod_tk = 65,                /* div_mod_tk  */
  YYSYMBOL_oprel_tk = 66,                  /* oprel_tk  */
  YYSYMBOL_YYACCEPT = 67,                  /* $accept  */
  YYSYMBOL_desc_algoritmo = 68,            /* desc_algoritmo  */
  YYSYMBOL_cabecera_alg = 69,              /* cabecera_alg  */
  YYSYMBOL_bloque_alg = 70,                /* bloque_alg  */
  YYSYMBOL_decl_globales = 71,             /* decl_globales  */
  YYSYMBOL_decl_a_f = 72,                  /* decl_a_f  */
  YYSYMBOL_bloque = 73,                    /* bloque  */
  YYSYMBOL_declaraciones = 74,             /* declaraciones  */
  YYSYMBOL_declaracion_tipo = 75,          /* declaracion_tipo  */
  YYSYMBOL_declaracion_const = 76,         /* declaracion_const  */
  YYSYMBOL_declaracion_var = 77,           /* declaracion_var  */
  YYSYMBOL_lista_d_tipo = 78,              /* lista_d_tipo  */
  YYSYMBOL_d_tipo = 79,                    /* d_tipo  */
  YYSYMBOL_tipo_base = 80,                 /* tipo_base  */
  YYSYMBOL_expresion_t = 81,               /* expresion_t  */
  YYSYMBOL_lista_campos = 82,              /* lista_campos  */
  YYSYMBOL_lista_d_cte = 83,               /* lista_d_cte  */
  YYSYMBOL_literal = 84,                   /* literal  */
  YYSYMBOL_lista_d_var = 85,               /* lista_d_var  */
  YYSYMBOL_lista_id = 86,                  /* lista_id  */
  YYSYMBOL_decl_ent_sal = 87,              /* decl_ent_sal  */
  YYSYMBOL_decl_ent = 88,                  /* decl_ent  */
  YYSYMBOL_decl_salida = 89,               /* decl_salida  */
  YYSYMBOL_exp_a = 90,                     /* exp_a  */
  YYSYMBOL_literal_numerico = 91,          /* literal_numerico  */
  YYSYMBOL_exp_b = 92,                     /* exp_b  */
  YYSYMBOL_expresion = 93,                 /* expresion  */
  YYSYMBOL_operando_a = 94,                /* operando_a  */
  YYSYMBOL_operando_b = 95,                /* operando_b  */
  YYSYMBOL_instrucciones = 96,             /* instrucciones  */
  YYSYMBOL_instruccion = 97,               /* instruccion  */
  YYSYMBOL_asignacion = 98,                /* asignacion  */
  YYSYMBOL_alternativa = 99,               /* alternativa  */
  YYSYMBOL_lista_opciones = 100,           /* lista_opciones  */
  YYSYMBOL_iteracion = 101,                /* iteracion  */
  YYSYMBOL_it_cota_exp = 102,              /* it_cota_exp  */
  YYSYMBOL_it_cota_fija = 103,             /* it_cota_fija  */
  YYSYMBOL_accion_d = 104,                 /* accion_d  */
  YYSYMBOL_funcion_d = 105,                /* funcion_d  */
  YYSYMBOL_a_cabecera = 106,               /* a_cabecera  */
  YYSYMBOL_f_cabecera = 107,               /* f_cabecera  */
  YYSYMBOL_d_par_form = 108,               /* d_par_form  */
  YYSYMBOL_d_p_form = 109,                 /* d_p_form  */
  YYSYMBOL_accion_ll = 110,                /* accion_ll  */
  YYSYMBOL_funcion_ll = 111,               /* funcion_ll  */
  YYSYMBOL_l_ll = 112                      /* l_ll  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   268

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  67
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  46
/* YYNRULES -- Number of rules.  */
#define YYNRULES  109
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  242

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   321


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   118,   118,   121,   124,   127,   129,   131,   134,   136,
     138,   141,   144,   146,   148,   150,   157,   160,   163,   168,
     170,   173,   175,   177,   179,   181,   183,   188,   191,   194,
     197,   200,   204,   206,   209,   211,   216,   218,   222,   224,
     226,   228,   230,   232,   235,   240,   244,   248,   253,   255,
     257,   260,   263,   270,   272,   274,   276,   278,   280,   282,
     286,   288,   292,   294,   296,   298,   300,   302,   304,   306,
     309,   311,   313,   316,   318,   320,   322,   325,   327,   329,
     331,   350,   352,   355,   357,   359,   361,   363,   366,   368,
     371,   374,   376,   379,   381,   384,   387,   393,   396,   399,
     402,   405,   407,   410,   412,   414,   417,   420,   423,   425
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "literal_entero_tk",
  "literal_real_tk", "literal_caracter_tk", "literal_cadena_tk",
  "verdadero_tk", "falso_tk", "accion_tk", "faccion_tk", "algoritmo_tk",
  "falgoritmo_tk", "booleano_tk", "cadena_tk", "caracter_tk", "const_tk",
  "fconst_tk", "continuar_tk", "de_tk", "dev_tk", "ent_tk", "entero_tk",
  "e_s_tk", "funcion_tk", "ffuncion_tk", "mientras_tk", "fmientras_tk",
  "para_tk", "fpara_tk", "si_tk", "fsi_tk", "tipo_tk", "ftipo_tk",
  "tupla_tk", "ftupla_tk", "var_tk", "fvar_tk", "hacer_tk", "hasta_tk",
  "no_tk", "o_tk", "real_tk", "ref_tk", "sal_tk", "tabla_tk", "y_tk",
  "comentario_tk", "id_tk", "id_bool_tk", "abrir_parentesis_tk",
  "cerrar_parentesis_tk", "igual_tk", "inicio_array_tk", "fin_array_tk",
  "coma_tk", "punto_coma_tk", "punto_tk", "dos_puntos_tk", "subrango_tk",
  "asignacion_tk", "entonces_tk", "si_no_si_tk", "op1_tk", "op2_tk",
  "div_mod_tk", "oprel_tk", "$accept", "desc_algoritmo", "cabecera_alg",
  "bloque_alg", "decl_globales", "decl_a_f", "bloque", "declaraciones",
  "declaracion_tipo", "declaracion_const", "declaracion_var",
  "lista_d_tipo", "d_tipo", "tipo_base", "expresion_t", "lista_campos",
  "lista_d_cte", "literal", "lista_d_var", "lista_id", "decl_ent_sal",
  "decl_ent", "decl_salida", "exp_a", "literal_numerico", "exp_b",
  "expresion", "operando_a", "operando_b", "instrucciones", "instruccion",
  "asignacion", "alternativa", "lista_opciones", "iteracion",
  "it_cota_exp", "it_cota_fija", "accion_d", "funcion_d", "a_cabecera",
  "f_cabecera", "d_par_form", "d_p_form", "accion_ll", "funcion_ll",
  "l_ll", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-134)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-24)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      18,    -1,   124,    -6,  -134,    83,    94,    96,    51,    87,
      83,    83,   109,   158,   130,   151,   128,   175,   160,     9,
      51,    51,    51,   141,   162,     2,    87,    87,  -134,  -134,
     191,   134,   143,   152,   154,   174,   155,   159,  -134,  -134,
      45,   164,    45,   169,  -134,    57,   102,  -134,   165,  -134,
    -134,  -134,  -134,  -134,  -134,  -134,  -134,  -134,   170,    51,
     172,    51,   128,   128,   176,   180,  -134,  -134,  -134,  -134,
    -134,  -134,  -134,  -134,  -134,   171,  -134,  -134,  -134,  -134,
    -134,  -134,  -134,  -134,  -134,  -134,   177,    45,  -134,   143,
     173,    42,    45,    28,   178,  -134,   179,   137,  -134,    -8,
     163,   110,   117,  -134,  -134,   128,   181,   143,  -134,   182,
     -25,   184,    65,    45,  -134,    45,   185,    45,  -134,    45,
     186,    45,     9,    22,   218,   128,   210,  -134,  -134,  -134,
    -134,    94,   187,   196,  -134,   163,  -134,    14,    45,    58,
      86,  -134,    28,    -5,    96,    14,    28,    28,    28,    45,
      45,    45,  -134,  -134,   190,     9,    45,     9,    50,   188,
     -26,   110,   163,   -24,   117,   163,  -134,   128,   128,   128,
     189,   192,  -134,   198,    45,  -134,   143,  -134,   193,   199,
    -134,  -134,    58,  -134,  -134,    -5,  -134,  -134,  -134,  -134,
     194,   128,   209,   -15,   195,    45,  -134,  -134,  -134,   197,
     200,   201,   205,    22,   221,   -11,   206,    14,  -134,  -134,
    -134,    45,    45,   211,  -134,   143,   143,   143,  -134,  -134,
     143,  -134,   177,   202,   -22,    74,  -134,  -134,  -134,  -134,
     207,  -134,   224,     9,     9,  -134,   143,   222,   195,  -134,
    -134,  -134
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     1,     7,    37,    20,    15,    10,
       7,     7,     0,     0,     0,     0,    45,     0,     0,     0,
      15,    15,    15,     0,     0,     0,    10,    10,     5,     6,
       0,     0,     0,     0,    47,     0,     0,     0,     4,    83,
       0,     0,     0,    73,    77,     0,     0,    11,    82,    84,
      85,    86,    94,    93,    87,    12,    13,    14,     0,    15,
       0,    15,    45,    45,     0,    48,    50,     8,     9,    38,
      39,    43,    42,    40,    41,     0,    17,    60,    61,    33,
      66,    67,    29,    30,    31,    27,    35,     0,    28,     0,
       0,    73,     0,     0,     0,    26,     0,    70,    58,    71,
      32,    57,    65,    72,    16,     0,     0,     0,     2,    73,
       0,     0,     0,     0,    76,     0,     0,     0,    80,     0,
       0,     0,     0,   102,     0,    45,     0,    51,    52,     3,
      49,    37,     0,     0,    64,     0,    25,     0,     0,    70,
      71,    73,     0,    59,    20,     0,     0,     0,     0,     0,
       0,     0,    46,    18,     0,     0,     0,     0,   109,     0,
       0,    74,    88,     0,    78,    89,    81,     0,     0,     0,
       0,     0,    97,     0,     0,    36,     0,    21,     0,     0,
      56,    69,     0,    19,    24,    53,    54,    55,    63,    62,
      68,    45,     0,     0,    92,     0,   106,    75,    79,     0,
       0,     0,     0,   102,     0,     0,     0,     0,   107,    44,
      95,     0,     0,     0,   108,     0,     0,     0,    99,   101,
       0,    98,    35,     0,     0,     0,    90,   103,   105,   104,
       0,    34,     0,     0,     0,   100,     0,     0,    92,    22,
      96,    91
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -134,  -134,  -134,  -134,    91,   142,    93,   183,   161,   168,
    -134,   103,   -87,  -134,  -133,    31,   123,  -134,   -57,   -98,
    -134,  -134,   203,   -67,  -134,   -77,   -31,   -19,   -16,  -121,
    -134,  -134,  -134,    26,  -134,  -134,  -134,  -134,  -134,  -134,
    -134,    62,  -134,  -134,  -134,  -130
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,     8,    17,     9,    25,    18,    19,    20,    21,
      22,    15,    94,    95,    96,   133,    13,    75,    35,    36,
      64,    65,    66,    97,    98,    99,   100,   101,   102,    47,
      48,    49,    50,   213,    51,    52,    53,    26,    27,    59,
      61,   170,   171,    54,   103,   159
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      45,   166,   136,    46,   178,   127,   128,   152,   179,   110,
     134,   112,   184,   155,   221,   140,   233,    77,    78,    79,
     154,    80,    81,    62,   211,   139,   143,    39,   197,     1,
     198,    77,    78,   149,   192,    40,   194,    41,   150,    42,
     151,   151,   151,   167,   151,   168,    63,     3,    77,    78,
       5,   151,    80,    81,    87,   151,   135,    43,    44,   147,
     148,   135,   109,    44,    92,   214,   169,     6,   173,   199,
     200,   201,   188,   189,   223,   182,   141,    93,   142,   185,
     186,   187,   158,     7,   160,    87,   162,    16,   163,   206,
     165,    93,   138,   109,    44,    92,    23,   161,   -23,     6,
     114,    28,    29,    45,   164,   195,    46,   158,    93,   180,
     115,    24,   237,   238,   116,     7,   151,   117,   135,   135,
     190,   146,   147,   148,     4,   193,   157,   149,   227,   228,
     229,   151,   150,   230,   209,   234,    45,   181,    45,    46,
     151,    46,    12,   205,    14,   118,    77,    78,    79,   239,
      80,    81,   124,   114,   126,   119,    82,    83,    84,   120,
     118,    30,   121,   115,   158,    85,    10,   116,    67,    68,
     119,    10,    10,    11,   120,    31,    34,    86,    11,    11,
     224,   225,    32,    87,    33,    88,    89,    37,    90,    58,
      76,    91,    44,    92,    69,    70,    71,    72,    73,    74,
     146,   147,   148,    55,    56,    57,    93,    38,   104,   105,
      60,   106,   111,   107,    45,    45,   108,    46,    46,   113,
     123,   122,   125,   129,    63,   132,   137,   131,   172,   151,
     174,   177,   138,   141,   144,    44,   210,   153,   145,   196,
     202,   220,   226,   236,   156,   176,   191,   183,   203,   204,
     208,   240,   207,   231,   175,   215,   232,   212,   216,   217,
     -24,   218,   222,   235,   241,   219,     0,     0,   130
};

static const yytype_int16 yycheck[] =
{
      19,   122,    89,    19,   137,    62,    63,   105,   138,    40,
      87,    42,   145,    38,    25,    92,    38,     3,     4,     5,
     107,     7,     8,    21,    39,    92,    93,    18,    54,    11,
      54,     3,     4,    41,   155,    26,   157,    28,    46,    30,
      66,    66,    66,    21,    66,    23,    44,    48,     3,     4,
      56,    66,     7,     8,    40,    66,    87,    48,    49,    64,
      65,    92,    48,    49,    50,   195,    44,    16,   125,   167,
     168,   169,   149,   150,   207,   142,    48,    63,    50,   146,
     147,   148,   113,    32,   115,    40,   117,    36,   119,   176,
     121,    63,    50,    48,    49,    50,     9,   116,    56,    16,
      43,    10,    11,   122,   120,    55,   122,   138,    63,    51,
      53,    24,   233,   234,    57,    32,    66,    60,   149,   150,
     151,    63,    64,    65,     0,   156,    61,    41,   215,   216,
     217,    66,    46,   220,   191,    61,   155,    51,   157,   155,
      66,   157,    48,   174,    48,    43,     3,     4,     5,   236,
       7,     8,    59,    43,    61,    53,    13,    14,    15,    57,
      43,    52,    60,    53,   195,    22,     5,    57,    26,    27,
      53,    10,    11,     5,    57,    17,    48,    34,    10,    11,
     211,   212,    52,    40,    33,    42,    43,    12,    45,    48,
      56,    48,    49,    50,     3,     4,     5,     6,     7,     8,
      63,    64,    65,    20,    21,    22,    63,    47,    56,    55,
      48,    37,    48,    58,   233,   234,    57,   233,   234,    50,
      50,    56,    50,    47,    44,    48,    53,    56,    10,    66,
      20,    35,    50,    48,    56,    49,    27,    56,    59,    51,
      51,    20,    31,    19,    60,    58,    56,   144,    56,    51,
      51,    29,    59,   222,   131,    58,    54,    62,    58,    58,
      66,    56,    56,    56,   238,   203,    -1,    -1,    65
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    11,    68,    48,     0,    56,    16,    32,    69,    71,
      75,    76,    48,    83,    48,    78,    36,    70,    73,    74,
      75,    76,    77,     9,    24,    72,   104,   105,    71,    71,
      52,    17,    52,    33,    48,    85,    86,    12,    47,    18,
      26,    28,    30,    48,    49,    94,    95,    96,    97,    98,
      99,   101,   102,   103,   110,    74,    74,    74,    48,   106,
      48,   107,    21,    44,    87,    88,    89,    72,    72,     3,
       4,     5,     6,     7,     8,    84,    56,     3,     4,     5,
       7,     8,    13,    14,    15,    22,    34,    40,    42,    43,
      45,    48,    50,    63,    79,    80,    81,    90,    91,    92,
      93,    94,    95,   111,    56,    55,    37,    58,    57,    48,
      93,    48,    93,    50,    43,    53,    57,    60,    43,    53,
      57,    60,    56,    50,    73,    50,    73,    85,    85,    47,
      89,    56,    48,    82,    92,    93,    79,    53,    50,    90,
      92,    48,    50,    90,    56,    59,    63,    64,    65,    41,
      46,    66,    86,    56,    79,    38,    60,    61,    93,   112,
      93,    94,    93,    93,    95,    93,    96,    21,    23,    44,
     108,   109,    10,    85,    20,    83,    58,    35,    81,   112,
      51,    51,    90,    78,    81,    90,    90,    90,    92,    92,
      93,    56,    96,    93,    96,    55,    51,    54,    54,    86,
      86,    86,    51,    56,    51,    93,    79,    59,    51,    85,
      27,    39,    62,   100,   112,    58,    58,    58,    56,   108,
      20,    25,    56,    81,    93,    93,    31,    79,    79,    79,
      79,    82,    54,    38,    61,    56,    19,    96,    96,    79,
      29,   100
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    67,    68,    69,    70,    71,    71,    71,    72,    72,
      72,    73,    74,    74,    74,    74,    75,    76,    77,    78,
      78,    79,    79,    79,    79,    79,    79,    80,    80,    80,
      80,    80,    81,    81,    82,    82,    83,    83,    84,    84,
      84,    84,    84,    84,    85,    85,    86,    86,    87,    87,
      87,    88,    89,    90,    90,    90,    90,    90,    90,    90,
      91,    91,    92,    92,    92,    92,    92,    92,    92,    92,
      93,    93,    93,    94,    94,    94,    94,    95,    95,    95,
      95,    96,    96,    97,    97,    97,    97,    97,    98,    98,
      99,   100,   100,   101,   101,   102,   103,   104,   105,   106,
     107,   108,   108,   109,   109,   109,   110,   111,   112,   112
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     7,     4,     2,     2,     2,     0,     2,     2,
       0,     2,     2,     2,     2,     0,     4,     4,     4,     5,
       0,     3,     8,     1,     3,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     5,     0,     5,     0,     1,     1,
       1,     1,     1,     1,     5,     0,     3,     1,     1,     2,
       1,     2,     2,     3,     3,     3,     3,     1,     1,     2,
       1,     1,     3,     3,     2,     1,     1,     1,     3,     3,
       1,     1,     1,     1,     3,     4,     2,     1,     3,     4,
       2,     3,     1,     1,     1,     1,     1,     1,     3,     3,
       6,     5,     0,     1,     1,     5,     9,     4,     6,     5,
       7,     3,     0,     4,     4,     4,     4,     4,     3,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* desc_algoritmo: algoritmo_tk id_tk punto_coma_tk cabecera_alg bloque_alg falgoritmo_tk punto_tk  */
#line 118 "parser.y"
                                                                                                        {
}
#line 1365 "parser.tab.c"
    break;

  case 3: /* cabecera_alg: decl_globales decl_a_f decl_ent_sal comentario_tk  */
#line 121 "parser.y"
                                                                        {
}
#line 1372 "parser.tab.c"
    break;

  case 4: /* bloque_alg: bloque comentario_tk  */
#line 124 "parser.y"
                                        {
}
#line 1379 "parser.tab.c"
    break;

  case 5: /* decl_globales: declaracion_tipo decl_globales  */
#line 127 "parser.y"
                                                {
}
#line 1386 "parser.tab.c"
    break;

  case 6: /* decl_globales: declaracion_const decl_globales  */
#line 129 "parser.y"
                                        {
}
#line 1393 "parser.tab.c"
    break;

  case 7: /* decl_globales: %empty  */
#line 131 "parser.y"
                {
}
#line 1400 "parser.tab.c"
    break;

  case 8: /* decl_a_f: accion_d decl_a_f  */
#line 134 "parser.y"
                                {
}
#line 1407 "parser.tab.c"
    break;

  case 9: /* decl_a_f: funcion_d decl_a_f  */
#line 136 "parser.y"
                                {
}
#line 1414 "parser.tab.c"
    break;

  case 10: /* decl_a_f: %empty  */
#line 138 "parser.y"
                {
}
#line 1421 "parser.tab.c"
    break;

  case 11: /* bloque: declaraciones instrucciones  */
#line 141 "parser.y"
                                        {
}
#line 1428 "parser.tab.c"
    break;

  case 12: /* declaraciones: declaracion_tipo declaraciones  */
#line 144 "parser.y"
                                                {
}
#line 1435 "parser.tab.c"
    break;

  case 13: /* declaraciones: declaracion_const declaraciones  */
#line 146 "parser.y"
                                        {
}
#line 1442 "parser.tab.c"
    break;

  case 14: /* declaraciones: declaracion_var declaraciones  */
#line 148 "parser.y"
                                        {
}
#line 1449 "parser.tab.c"
    break;

  case 15: /* declaraciones: %empty  */
#line 150 "parser.y"
                {
}
#line 1456 "parser.tab.c"
    break;

  case 16: /* declaracion_tipo: tipo_tk lista_d_tipo ftipo_tk punto_coma_tk  */
#line 157 "parser.y"
                                                                {
}
#line 1463 "parser.tab.c"
    break;

  case 17: /* declaracion_const: const_tk lista_d_cte fconst_tk punto_coma_tk  */
#line 160 "parser.y"
                                                                        {
}
#line 1470 "parser.tab.c"
    break;

  case 18: /* declaracion_var: var_tk lista_d_var fvar_tk punto_coma_tk  */
#line 163 "parser.y"
                                                                {
}
#line 1477 "parser.tab.c"
    break;

  case 19: /* lista_d_tipo: id_tk igual_tk d_tipo punto_coma_tk lista_d_tipo  */
#line 168 "parser.y"
                                                                {
}
#line 1484 "parser.tab.c"
    break;

  case 20: /* lista_d_tipo: %empty  */
#line 170 "parser.y"
                {
}
#line 1491 "parser.tab.c"
    break;

  case 21: /* d_tipo: tupla_tk lista_campos ftupla_tk  */
#line 173 "parser.y"
                                                {
}
#line 1498 "parser.tab.c"
    break;

  case 22: /* d_tipo: tabla_tk inicio_array_tk expresion_t subrango_tk expresion_t fin_array_tk de_tk d_tipo  */
#line 175 "parser.y"
                                                                                                {
}
#line 1505 "parser.tab.c"
    break;

  case 23: /* d_tipo: id_tk  */
#line 177 "parser.y"
        {
}
#line 1512 "parser.tab.c"
    break;

  case 24: /* d_tipo: expresion_t subrango_tk expresion_t  */
#line 179 "parser.y"
                                                {
}
#line 1519 "parser.tab.c"
    break;

  case 25: /* d_tipo: ref_tk d_tipo  */
#line 181 "parser.y"
                        {
}
#line 1526 "parser.tab.c"
    break;

  case 26: /* d_tipo: tipo_base  */
#line 183 "parser.y"
                        {
	(yyval.tipo) = (yyvsp[0].tipo);
}
#line 1534 "parser.tab.c"
    break;

  case 27: /* tipo_base: entero_tk  */
#line 188 "parser.y"
                      { 
	(yyval.tipo) = ENTERO; 
}
#line 1542 "parser.tab.c"
    break;

  case 28: /* tipo_base: real_tk  */
#line 191 "parser.y"
             { 
	(yyval.tipo) = REAL; 
}
#line 1550 "parser.tab.c"
    break;

  case 29: /* tipo_base: booleano_tk  */
#line 194 "parser.y"
              { 
	(yyval.tipo) = BOOLEANO; 
}
#line 1558 "parser.tab.c"
    break;

  case 30: /* tipo_base: cadena_tk  */
#line 197 "parser.y"
             { 
	(yyval.tipo) = CADENA; 
}
#line 1566 "parser.tab.c"
    break;

  case 31: /* tipo_base: caracter_tk  */
#line 200 "parser.y"
              { 
	(yyval.tipo) = CARACTER; 
}
#line 1574 "parser.tab.c"
    break;

  case 32: /* expresion_t: expresion  */
#line 204 "parser.y"
                        {
}
#line 1581 "parser.tab.c"
    break;

  case 33: /* expresion_t: literal_caracter_tk  */
#line 206 "parser.y"
                                {
}
#line 1588 "parser.tab.c"
    break;

  case 34: /* lista_campos: id_tk dos_puntos_tk d_tipo punto_coma_tk lista_campos  */
#line 209 "parser.y"
                                                                        {
}
#line 1595 "parser.tab.c"
    break;

  case 35: /* lista_campos: %empty  */
#line 211 "parser.y"
                {
}
#line 1602 "parser.tab.c"
    break;

  case 36: /* lista_d_cte: id_tk igual_tk literal punto_coma_tk lista_d_cte  */
#line 216 "parser.y"
                                                                {
}
#line 1609 "parser.tab.c"
    break;

  case 37: /* lista_d_cte: %empty  */
#line 218 "parser.y"
                {
}
#line 1616 "parser.tab.c"
    break;

  case 38: /* literal: literal_entero_tk  */
#line 222 "parser.y"
                                {
}
#line 1623 "parser.tab.c"
    break;

  case 39: /* literal: literal_real_tk  */
#line 224 "parser.y"
                        {
}
#line 1630 "parser.tab.c"
    break;

  case 40: /* literal: verdadero_tk  */
#line 226 "parser.y"
                        {
}
#line 1637 "parser.tab.c"
    break;

  case 41: /* literal: falso_tk  */
#line 228 "parser.y"
                        {
}
#line 1644 "parser.tab.c"
    break;

  case 42: /* literal: literal_cadena_tk  */
#line 230 "parser.y"
                                {
}
#line 1651 "parser.tab.c"
    break;

  case 43: /* literal: literal_caracter_tk  */
#line 232 "parser.y"
                                {
}
#line 1658 "parser.tab.c"
    break;

  case 44: /* lista_d_var: lista_id dos_puntos_tk d_tipo punto_coma_tk lista_d_var  */
#line 235 "parser.y"
                                                                        {
	insertarListaEnTS((yyvsp[-4].lista), (yyvsp[-2].tipo)); 
	liberarListaNombre((yyvsp[-4].lista)); 
	(yyval.lista) = (yyvsp[0].lista);
}
#line 1668 "parser.tab.c"
    break;

  case 45: /* lista_d_var: %empty  */
#line 240 "parser.y"
                {
	(yyval.lista) = NULL;
}
#line 1676 "parser.tab.c"
    break;

  case 46: /* lista_id: id_tk coma_tk lista_id  */
#line 244 "parser.y"
                                        {
	nuevaCelda((yyvsp[0].lista), (yyvsp[-2].cad)); 
	(yyval.lista) = (yyvsp[0].lista);
}
#line 1685 "parser.tab.c"
    break;

  case 47: /* lista_id: id_tk  */
#line 248 "parser.y"
                {
	(yyval.lista) = nuevaLista();
	nuevaCelda((yyval.lista), (yyvsp[0].cad));
}
#line 1694 "parser.tab.c"
    break;

  case 48: /* decl_ent_sal: decl_ent  */
#line 253 "parser.y"
                        {
}
#line 1701 "parser.tab.c"
    break;

  case 49: /* decl_ent_sal: decl_ent decl_salida  */
#line 255 "parser.y"
                                {
}
#line 1708 "parser.tab.c"
    break;

  case 50: /* decl_ent_sal: decl_salida  */
#line 257 "parser.y"
                {
}
#line 1715 "parser.tab.c"
    break;

  case 51: /* decl_ent: ent_tk lista_d_var  */
#line 260 "parser.y"
                                {
}
#line 1722 "parser.tab.c"
    break;

  case 52: /* decl_salida: sal_tk lista_d_var  */
#line 263 "parser.y"
                                        {
}
#line 1729 "parser.tab.c"
    break;

  case 53: /* exp_a: exp_a op1_tk exp_a  */
#line 270 "parser.y"
                                {
}
#line 1736 "parser.tab.c"
    break;

  case 54: /* exp_a: exp_a op2_tk exp_a  */
#line 272 "parser.y"
                                {
}
#line 1743 "parser.tab.c"
    break;

  case 55: /* exp_a: exp_a div_mod_tk exp_a  */
#line 274 "parser.y"
                                {
}
#line 1750 "parser.tab.c"
    break;

  case 56: /* exp_a: abrir_parentesis_tk exp_a cerrar_parentesis_tk  */
#line 276 "parser.y"
                                                        {
}
#line 1757 "parser.tab.c"
    break;

  case 57: /* exp_a: operando_a  */
#line 278 "parser.y"
                        {
}
#line 1764 "parser.tab.c"
    break;

  case 58: /* exp_a: literal_numerico  */
#line 280 "parser.y"
                                {
}
#line 1771 "parser.tab.c"
    break;

  case 59: /* exp_a: op1_tk exp_a  */
#line 282 "parser.y"
                        {
}
#line 1778 "parser.tab.c"
    break;

  case 60: /* literal_numerico: literal_entero_tk  */
#line 286 "parser.y"
                                        {
}
#line 1785 "parser.tab.c"
    break;

  case 61: /* literal_numerico: literal_real_tk  */
#line 288 "parser.y"
                        {
}
#line 1792 "parser.tab.c"
    break;

  case 62: /* exp_b: exp_b y_tk exp_b  */
#line 292 "parser.y"
                                {
}
#line 1799 "parser.tab.c"
    break;

  case 63: /* exp_b: exp_b o_tk exp_b  */
#line 294 "parser.y"
                                {
}
#line 1806 "parser.tab.c"
    break;

  case 64: /* exp_b: no_tk exp_b  */
#line 296 "parser.y"
                        {
}
#line 1813 "parser.tab.c"
    break;

  case 65: /* exp_b: operando_b  */
#line 298 "parser.y"
                        {
}
#line 1820 "parser.tab.c"
    break;

  case 66: /* exp_b: verdadero_tk  */
#line 300 "parser.y"
                        {
}
#line 1827 "parser.tab.c"
    break;

  case 67: /* exp_b: falso_tk  */
#line 302 "parser.y"
                        {
}
#line 1834 "parser.tab.c"
    break;

  case 68: /* exp_b: expresion oprel_tk expresion  */
#line 304 "parser.y"
                                        {
}
#line 1841 "parser.tab.c"
    break;

  case 69: /* exp_b: abrir_parentesis_tk exp_b cerrar_parentesis_tk  */
#line 306 "parser.y"
                                                        {
}
#line 1848 "parser.tab.c"
    break;

  case 70: /* expresion: exp_a  */
#line 309 "parser.y"
                        {
}
#line 1855 "parser.tab.c"
    break;

  case 71: /* expresion: exp_b  */
#line 311 "parser.y"
                {
}
#line 1862 "parser.tab.c"
    break;

  case 72: /* expresion: funcion_ll  */
#line 313 "parser.y"
                        {
}
#line 1869 "parser.tab.c"
    break;

  case 73: /* operando_a: id_tk  */
#line 316 "parser.y"
                        {
}
#line 1876 "parser.tab.c"
    break;

  case 74: /* operando_a: operando_a punto_tk operando_a  */
#line 318 "parser.y"
                                        {
}
#line 1883 "parser.tab.c"
    break;

  case 75: /* operando_a: operando_a inicio_array_tk expresion fin_array_tk  */
#line 320 "parser.y"
                                                                {
}
#line 1890 "parser.tab.c"
    break;

  case 76: /* operando_a: operando_a ref_tk  */
#line 322 "parser.y"
                                {
}
#line 1897 "parser.tab.c"
    break;

  case 77: /* operando_b: id_bool_tk  */
#line 325 "parser.y"
                        {
}
#line 1904 "parser.tab.c"
    break;

  case 78: /* operando_b: operando_b punto_tk operando_b  */
#line 327 "parser.y"
                                        {
}
#line 1911 "parser.tab.c"
    break;

  case 79: /* operando_b: operando_b inicio_array_tk expresion fin_array_tk  */
#line 329 "parser.y"
                                                                {
}
#line 1918 "parser.tab.c"
    break;

  case 80: /* operando_b: operando_b ref_tk  */
#line 331 "parser.y"
                                {
}
#line 1925 "parser.tab.c"
    break;

  case 81: /* instrucciones: instruccion punto_coma_tk instrucciones  */
#line 350 "parser.y"
                                                        {
}
#line 1932 "parser.tab.c"
    break;

  case 82: /* instrucciones: instruccion  */
#line 352 "parser.y"
                        {
}
#line 1939 "parser.tab.c"
    break;

  case 83: /* instruccion: continuar_tk  */
#line 355 "parser.y"
                                {
}
#line 1946 "parser.tab.c"
    break;

  case 84: /* instruccion: asignacion  */
#line 357 "parser.y"
                        {
}
#line 1953 "parser.tab.c"
    break;

  case 85: /* instruccion: alternativa  */
#line 359 "parser.y"
                        {
}
#line 1960 "parser.tab.c"
    break;

  case 86: /* instruccion: iteracion  */
#line 361 "parser.y"
                        {
}
#line 1967 "parser.tab.c"
    break;

  case 87: /* instruccion: accion_ll  */
#line 363 "parser.y"
                        {
}
#line 1974 "parser.tab.c"
    break;

  case 88: /* asignacion: operando_a asignacion_tk expresion  */
#line 366 "parser.y"
                                                {
}
#line 1981 "parser.tab.c"
    break;

  case 89: /* asignacion: operando_b asignacion_tk expresion  */
#line 368 "parser.y"
                                                {
}
#line 1988 "parser.tab.c"
    break;

  case 90: /* alternativa: si_tk expresion entonces_tk instrucciones lista_opciones fsi_tk  */
#line 371 "parser.y"
                                                                                {
}
#line 1995 "parser.tab.c"
    break;

  case 91: /* lista_opciones: si_no_si_tk expresion entonces_tk instrucciones lista_opciones  */
#line 374 "parser.y"
                                                                                {
}
#line 2002 "parser.tab.c"
    break;

  case 92: /* lista_opciones: %empty  */
#line 376 "parser.y"
                {
}
#line 2009 "parser.tab.c"
    break;

  case 93: /* iteracion: it_cota_fija  */
#line 379 "parser.y"
                                {
}
#line 2016 "parser.tab.c"
    break;

  case 94: /* iteracion: it_cota_exp  */
#line 381 "parser.y"
                        {
}
#line 2023 "parser.tab.c"
    break;

  case 95: /* it_cota_exp: mientras_tk expresion hacer_tk instrucciones fmientras_tk  */
#line 384 "parser.y"
                                                                        {
}
#line 2030 "parser.tab.c"
    break;

  case 96: /* it_cota_fija: para_tk id_tk asignacion_tk expresion hasta_tk expresion hacer_tk instrucciones fpara_tk  */
#line 387 "parser.y"
                                                                                                        {
}
#line 2037 "parser.tab.c"
    break;

  case 97: /* accion_d: accion_tk a_cabecera bloque faccion_tk  */
#line 393 "parser.y"
                                                        {
}
#line 2044 "parser.tab.c"
    break;

  case 98: /* funcion_d: funcion_tk f_cabecera bloque dev_tk expresion ffuncion_tk  */
#line 396 "parser.y"
                                                                        {
}
#line 2051 "parser.tab.c"
    break;

  case 99: /* a_cabecera: id_tk abrir_parentesis_tk d_par_form cerrar_parentesis_tk punto_coma_tk  */
#line 399 "parser.y"
                                                                                        {
}
#line 2058 "parser.tab.c"
    break;

  case 100: /* f_cabecera: id_tk abrir_parentesis_tk lista_d_var cerrar_parentesis_tk dev_tk d_tipo punto_coma_tk  */
#line 402 "parser.y"
                                                                                                        {
}
#line 2065 "parser.tab.c"
    break;

  case 101: /* d_par_form: d_p_form punto_coma_tk d_par_form  */
#line 405 "parser.y"
                                                {
}
#line 2072 "parser.tab.c"
    break;

  case 102: /* d_par_form: %empty  */
#line 407 "parser.y"
                {
}
#line 2079 "parser.tab.c"
    break;

  case 103: /* d_p_form: ent_tk lista_id dos_puntos_tk d_tipo  */
#line 410 "parser.y"
                                                {
}
#line 2086 "parser.tab.c"
    break;

  case 104: /* d_p_form: sal_tk lista_id dos_puntos_tk d_tipo  */
#line 412 "parser.y"
                                                {
}
#line 2093 "parser.tab.c"
    break;

  case 105: /* d_p_form: e_s_tk lista_id dos_puntos_tk d_tipo  */
#line 414 "parser.y"
                                        {
}
#line 2100 "parser.tab.c"
    break;

  case 106: /* accion_ll: id_tk abrir_parentesis_tk l_ll cerrar_parentesis_tk  */
#line 417 "parser.y"
                                                                {
}
#line 2107 "parser.tab.c"
    break;

  case 107: /* funcion_ll: id_tk abrir_parentesis_tk l_ll cerrar_parentesis_tk  */
#line 420 "parser.y"
                                                                        {
}
#line 2114 "parser.tab.c"
    break;

  case 108: /* l_ll: expresion coma_tk l_ll  */
#line 423 "parser.y"
                                {
}
#line 2121 "parser.tab.c"
    break;

  case 109: /* l_ll: expresion  */
#line 425 "parser.y"
                        {
}
#line 2128 "parser.tab.c"
    break;


#line 2132 "parser.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 428 "parser.y"


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
