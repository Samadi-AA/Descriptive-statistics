#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/****************************************************************************
 *    Programme de statistique descriptive ( cas de serie a deux variables) *
 *    Date de création     :10/01/2019                                      *
 *    Auteur               : AIT OUAKRIM Abdessamad                         *
 ****************************************************************************/

//procédure pour saisir les valeurs de X et Y
void SaisirTab(int n, float X[], float Y[])
{
     int i;
     for(i=1;i<=n;i++){
           printf("donner la valeur X%d: ",i);
           scanf("%f",&X[i]);
        }
    printf("\n");    
     for(i=1;i<=n;i++){
           printf("donner la valeur Y%d: ",i);
           scanf("%f",&Y[i]);
        }  
	printf("\n\n");	 
}
//procédure pour afficher le tableau principal  
void AfficherTab(int n, float X[], float Y[])
{
     int i;
    printf("voila le tableau que vous avez saisir :\n\n");
    printf("\tX: ");
    for( i=1;i<=n;i++){
              printf ("\t%4.2f",X[i]) ;
              }
    printf("\n");
    printf("\tY: ");
        for( i=1;i<=n;i++){
              printf ("\t%4.2f",Y[i]) ;
              }
    printf("\n\nNous vous presente le menu suivant pour choiser qui ce que vous vouler calculer :\n\n");
}
// fonction qui calcule la moyenne de X
float moyenX(int n, float X[]){
	int i;
    float s=0,m;
    for(i=1;i<=n;i++){
        s+=X[i];
	}
	m=s/n;
	return m;
}
// fonction qui calcule la moyenne de Y
float moyenY(int n, float Y[]){
	int i;
    float s=0,m;
    for(i=1;i<=n;i++){
        s+=Y[i];
	}
	m=s/n;
	return m;
}
// fonction qui calcule la variance de X
float varianceX(int n, float X[]){
	int i;
    float s=0,v;
    for(i=1;i<=n;i++){
    	s+=X[i]*X[i];
	}
	v=s/n-moyenX(n, X)*moyenX(n, X);
	return v;
}
// fonction qui calcule la variance de Y
float varianceY(int n, float Y[]){
	int i;
    float s=0,v;
    for(i=1;i<=n;i++){
    	s+=Y[i]*Y[i];
	}
	v=s/n-moyenY(n, Y)*moyenY(n, Y);
	return v;
}
// fonction qui calcule l'ecart type de X
float ecartX(int n, float X[]){
	float ec,v;
	v=varianceX(n, X);
	ec=sqrt(v);
	return ec;
}
// fonction qui calcule l'ecart type de Y
float ecartY(int n, float Y[]){
	float ec,v;
	v=varianceY(n, Y);
	ec=sqrt(v);
	return ec;
}
// fonction pour calcule le covariance
float covariance(int n, float X[], float Y[]){
	int i;
	float cov,p=0;
	for(i=1;i<=n;i++){
		p+=X[i]*Y[i];
	}
	cov=p/n-moyenX(n, X)*moyenY(n, Y);
	return cov;
}
// fonction pour calcule le coefficient de correlation
float coefficient(int n, float X[], float Y[]){
	float cc;
	cc=covariance(n, X, Y)/(ecartX(n, X)*ecartY(n, Y));
	return cc;
}
// procédure pour determiner les equations des droites de regression de y en x, et de x en y
void equation(int n, float X[], float Y[]){
	float a1,a2,b1,b2;
	a1=covariance(n, X, Y)/varianceX(n, X);
	a2=covariance(n, X, Y)/varianceY(n, Y);
	b1=moyenY(n, Y)-(a1*moyenY(n, X));
	b2=moyenY(n, X)-(a2*moyenY(n, Y));
	printf("l''equation de droite de regression de y en x est :");
	printf("\tY = %.2f*X + %.2f",a1,b1);
	printf("\n\nl''equation de droite de regression de x en y est :");
	printf("\tX = %.2f*Y + %.2f",a2,b2);
}
// fonctions pour le choix
int Menu()
{
   int choix;
    printf("\t\t|-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_- Menu -_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-|\n");
	printf("\t\t|                                                                                                  |\n");
    printf("\t\t|\t\t:1 pour calcule la moyenne de X                                                    |\n");
    printf("\t\t|\t\t:2 pour calcule la moyenne de Y                                                    |\n");
    printf("\t\t|\t\t:3 pour calcule la variance de X                                                   |\n");
    printf("\t\t|\t\t:4 pour calcule la variance de Y                                                   |\n");
    printf("\t\t|\t\t:5 pour calcule l'ecart type de X                                                  |\n");
    printf("\t\t|\t\t:6 pour calcule l'ecart type de Y                                                  |\n");
    printf("\t\t|\t\t:7 pour calcule la covariance                                                      |\n");
    printf("\t\t|\t\t:8 pour calcule le coefficient de correlation                                      |\n"); 
    printf("\t\t|\t\t:9 pour determiner les equations des droites de regression de y en x, et de x en y |\n");
    printf("\t\t|\t\t:0 pour quitter le programme                                                       |\n");
    printf("\t\t|-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_|\n");
    printf("\n");
    printf("donnez votre choix : ");
    scanf("%d",&choix);
 return choix;
 }
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@------ programme principal ------@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
int main(){
    float X[10000],Y[10000];
    int choix,n;
    printf("\t\t\t\t|---------------------------------------------------------------------------|\n");
    printf("\t\t\t\t|\t bienvenu a notre programme de la statistique descriptive :         |\n");
	printf("\t\t\t\t|\t\tle cas d'une serie statistique a deux variables .           |\n");
	printf("\t\t\t\t|---------------------------------------------------------------------------|\n\n"); 
    printf("d'abord donner le nombre des elements de votre tableau : ");
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
    SaisirTab(n,X,Y);
    AfficherTab(n,X,Y);
    do {
     choix=Menu();
     switch (choix)
    {
           case 1: printf("\nla moyenne de X est : %.2f\n\n",moyenX(n, X));
                   break;
           case 2: printf("\nla moyenne de Y est : %.2f\n\n",moyenY(n, Y));
                   break;
           case 3: printf("\nla variance de X est : %.2f\n\n",varianceX(n, X));
                   break;
           case 4: printf("\nla variance de Y est : %.2f\n\n",varianceY(n, Y));
                   break;
           case 5: printf("\nl'ecart type de X est : %.2f\n\n",ecartX(n, X));
                   break;
           case 6: printf("\nl'ecart type de Y est : %.2f\n\n",ecartY(n, Y));
                   break;
           case 7: printf("\nla covariance de cette serie est : %.2f\n\n",covariance(n, X, Y));
                   break;
           case 8: printf("\nle coefficient de correlation de cette serie : %.2f\n\n",coefficient(n, X, Y));
                   break;
           case 9: printf("\nvoila les equations des droites de regression de y en x, et de x en y :\n\n");
                   equation(n, X, Y);
                   printf("\n\n");
                   break;				   				   				   				   				                      
    }      
     }while (choix!=0);
	return 0;
}
