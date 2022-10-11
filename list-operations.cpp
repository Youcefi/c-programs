#include <stdio.h>
#include <stdlib.h>

typedef struct liste{
int val;
struct liste* svt;
};

void afficher(struct liste *tete){
struct liste *p=tete;
while(p!=NULL){
    printf("%d\t",p->val);
    p=p->svt;
}
}



struct liste* insertion_queue(struct liste* tete, int a)
{
 struct liste* p = (liste*)malloc(sizeof(liste));
 p->val = a;
 p->svt= NULL;
if (tete==NULL)
 {
tete=p;
}
 else
 {
struct liste* q = tete;
 while (q->svt != NULL)
 {
 q= q->svt;
 }
q->svt=p;
}
return tete;
}


struct liste *suppressiond(struct liste *tete){
 struct liste *p=tete;
 tete=tete->svt;
 free (p);
 return tete;
}

struct liste *suppressionf(struct liste *tete){
struct liste *p=tete;
struct liste *r;
while(p->svt!=NULL){
    r =p;
    p=p->svt;
}
r->svt=NULL;
free(p);
return tete;
}

struct liste *suppressionm(struct liste *tete,int a){
struct liste *p=tete;
struct liste *t;


    while(p!=NULL & p->val!=a){
        t=p;
        p=p->svt;
    }
    t->svt=p->svt;
    free(p);

return tete;

}


struct liste *trie(liste *tete){
 liste *p=tete;
 liste *t;

int tmp;
while(p!=NULL){
	t=p->svt;
    while(t!=NULL){
        if(t->val<p->val){
            tmp=p->val;
            p->val=t->val;
            t->val=tmp;
            t=t->svt;
        }
        else {t=t->svt;}
    }
    p=p->svt;
    
}

return tete;

}

void fragmenter( struct liste *liste,struct liste ** l1,struct liste ** l2) {
 struct liste* p = liste;
 while (p != NULL)
 {
 if (p->val>0) *l1=insertion_queue(*l1,p->val);
 else *l2=insertion_queue(*l2,p->val);
 p = p->svt;
 }
 }


struct liste *suppressiondoublan(struct liste *tete){
struct liste *p=tete;
struct liste *t;
t=p->svt;
while(p!=NULL){
	t=p->svt;
    while(t!=NULL){
        if(t->val==p->val){
            p->svt=t->svt;
            free(t);
            t=p->svt;
        }
        else {t=t->svt;}
    }
    p=p->svt;
    
}

return tete;

}


int main()
{
struct liste *maListe=NULL,*maListe1=NULL,*maListe2=NULL;

maListe=insertion_queue(maListe, 2);
maListe=insertion_queue(maListe, 8);
maListe=insertion_queue(maListe, -4);
maListe=insertion_queue(maListe, 3);
maListe=insertion_queue(maListe, -4);
maListe=insertion_queue(maListe, -1);
maListe=insertion_queue(maListe, 95);
maListe=insertion_queue(maListe, -81);
maListe=insertion_queue(maListe, -1);

printf("La liste initial:\n ");
afficher(maListe);

maListe=suppressiond(maListe);
printf("\nLa liste apres suppression au debut: \n");
afficher(maListe);

maListe=suppressionf(maListe);
printf("\nLa liste apres suppression a la fin :\n");
afficher(maListe);

maListe=suppressionm(maListe,3);
printf("\nLa liste apres suppression au milieu:\n");
afficher(maListe);

maListe=trie(maListe);
printf("\nLa liste trie :\n");
afficher(maListe);

maListe=suppressiondoublan(maListe);
printf("\nLa liste sans repetition : \n");
afficher(maListe);


fragmenter(maListe,&maListe1,&maListe2);
printf("\n\nFragmentation de la liste principale:");

printf("\n 1. Liste des nombres positifs : \n");

afficher(maListe1);

printf("\n 2. La liste des nombre negatifs : \n");

afficher(maListe2);





    return 0;
}

