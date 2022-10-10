#include<stdio.h>
#include<stdlib.h>
typedef struct{
    int T[100];
    int Long;
}liste;
//procedure pour supprimée un element de la liste
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
        else{
            printf("L'operation est imposible");
        }
    }

}
main(){
    liste L;
    int i,k;
    printf("donner la taille du la liste: ");
    scanf("%d",&L.Long);

    printf("Veillez vous remplir la liste\n");
    for(i=0;i<L.Long;i++){
        printf("L.T[%d]=",i);
        scanf("%d",&L.T[i]);
    }
    printf("Donner la position de element a supprime: ");
    scanf("%d",&k);
    //Appel
    supprimer(&L,k);

    printf("\n*************\n");
    for(i=0;i<L.Long;i++){
        printf("  L.T[%d]=%d \n ",i,L.T[i]);
    }


}
