
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
     MC_NEGATION_LOGIQUE = 261,
     ERREUR_LEXICAL = 262,
     MC_PROGRAMME = 263,
     MC_END = 264,
     MC_IDF = 265,
     MC_CHAINE = 266,
     pvg = 267,
     aff = 268,
     MC_writeln = 269,
     MC_READLN = 270,
     MC_ENDIF = 271,
     MC_ELSE = 272,
     MC_THEN = 273,
     MC_IF = 274,
     MC_ENDDO = 275,
     MC_BEGIN = 276,
     MC_FOR = 277,
     MC_WHILE = 278,
     MC_DO = 279,
     MC_ENTIER = 280,
     MC_REAL = 281,
     MC_VAR = 282,
     MC_CONST = 283,
     MC_CARACTERE = 284,
     MC_INTEGER = 285,
     MC_DIMENSION = 286,
     MC_ROUTINE = 287,
     MC_ENDR = 288,
     MC_TAB = 289,
     MC_SUP = 290,
     MC_SUPEGAL = 291,
     MC_INF = 292,
     MC_NOEGAL = 293,
     MC_EGAL = 294,
     MC_OR = 295,
     MC_AND = 296,
     MC_INFEGAL = 297,
     vg = 298,
     division = 299,
     soustraction = 300,
     addition = 301,
     multiplication = 302,
     parouv = 303,
     parferm = 304,
     point = 305,
     pourcentage = 306,
     acov = 307,
     acoferm = 308,
     entier = 309,
     mc_bool = 310,
     reel = 311
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1676 of yacc.c  */
#line 44 "syntaxique.y"

         int     entier;
         char*   str;
         float reel;



/* Line 1676 of yacc.c  */
#line 116 "syntaxique.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


