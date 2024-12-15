%{ 
	extern int yylex(void); 
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include "ts.h"

	void yyerror(const char *s);
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
	
	int  valCst;
	char *valChar;
	float valFloat;
	char *valStr;

	int condition=0;


%}

%union {
         int     entier;
         char*   str;
         float reel;
}

%token cst_int
%token cst_real
%token cst_str
%token MC_NEGATION_LOGIQUE
%token ERREUR_LEXICAL
%token MC_PROGRAMME MC_END <str>MC_IDF <str>MC_CHAINE pvg aff MC_writeln MC_READLN MC_ENDIF MC_ELSE MC_THEN MC_IF MC_ENDDO MC_BEGIN MC_FOR MC_WHILE MC_DO MC_ENTIER MC_REAL
%token MC_VAR MC_CONST MC_CARACTERE MC_INTEGER MC_DIMENSION MC_ROUTINE MC_ENDR MC_TAB MC_SUP MC_SUPEGAL MC_INF MC_NOEGAL MC_EGAL MC_OR MC_AND MC_INFEGAL
%token vg division soustraction addition multiplication parouv parferm point pourcentage acov acoferm <entier>entier <str>mc_bool <reel>reel 
%start S
%%
S : C B 
 { printf(" Le programme est correcte syntaxiquement\n"); YYACCEPT; }
;
;
C:LIST_R |
;
LIST_R:A L_R  
;
A:TYPE MC_ROUTINE MC_IDF parouv LIST_IDF parferm LIST_DEC LIST_INST pvg MC_ENDR 
;
L_R:LIST_R |
;
B : MC_PROGRAMME MC_IDF LIST_DEC LIST_INST MC_END
   |MC_PROGRAMME MC_IDF LIST_INST MC_END
;
TYPE : MC_INTEGER {strcpy(save,"INTEGER");}
	  | MC_REAL {strcpy(save,"FLOAT");}
	  | MC_CARACTERE {strcpy(save,"caractere");}
      
;
LIST_DEC : DEC_VAR L_DEC
;
L_DEC: LIST_DEC 
       |
;
  

DEC_VAR: TYPE LIST_IDF pvg { for (j=0; j<i; j++)
								   { if(doubleDeclaration(IDF[j])==0)	
								   	{ 
										insererTypeIDF(IDF[j] , save);
								   		DonnerVS(IDF[j] ,1);
									}
								      	else{
											 if(doubleDeclaration(IDF[j])==-1)
								   				{
										   		printf("\n ==============> Erreur Semantique : Double declaration a la ligne : %d et laColonne : %d <==============\n",nb_ligne,col);
								   				return -1;
												}
								     		}

								   }
								   	Re_TAB(IDF,i); i=0;
								   	} 
 | TYPE  MC_IDF MC_DIMENSION parouv entier  parferm pvg {strcpy(sauvType,save);	
																	
																	{ if(doubleDeclaration($2)==0)	
																		{insererTypeIDF($2 , sauvType );
																		 DonnerVS($2 ,1);
																		 }
																	   else { if(doubleDeclaration($2)==-1)
																		{printf("\n /52==============> Erreur Semantique : Double declaration a la ligne : %d et laColonne : %d <==============\n",nb_ligne,col);
																		return -1;}
																	  }
																	}
																    
																	if  ($5<0)
																	{printf("\n ==============> Erreur Semantique : Fausse taille  a la ligne :%d  et laColonne : %d <==============\n",nb_ligne,col);
																	return -1;}
																	   }		
 |TYPE  MC_IDF MC_DIMENSION parouv entier   vg entier parferm pvg {strcpy(sauvType,save);	
																	
																	{ if(doubleDeclaration($2)==0)	
																		{insererTypeIDF($2 , sauvType );
																		 DonnerVS($2 ,1);
																		 }
																	   else { if(doubleDeclaration($2)==-1)
																		{printf("\n /52==============> Erreur Semantique : Double declaration a la ligne : %d et laColonne : %d <==============\n",nb_ligne,col);
																		return -1;}
																	  }
																	}

																    
																	if (($7<$5) || ($5<0))
																	{printf("\n ==============> Erreur Semantique : Fausse taille  a la ligne :%d  et laColonne : %d <==============\n",nb_ligne,col);
																	return -1;}
																	   }
 | TYPE MC_IDF aff VAL pvg { int x = doubleDeclaration($2);
												if(x==-1)
													{
														if(getCstDec($2)==0){

														printf("\n ==============> Erreur Semantique : Double declaration a la ligne %d <==============\n",nb_ligne);
														return -1;
														}
														else if(get_type($2)!=type){
															printf("\n ==============> Erreur Semantique :Incompatibilte des types a la ligne %d <==============\n",nb_ligne);
														return -1;
														}
														
													}
												else switch (type)
												{
												case 1 : 
													insererTypeIDF($2 ,"INT");
													sprintf(v , "%d" , valCst);
													DonnerVS($2,0);
													insererVAL($2,v);

													
												break;

												case 2 :
													insererTypeIDF($2,"FLOAT");
													
													sprintf(v , "%f" , valCst);	
													insererVAL($2,v);

												break;

												case 3 :
													insererTypeIDF($2,"CHAR");
													
													insererVAL($2,cstStr);
												break;

												case 4 :
													insererTypeIDF($2,"STRING");
													
													insererVAL($2,cstStr);
												break;
												
												} 
													setCstDec($2,0);
													updateCodeCst($2,0);

												Re_TAB(IDF,i);i=0;
 } 
;

LIST_IDF: MC_IDF vg LIST_IDF {  strcpy(IDFF , $1);  strcpy(IDF[i] , IDFF);  i++;  }
         | MC_IDF   {  strcpy(IDFF , $1);  strcpy(IDF[i] , IDFF);  i++;  }
; 
                                                  

LIST_INST:INST L_INST                                           
;		                                  

L_INST: LIST_INST  |
;

INST: INST_READLN
    |INST_writeln
    |INST_IF
    |EXPR_ARITH
;
INST_READLN: MC_READLN parouv MC_IDF parferm pvg
;
INST_writeln: MC_writeln parouv COMMANDES parferm pvg
;
COMMANDES: MC_CHAINE vg MC_IDF vg COMMANDES
          |MC_CHAINE vg MC_IDF
          |MC_CHAINE
          |MC_CARACTERE
          |MC_IDF
;

TYPE_AFF:MC_IDF  {
	 				if(nonDeclared($1)==-1 ){
		 				printf("Erreur Semantique idf non declare a la ligne : %d et laColonne : %d <============== \n ",nb_ligne,col);return -1;
	 				}
} 
| VAL 
| EXPRESSION
;
AFF_COURT: MC_IDF {
	 				if(nonDeclared($1 )==-1 ){
		 				printf("Erreur Semantique idf non declare a la ligne : %d et laColonne : %d <============== \n ",nb_ligne,col);return -1;
	 				}
} 
| VAL
;
EXPRESSION: AFF_COURT OPERATEUR_A TYPE_AFF 
            | parouv EXPRESSION parferm
;
EXPR_ARITH:MC_IDF aff CALCUL pvg;
								
				
		   |MC_IDF aff VAL pvg {	
			   								

			   					if (nonDeclared($1)==-1)
								{printf(" ==============>Erreur Semantique : la variable %s est non Declarer dans la  partie declaration  a la ligne %d et laColonnes %d !!! <============== \n",$1,nb_ligne,col);
								return -1;}
								else if ( DemanderVS($1) ==0 ) {
												if(  getCstDec($1)==0){

															printf(" ==============>Erreur semantique : le %s c'est une constante , tu peut pas fait une affectation  , a la ligne %d et laColonne : %d<============== \n",$1,nb_ligne,col);
															return -1;
												}			
															}
															 
								if( ( type <3 && get_type($1) < 3 ) ){
									switch(get_type($1)){
										case 1: 
											sprintf(v , "%d" , (int)valFloat);
											insererVAL($1,v); 
											setCstDec($1,0);

											break;
										case 2:
											sprintf(v , "%f" , valFloat);
											insererVAL($1,v);
											setCstDec($1,0);

											break;
									}
								}

								


								else switch (type)
											{
											case 3 :
												insererVAL($1,cstStr);
												setCstDec($1,0);
											break;
											case 4 :
												insererVAL($1,cstStr);
												setCstDec($1,0);
											break;
											
											}

		                  }
									
									
									
								


		   |MC_IDF aff MC_IDF pvg{  
			   					if(nonDeclared($1) == -1){
									   printf(" ==============> Erreur Semantique: variable %s non declare a la ligne : %d et laColonne : %d <============== \n",$3,nb_ligne,col);return -1;
								   }
																
								if(nonDeclared($3) == -1){
									printf(" ==============> Erreur Semantique: variable %s non declare a la ligne : %d et laColonne : %d <============== \n",$3,nb_ligne,col);return -1;
								}

								if ( DemanderVS($1) ==0 ) {
												if(  getCstDec($1)==0){

															printf(" ==============>Erreur semantique : le %s c'est une constante , tu peut pas fait une affectation  , a la ligne %d et laColonne : %d<============== \n",$1,nb_ligne,col);
															return -1;
												}			
															}

								if(get_type($1)<2 && get_type($3)<2){
									if(get_type($1)==1){
										updateValIdf($1,$3);
									}
								}
								else	if(get_type($1) != get_type($3)){
											printf(" ==============> Erreur Semantique : incompatibilte de type  a la ligne : %d et laColonne : %d !!! <============== \n",nb_ligne,col);
										return -1;
									}

								updateValIdf($1,$3);



								};
/*__________________________________________________________________________________________________________________________*/

CALCUL: MC_IDF OPERATEUR_A MC_IDF {
	 				if(nonDeclared($1 )==-1 ){
		 				printf("Erreur Semantique idf non declare a la ligne : %d et laColonne : %d <============== \n ",nb_ligne,col);return -1;
	 				}

					

					if(get_type($1) != get_type($3)){ 

									printf(" ==============> Erreur Semantique : incompatibilte de type  a la ligne: %d et laColonne : %d  !!! <============== \n",nb_ligne,col);
										return -1;
								}
					
					
					calcul($1,$3,operateur[opera-1],&k); opera--;
					calculResult[j]= k;  j++;
					

 }



		| MC_IDF OPERATEUR_A VAL {
	 								if(nonDeclared($1) == -1 ){
		 							printf("==============> Erreur Semantique idf non declare a la ligne : %d et laColonne : %d <============== \n ",nb_ligne,col);
									return -1;
	 							}

								 if(get_type($1) >2 ||  type > 2 ){ 
									printf("==============> Erreur Semantique : imncompatibilte de type  a la ligne : %d et laColonne : %d  !!!<============== \n",nb_ligne,col);
								return -1;}
								
								if(valCst==0 && operateur[opera-1]==4){
									printf("==============> Erreur Semantique : devision sur ZEROOO a la ligne : %d et laColonne : %d <============== \n",nb_ligne,col);
									return -1;
								}
								
								 calculIdfXCst($1,&valFloat,operateur[opera-1],&k); opera--;
								 					calculResult[j]= k; j++;

		}
								



		| VAL OPERATEUR_A entier{
			if($3 == 0)
            printf("==============>Erreur Semantique devision sur zero  a la ligne : %d et laColonne : %d <============== \n ",nb_ligne,col);return -1;
			
			calculCstXCst(&cstNum[y-1],&cstNum[y-2],operateur[opera-1],&k); opera--;
			
			calculResult[j]=k;	j++;				


		}
		| VAL OPERATEUR_A MC_IDF {

	 								if(nonDeclared($3 )==-1 ){
		 								printf("==============>Erreur Semantique idf non declare a la ligne : %d et laColonne : %d <============== \n ",nb_ligne,col);return -1;
	 									}
										 
									 if(get_type($3) >2 ||  type > 2){
									printf("==============> Erreur Semantique : imncompatibilte de type  a la ligne : %d et laColonne : %d  !!! <============== \n",nb_ligne,col);
								return -1;}
								
								 calculIdfXCst($3,&valFloat,operateur[opera-1],&k); opera--;
										 					calculResult[j]= k;j++; 

										 
										 	}


		| MC_IDF OPERATEUR_A  CALCUL	   { 
	 								if(nonDeclared($1 )==-1 ){
		 							printf("==============> Erreur Semantique idf non declare a la ligne : %d et laColonne : %d <============== \n",nb_ligne,col);return -1;
	 									}
										
								calculIdfXCst($1,&calculResult[j-1],operateur[opera-1],&k);opera--;
								
								calculResult[j]= k; j++;
								 


								// na7sbo w n7ato f sommet de pile, resultat ta3 calcul tkon f sommet sema hna ndiro idf operateur sommet de pile, apres nremplaciw sommet l9dim b resultat jdida,
								// f expression arethmetique (idf oper calcul) nvidiw tableau, tkon deja fih ghir 1
								// f le cas ta3 calcul oper calcul, nahasbo sommet de pile operateur l'element li 9bel sommet, na7iwhom w n7ato resultat



									}
		
		| VAL OPERATEUR_A CALCUL {
			calculCstXCst(&cstNum[y-1],&calculResult[j-1],operateur[opera-1],&k); opera--;
			calculResult[j]=k;j++;

		}
	
;

INST_IF: MC_IF  CONDITION_CPLX MC_THEN LIST_INST MC_ENDIF
        |MC_IF  CONDITION_CPLX MC_THEN LIST_INST MC_ELSE LIST_INST MC_ENDIF
;
CONDITION_CPLX: CONDITION
               |parouv CONDITION point LIST_CONDITION point CONDITION parferm
;
CONDITION: parouv MC_IDF point LIST_CONDITION point VAL parferm   
           {
	 				if(nonDeclared($2 )==-1 ){
		 				printf("Erreur Semantique idf non declare a la ligne : %d et laColonne : %d <============== \n ",nb_ligne,col);return -1;
	 				}
	 				

          }

          |parouv MC_IDF point LIST_CONDITION point MC_IDF parferm  
		             {
	 				if(nonDeclared($2 )==-1 ){
		 				printf("Erreur Semantique idf non declare a la ligne : %d et laColonne : %d <============== \n ",nb_ligne,col);return -1;
					}

          }
          |parouv EXPRESSION point LIST_CONDITION point EXPRESSION parferm
          |parouv MC_IDF point LIST_CONDITION point EXPRESSION parferm
          |parouv EXPRESSION point LIST_CONDITION point VAL parferm
          |parouv EXPRESSION point LIST_CONDITION point MC_IDF parferm
;
LIST_CONDITION: MC_SUP
               |MC_SUPEGAL
               |MC_EGAL
               |MC_NOEGAL
               |MC_INFEGAL
               |MC_INF
               |MC_AND
               |MC_OR
;
OPERATEUR_A : addition | multiplication | soustraction |division
; 
VAL: entier | mc_bool | reel | MC_CHAINE | MC_CARACTERE
;
%%
int main()
{
    initialisation();
    yyparse(); 
    afficher();
	return 0;
}

int yywrap(){
	return 1;
}

void yyerror(const char *s)
{
	fprintf (stderr, "Erreur syntaxique: %s\n", s);
}
