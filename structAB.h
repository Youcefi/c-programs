#include <stdio.h>
#include <stdlib.h>
/*    definir un noeud    */
typedef struct noeud{
	int info;
	struct noeud *fg;
	struct noeud *fd;
}noeud;

/*    creer un AB      */
noeud* creer_AB(){
	int val;
	noeud *A=NULL;
	printf("\n donnez une valeur :");
	scanf("%d",&val);
	if(val!=-1){
		A=(noeud*)malloc(sizeof(noeud));
		A->info=val;
		A->fg=creer_AB();
		A->fd=creer_AB();
	}
	return A;
}

/*    insere ABR */
noeud* insere_ABR(noeud* A,int val){ 
	if(A==NULL){
		A=(noeud*)malloc(sizeof(noeud));
		A->info=val; 
		A->fd=NULL;
		A->fg=NULL;           
	}
	else if(val > A->info){
			A->fd=insere_ABR(A->fd,val);
		}
		else if(val < A->info){
		A->fg=insere_ABR(A->fg,val);
		}
	
	return A;
}

/*    creer un AB de recherche    */
noeud* creer_ABR(){
	int val,n,i;
	noeud* A=NULL;
	printf("\n donnez le nombre d'element : ");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		printf("\n donnez une valeur :");
		scanf("%d",&val);
		A=insere_ABR(A,val);
	}
	return A;
}


/* nbr noeud total    */
int nbr_noeud_total(noeud *A){
	if(A!=NULL){
		return 1+nbr_noeud_total(A->fd)+nbr_noeud_total(A->fg);
	}
	return 0;
}

/*    nbr noeud interne    */
int nbr_noeud_interne(noeud* A){
	if(A!=NULL){
		if(A->fd!=A->fg){
			return 1+nbr_noeud_interne(A->fd)+nbr_noeud_interne(A->fg);
		}
	}
	return 0;
}

/*    nbr noeud externe   */
int nbr_noeud_externe(noeud* A){
	if(A!=NULL){
		if(A->fd==A->fg){ //A->fd==NULL && A->fg==NULL
			return 1;
		}
		return nbr_noeud_externe(A->fd)+nbr_noeud_externe(A->fg);
	}
	return 0;
}

/* difinition d'une liste */
typedef struct liste{
	int val;
	struct liste *svt;
}liste;

/*  afficher liste   */
void Affiche_Liste(liste *l){
	while(l!=NULL){
		printf("%d->",l->val);
		l=l->svt;
	}
	printf("NULL \n");
}

/* inser liste fin */
liste* inser_liste_fin(liste*l,int element){
	liste* p=(liste* )malloc(sizeof(p));
	p->val=element;
	p->svt=NULL;
	
	if(l==NULL){
		return p;
	}
	else{
		liste *q=l;
		while(q->svt!=NULL){
			q=q->svt;
		}
		q->svt=p;
		return l;
	}
}
/*  liste prefixe  */
     // creer une liste prefixe 
void creer_Liste_Prefixe(noeud *A,liste **l){
	if(A!=NULL){
		*l=inser_liste_fin(*l,A->info);
		creer_Liste_Prefixe(A->fg,l);
		creer_Liste_Prefixe(A->fd,l);	
	}
}
	 // liste prefixe
liste* Liste_Prefixe(noeud *A){
	liste *l=NULL;
	creer_Liste_Prefixe(A,&l);
	Affiche_Liste(l);
	return l;
}

/*  liste infixe  */
     // creer une liste infixe 
void creer_Liste_Infixe(noeud *A,liste **l){
	if(A!=NULL){
		creer_Liste_Infixe(A->fg,l);
		*l=inser_liste_fin(*l,A->info);
		creer_Liste_Infixe(A->fd,l);	
	}
}
	 // liste infixe
liste* Liste_Infixe(noeud *A){
	liste *l=NULL;
	creer_Liste_Infixe(A,&l);
	Affiche_Liste(l);
	return l;
}




/*  liste postefixe  */
     // creer une liste postefixe 
void creer_Liste_Postefixe(noeud *A,liste **l){
	if(A!=NULL){
		creer_Liste_Postefixe(A->fg,l);
		creer_Liste_Postefixe(A->fd,l);	
		*l=inser_liste_fin(*l,A->info);
	}
}
	 // liste infixe
liste* Liste_Postefixe(noeud *A){
	liste *l=NULL;
	creer_Liste_Postefixe(A,&l);
	Affiche_Liste(l);
	return l;
}
/* existe */
noeud* existe(noeud *A,int val){ // cette fonction marche sur les arbres binaires et sur les arbres binaires de recherch
	if(A!=NULL){
		if(A->info==val){
			return A;
		}
		noeud* b=NULL;
		b=existe(A->fg,val);
		if(b!=NULL)return b;
		b=existe(A->fd,val);
		if(b!=NULL)return b;
	}
	return NULL;
}

/*  existe ABR*/
noeud* existe_ABR(noeud *A,int val){
	if(A!=NULL){
		if(A->info==val)return A;
		if(A->info >val) return existe_ABR(A->fg,val);
		return existe_ABR(A->fd,val);
	}
	return NULL;
}
/* verfie */

int verifie(noeud *A){
	liste *l=NULL;
	creer_Liste_Infixe(A,&l);
	if(l!=NULL){
		while(l->svt!=NULL){
			if(l->val > l->svt->val){
				return 0;
			}
			l=l->svt;
		}
	}
	else{
		printf("\n ARBRE VIDE \n");
	}
	return 1;  // si A est NULL par défaut en return 1
}


/* max et min */
// ABR max
noeud* max_ABR(noeud *A){
	if(A!=NULL){
		if(A->fd==NULL){
			return A;
		}
		return max_ABR(A->fd);
	}
	return NULL;
}
// ABR min
noeud* min_ABR(noeud *A){
	if(A!=NULL){
		if(A->fg==NULL){
			return A;
		}
		return min_ABR(A->fg);
	}
	return NULL;
}



/* Afficher AB*/
  // afficher ABR
void Affiche_ABR(noeud *A){  //parcour infixe  
	if(A!=NULL){
		Affiche_ABR(A->fg);
		printf("%d,",A->info);
		Affiche_ABR(A->fd);
	}
}
  // afficher AB coisson
void Affiche_AB(noeud *A){
	liste *l=NULL;
	creer_Liste_Infixe(A,&l);// vous pouvez utiliser prefixe ou postefixe
	liste *p=l;
	liste *q;
	if(l!=NULL){
		while(p->svt!=NULL){
			q=p->svt;
			while(q!=NULL){
				if(q->val < p->val){
					int c=q->val;
					q->val=p->val;
					p->val=c;
				}
				q=q->svt;
			}
			p=p->svt;
		}
	}
	p=l;
	while(p!=NULL){
		printf("%d ,",p->val);
		p=p->svt;
	}
}

/*   supprime   */
noeud* supprime(noeud *A,int val){
	if(A!=NULL){
		if(A->info==val){
			noeud *B=A;
			if((A->fg==NULL)||(A->fd==NULL)){
				if(A->fd==A->fg){// A->fd==NULL && A->fg==NULL (feuille)
				free(A);
				return NULL;
			}
			if(A->fg==NULL){
				A=A->fg;
			}
			else{
				A=A->fd;
			}
			free(B);
			return A;
			}
			
			else{
					noeud *C=A->fg;
					while(C->fd!=NULL){
						B=C;
						C=C->fd;
					}
					B->fd=NULL;
					A->info=C->info;
					free(C);
				}
				return A;
		}
		else if(A->info > val)
		A->fg=supprime(A->fg,val);
		else{
				A->fd=supprime(A->fd,val);
		}		
	}
	return A;
}

/* detriut ARBRE  */
noeud* Detruit_ARBRE(noeud *A){
	if(A!=NULL){
		A->fg=Detruit_ARBRE(A->fg);
		A->fd=Detruit_ARBRE(A->fd);
		free(A);
	}
	return NULL;
}
