#include<stdio.h>
#include<stdlib.h>
#include<math.h>
typedef struct{
	int T[100];
	int Long;
}liste;


void initialiser(liste *L){
L->Long=0;
}


void inserer(liste *L,int k,int e){
    int n,i;
    n=L->Long;
	if(n>=100){
		printf("la liste est pleine");
    }
	else{
            if(k>=0 && k<=n+1){
                for(i=n;i>=k;i--){
                    L->T[i+1]=L->T[i];
                    }
                    L->T[k]=e;
                    L->Long=L->Long+1;
                    
            }else{
                 printf("  operation impossible\n");
            }
        }
}


void supprimer(liste *L,int p){
int i;
    if(L->Long<=0){
        printf("la liste est vide\nDonc il n'y aucun element a supprime");
    }
    else{
        if(p>=0 && p<=L->Long){
           for(i=p;i<=L->Long-1;i++){
            L->T[i]=L->T[i+1];
           }
            L->Long=L->Long-1;
        }

    }
}


void Separer(liste *L,liste *L1,liste *L2){
    int i;
   
  	  initialiser(L1);
   	  initialiser(L2);
        while(L->Long!=0){
        if(L->T[i]>=0) inserer(L1,L1->Long,L->T[i]);
        else inserer(L2,L2->Long,L->T[i]);
        supprimer(L,0);
        }
}
main()
{
liste L,L1,L2;
int i;
 printf("donner la taille du la liste: ");
    scanf("%d",&L.Long);

     printf("Veillez vous remplir la liste\n");
    for(i=0;i<L.Long;i++){
        printf("L.T[%d]=",i);
        scanf("%d",&L.T[i]);
    }
//appel de la procedure Separer
Separer(&L,&L1,&L2);

 printf("*************\n");
 printf("Separations: ");
 printf("La liste L1 qui contient les elements positifs ou nuls de L \n");
    for(i=0;i<L1.Long;i++){
        printf("  L1.T[%d]=%d \n ",i,L1.T[i]);
    }

printf("\nLa liste L2 qui contient les elements negatifs de L\n ");
    for(i=0;i<L2.Long;i++){
        printf("  L2.T[%d]=%d \n ",i,L2.T[i]);
    }

}
