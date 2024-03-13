#ifndef BIBLIO_H   //compilation conditionnelle
#define BIBLIO_H


#include "livre.h"

#define CAPACITE_BIBLIO 20 // nb maximum de livres ds la bibliotheque

typedef  T_livre 	T_tabloDeLivres[CAPACITE_BIBLIO];

typedef struct
{
	T_tabloDeLivres etagere;
	int nbLivres;  //nb de livres actuellement ds la bibliotheque

} T_Bibliotheque;




//prototypes
void init (T_Bibliotheque *ptrB);
int ajouterLivre(T_Bibliotheque  *ptrB);
int  afficherBibliotheque(const T_Bibliotheque  *ptrB);
int rechercheLivre(const T_Bibliotheque  *ptrB, T_Titre nomLivre);
int rechercheAuteur(const T_Bibliotheque  *ptrB, T_Aut nomAut);
int supprimerLivre(T_Bibliotheque  *ptrB, T_Titre nomLivre);
int emprunterLivre(T_Bibliotheque *ptrB, T_Titre nomLivre, T_Emp emp);
int rendreUnLivre(T_Bibliotheque *ptrB, T_Titre nomLivre);
void triTitre(T_Bibliotheque *ptrB);
void triAuteur(T_Bibliotheque *ptrB);
void triAnnee(T_Bibliotheque *ptrB);
void lireDateSysteme(T_Emp *E);
#endif