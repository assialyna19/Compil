%option yylineno
%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "syntaxique.tab.h"
    
    extern nb_ligne;
    extern nb_colonnes;
    extern YYSTYPE yylval;
    char Const[20];    // Pour les constantes reconnues
%}

TYPE (INTEGER|FLOAT)
lettre [a-zA-Z]
chiffre [0-9]
IDF {lettre}({lettre}|{chiffre})*
INT [+-]?[0-9]+
float {INT}\.{INT}
BOOL TRUE|FALSE
caractere \"[^"]?\"
chaine \"[^"]*\"
COMMENTAIRE \/\/[^\n]*|\/\*([^*]|\*+[^*/])*\*+\/

%%

"CONST" {
    rechercher(yytext, "Mot cle", "", 0, 1);
    printf("Constante reconnue : %s\n", yytext);
    Col += strlen(yytext);
    return mc_const;
}

"PROGRAM"   {   rechercher(yytext, "Mot cle", "", 0, 1);
    printf("programme reconnue : %s\n", yytext);
    Col += strlen(yytext);
    return mc_pgm; }

"END."      {   rechercher(yytext, "Mot cle", "", 0, 1);
    printf("fin reconnue : %s\n", yytext);
    Col += strlen(yytext);
     return mc_fin; }

"BEGIN"     {   rechercher(yytext, "Mot cle", "", 0, 1);
    printf("debut reconnue : %s\n", yytext);
    Col += strlen(yytext);
    return MC_BEGIN; } 

"FOR"       {
    rechercher(yytext, "Mot cle", "", 0, 1);
    printf(" for reconnue : %s\n", yytext);
    Col += strlen(yytext);
    return MC_FOR; }

"WHILE"     {
  rechercher(yytext, "Mot cle", "", 0, 1);
    printf(" while reconnue : %s\n", yytext);
    Col += strlen(yytext);
     return MC_WHILE; }

"IF"        { 
    rechercher(yytext, "Mot cle", "", 0, 1);
    printf("if reconnue : %s\n", yytext);
    Col += strlen(yytext);
    return MC_IF; }

"ELSE"      { 
    rechercher(yytext, "Mot cle", "", 0, 1);
    printf("else reconnue : %s\n", yytext);
    Col += strlen(yytext);
    return MC_ELSE; }

"INTEGER"   {   
    rechercher(yytext, "Mot cle", "", 0, 1);
    printf("integer reconnue : %s\n", yytext);
    Col += strlen(yytext);
    return MC_INTEGER; }

"FLOAT"     { 
   rechercher(yytext, "Mot cle", "", 0, 1);
    printf("float reconnue : %s\n", yytext);
    Col += strlen(yytext);
    return MC_FLOAT ;}

"READLN"    { 
    rechercher(yytext, "Mot cle", "", 0, 1);
    printf("readln reconnue : %s\n", yytext);
    Col += strlen(yytext);
    return MC_READLN; }

"WRITELN"   { 
    rechercher(yytext, "Mot cle", "", 0, 1);
    printf(" writeln reconnue : %s\n", yytext);
    Col += strlen(yytext);
    return MC_WRITELN; }
"VAR"       { 
    rechercher(yytext, "Mot cle", "", 0, 1);
    printf(" var reconnue : %s\n", yytext);
    Col += strlen(yytext);
    return MC_VAR; }



{IDF} {
    if (strlen(yytext) <= 9) {
        printf("IDF reconnu : %s\n", yytext);
        yylval.str = strdup(yytext);
        Col += strlen(yytext);
        return MC_IDF;
    } else {
        Col += strlen(yytext);
        printf("Erreur : Identificateur trop long à la ligne %d, colonne %d : %s\n", nb_ligne, Col, yytext);
    }
}


{INT} {
    int val = atoi(yytext);
    if (val >= -32768 && val <= 32767) {
        printf("CST entière reconnue : %s\n", yytext);
        yylval.entier = val;
        Col += strlen(yytext);
        return entier;
    } else {
        Col += strlen(yytext);
        printf("Erreur : Dépassement de capacité à la ligne %d, colonne %d : %s\n", nb_ligne, Col, yytext);
    }
}

{float} {
    printf("CST réelle reconnue : %s\n", yytext);
    yylval.reel = atof(yytext);
    Col += strlen(yytext);
    return reel;
}


{COMMENTAIRE} {
    printf("Commentaire ignoré\n");
    for (int i = 0; i < strlen(yytext); i++) {
        if (yytext[i] == '\n') {
            nb_ligne++;
            Col = 1;
        } else {
            Col++;
        }
    }
}


{caractere} {
    printf("Caractère reconnu : %s\n", yytext);
    Col += strlen(yytext);
    return mc_caractere;
}

{chaine} {
    if (strlen(yytext) <= 22) {
        printf("Chaîne reconnue : %s\n", yytext);
        yylval.str = strdup(yytext);
        Col += strlen(yytext);
        return mc_chaine;
    } else {
        printf("Erreur : Chaîne trop longue à la ligne %d, colonne %d : %s\n", nb_ligne, Col, yytext);
    }
}


"&&" { printf("Opérateur ET logique reconnu\n"); Col += strlen(yytext); return ET_LOGIQUE; }
"||" { printf("Opérateur OU logique reconnu\n"); Col += strlen(yytext); return OU_LOGIQUE; }
"!"  { printf("Opérateur Négation logique reconnu\n"); Col += strlen(yytext); return NEGATION_LOGIQUE; }


">"  { printf("Opérateur '>' reconnu\n"); Col += strlen(yytext); return SUP; }
"<"  { printf("Opérateur '<' reconnu\n"); Col += strlen(yytext); return INF; }
">=" { printf("Opérateur '>=' reconnu\n"); Col += strlen(yytext); return SUPEGAL; }
"<=" { printf("Opérateur '<=' reconnu\n"); Col += strlen(yytext); return INFEGAL; }
"==" { printf("Opérateur '==' reconnu\n"); Col += strlen(yytext); return EGAL; }
"!=" { printf("Opérateur '!=' reconnu\n"); Col += strlen(yytext); return NOEGAL; }
 

","       { rechercher(yytext,"Mot cle",0,0,2); printf("virgule reconnu\n") ;Col= Col + strlen(yytext);return vg;}
";"       { rechercher(yytext,"Mot cle",0,0,2); printf("point virgule reconnu\n");Col= Col + strlen(yytext); return pvg;}
"/"       { rechercher(yytext,"Mot cle",0,0,2);printf("division reconnu\n");Col= Col + strlen(yytext); return division;}
"-"       { rechercher(yytext,"Mot cle",0,0,2);printf("soustraction reconnu\n") ;Col= Col + strlen(yytext);return soustraction;}
"+"       { rechercher(yytext,"Mot cle",0,0,2);printf("addition reconnu\n") ;Col= Col + strlen(yytext);return addition;}
"="       { rechercher(yytext,"Mot cle",0,0,2);printf("affectation reconnu\n");Col= Col + strlen(yytext); return aff; }
"*"       { rechercher(yytext,"Mot cle",0,0,2);printf("multiplication reconnu\n") ;Col= Col + strlen(yytext);return multiplication;}
"("       { rechercher(yytext,"Mot cle",0,0,2);printf("parenthese ouvrante reconnu\n") ;Col= Col + strlen(yytext); return parouv;}
")"       { rechercher(yytext,"Mot cle",0,0,2);printf("parenthese fermante  reconnu\n") ;Col= Col + strlen(yytext);return parferm;}
"."       { rechercher(yytext,"Mot cle",0,0,2);printf("point separateur reconnu\n") ;Col= Col + strlen(yytext); return point;}
"%"       { rechercher(yytext,"Mot cle",0,0,2); printf("pourcentage  reconnu\n") ; Col= Col + strlen(yytext); return pourcentage;}
"{"       { rechercher(yytext,"Mot cle",0,0,2); printf("acolade ouverte reconnu\n") ; Col= Col + strlen(yytext); return acouv;}
"}"       { rechercher(yytext,"Mot cle",0,0,2); printf("acolade fermeante reconnu\n") ; Col= Col + strlen(yytext); return acoferm;}


[ \t]+ { Col += strlen(yytext); }

\n { nb_ligne++; Col = 1; }


. {
    printf("Erreur lexicale : Ligne %d, Colonne %d, Caractère inconnu : %s\n", nb_ligne, Col, yytext);
    return ERREUR_LEXICAL;
}

%%
