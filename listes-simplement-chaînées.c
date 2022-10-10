#include <stdio.h>
#include <stdlib.h>

//Déclaration de la structure de données de type Liste simplement chaînée
typedef struct Element Element;
struct Element
{
    int nombre;
    Element *suivant;
};

// afficher les elements d'une liste
void afficherListe(Element *liste)
{
    Element* actuel = liste;

    printf("TETE-> ");
    while (actuel != NULL)
    {
        printf("%d -> ", actuel->nombre);
        actuel = actuel->suivant;
    }
    printf("NULL\n");
}

// 1- Insérer un élément quelconque en tête de liste.
Element* insertion_tete(Element* liste, int nvNombre)
{
    /* Création du nouvel élément */
    Element* nouveau = malloc(sizeof(Element*));
    nouveau->nombre = nvNombre;

    /* Insertion de l'élément au début de la liste */
    nouveau->suivant = liste;
    liste=nouveau;

    return liste;
}

// 2- Insérer un élément en tête de liste telle que la liste ne doit pas comporter de doublons.
Element* insertion_tete_sans_double(Element* liste, int nvNombre)
{

    Element* actuel = liste;
    while (actuel!= NULL)
    {
        if (actuel->nombre == nvNombre)
        {
            break;
        }
        actuel = actuel->suivant;
    }

    if (actuel!=NULL)
    {
        printf("elem %d existe dans le liste!\n",nvNombre);
    }
    else
    {
        /* Création du nouvel élément */
        Element* nouveau = malloc(sizeof(Element*));
        nouveau->nombre = nvNombre;

        /* Insertion de l'élément au début de la liste */
        nouveau->suivant = liste;
        liste=nouveau;
    }
    return liste;
}

// 3- Insérer un élément quelconque en queue de liste.
Element* insertion_queue(Element* liste, int nvNombre)
{
    /* Création du nouvel élément */
    Element* nouveau = malloc(sizeof(Element*));
    nouveau->nombre = nvNombre;
    nouveau->suivant = NULL;

    if (liste==NULL)
    {
      liste=nouveau;
    }
    else
    {
        Element* actuel = liste;
        while (actuel->suivant != NULL)
        {
            actuel = actuel->suivant;
        }
        /* Insertion de l'élément au queue de la liste */
        actuel->suivant=nouveau;
    }
    return liste;
}


// 4- Insérer un élément quelconque en queue de liste telle que la liste ne doit pas comporter de doublons.
Element* insertion_queue_sans_double(Element* liste, int nvNombre)
{

    Element* actuel = liste;
    while (actuel!= NULL)
    {
        if (actuel->nombre == nvNombre)
        {
            break;
        }
        actuel = actuel->suivant;
    }

    if (actuel!=NULL)
    {
        printf("elem %d existe dans le liste!\n",nvNombre);
    }
    else
    {
        /* Création du nouvel élément */
        Element* nouveau = malloc(sizeof(Element*));
        nouveau->nombre = nvNombre;
        nouveau->suivant = NULL;

        if (liste==NULL)
        {
          liste=nouveau;
        }
        else
        {
            Element* actuel = liste;
            while (actuel->suivant != NULL)
            {
                actuel = actuel->suivant;
            }
            /* Insertion de l'élément au queue de la liste */
            actuel->suivant=nouveau;
        }
    }
    return liste;
}

// 5- Insérer un élément quelconque au rang r de la liste
Element* insertion_dans_Rang(Element* liste, int range, int nvNombre)
{
    if (range==0)
    {
        liste= insertion_tete(liste, nvNombre);
    }
    else
    {
           Element* actuel = liste;
            Element* precedent=NULL;

            int range_actuel=0;
            while (actuel!= NULL && actuel->suivant!= NULL && range_actuel!=range)
            {
                range_actuel+=1;
                precedent=actuel;
                actuel = actuel->suivant;
            }

            if(range_actuel==range)
            {
                /* Création du nouvel élément */
                Element* nouveau = malloc(sizeof(Element*));
                nouveau->nombre = nvNombre;

                if (liste==NULL)
                {
                    nouveau->suivant = NULL;
                    /* Insertion de l'élément au queue de la liste */
                    liste=nouveau;
                }
                else
                {
                    precedent->suivant = nouveau;
                    /* Insertion de l'élément au queue de la liste */
                    nouveau->suivant=actuel;
                }
            }
            else
            {
                printf("la taille de de la liste est inferieure a %d \n",range);
            }
    }
    return liste;
}

// 6- Calcule le nombre d'élément d'une liste
void nombre_elem_liste(Element *liste)
{
    Element* actuel = liste;
    int cpt=0;
    while (actuel != NULL)
    {
        cpt+=1;
        actuel = actuel->suivant;
    }
    printf("le nombre d'element de la liste est %d \n",cpt);
}

// 7 - Fragmenter une liste en deux listes L1 et L2 telles que la première contient les éléments
//pairs et la seconde les éléments impairs.
void fragmenter(Element *liste,Element ** l1,Element ** l2)
{
    Element* actuel = liste;
    while (actuel != NULL)
    {
        if (actuel->nombre%2==0) *l1=insertion_queue(*l1,actuel->nombre);
        else *l2=insertion_queue(*l2,actuel->nombre);
        actuel = actuel->suivant;
    }
}

// 8- Trier liste
Element* trier(Element *liste)
{
    int bool_liste_triee=0,chengment;
    Element* actuel,*suiv=NULL;
    while (bool_liste_triee==0)
    {
        actuel=liste;
        chengment=0;
        while (actuel != NULL && actuel->suivant != NULL)
        {
            suiv=actuel->suivant;
            if (actuel->nombre > suiv->nombre)
            {
                int temp=actuel->nombre;
                actuel->nombre=suiv->nombre;
                suiv->nombre=temp;
                chengment++;
            }
            actuel=suiv;
        }
        if(chengment==0) bool_liste_triee=1;
    }
    return liste;
}

// 9 - Supprimer tous les doublons d'une liste
Element *  delete_elem(Element * liste, int val)
{
    Element * actuel = liste;
    if (actuel==NULL)
    {
        return NULL;
    }
    else
    {
        Element * prec=NULL;
         while (actuel != NULL)
        {
            if ( actuel->nombre == val)
            {
                if(prec==NULL)
                {
                    liste=actuel->suivant;

                    free(actuel);
                    break;
                }
                else
                {
                    prec->suivant = actuel->suivant;
                    free(actuel);
                    break;
                }

            }
            prec = actuel;
            actuel = actuel->suivant;
        }
        return liste;
    }

}


//10- Produire la liste miroir
Element* miroir(Element * liste)
{
    Element *liste2=NULL;
    int nbr;

    Element* actuel = liste;
    while (actuel != NULL)
    {
        nbr= actuel->nombre;
        liste2=insertion_tete(liste2,nbr);
        actuel = actuel->suivant;
    }
    return liste2;
}

int main()
{

    printf("creation de liste:\n");
    Element *maListe=NULL,*maListe1=NULL,*maListe2=NULL;

    maListe=insertion_queue(maListe, 4);
    maListe=insertion_queue(maListe, 1);
    maListe=insertion_queue(maListe, 5);
    maListe=insertion_queue(maListe, 0);
    afficherListe(maListe);

    printf("\nfragmenter liste:\n");
    fragmenter(maListe,&maListe1,&maListe2);
    afficherListe(maListe1);
    afficherListe(maListe2);

    int val=1;
    printf("\nsup de %d:\n",val);
    maListe=delete_elem(maListe,val);
    afficherListe(maListe);

    printf("\ntrier la liste:\n");
    maListe=trier(maListe);
    afficherListe(maListe);

    printf("\nliste miroir:\n");
    maListe1=miroir(maListe);
    afficherListe(maListe1);


    return 0;
}
