%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ts.h" // Inclusion de la table des symboles pour les actions associées

// Prototypes
void yyerror(const char *s);
int yylex();
%}

/* Tokens from the lexical analyzer */
%token mc_prog mc_var mc_beg mc_endp idf cst mc_aff mc_pvg acO acF addition soustraction multiplication division mc_write mc_read mc_if mc_else mc_then mc_endif

/* Declarations for token types */
%union {
    int entier;
    float reel;
    char* str;
}

/* Type associations for non-terminals */
%type <entier> expr
%type <reel> expr_reel
%type <str> texte

/* Operator precedence and associativity */
%left addition soustraction
%left multiplication division

%%

/* Grammar Rules */
S:
    mc_prog corps mc_endp
    {
        printf("Programme reconnu avec succès.\n");
        YYACCEPT;
    }
;

corps:
    corps instruction
    | /* vide */
;

instruction:
    declaration
    | affectation
    | mc_write texte mc_pvg
        {
            printf("Écriture : %s\n", $2);
        }
    | mc_read idf mc_pvg
        {
            printf("Lecture : %s\n", $2);
            DonnerVS($2, 1);
        }
    | mc_if condition mc_then corps mc_endif
        {
            printf("Conditionnelle IF reconnue.\n");
        }
    | mc_if condition mc_then corps mc_else corps mc_endif
        {
            printf("Conditionnelle IF-ELSE reconnue.\n");
        }
;

declaration:
    idf mc_pvg
        {
            if (doubleDeclaration($1) == -1) {
                yyerror("Double déclaration détectée !");
            } else {
                printf("Déclaration valide : %s\n", $1);
                inserer($1, "VAR", "", "", 0, Rechercher_PosIDF($1));
            }
        }
;

affectation:
    idf mc_aff expr mc_pvg
        {
            printf("Affectation : %s = %d\n", $1, $3);
            insererVAL($1, $3);
        }
;

condition:
    expr
        {
            printf("Condition simple.\n");
        }
;

expr:
    expr addition expr
        {
            $$ = $1 + $3;
        }
    | expr soustraction expr
        {
            $$ = $1 - $3;
        }
    | expr multiplication expr
        {
            $$ = $1 * $3;
        }
    | expr division expr
        {
            if ($3 == 0) {
                yyerror("Erreur : Division par zéro !");
            } else {
                $$ = $1 / $3;
            }
        }
    | cst
        {
            $$ = $1;
        }
    | idf
        {
            $$ = $1;
        }
;

texte:
    cst
        {
            $$ = strdup($1);
        }
;

%%

void yyerror(const char *s) {
    fprintf(stderr, "Erreur syntaxique : %s\n", s);
}

int main() {
    printf("Début de l'analyse syntaxique...\n");
    yyparse();
    printf("Fin de l'analyse syntaxique.\n");
    return 0;
}

int yywrap() {
    return 1;
}