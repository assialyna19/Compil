%option yylineno
%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "syntaxique.tab.h"
    #include "ts.h"
  extern FILE *yyin;
    extern int nb_ligne;
    extern int col;
    extern YYSTYPE yylval;
    char Const[20];   
%}

TYPE (INTEGER|REAL)
lettre          [a-z]
lettreM         [A-Z]
chiffre         [0-9]
IDF  ({lettreM}|{lettre})({lettre}|{chiffre})*("_"({lettre}|{chiffre})+)*  
INT [+-]?[0-9]+
REAL {INT}\.{INT}
BOOL TRUE|FALSE
caractere \"[^"]?\"
cst_real [+-]?{chiffre}+\.{chiffre}+
cst_int [-+]?{chiffre}+
cst_str \"[^\"]*\"
chaine \"[^"]*\"
COMMENTAIRE \/\/[^\n]*|\/\*([^*]|\*+[^*/])*\*+\/

%%


"PROGRAMME"   {   
    rechercher(yytext, "Mot cle", "", 0, 1);
    printf("programme reconnu : %s\n", yytext);
    col += strlen(yytext);
    return MC_PROGRAMME; }

"VAR"       { 
    rechercher(yytext, "Mot cle", "", 0, 1);
    printf("var reconnu : %s\n", yytext);
    col += strlen(yytext);
    return MC_VAR; }

"BEGIN"     {   
    rechercher(yytext, "Mot cle", "", 0, 1);
    printf("début reconnu : %s\n", yytext);
    col += strlen(yytext);
    return MC_BEGIN; } 

"END."      {   
    rechercher(yytext, "Mot cle", "", 0, 1);
    printf("fin reconnue : %s\n", yytext);
    col += strlen(yytext);
    return MC_END ; }

"IF"        { 
    rechercher(yytext, "Mot cle", "", 0, 1);
    printf("if reconnu : %s\n", yytext);
    col += strlen(yytext);
    return MC_IF; }

"ELSE"      { 
    rechercher(yytext, "Mot cle", "", 0, 1);
    printf("else reconnu : %s\n", yytext);
    col += strlen(yytext);
    return MC_ELSE; }


"FOR"       {
    rechercher(yytext, "Mot cle", "", 0, 1);
    printf("for reconnu : %s\n", yytext);
    col += strlen(yytext);
    return MC_FOR; }

"WHILE"     {
    rechercher(yytext, "Mot cle", "", 0, 1);
    printf("while reconnu : %s\n", yytext);
    col += strlen(yytext);
    return MC_WHILE; }
    
"DO"        {
    rechercher(yytext, "Mot cle", "", 0, 1);
    printf("do reconnu : %s\n", yytext);
    col += strlen(yytext);
    return MC_DO; }

"ENDDO"     {
    rechercher(yytext, "Mot cle", "", 0, 1);
    printf("enddo reconnu : %s\n", yytext);
    col += strlen(yytext);
    return MC_ENDDO; }



"ENDIF"     {
    rechercher(yytext, "Mot cle", "", 0, 1);
    printf("endif reconnu : %s\n", yytext);
    col += strlen(yytext);
    return MC_ENDIF; }

"THEN"      {
    rechercher(yytext, "Mot cle", "", 0, 1);
    printf("then reconnu : %s\n", yytext);
    col += strlen(yytext);
    return MC_THEN; }


"INTEGER"   {   
    rechercher(yytext, "Mot cle", "", 0, 1);
    printf("integer reconnu : %s\n", yytext);
    col += strlen(yytext);
    return MC_INTEGER; }

"TAB"       {   
    rechercher(yytext,"Mot cle"," ",0, 1);  
    printf("tableau reconnu : %s\n", yytext); 
    col += strlen(yytext); 
    return MC_TAB;}

"DIMENSION" { 
    rechercher(yytext, "Mot cle", "", 0, 1);
    printf("dimension reconnue : %s\n", yytext);
    col += strlen(yytext); 
    return MC_DIMENSION; 
}

"REAL"     { 
    rechercher(yytext, "Mot cle", "", 0, 1);
    printf("float reconnu : %s\n", yytext);
    col += strlen(yytext);
    return MC_REAL ;}

"READLN"    { 
    rechercher(yytext, "Mot cle", "", 0, 1);
    printf("readln reconnu : %s\n", yytext);
    col += strlen(yytext);
    return MC_READLN; }

"writeln"   { 
    rechercher(yytext, "Mot cle", "", 0, 1);
    printf("writeln reconnu : %s\n", yytext);
    col += strlen(yytext);
    return MC_writeln; }



"CONST" {
    rechercher(yytext, "Mot cle", "", 0, 1);
    printf("Constante reconnue : %s\n", yytext);
    col += strlen(yytext);
    return MC_CONST;
}



    
"&&" { 
    printf("Opérateur ET logique reconnu\n"); 
    col += strlen(yytext); 
    return MC_AND; }

"||" { 
    printf("Opérateur OU logique reconnu\n"); 
    col += strlen(yytext); 
    return MC_OR; }

"!"  { 
    printf("Opérateur Négation logique reconnu\n"); 
    col += strlen(yytext); 
    return MC_NEGATION_LOGIQUE; }

">"  { 
    printf("Séparateur '>' reconnu\n"); 
    col += strlen(yytext); 
    return MC_SUP; }

"<"  { 
    printf("Opérateur '<' reconnu\n"); 
    col += strlen(yytext); 
    return MC_INF; }

">=" { 
    printf("séparateur '>=' reconnu\n"); 
    col += strlen(yytext); 
    return MC_SUPEGAL; }

"<=" { 
    printf("séparateur '<=' reconnu\n"); 
    col += strlen(yytext); 
    return MC_INFEGAL; }

"==" { 
    printf("séparateur '==' reconnu\n"); 
    col += strlen(yytext); 
    return MC_EGAL; }

"!=" { 
    printf("séparateur '!=' reconnu\n"); 
    col += strlen(yytext); 
    return MC_NOEGAL; }

","  { 
    rechercher(yytext,"Mot cle",0,0,2); 
    printf("Virgule reconnue\n"); 
    col += strlen(yytext); 
    return vg; }



";"  { 
    rechercher(yytext,"Mot cle",0,0,2); 
    printf("Point-virgule reconnu\n"); 
    col += strlen(yytext); 
    return pvg; }

"/"  { 
    rechercher(yytext,"Mot cle",0,0,2); 
    printf("Division reconnue\n"); 
    col += strlen(yytext); 
    return division; }

"-"  { 
    rechercher(yytext,"Mot cle",0,0,2); 
    printf("Soustraction reconnue\n"); 
    col += strlen(yytext); 
    return soustraction; }

"+"  { 
    rechercher(yytext,"Mot cle",0,0,2); 
    printf("Addition reconnue\n"); 
    col += strlen(yytext); 
    return addition; }

"="  { 
    rechercher(yytext,"Mot cle",0,0,2); 
    printf("Affectation reconnue\n"); 
    col += strlen(yytext); 
    return aff; }

"*"  { 
    rechercher(yytext,"Mot cle",0,0,2); 
    printf("Multiplication reconnue\n"); 
    col += strlen(yytext); 
    return multiplication; }

"("  { 
    rechercher(yytext,"Mot cle",0,0,2); 
    printf("Parenthèse ouvrante reconnue\n"); 
    col += strlen(yytext); 
    return parouv; }

")"  { 
    rechercher(yytext,"Mot cle",0,0,2); 
    printf("Parenthèse fermante reconnue\n"); 
    col += strlen(yytext); 
    return parferm; }

"."  { 
    rechercher(yytext,"Mot cle",0,0,2); 
    printf("Point séparateur reconnu\n"); 
    col += strlen(yytext); 
    return point; }

"%"  { 
    rechercher(yytext,"Mot cle",0,0,2); 
    printf("Pourcentage reconnu\n"); 
    col += strlen(yytext); 
    return pourcentage; }

"{"  { 
    rechercher(yytext,"Mot cle",0,0,2); 
    printf("Accolade ouverte reconnue\n"); 
    col += strlen(yytext); 
    return acov; }

"}"  { 
    rechercher(yytext,"Mot cle",0,0,2); 
    printf("Accolade fermante reconnue\n"); 
    col += strlen(yytext); 
    return acoferm; }

"["  { 
    rechercher(yytext,"Mot cle",0,0,2); 
    printf("crochet ouvrant reconnue\n"); 
    col += strlen(yytext); 
    return crou; }

"]"  { 
    rechercher(yytext,"Mot cle",0,0,2); 
    printf("crochet fermant reconnue\n"); 
    col += strlen(yytext); 
    return crof; }

{IDF}     { 
	 yylval.str = strdup(yytext);
              col = col + strlen(yytext);
			  if (yyleng>7) printf ("Erreur Lexical: IDF trop long a la ligne %d a la colonne %d \n ",nb_ligne, col);
              printf ("L'entite reconnue est %s \n", yytext); 
			  return MC_IDF;
}


{INT} {
    int val = atoi(yytext);
    if (val >= -32768 && val <= 32767) {
        printf("CST entière reconnue : %s\n", yytext);
        yylval.entier = val;
        col += strlen(yytext);
        return Int;
    } else {
        col += strlen(yytext);
        printf("Erreur : Dépassement de capacité à la ligne %d, colonne %d : %s\n", nb_ligne, col, yytext);
    }
}

{REAL} {
    printf("CST réelle reconnue : %s\n", yytext);
    yylval.reel = atof(yytext);
    col += strlen(yytext);
    return MC_REAL;
}

{cst_int} { 
    printf("L'entité lexicale reconnue est %s\n", yytext); 
    yylval.entier = atoi(yytext);
    char val[20];
    sprintf(val, "%f", atof(yytext));
    rechercher(yytext, "CONSTANT", "INTEGER", val, 0);
    col += strlen(yytext); 
    return cst_int; }

{cst_real} {    
    printf("L'entité lexicale reconnue est %s\n", yytext); 
    yylval.reel = atoi(yytext);
    char val[20];
    sprintf(val, "%f", atof(yytext));
    rechercher(yytext, "CONSTANT", "FLOAT", val, 0);
    col += strlen(yytext); 
    return cst_real; }

{cst_str} {    
    printf("L'entité lexicale reconnue est %s\n", yytext); 
    yylval.reel = atoi(yytext);
    char val[20];
    sprintf(val, "%f", atof(yytext));
    rechercher(yytext, "CONSTANT", "STRING", val, 0);
    col += strlen(yytext); 
    return cst_str; }

{COMMENTAIRE} {
    printf("Commentaire ignoré\n");
    for (int i = 0; i < strlen(yytext); i++) {
        if (yytext[i] == '\n') {
            nb_ligne++;
            col = 1;
        } else {
            col++;
        }
    }
}

{caractere} {
    printf("Caractère reconnu : %s\n", yytext);
    col += strlen(yytext);
    return MC_CARACTERE;
}

{chaine} {
    if (strlen(yytext) <= 22) {
        printf("Chaîne reconnue : %s\n", yytext);
        yylval.str = strdup(yytext);
        col += strlen(yytext);
        return MC_CHAINE;
    } else {
        printf("Erreur : Chaîne trop longue à la ligne %d, colonne %d : %s\n", nb_ligne, col, yytext);
    }
}


[ \t]+ { col += strlen(yytext); }

\n { nb_ligne++; col = 1; }

. {
    printf("Erreur lexicale : Ligne %d, Colonne %d, Caractère inconnu : %s\n", nb_ligne, col, yytext);
    return ERREUR_LEXICAL;
}
%%
