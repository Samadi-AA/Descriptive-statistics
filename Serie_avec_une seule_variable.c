#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*********************************************************************************
 *    Programme de statistique descriptive ( cas de serie à une seule variable ) *
 *    Date de création     :10/01/2019                                           *
 *    Auteur               : AIT OUAKRIM Abdessamad                              *
 *********************************************************************************/

//procédure pour saisir les valeurs du serie
void SaisirTab(int n, float M[], float E[])
{
     int i;
     for(i=1;i<=n;i++){
           printf("donner la valeur %d : ",i);
           scanf("%f",&M[i]);
           printf("donner l'effectif de cette valeur : ",i);
           scanf("%f",&E[i]);
        }  
	printf("\n\n");
}
//procédure pour afficher le tableau principal du serie  
void AfficherTab(int n, float M[], float E[])
{
     int i;
    printf("\tModalites  :");
    for( i=1;i<=n;i++){
              printf ("\t%4.2f",M[i]) ;
              }
    printf("\n");
    printf("\tEffectifs  :");
        for( i=1;i<=n;i++){
              printf ("\t%4.2f",E[i]) ;
              }
}
// fonction qui calcule l'effectif totale de la serie
float effectiftotal(int n, float E[]){
	int i;
	float et=0;
	for(i=1;i<=n;i++){
		et+=E[i];
	}
	return et;
}
//procédure pour afficher le tableau avec les ECC
void ecc(int n, float M[], float E[]){
	int i;
	float ecc[n];
	printf("\n\t    ECC    :");
	ecc[1]=E[1];
	printf("\t%4.2f",ecc[1]);
	for(i=2;i<=n;i++){
		ecc[i]=ecc[i-1]+E[i];
		printf("\t%4.2f",ecc[i]);
	}
}
//procédure pour afficher le tableau avec les ECD
void ecd(int n, float M[], float E[]){
	int i;
	float ecd[n];
	printf("\n\t    ECD    :");
	ecd[1]=effectiftotal(n, E);
	printf("\t%4.2f",ecd[1]);
	for(i=2;i<=n;i++){
		ecd[i]=ecd[i-1]-E[i-1];
		printf("\t%4.2f",ecd[i]);
	}
}
//procédure pour afficher le tableau avec les fréquences
void frequence(int n, float M[], float E[]){
	int i;
	float fr;
	printf("\n\tfrequences :");
	for(i=1;i<=n;i++){
		fr=E[i]/effectiftotal(n, E);
		printf("\t%4.2f",fr);
	}
}
//procédure pour afficher le tableau avec les FCC 
void fcc(int n, float M[], float E[]){
	int i;
	float fcc[n];
	float fr;
	printf("\n\t    FCC    :");
	fcc[1]=E[1]/effectiftotal(n, E);
	printf("\t%4.2f",fcc[1]);
	for(i=2;i<=n;i++){
		fr=E[i]/effectiftotal(n, E);
		fcc[i]=fr+fcc[i-1];
		printf("\t%4.2f",fcc[i]);
	}
}
//procédure pour afficher le tableau avec les FCD 
void fcd(int n, float M[], float E[]){
	int i;
	float fcd[n];
	float fr;
	printf("\n\t    FCD    :");
	fcd[1]=1;
	printf("\t%4.2f",fcd[1]);
	fr=E[1]/effectiftotal(n, E);
	for(i=2;i<=n;i++){
		fcd[i]=fcd[i-1]-fr;
		fr=E[i]/effectiftotal(n, E);
		printf("\t%4.2f",fcd[i]);
	}
}
// fonction qui calcule le mode de la serie
float mode(int n, float M[], float E[]){
	int i;
	float mode,Em;
	Em=E[1];
	mode=M[1];
	for(i=2;i<=n;i++){
		if(E[i]>=Em){
		mode=M[i];
		Em=E[i];
	    }
	}
	return mode;
}
// fonction qui calcule la moyenne de la serie
float moyenne(int n, float M[], float E[]){
	int i;
    float s=0,m;
    for(i=1;i<=n;i++){
        s+=M[i]*E[i];
	}
	m=s/effectiftotal(n, E);
	return m;
}
// fonction qui calcule la variance de la serie
float variance(int n, float M[], float E[]){
	int i;
    float s=0,v;
    for(i=1;i<=n;i++){
    	s+=E[i]*M[i]*M[i];
	}
	v=s/effectiftotal(n, E)-moyenne(n, M, E)*moyenne(n, M, E);
	return v;
}
// fonction qui calcule l'ecart type de la serie
float ecart(int n, float M[], float E[]){
	float ec,v;
	v=variance(n, M, E);
	ec=sqrt(v);
	return ec;
}
// fonctions pour le choix
int Menu()
{
   int choix;
    printf("\t\t|-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_ Menu _-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_|\n");
	printf("\t\t|                                                                                     |\n");
    printf("\t\t|\t:1 pour calcule l'effectif totale de cette serie                              |\n");
    printf("\t\t|\t:2 pour afficher le tableau avec les frequences                               |\n");
    printf("\t\t|\t:3 pour afficher le tableau avec les FCC et les FCD                           |\n");
    printf("\t\t|\t:4 pour afficher le tableau avec les ECC et les ECD                           |\n");
    printf("\t\t|\t:5 pour afficher le tableau global qui contient (F,FCC,FCD,ECC,ECD)           |\n"); 
    printf("\t\t|\t:6 pour calcule le mode de cette serie                                        |\n");
    printf("\t\t|\t:7 pour calcule la moyenne de cette serie                                     |\n");
    printf("\t\t|\t:8 pour calcule la variance de cette serie                                    |\n");
    printf("\t\t|\t:9 pour calcule l'ecart type de cette serie                                   |\n");
    printf("\t\t|\t:0 pour quitter le programme                                                  |\n");
    printf("\t\t|_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_|\n");
    printf("\n");
    printf("donnez votre choix : ");
    scanf("%d",&choix);
 return choix;
 }
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@------ programme principal ------@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
int main() {
   float M[10000],E[10000];
   int choix, n;
    printf("\t\t\t\t|---------------------------------------------------------------------------|\n");
    printf("\t\t\t\t|\t bienvenu a notre programme de la statistique descriptive :         |\n");
	printf("\t\t\t\t|\t\tle cas d'une serie statistique a une variable .             |\n");
	printf("\t\t\t\t|---------------------------------------------------------------------------|\n\n"); 
    printf("d'abord donner le nombre des element de votre tableau : ");
    scanf("%d",&n);
    printf("\n");
    while (n<=0 || n>10000){
    	if(n<=0){
    		printf("le nombre que vous avez saisir est negative ou egale 0!!\n");
    	}
		else if(n>10000){
    		printf("le nombre que vous avez saisir est superieur de 10000 !!\n");
	    }
	    printf("\n");
	    printf("entrez le nombre des elements de votre tableaux : ");
	    scanf("%d",&n);
        printf("\n");
	}
    SaisirTab(n, M, E);
    printf("voila le tableau que vous avez saisir :\n\n");
    AfficherTab(n, M, E);
    printf("\n\nNous vous presente le menu suivant pour choiser qui ce que vous vouler calculer :\n\n");
    do {
     choix=Menu();
     switch (choix)
    {
           case 1: printf("\nl'effectif totale de cette serie est : %.2f\n\n",effectiftotal(n, E));
                   break;
           case 2: printf("\nvoila votre tableau avec les frequences :\n\n");
                   AfficherTab(n, M, E);
                   frequence(n, M, E);
				   printf("\n\n");			   				   				   				   				                      
                   break;            
           case 3: printf("\nvoila votre tableau avec les FCC et les FCD :\n\n");
                   AfficherTab(n, M, E);
				   frequence(n, M, E);
				   fcc(n, M, E);
                   fcd(n, M, E);
				   printf("\n\n"); 
				   break;
           case 4: printf("\nvoila votre tableau avec les ECC et les ECD :\n\n");
                   AfficherTab(n, M, E);
				   ecc(n, M, E);
				   ecd(n, M, E);
				   printf("\n\n"); 
				   break;
           case 5: printf("\nvoila le tableau global qui contient (F,FCC,FCD,ECC,ECD)  :\n\n");
                   AfficherTab(n, M, E);
				   ecc(n, M, E);
				   ecd(n, M, E);
				   frequence(n, M, E);
				   fcc(n, M, E);
                   fcd(n, M, E);				   
				   printf("\n\n"); 
				   break;   
           case 6: printf("\nle mode de cette serie est : %.2f\n\n",mode(n, M, E));
                   break;
           case 7: printf("\nla moyenne de cette serie est : %.2f\n\n",moyenne(n, M, E));
                   break;
           case 8: printf("\nla variance de cette serie est : %.2f\n\n",variance(n, M, E));
                   break;
           case 9: printf("\nl'ecart type de cette serie est : %.2f\n\n",ecart(n, M, E));				   				   				   				   				                      
                   break;
    } 
     }while (choix!=0);
	return 0;
}
