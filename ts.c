/****************CREATION DE LA TABLE DES SYMBOLES ******************/

/***Step 1: Definition des structures de données ***/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>  // Ajout de cet en-tête pour utiliser la fonction strcpy
#include <stdbool.h> // Ajout de cet en-tête pour utiliser le type de donnees bool


//  BTW PARFOIS J'ECRIS "IDF" PARFOIS "VARIABLE" (C'EST LA MEME CHOSE)

/***** Représente une entrée dans la table des symboles pour les variables et constantes*****/
typedef struct
{
  int state;  //  Indique si l'entrée est occupée (1) ou libre (0)
  char name[200]; // Nom de l'entité 
  char code[60];  // Informations sur l'entité
  char type[60];  // Informations sur l'entité
  char val[60];   // Informations sur l'entité
  int VS;    // Variable (1) ou constante (0)    
  int D;     // Indique si la case a été écrasée
  int cstDeclaration; // Indique si la constante est déclarée
} element;


/*****  Représente une entrée simplifiée pour les mots-clés et les séparateurs*/
typedef struct
{
  int state;
  char name[20];
  char code[20];
} elt;


element tab[1000]; // Table des symboles pour les variables et constantes
elt tabs[40], // Table des séparateurs.
elt tabm[40]; // Table des mots-clés
extern char sav[20];
char chaine[] = "";


/***Step 2: initialisation de l'état des cases des tables des symbloles***/
/*0: la case est libre    1: la case est occupée*/

void initialisation()
{
  int i;
  for (i = 0; i < 1000; i++)
    tab[i].state = 0;

  for (i = 0; i < 40; i++)
  {
    tabs[i].state = 0;
    tabm[i].state = 0;
  }
}


/***Step 3: insertion des entititées lexicales dans les tables des symboles ***/

void inserer(char entite[], char code[], char type[], char val[], int y, int i)
{

  switch (y)
  {
  case 0: /*insertion dans la table des IDF et des const */
    if (tab[i-1].D == 1) i=i-1; // // Réutilise une case écrasée
    tab[i].state = 1;
    strcpy(tab[i].name, entite);
    strcpy(tab[i].code, code);
    strcpy(tab[i].type, type);
    strcpy(tab[i].val,val);
    tab[i].D=0;
    break;

  case 1: /*insertion dans la table des mc*/
    tabm[i].state = 1;
    strcpy(tabm[i].name, entite);
    strcpy(tabm[i].code, code);
    break;

  case 2: /*insertion dans la table des séparateurs*/
    tabs[i].state = 1;
    strcpy(tabs[i].name, entite);
    strcpy(tabs[i].code, code);
    break;
  }
}


/***Step 4: La fonction Rechercher permet de verifier  si l'entité existe dèja dans la table des symboles */

void rechercher(char entite[], char code[], char type[], int y, char val[20])
{
  int i;
  int current = 0;
  switch (y)
  {
  case 0: /*verifier si l'entité existe dans la table des idf et const*/
    for (i = 0; i < 1000; i++)
    {
      if (tab[i].state == 0)
      {
        current = i;
        inserer(entite, code, type, val, y, current);
        break;
      }
      else if (strcmp(tab[i].name, entite) == 0)
      {
        break; // Trouvé
      }
    }

    break;
  case 1: /*pour les MC*/
    for (i = 0; i < 40; i++)
    {
      if (tabm[i].state == 0)
      {
        current = i;
        inserer(entite, code, type, val, y, current);
        break;
      }
      else if (strcmp(tabm[i].name, entite) == 0)
      {
        break;
      }
    }
    break;
  case 2: /*insertion dans la table des sep*/
    for (i = 0; i < 40; i++)
    {
      if (tabs[i].state == 0)
      {
        current = i;
        inserer(entite, code, type, val, y, current);
        break;
      }
      else if (strcmp(tabs[i].name, entite) == 0)
      {
        break;
      }
    }
    break;
  }
}


/***Step 5 L'affichage du contenue de la table des symboles ***/

void afficher()
{
  int i;

  printf("\n/***************Table des symboles IDF ET CONST*************/\n");
  printf("____________________________________________________________________\n");
  printf("\t| Nom_Entite |  Code_Entite | Type_Entite | Val_Entite\n");
  printf("____________________________________________________________________\n");

  for (i = 0; i < 1000; i++)
  {

    if (tab[i].state == 1)
    {
      printf("\t|%10s  |%13s | %11s | %12s |\n", tab[i].name, tab[i].code, tab[i].type, tab[i].val);
    }
  }
  printf("____________________________________________________________________\n\n");

  printf("\n/***************Table des symboles Mot cles*************/\n");

  printf("_______________________________________\n");
  printf("\t| NomEntite     |  CodeEntite | \n");
  printf("_______________________________________\n");

  for (i = 0; i < 40; i++)
  {
    if (tabm[i].state == 1)
    {
      printf("\t|%14s |%12s | \n", tabm[i].name, tabm[i].code);
    }
  }
  printf("_______________________________________\n\n");
  printf("\n/***************Table des symboles separateurs*************/\n");

  printf("_________________________________________\n");
  printf("\t| NomEntite |  CodeEntite | \n");
  printf("_________________________________________\n");

  for (i = 0; i < 40; i++)
  {

    if (tabs[i].state == 1)
    {
      printf("\t|%10s |%12s | \n", tabs[i].name, tabs[i].code);
    }
  }
  printf("_____________________________________\n");
}


/***** Trouve la position d’une entité dans tab */
int Rechercher_PosIDF(char entite[])
{
  int i = 0;
  while (i < 1000)
  {
    if (strcmp(entite, tab[i].name) == 0)
      return i;
    i++;
  }

  return -1;
}


/*****  Ajoute un type à une variable */
void insererTypeIDF(char entite[], char type[])
{
  int pos;
  pos = Rechercher_PosIDF(entite);
  if (pos != -1)
  {
    strcpy(tab[pos].type, type);
  }
}


/***** Retourne un identifiant pour le type  */
int get_type(char entite[]){
  int pos=Rechercher_PosIDF(entite);
  if (pos != -1)
  {
  if (strcmp(tab[pos].type,"INT")==0)      return 1;
  if (strcmp(tab[pos].type,"FLOAT")==0)   return 2;
  if (strcmp(tab[pos].type,"CHAR")==0)    return 3;
  if (strcmp(tab[pos].type,"STRING")==0)  return 4;
}

}


/*****  Vérifie si une variable est redéclarée */
int doubleDeclaration(char entite[])
{
  int pos;
  pos = Rechercher_PosIDF(entite);
  if(pos!= -1){

  if (strcmp(tab[pos].type,"") ==0 )
    return 0;
  }

    return -1;
}


/*****  Vérifie si une variable est redéclarée */
int nonDeclared(char entite[]){
 int pos;
  pos = Rechercher_PosIDF(entite);
  if (strcmp(tab[pos].type,"") == 0)
    return -1;
  else
    return 0;
}


/*****  attribue une valeur (1/0) au champ VS d'une entité
Elle localise la position de l'entité avec Rechercher_PosIDF(entite)
Elle affecte ensuite la valeur donnée par le paramètre i au champ VS de l'entité  */
void DonnerVS(char entite[] , int i)
 {
 tab[Rechercher_PosIDF(entite)].VS =i;
 }


 int DemanderVS(char entite[]) // Retourne la valeur de VS
{
   int V;
   V=tab[Rechercher_PosIDF(entite)].VS; 
	return V ; 
}


/***** réinitialise un tableau de chaînes de caractères en y remplaçant toutes les chaînes par des chaînes vides ("") */
void Re_TAB(char TAB[100][20] , int n ){
	int i;
	for (i=0 ; i<n ; i++)
		strcpy (TAB[i] , "");
}


/***** met à jour la valeur (val) associée à une entité */
void insererVAL(char entite[], char val[])
{
  int pos = Rechercher_PosIDF(entite);
  if  (pos != -1) {
                    strcpy(tab[pos].val,val);
                   }
}                   


/*****  modifie une chaîne val en: 
Retirant les parenthèses entourant la chaîne (si elles existent)
Remplacant les virgules , par des points . */
void Change_affich(char val[20])
 { 
 char R [20];
	int i,j=0;
	if ( val[0] =='(' )
	{ for (i=1 ; i<strlen(val)-1 ; i++) {
                        	R[j]=val[i];
                          j++; }
	strcpy(val ,R); 
  }
  
	for (i=0 ; i<strlen(val) ; i++){ 
                        if (val[i]==',') val[i]='.';
                                  }

 }


/***** Met à jour le champ code d'une entité en y plaçant "CST" (constante) */
void updateCodeCst(char entite[],int cstDec){
    int i = Rechercher_PosIDF(entite);
    strcpy(tab[i].code, "CST");
    tab[i].cstDeclaration = cstDec;

}


/***** Met à jour le type (type) d'une entité dans la table des symboles */
void updateType(char entite[], char type[]){
  int i =0;
  while (i < 1000)
  {
    if (strcmp(entite, tab[i].name) == 0){
      strcpy(tab[i].type, type);
      break;
    }
    i++;
  }
}


/***** Effectue des opérations (+, -, *, /) entre deux entités */
void calcul(char entite1[],char entite2[],int oper,float *x){

  // atof 
  int i = Rechercher_PosIDF(entite1);
  int j = Rechercher_PosIDF(entite2);
  char val1[10];
  char val2[10];
  strcpy(val1,tab[i].val);
  strcpy(val2,tab[j].val);

  float v1= atof(val1);
  float v2 = atof(val2);
  float result=0;
  
  switch(oper){
    case 1:
        result = v1+v2;
      *x= result; break;
    case 2:
      result = v1-v2;
      *x= result;break;
    case 3:
      result= v1*v2;
      *x= result;break;
    case 4:
      result=v1/v2;
      *x= result;break;
  }

}


/***** Effectue un calcul entre une variable/constante (entité1) et une constante (v2) */
void calculIdfXCst(char entite1[],float *v2,int oper,float *x){

  // atof 
  int i = Rechercher_PosIDF(entite1);
  char val1[10];
  float a=(*v2); 
  strcpy(val1,tab[i].val);

  float v1= atof(val1);
  
  float result=0;
  
  switch(oper){
    case 1:
        result = v1+(*v2); 
        *x= result;   break;
    case 2:
      result = v1-(*v2);
            *x= result;break;
    case 3:
      result= v1*(*v2);
            *x= result;break;
    case 4:
      result=v1/(*v2); 
           *x= result;break;
  }

}


/***** Effectue un calcul entre deux constantes (v1 et v2) */
void calculCstXCst(float *v1,float *v2,int oper,float *x){

  
  float result=0;
  
  switch(oper){
    case 1:
        result = *v1+ (*v2);
      *x= result;  
       break;
    case 2:
      result = *v1-(*v2);
            *x= result;break;
    case 3:
      result= *v1*(*v2);
            *x= result;break;
    case 4:
      result=*v1/(*v2);
            *x= result;break;
  }

}


/*****  Met à jour la valeur d’une constante après calcul */
void updateValCst(char entite[],float x){
  int i = Rechercher_PosIDF(entite);
  char v[10];
    

  sprintf(v , "%f" , x);	
  strcpy(tab[i].val,v);
}


/***** Affecte une valeur (entier, flottant, chaîne, caractère) à une entité */
void affecter(char entite[], int valInt, float valFloat, char valChar, char valStr[],int type){
  int i = Rechercher_PosIDF(entite);
  char str[7];
  char val[20];
  switch(type){
    case 1: 
      val[0]=valChar;
      break;
    case 2:
      strcpy(val,valStr);
      break;
    case 3:
      snprintf(str, sizeof(str), "%d", valInt);
      strcpy(val,str);
      break;
    case 4:
      gcvt(valFloat, 6, val);
      break;
  }
  strcpy( tab[i].val,val);

}


/***** Copie la valeur d'une entité (entite2) vers une autre (entite1) */
void updateValIdf(char entite1[],char entite2[]){
  int i = Rechercher_PosIDF(entite1);
  int j = Rechercher_PosIDF(entite2);

  if(i!=-1 && j != -1){
    strcpy(tab[i].val,tab[j].val);
  }
}


/***** Supprime une entité de la table (réinitialise ses champs) */
void SuppMsg(char entite [50])
{
 int pos=Rechercher_PosIDF(entite);
 if (pos != -1)
  {
  strcpy(tab[pos].name,"");
	strcpy(tab[pos].code,"");
	strcpy(tab[pos].type,"");
	strcpy(tab[pos].val,"");
  tab[pos].D=1;
  }
}


/***** Recherche des caractères spéciaux dans une chaîne */
void chercher_sign(char txt[100],char sign [20])
{
int i;
int j=0;

 for (i=0 ; i<strlen(txt) ; i++)
		{
			if (txt[i] =='%' || txt[i] == '$' || txt[i] =='#' || txt[i] =='&')
        {
          sign[j]=txt[i];
          j++;
        }
			 
      }
}


/***** Réinitialise un tableau de caractères en le remplissant avec des zéros ('\0') */
void RE_tab(char TAB [100],int t )
{
  int i;
  for (i=0 ; i<t ; i++)
  {TAB[i] ='\0';}
}


/***** Valide la compatibilité des types avec des opérateurs */
int Incomsign(char IDFD [100][20],char sign [40] , int t)
{
  int i,j;
	char idf [20]; 
  j=t;
	for (i=0 ; i < t ; i++)
	{
  strcpy(idf , IDFD[i]);
    j--;
	switch (sign[j])
	{	
		case '$' : {if (get_type(idf) != 1){return -1; }}break;
		case '%' : {if (get_type(idf) != 2){return -1; }}break;
		case '&' : {if (get_type(idf) != 3){return -1; }}break;
    case '#' : {if (get_type(idf) != 4){return -1; }}break;
	}
	}	
	return 0 ; 
}


/***** Retourne l'état de déclaration (cstDeclaration) d'une constante dans la table des symboles */
int getCstDec(char entite[]){
  int i = Rechercher_PosIDF(entite);
  return tab[i].cstDeclaration;
}


/*****  Modifie l'état de déclaration (cstDeclaration) d'une constante donnée */
void setCstDec(char entite[],int val){
  int i = Rechercher_PosIDF(entite);
  tab[i].cstDeclaration= val;
}
