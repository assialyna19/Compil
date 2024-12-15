#ifndef TS_H
#define TS_H

// declaration des fonctions 
void initialisation();
void inserer(char entite[], char code[], char type[], char val[], int y, int i);
void rechercher(char entite[], char code[], char type[], char val[20], int y );
void afficher();
int Rechercher_PosIDF(char entite[]);
int rechercheBib(char entite[]);
int rechercheNonDeclare(char entite[]);
void insererTypeIDF(char entite[], char type[]);
int DoubleDecBib(char entite[]);
int get_type(char entite[]);
int doubleDeclaration(char entite[]);
int nonDeclared(char entite[]);
int VerifIdfConst(char entite[]) ;
void DonnerVS(char entite[] , int i);
int DemanderVS(char entite[]);
void Re_TAB(char TAB[100][20], int n);
void insererVAL(char entite[], char val[]);
void Change_affich(char val[20]);
void updateCodeCst(char entite[],int cstDec);
void updateType(char entite[], char type[]);
void calcul(char entite1[],char entite2[],int oper,float *x);
void calculIdfXCst(char entite1[],float *v2,int oper,float *x);
void calculCstXCst(float *v1,float *v2,int oper,float *x);
void updateValCst(char entite[],float x);
void affecter(char entite[], int valInt, float valFloat, char valChar, char valStr[],int type);
void updateValIdf(char entite1[],char entite2[]);
void SuppMsg(char entite [50]);
void chercher_sign(char txt[100],char sign [20]);
void RE_tab(char TAB [100],int t );
int Incomsign(char IDFD [100][20],char sign [40] , int t);
int getCstDec(char entite[]);
void setCstDec(char entite[],int val);

#endif