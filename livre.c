#include "livre.h"


void saisirLivre(T_livre * ptrL)
{
int annee=0;
lireChaine("TITRE :", (ptrL->titre), MAX_TITRE );
lireChaine("AUTEUR :", (ptrL->auteur ), MAX);
lireChaine("EDITEUR :", (ptrL->editeur ), MAX);
printf("ANNEE : ");
scanf("%d",&annee);
ptrL->annee=annee;
strcpy (ptrL->emprunteur.nomemprunteur ,"");
}

void afficherLivre(const T_livre *ptrL)
{
afficherChaine("TITRE :", (ptrL->titre));
printf(" - ");
afficherChaine("AUTEUR :", (ptrL->auteur ));
printf(" - ");
afficherChaine("EDITEUR :", (ptrL->editeur ));
printf(" - ");
printf("ANNEE : %d",ptrL->annee);
printf(" - ");
printf("EMPRUNTEUR : %s",ptrL->emprunteur.nomemprunteur);
printf("\n");
}

