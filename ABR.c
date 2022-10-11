#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "structAB.h"

int main(int argc, char *argv[]) {
	srand(time(NULL));
	clock_t temps,t;
	int n,valeur;
	liste *l;
	l=NULL;
	noeud *A,*c;
	printf("\noperation 0: arreter\n");
	printf("operation 1: creer un AB\n");
	printf("operation 2: creer un ABR\n");
	printf("operation 3: Afficher AB ordonnez\n");
	printf("operation 4: Affiche ABR\n");
	printf("operation 5: insertion d'un element dans un ABR\n");
	printf("operation 6: nbr de noeud total\n");
	printf("operation 7: nbr de noeud externe\n");
	printf("operation 8: nbr de noeud interne\n");
	printf("operation 9: liste prefixe\n");
	printf("operation 10: liste infixe\n");
	printf("operation 11: liste postefixe\n");
	printf("operation 12: existe \n");
	printf("operation 13: existe ABR\n");
	printf("operation 14: verifie si ABR\n");
	printf("operation 15: max ABR\n");
	printf("operation 16: min\ ABRn");
	printf("operation 17: supprime un element dans un ABR\n");
	printf("operation 18: detruire AB\n");
	do{
	printf("\n quel operation vous voulez ");
	scanf("%d",&n);
	switch(n){
		case 0:
		break;
		
		case 1:
			t=clock();
			A=creer_AB();
			temps=clock()-t;
			printf("\n temps d'execution = %f s\n",(double)temps/CLOCKS_PER_SEC);
			break;
			
		case 2:
			t=clock();
			A=creer_ABR();
			temps=clock()-t;
			printf("\n temps d'execution = %f \sn",(double)temps/CLOCKS_PER_SEC);
			break;
			
		case 3:
			t=clock();
			Affiche_AB(A);
			temps=clock()-t;
			printf("\n temps d'execution = %f s\n",(double)temps/CLOCKS_PER_SEC);
			break;
			
		case 4:
			t=clock();
			Affiche_ABR(A);
			temps=clock()-t;
			printf("\n temps d'execution = %f s\n",(double)temps/CLOCKS_PER_SEC);
			break;
			
		case 5:
			t=clock();
			printf("donnez val");
			scanf("%d",&valeur);
			A=insere_ABR(A,valeur);
			temps=clock()-t;
			printf("\n temps d'execution = %f s\n",(double)temps/CLOCKS_PER_SEC);
			break;
		
		case 6:
			t=clock();
			printf("le nombre de noeud total:%d",nbr_noeud_total(A));
			temps=clock()-t;
			printf("\n temps d'execution = %f s\n",(double)temps/CLOCKS_PER_SEC);
			break;
		
		case 7:
			t=clock();
			printf("le nombre de noeud externe:%d",nbr_noeud_externe(A));
			temps=clock()-t;
			printf("\n temps d'execution = %f s\n",(double)temps/CLOCKS_PER_SEC);
			break;
		
		case 8:
			t=clock();
			printf("le nombre de noeud interne:%d",nbr_noeud_interne(A));
			temps=clock()-t;
			printf("\n temps d'execution = %f s\n",(double)temps/CLOCKS_PER_SEC);
			break;
		
		case 9:
			t=clock();
			l=Liste_Prefixe(A);
			temps=clock()-t;
			printf("\n temps d'execution = %f s\n",(double)temps/CLOCKS_PER_SEC);
			break;
		
		case 10:
			t=clock();
			l=Liste_Infixe(A);
			temps=clock()-t;
			printf("\n temps d'execution = %f s\n",(double)temps/CLOCKS_PER_SEC);
			break;
			
		case 11:
			t=clock();
			l=Liste_Postefixe(A);
			temps=clock()-t;
			printf("\n temps d'execution = %f s\n",(double)temps/CLOCKS_PER_SEC);
			break;
		case 12:
			t=clock();
			printf("donnez val:");
			scanf("%d",&valeur);
			if(existe(A,valeur)!=NULL)
			printf("%d existe dans AB",valeur);
			else
			printf("%d n'existe pas dans AB",valeur);
			temps=clock()-t;
			printf("\n temps d'execution = %f s\n",(double)temps/CLOCKS_PER_SEC);
			break;
			
		case 13:
			t=clock();
			printf("donnez val:");
			scanf("%d",&valeur);
			if(existe_ABR(A,valeur)!=NULL)
			printf("%d existe dans ABR",valeur);
			else
			printf("%d n'existe pas dans ABR",valeur);
			temps=clock()-t;
			printf("\n temps d'execution = %f s\n",(double)temps/CLOCKS_PER_SEC);
			break;
			
		case 14:
			t=clock();
			if(verifie(A))
			printf("C'est un arbre binaire de recherche ");
			else
			printf("Ce n'est pas un arbre binaire de recherche ");
			temps=clock()-t;
			printf("\n temps d'execution = %f s\n",( (double)temps/CLOCKS_PER_SEC) );
			break;
			
		case 15:
			t=clock();
			c=max_ABR(A);
			if(c!=NULL)
			printf("max = %d",c->info);
			else
			printf("ABR VIDE");
			temps=clock()-t;
			printf("\n temps d'execution = %f s\n",(double)temps/CLOCKS_PER_SEC);
			break;
			
		case 16:
			t=clock();
			c=min_ABR(A);
			if(c!=NULL)
			printf("min = %d",c->info);
			else
			printf("ABR VIDE");
			temps=clock()-t;
			printf("\n temps d'execution = %f s\n",(double)temps/CLOCKS_PER_SEC);
			break;
			
		case 17:
			t=clock();
			printf("donnez val");
			A=supprime(A,valeur);
			temps=clock()-t;
			printf("\n temps d'execution = %f s\n",(double)temps/CLOCKS_PER_SEC);
			break;
			
		case 18:
			t=clock();
			A=Detruit_ARBRE(A);
			temps=clock()-t;
			printf("\n temps d'execution = %f s\n",(double)temps/CLOCKS_PER_SEC);
			break;
		default :
		printf("\n operation n'existe pas \n");				
	}
	
	}while(n!=0);
	return 0;
}
