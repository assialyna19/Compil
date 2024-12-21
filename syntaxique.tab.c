
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "syntaxique.y"
 
	extern int yylex(void); 
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include "ts.h"


    int nb_ligne=1, col=1;
    int i=0;	
	int j=0;
	int t=0;
	int s;
	int A=1;
	int operateur[10];
	int opera = 0;
	float k;
	int affect;
	int type;
	int y=0;
	char displ[50];
	char sauvType[25];
	char save[20];
	char IDF[100][20];
	char sign[40];
	char IDFF[20];
	char IDFD[100][20];
	char cstStr[10];
	float cstNum[10];
	float calculResult[10];
	char STR[100];
	char v[20];
	extern FILE *yyin;
	int  valCst;
	char *valChar;
	float valFloat;
	char *valStr;

	int condition=0;
	
		void yyerror(const char *s)
{
    fprintf(stderr, "Erreur syntaxique: %s à la ligne %d, colonne %d\\n", s, nb_ligne, col);
}




/* Line 189 of yacc.c  */
#line 122 "syntaxique.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     cst_int = 258,
     cst_real = 259,
     cst_str = 260,
     ERREUR_LEXICAL = 261,
     MC_PROGRAMME = 262,
     MC_END = 263,
     MC_IDF = 264,
     MC_CHAINE = 265,
     MC_writeln = 266,
     MC_READLN = 267,
     MC_ENDIF = 268,
     MC_ELSE = 269,
     MC_THEN = 270,
     MC_IF = 271,
     MC_ENDDO = 272,
     MC_BEGIN = 273,
     MC_FOR = 274,
     MC_WHILE = 275,
     MC_DO = 276,
     MC_ENTIER = 277,
     MC_REAL = 278,
     MC_VAR = 279,
     MC_CONST = 280,
     MC_CARACTERE = 281,
     MC_INTEGER = 282,
     MC_DIMENSION = 283,
     MC_ROUTINE = 284,
     MC_ENDR = 285,
     MC_TAB = 286,
     MC_SUP = 287,
     MC_SUPEGAL = 288,
     MC_INF = 289,
     MC_NOEGAL = 290,
     MC_EGAL = 291,
     MC_OR = 292,
     MC_AND = 293,
     MC_INFEGAL = 294,
     Int = 295,
     pvg = 296,
     vg = 297,
     th = 298,
     division = 299,
     crof = 300,
     crou = 301,
     soustraction = 302,
     addition = 303,
     multiplication = 304,
     parouv = 305,
     parferm = 306,
     couvrante = 307,
     cfermante = 308,
     point = 309,
     aff = 310,
     pourcentage = 311,
     acov = 312,
     acoferm = 313,
     entier = 314,
     mc_bool = 315,
     reel = 316,
     MC_NEGATION_LOGIQUE = 317,
     OU = 318,
     ET = 319,
     supe = 320,
     infe = 321,
     sup = 322,
     inf = 323
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 49 "syntaxique.y"

         int     entier;
         char*   str;
         float reel;



/* Line 214 of yacc.c  */
#line 234 "syntaxique.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 246 "syntaxique.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  9
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   237

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  69
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  31
/* YYNRULES -- Number of rules.  */
#define YYNRULES  84
/* YYNRULES -- Number of states.  */
#define YYNSTATES  188

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   323

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
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
      65,    66,    67,    68
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     6,     8,     9,    12,    23,    25,    26,
      36,    41,    43,    45,    47,    50,    53,    56,    58,    59,
      65,    72,    76,    84,    94,   100,   104,   106,   109,   111,
     112,   114,   116,   118,   120,   126,   132,   138,   142,   144,
     146,   148,   150,   152,   154,   156,   158,   162,   166,   171,
     176,   181,   185,   189,   193,   197,   201,   205,   211,   219,
     221,   229,   242,   250,   258,   266,   274,   282,   290,   292,
     294,   296,   298,   300,   302,   304,   306,   308,   310,   312,
     314,   316,   318,   320,   322
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      70,     0,    -1,    71,    75,    -1,    72,    -1,    -1,    73,
      74,    -1,    76,    29,     9,    50,    82,    51,    77,    83,
      41,    30,    -1,    72,    -1,    -1,     7,     9,    24,    57,
      77,    58,    18,    83,     8,    -1,     7,     9,    83,     8,
      -1,    27,    -1,    23,    -1,    26,    -1,    81,    78,    -1,
      79,    78,    -1,    80,    78,    -1,    77,    -1,    -1,    25,
       9,    55,    40,    41,    -1,    76,     9,    46,    40,    45,
      41,    -1,    76,    82,    41,    -1,    76,     9,    28,    50,
      59,    51,    41,    -1,    76,     9,    28,    50,    59,    42,
      59,    51,    41,    -1,    76,     9,    55,    99,    41,    -1,
       9,    42,    82,    -1,     9,    -1,    85,    84,    -1,    83,
      -1,    -1,    86,    -1,    87,    -1,    94,    -1,    92,    -1,
      12,    50,     9,    51,    41,    -1,    11,    50,    88,    51,
      41,    -1,    10,    42,     9,    42,    88,    -1,    10,    42,
       9,    -1,    10,    -1,    26,    -1,     9,    -1,     9,    -1,
      99,    -1,    91,    -1,     9,    -1,    99,    -1,    90,    98,
      89,    -1,    50,    91,    51,    -1,     9,    55,    93,    41,
      -1,     9,    55,    99,    41,    -1,     9,    55,     9,    41,
      -1,     9,    98,     9,    -1,     9,    98,    99,    -1,    99,
      98,    59,    -1,    99,    98,     9,    -1,     9,    98,    93,
      -1,    99,    98,    93,    -1,    16,    95,    15,    83,    13,
      -1,    16,    95,    15,    83,    14,    83,    13,    -1,    96,
      -1,    50,    96,    54,    97,    54,    96,    51,    -1,    16,
      50,    50,    97,    51,    98,    50,    62,    50,     9,    51,
      51,    -1,    50,     9,    54,    97,    54,    99,    51,    -1,
      50,     9,    54,    97,    54,     9,    51,    -1,    50,    91,
      54,    97,    54,    91,    51,    -1,    50,     9,    54,    97,
      54,    91,    51,    -1,    50,    91,    54,    97,    54,    99,
      51,    -1,    50,    91,    54,    97,    54,     9,    51,    -1,
      32,    -1,    33,    -1,    36,    -1,    35,    -1,    39,    -1,
      34,    -1,    38,    -1,    37,    -1,    48,    -1,    49,    -1,
      47,    -1,    44,    -1,    59,    -1,    60,    -1,    61,    -1,
      10,    -1,    26,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    74,    74,    78,    78,    80,    82,    84,    84,    86,
      87,    92,    93,    94,    97,    98,    99,   102,   103,   106,
     112,   120,   137,   154,   170,   214,   215,   219,   222,   222,
     225,   226,   227,   228,   230,   232,   234,   235,   236,   237,
     238,   241,   246,   247,   249,   254,   256,   257,   259,   262,
     316,   349,   371,   394,   404,   421,   440,   448,   449,   451,
     452,   453,   455,   464,   471,   472,   473,   474,   477,   478,
     479,   480,   481,   482,   483,   484,   486,   486,   486,   486,
     488,   488,   488,   488,   488
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "cst_int", "cst_real", "cst_str",
  "ERREUR_LEXICAL", "MC_PROGRAMME", "MC_END", "MC_IDF", "MC_CHAINE",
  "MC_writeln", "MC_READLN", "MC_ENDIF", "MC_ELSE", "MC_THEN", "MC_IF",
  "MC_ENDDO", "MC_BEGIN", "MC_FOR", "MC_WHILE", "MC_DO", "MC_ENTIER",
  "MC_REAL", "MC_VAR", "MC_CONST", "MC_CARACTERE", "MC_INTEGER",
  "MC_DIMENSION", "MC_ROUTINE", "MC_ENDR", "MC_TAB", "MC_SUP",
  "MC_SUPEGAL", "MC_INF", "MC_NOEGAL", "MC_EGAL", "MC_OR", "MC_AND",
  "MC_INFEGAL", "Int", "pvg", "vg", "th", "division", "crof", "crou",
  "soustraction", "addition", "multiplication", "parouv", "parferm",
  "couvrante", "cfermante", "point", "aff", "pourcentage", "acov",
  "acoferm", "entier", "mc_bool", "reel", "MC_NEGATION_LOGIQUE", "OU",
  "ET", "supe", "infe", "sup", "inf", "$accept", "S", "C", "LIST_R", "A",
  "L_R", "B", "TYPE", "LIST_DEC", "L_DEC", "CONST_DECL", "TAB_DECL",
  "DEC_VAR", "LIST_IDF", "LIST_INST", "L_INST", "INST", "INST_READLN",
  "INST_writeln", "COMMANDES", "TYPE_AFF", "AFF_COURT", "EXPRESSION",
  "EXPR_ARITH", "CALCUL", "INST_IF", "CONDITION_CPLX", "CONDITION",
  "LIST_CONDITION", "OPERATEUR_A", "VAL", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    69,    70,    71,    71,    72,    73,    74,    74,    75,
      75,    76,    76,    76,    77,    77,    77,    78,    78,    79,
      80,    81,    81,    81,    81,    82,    82,    83,    84,    84,
      85,    85,    85,    85,    86,    87,    88,    88,    88,    88,
      88,    89,    89,    89,    90,    90,    91,    91,    92,    92,
      92,    93,    93,    93,    93,    93,    93,    94,    94,    95,
      95,    95,    96,    96,    96,    96,    96,    96,    97,    97,
      97,    97,    97,    97,    97,    97,    98,    98,    98,    98,
      99,    99,    99,    99,    99
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     1,     0,     2,    10,     1,     0,     9,
       4,     1,     1,     1,     2,     2,     2,     1,     0,     5,
       6,     3,     7,     9,     5,     3,     1,     2,     1,     0,
       1,     1,     1,     1,     5,     5,     5,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     3,     4,     4,
       4,     3,     3,     3,     3,     3,     3,     5,     7,     1,
       7,    12,     7,     7,     7,     7,     7,     7,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,    12,    13,    11,     0,     0,     3,     8,     0,     1,
       0,     2,     7,     5,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    29,    30,    31,    33,    32,     0,     0,
       0,     0,     0,     0,     0,    59,     0,    10,    28,    27,
      26,     0,     0,    83,    84,    80,    81,    82,     0,     0,
      40,    38,    39,     0,     0,     0,    44,     0,     0,     0,
       0,    45,     0,     0,     0,     0,    18,    18,    18,     0,
       0,    50,    79,    78,    76,    77,     0,    48,    49,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    26,     0,     0,    17,    15,    16,    14,    25,
       0,    51,    55,    52,    54,    80,    56,     0,    37,    35,
      34,    68,    69,    73,    71,    70,    75,    74,    72,     0,
       0,    44,     0,    47,    44,    46,    43,    45,     0,     0,
      57,     0,     0,     0,     0,     0,    21,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    36,     0,    44,     0,    45,    44,     0,    45,     0,
       0,    58,    19,     0,     0,    24,     9,     6,     0,    63,
      65,    62,    67,    64,    66,    60,     0,     0,    20,     0,
       0,    22,     0,     0,     0,    23,     0,    61
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     4,     5,     6,     7,    13,    11,    64,    95,    96,
      66,    67,    68,    41,    22,    39,    23,    24,    25,    53,
     125,    58,    59,    26,    48,    27,    34,    35,   119,    76,
      61
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -70
static const yytype_int16 yypact[] =
{
     126,   -70,   -70,   -70,    10,    24,   -70,   126,    -6,   -70,
      28,   -70,   -70,   -70,    32,   118,    -1,     0,    20,    34,
     -10,    45,    99,    35,   -70,   -70,   -70,   -70,    83,     7,
      16,   104,    68,    -2,   113,   -70,    94,   -70,   -70,   -70,
      81,   124,   107,   -70,   -70,   -70,   -70,   -70,   109,   116,
     -70,   136,   -70,   125,   128,   131,   129,     4,    56,   132,
     133,   -70,    35,   171,   173,   127,    94,    94,    94,    83,
      94,   -70,   -70,   -70,   -70,   -70,    65,   -70,   -70,    86,
     175,   147,   148,   134,   134,    12,    84,    19,   134,   134,
     130,   135,    55,   150,   174,   -70,   -70,   -70,   -70,   -70,
      35,    56,   -70,    56,    56,   152,   -70,    56,   153,   -70,
     -70,   -70,   -70,   -70,   -70,   -70,   -70,   -70,   -70,   143,
     142,   -70,   146,   -70,   108,   -70,   -70,   123,   144,   145,
     -70,    35,   160,   151,   162,    80,   -70,    35,   163,    16,
      56,    26,    72,   155,   190,   165,   149,   164,   166,   202,
     181,   -70,   167,   161,   168,   169,   170,   172,   176,     4,
     177,   -70,   -70,   -24,   183,   -70,   -70,   -70,   154,   -70,
     -70,   -70,   -70,   -70,   -70,   -70,   156,   184,   -70,   179,
     180,   -70,   204,   185,   182,   -70,   186,   -70
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -70,   -70,   -70,   207,   -70,   -70,   -70,     5,   -27,    69,
     -70,   -70,   -70,    30,   -23,   -70,   -70,   -70,   -70,    79,
     -70,   -70,   -53,   -70,    82,   -70,   -70,   -32,   -69,   -47,
     -26
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -54
static const yytype_int16 yytable[] =
{
      38,    60,    79,    49,    86,     8,    32,    56,    43,    65,
       9,    87,     8,    56,    43,   120,    42,    43,   176,   128,
     129,   121,    43,    14,    44,    50,    51,   177,   124,    43,
      44,    10,   122,    44,   126,   153,    43,    15,    44,    90,
      33,    16,    52,   100,    17,    44,    18,    19,    57,    28,
     103,    20,    44,   107,    85,    29,    79,    45,    46,    47,
      79,   127,    85,    45,    46,    47,    45,    46,    47,    85,
      30,    45,    46,    47,   101,    43,    85,   138,    45,    46,
      47,   156,    43,   133,    31,    45,    46,    47,   154,   157,
      43,    44,    40,   152,    93,   104,    43,    69,    44,    99,
      72,   134,    36,    73,    74,    75,    44,    37,   144,   148,
     135,   160,    44,    54,   149,   155,   158,     1,    55,    63,
       2,     3,    85,    69,    45,    46,    47,    17,    62,    18,
      19,    45,    46,    47,    20,   123,    97,    98,    88,    45,
      46,    47,    21,   130,   131,   105,    46,    47,    71,     1,
      77,    72,     2,     3,    73,    74,    75,    78,   102,   -41,
      72,   106,   -41,    73,    74,    75,   111,   112,   113,   114,
     115,   116,   117,   118,   -42,    70,    81,   -42,    80,    82,
      91,    83,    92,    84,   108,    94,    88,    89,   109,   110,
     132,   136,   137,   -53,   140,   139,   141,   123,   142,   143,
     145,   146,   147,   161,   150,   159,   162,   165,   163,   164,
     166,   167,   169,   184,    12,   180,   179,   168,   151,   170,
     171,   172,     0,   173,   178,   181,   185,   174,   175,   182,
       0,   183,     0,   186,     0,     0,     0,   187
};

static const yytype_int16 yycheck[] =
{
      23,    33,    49,    29,    57,     0,    16,     9,    10,    36,
       0,    58,     7,     9,    10,    84,     9,    10,    42,    88,
      89,     9,    10,    29,    26,     9,    10,    51,     9,    10,
      26,     7,    85,    26,    87,     9,    10,     9,    26,    62,
      50,     9,    26,    70,     9,    26,    11,    12,    50,    50,
      76,    16,    26,    79,    50,    55,   103,    59,    60,    61,
     107,    87,    50,    59,    60,    61,    59,    60,    61,    50,
      50,    59,    60,    61,     9,    10,    50,   100,    59,    60,
      61,     9,    10,    28,    50,    59,    60,    61,   141,   142,
      10,    26,     9,   140,    64,     9,    10,    42,    26,    69,
      44,    46,    57,    47,    48,    49,    26,     8,   131,   135,
      55,   143,    26,     9,   137,   141,   142,    23,    50,    25,
      26,    27,    50,    42,    59,    60,    61,     9,    15,    11,
      12,    59,    60,    61,    16,    51,    67,    68,    54,    59,
      60,    61,    24,    13,    14,    59,    60,    61,    41,    23,
      41,    44,    26,    27,    47,    48,    49,    41,    76,    51,
      44,    79,    54,    47,    48,    49,    32,    33,    34,    35,
      36,    37,    38,    39,    51,    51,    51,    54,    42,    51,
       9,    50,     9,    54,     9,    58,    54,    54,    41,    41,
      55,    41,    18,    41,    51,    42,    54,    51,    54,    54,
      40,    50,    40,    13,    41,    50,    41,    41,    59,    45,
       8,    30,    51,     9,     7,    59,    62,    50,   139,    51,
      51,    51,    -1,    51,    41,    41,    41,    51,    51,    50,
      -1,    51,    -1,    51,    -1,    -1,    -1,    51
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    23,    26,    27,    70,    71,    72,    73,    76,     0,
       7,    75,    72,    74,    29,     9,     9,     9,    11,    12,
      16,    24,    83,    85,    86,    87,    92,    94,    50,    55,
      50,    50,    16,    50,    95,    96,    57,     8,    83,    84,
       9,    82,     9,    10,    26,    59,    60,    61,    93,    99,
       9,    10,    26,    88,     9,    50,     9,    50,    90,    91,
      96,    99,    15,    25,    76,    77,    79,    80,    81,    42,
      51,    41,    44,    47,    48,    49,    98,    41,    41,    98,
      42,    51,    51,    50,    54,    50,    91,    98,    54,    54,
      83,     9,     9,    82,    58,    77,    78,    78,    78,    82,
      77,     9,    93,    99,     9,    59,    93,    99,     9,    41,
      41,    32,    33,    34,    35,    36,    37,    38,    39,    97,
      97,     9,    91,    51,     9,    89,    91,    99,    97,    97,
      13,    14,    55,    28,    46,    55,    41,    18,    83,    42,
      51,    54,    54,    54,    83,    40,    50,    40,    99,    83,
      41,    88,    98,     9,    91,    99,     9,    91,    99,    50,
      96,    13,    41,    59,    45,    41,     8,    30,    50,    51,
      51,    51,    51,    51,    51,    51,    42,    51,    41,    62,
      59,    41,    50,    51,     9,    41,    51,    51
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
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



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

/* Line 1455 of yacc.c  */
#line 75 "syntaxique.y"
    { printf(" Le programme est correcte syntaxiquement\n"); YYACCEPT; ;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 88 "syntaxique.y"
    { printf("Programme valide reconnu\\n"); ;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 92 "syntaxique.y"
    {strcpy(save,"INTEGER");;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 93 "syntaxique.y"
    {strcpy(save,"FLOAT");;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 94 "syntaxique.y"
    {strcpy(save,"caractere");;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 106 "syntaxique.y"
    {
    // $2 est l'identifiant, $4 est l'entier
    //printf("Constante déclarée : %s = %d\n", $2, $4);
    // Insérer la constante dans la table des symboles ou autre traitement
;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 113 "syntaxique.y"
    {
    
    printf("Tableau déclarée \n");

;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 120 "syntaxique.y"
    { 
    for (j = 0; j < i; j++) {
        // Vérification de la double déclaration
        if (doubleDeclaration(IDF[j]) == 0) { 
            // Si pas de double déclaration, insérer l'identifiant
            insererTypeIDF(IDF[j], save);
            DonnerVS(IDF[j], 1); // Marquer comme variable
        } else if (doubleDeclaration(IDF[j]) == -1) {
            // Gestion d'erreur pour double déclaration
            printf("\n ==============> Erreur Sémantique : Double déclaration pour %s à la ligne : %d et colonne : %d <==============\n", IDF[j], nb_ligne, col);
            return -1;
        }
    }
    // Réinitialiser les structures après traitement
    Re_TAB(IDF, i);
    i = 0;
;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 137 "syntaxique.y"
    {
    // Vérification des dimensions pour les tableaux
    strcpy(sauvType, save);
    if (doubleDeclaration((yyvsp[(2) - (7)].str)) == 0) { 
        insererTypeIDF((yyvsp[(2) - (7)].str), sauvType);
        DonnerVS((yyvsp[(2) - (7)].str), 1); // Marquer comme variable
    } else if (doubleDeclaration((yyvsp[(2) - (7)].str)) == -1) {
        printf("\n ==============> Erreur Sémantique : Double déclaration pour %s à la ligne : %d et colonne : %d <==============\n", (yyvsp[(2) - (7)].str), nb_ligne, col);
        return -1;
    }

    if ((yyvsp[(5) - (7)].entier) < 0) {
        // Vérification des dimensions invalides
        printf("\n ==============> Erreur Sémantique : Dimension négative pour %s à la ligne : %d et colonne : %d <==============\n", (yyvsp[(2) - (7)].str), nb_ligne, col);
        return -1;
    }
;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 154 "syntaxique.y"
    {
    strcpy(sauvType, save);
    if (doubleDeclaration((yyvsp[(2) - (9)].str)) == 0) { 
        insererTypeIDF((yyvsp[(2) - (9)].str), sauvType);
        DonnerVS((yyvsp[(2) - (9)].str), 1); // Marquer comme variable
    } else if (doubleDeclaration((yyvsp[(2) - (9)].str)) == -1) {
        printf("\n ==============> Erreur Sémantique : Double déclaration pour %s à la ligne : %d et colonne : %d <==============\n", (yyvsp[(2) - (9)].str), nb_ligne, col);
        return -1;
    }

    if (((yyvsp[(7) - (9)].entier) < (yyvsp[(5) - (9)].entier)) || ((yyvsp[(5) - (9)].entier) < 0)) {
        // Vérification des dimensions invalides
        printf("\n ==============> Erreur Sémantique : Dimension invalide pour %s à la ligne : %d et colonne : %d <==============\n", (yyvsp[(2) - (9)].str), nb_ligne, col);
        return -1;
    }
;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 170 "syntaxique.y"
    {
    // Gestion des déclarations avec affectation
    int x = doubleDeclaration((yyvsp[(2) - (5)].str));
    if (x == -1) {
        // Gestion des cas spécifiques
        if (getCstDec((yyvsp[(2) - (5)].str)) == 0) {
            printf("\n ==============> Erreur Sémantique : Constante %s redéclarée à la ligne : %d <==============\n", (yyvsp[(2) - (5)].str), nb_ligne);
            return -1;
        } else if (get_type((yyvsp[(2) - (5)].str)) != type) {
            printf("\n ==============> Erreur Sémantique : Incompatibilité de type pour %s à la ligne : %d <==============\n", (yyvsp[(2) - (5)].str), nb_ligne);
            return -1;
        }
    } else {
        // Insertion et initialisation en fonction du type
        switch (type) {
            case 1: // INT
                insererTypeIDF((yyvsp[(2) - (5)].str), "INT");
                sprintf(v, "%d", valCst);
                DonnerVS((yyvsp[(2) - (5)].str), 0); // Marquer comme constante
                insererVAL((yyvsp[(2) - (5)].str), v);
                break;
            case 2: // FLOAT
                insererTypeIDF((yyvsp[(2) - (5)].str), "FLOAT");
                sprintf(v, "%f", valCst);
                insererVAL((yyvsp[(2) - (5)].str), v);
                break;
            case 3: // CHAR
                insererTypeIDF((yyvsp[(2) - (5)].str), "CHAR");
                insererVAL((yyvsp[(2) - (5)].str), cstStr);
                break;
            case 4: // STRING
                insererTypeIDF((yyvsp[(2) - (5)].str), "STRING");
                insererVAL((yyvsp[(2) - (5)].str), cstStr);
                break;
        }
        setCstDec((yyvsp[(2) - (5)].str), 0); // Marquer comme déclaré
        updateCodeCst((yyvsp[(2) - (5)].str), 0); // Mettre à jour le code
    }

    // Réinitialiser après traitement
    Re_TAB(IDF, i);
    i = 0;
;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 214 "syntaxique.y"
    {  strcpy(IDFF , (yyvsp[(1) - (3)].str));  strcpy(IDF[i] , IDFF);  i++;  ;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 215 "syntaxique.y"
    {  strcpy(IDFF , (yyvsp[(1) - (1)].str));  strcpy(IDF[i] , IDFF);  i++;  ;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 241 "syntaxique.y"
    {
	 				if(nonDeclared((yyvsp[(1) - (1)].str))==-1 ){
		 				printf("Erreur Semantique idf non declare a la ligne : %d et laColonne : %d <============== \n ",nb_ligne,col);return -1;
	 				}
;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 249 "syntaxique.y"
    {
	 				if(nonDeclared((yyvsp[(1) - (1)].str) )==-1 ){
		 				printf("Erreur Semantique idf non declare a la ligne : %d et laColonne : %d <============== \n ",nb_ligne,col);return -1;
	 				}
;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 262 "syntaxique.y"
    {	
			   								

			   					if (nonDeclared((yyvsp[(1) - (4)].str))==-1)
								{printf(" ==============>Erreur Semantique : la variable %s est non Declarer dans la  partie declaration  a la ligne %d et laColonnes %d !!! <============== \n",(yyvsp[(1) - (4)].str),nb_ligne,col);
								return -1;}
								else if ( DemanderVS((yyvsp[(1) - (4)].str)) ==0 ) {
												if(  getCstDec((yyvsp[(1) - (4)].str))==0){

															printf(" ==============>Erreur semantique : le %s c'est une constante , tu peut pas fait une affectation  , a la ligne %d et laColonne : %d<============== \n",(yyvsp[(1) - (4)].str),nb_ligne,col);
															return -1;
												}			
															}
															 
								if( ( type <3 && get_type((yyvsp[(1) - (4)].str)) < 3 ) ){
									switch(get_type((yyvsp[(1) - (4)].str))){
										case 1: 
											sprintf(v , "%d" , (int)valFloat);
											insererVAL((yyvsp[(1) - (4)].str),v); 
											setCstDec((yyvsp[(1) - (4)].str),0);

											break;
										case 2:
											sprintf(v , "%f" , valFloat);
											insererVAL((yyvsp[(1) - (4)].str),v);
											setCstDec((yyvsp[(1) - (4)].str),0);

											break;
									}
								}

								


								else switch (type)
											{
											case 3 :
												insererVAL((yyvsp[(1) - (4)].str),cstStr);
												setCstDec((yyvsp[(1) - (4)].str),0);
											break;
											case 4 :
												insererVAL((yyvsp[(1) - (4)].str),cstStr);
												setCstDec((yyvsp[(1) - (4)].str),0);
											break;
											
											}

		                  ;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 316 "syntaxique.y"
    {  
			   					if(nonDeclared((yyvsp[(1) - (4)].str)) == -1){
									   printf(" ==============> Erreur Semantique: variable %s non declare a la ligne : %d et laColonne : %d <============== \n",(yyvsp[(3) - (4)].str),nb_ligne,col);return -1;
								   }
																
								if(nonDeclared((yyvsp[(3) - (4)].str)) == -1){
									printf(" ==============> Erreur Semantique: variable %s non declare a la ligne : %d et laColonne : %d <============== \n",(yyvsp[(3) - (4)].str),nb_ligne,col);return -1;
								}

								if ( DemanderVS((yyvsp[(1) - (4)].str)) ==0 ) {
												if(  getCstDec((yyvsp[(1) - (4)].str))==0){

															printf(" ==============>Erreur semantique : le %s c'est une constante , tu peut pas fait une affectation  , a la ligne %d et laColonne : %d<============== \n",(yyvsp[(1) - (4)].str),nb_ligne,col);
															return -1;
												}			
															}

								if(get_type((yyvsp[(1) - (4)].str))<2 && get_type((yyvsp[(3) - (4)].str))<2){
									if(get_type((yyvsp[(1) - (4)].str))==1){
										updateValIdf((yyvsp[(1) - (4)].str),(yyvsp[(3) - (4)].str));
									}
								}
								else	if(get_type((yyvsp[(1) - (4)].str)) != get_type((yyvsp[(3) - (4)].str))){
											printf(" ==============> Erreur Semantique : incompatibilte de type  a la ligne : %d et laColonne : %d !!! <============== \n",nb_ligne,col);
										return -1;
									}

								updateValIdf((yyvsp[(1) - (4)].str),(yyvsp[(3) - (4)].str));



								;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 349 "syntaxique.y"
    {
	 				if(nonDeclared((yyvsp[(1) - (3)].str) )==-1 ){
		 				printf("Erreur Semantique idf non declare a la ligne : %d et laColonne : %d <============== \n ",nb_ligne,col);return -1;
	 				}

					

					if(get_type((yyvsp[(1) - (3)].str)) != get_type((yyvsp[(3) - (3)].str))){ 

									printf(" ==============> Erreur Semantique : incompatibilte de type  a la ligne: %d et laColonne : %d  !!! <============== \n",nb_ligne,col);
										return -1;
								}
					
					
					calcul((yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].str),operateur[opera-1],&k); opera--;
					calculResult[j]= k;  j++;
					

 ;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 371 "syntaxique.y"
    {
	 								if(nonDeclared((yyvsp[(1) - (3)].str)) == -1 ){
		 							printf("==============> Erreur Semantique idf non declare a la ligne : %d et laColonne : %d <============== \n ",nb_ligne,col);
									return -1;
	 							}

								 if(get_type((yyvsp[(1) - (3)].str)) >2 ||  type > 2 ){ 
									printf("==============> Erreur Semantique : imncompatibilte de type  a la ligne : %d et laColonne : %d  !!!<============== \n",nb_ligne,col);
								return -1;}
								
								if(valCst==0 && operateur[opera-1]==4){
									printf("==============> Erreur Semantique : devision sur ZEROOO a la ligne : %d et laColonne : %d <============== \n",nb_ligne,col);
									return -1;
								}
								
								 calculIdfXCst((yyvsp[(1) - (3)].str),&valFloat,operateur[opera-1],&k); opera--;
								 					calculResult[j]= k; j++;

		;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 394 "syntaxique.y"
    {
			if((yyvsp[(3) - (3)].entier) == 0)
            printf("==============>Erreur Semantique devision sur zero  a la ligne : %d et laColonne : %d <============== \n ",nb_ligne,col);return -1;
			
			calculCstXCst(&cstNum[y-1],&cstNum[y-2],operateur[opera-1],&k); opera--;
			
			calculResult[j]=k;	j++;				


		;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 404 "syntaxique.y"
    {

	 								if(nonDeclared((yyvsp[(3) - (3)].str) )==-1 ){
		 								printf("==============>Erreur Semantique idf non declare a la ligne : %d et laColonne : %d <============== \n ",nb_ligne,col);return -1;
	 									}
										 
									 if(get_type((yyvsp[(3) - (3)].str)) >2 ||  type > 2){
									printf("==============> Erreur Semantique : imncompatibilte de type  a la ligne : %d et laColonne : %d  !!! <============== \n",nb_ligne,col);
								return -1;}
								
								 calculIdfXCst((yyvsp[(3) - (3)].str),&valFloat,operateur[opera-1],&k); opera--;
										 					calculResult[j]= k;j++; 

										 
										 	;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 421 "syntaxique.y"
    { 
	 								if(nonDeclared((yyvsp[(1) - (3)].str) )==-1 ){
		 							printf("==============> Erreur Semantique idf non declare a la ligne : %d et laColonne : %d <============== \n",nb_ligne,col);return -1;
	 									}
										
								calculIdfXCst((yyvsp[(1) - (3)].str),&calculResult[j-1],operateur[opera-1],&k);opera--;
								
								calculResult[j]= k; j++;
								 


								// na7sbo w n7ato f sommet de pile, resultat ta3 calcul tkon f sommet sema hna ndiro idf operateur sommet de pile, apres nremplaciw sommet l9dim b resultat jdida,
								// f expression arethmetique (idf oper calcul) nvidiw tableau, tkon deja fih ghir 1
								// f le cas ta3 calcul oper calcul, nahasbo sommet de pile operateur l'element li 9bel sommet, na7iwhom w n7ato resultat



									;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 440 "syntaxique.y"
    {
			calculCstXCst(&cstNum[y-1],&calculResult[j-1],operateur[opera-1],&k); opera--;
			calculResult[j]=k;j++;

		;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 456 "syntaxique.y"
    {
	 				if(nonDeclared((yyvsp[(2) - (7)].str) )==-1 ){
		 				printf("Erreur Semantique idf non declare a la ligne : %d et laColonne : %d <============== \n ",nb_ligne,col);return -1;
	 				}
	 				

          ;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 465 "syntaxique.y"
    {
	 				if(nonDeclared((yyvsp[(2) - (7)].str) )==-1 ){
		 				printf("Erreur Semantique idf non declare a la ligne : %d et laColonne : %d <============== \n ",nb_ligne,col);return -1;
					}

          ;}
    break;



/* Line 1455 of yacc.c  */
#line 2070 "syntaxique.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 490 "syntaxique.y"

int main(int argc, char *argv[])
{ 
     
	if (argc != 2) {
        printf("Usage: %s <fichier.txt>\n", argv[0]);
        return 1;
    }
    
  
    FILE *fichier = fopen(argv[1], "r");
    if (fichier == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        return 1;
    }
    initialisation();
   
    yyin = fichier;
    int result = yyparse();
    afficher();
	return 0;
}

int yywrap(){
	return 1;
}

int parse() 
{

 return yyparse();

}


