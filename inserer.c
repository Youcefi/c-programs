#include<stdio.h>
#include<stdlib.h>
#include<math.h>
typedef struct{
	int T[100];
	int Long;
}liste;

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

main(){
	liste L;
	int i,k,e;
	printf("donner la longeure du la liste: ");
	scanf("%d",&L.Long);

	printf("Donner une position pour inserer un element dans une liste: ");
	scanf("%d",&k);

	printf("Donner la valeur de element a inseree: ");
	scanf("%d",&e);

	for(i=0;i<L.Long;i++){
	printf("donner L.T[%d]= ",i);
	scanf("%d",&L.T[i]);
	}
	
	inserer(&L,k,e);
	printf(" *********************** \n");
	for(i=0;i<L.Long;i++){
	printf("L.T[%d]=%d\n ",i,L.T[i]);

	}

}
