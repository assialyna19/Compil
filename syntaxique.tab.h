
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
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

/* Line 1676 of yacc.c  */
#line 49 "syntaxique.y"

         int     entier;
         char*   str;
         float reel;



/* Line 1676 of yacc.c  */
#line 128 "syntaxique.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


