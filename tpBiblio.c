// TP GESTION D'UNE BIBLIOTHEQUE 
#include "biblio.h"

int menu()
{
	int choix;
// au programme du TP7 :
printf("\n\n 1 - ajouter un nouveau livre dans la bibliotheque "); 
printf("\n 2 - afficher tous les livres de la bibliotheque "); 
printf("\n 3 - rechercher un livre (par son titre)");  // il peut y avoir plusieurs livres de même titre. Dans ce cas, indiquez le nombre d'exemplaires disponibles
printf("\n 4 - rechercher et afficher tous les livres d'un auteur");
printf("\n 5 - supprimer un livre de la bibliotheque");
// si les 5 choix ci dessus sont bien codés, modifiez votre structure T_Livre et passez à 5 champs (avec cote,editeur et annee)


// au programme du TP8 :
// ajouter le champ emprunteur à votre structure T_Livre

printf("\n 6 - emprunter un livre de la bibliotheque");
printf("\n 7 - restituer/rendre un livre de la bibliotheque");
printf("\n 8 - trier les livres (par titre)");
printf("\n 9 - trier les livres (par auteur)");
printf("\n 10 - trier les livres (par annee)");

// si les 5 choix (6-10) sont bien codés, changez le type T_Emp et remplacez-le par la structure T_Emp visible dans livre.h
// vous pourrez alors faire les menus 11,12,etc...
// printf("\n 11- lister les livres disponibles "); 
// printf("\n 12 - lister les emprunts en retard "); //on suppose qu'un emprunt dure 7 jours.
// printf("\n 13 - ... imaginez vous même vos propres fonctionnalités ")

printf("\n 0 - QUITTER");
printf("\n Votre choix : ");
scanf("%d[^\n]",&choix);getchar();
return choix;


}
void sauvegarde(T_Bibliotheque *ptrB)
{
FILE *fic=NULL; //le type FILE
int i;
fic=fopen("baseLivres","w"); // w = le mode = write avec ECRASEMENT
//fopen renvoie NULL si probleme (disque plein, disque non accessible ...
if (fic!=NULL)
	{
	for(i=0;i<ptrB->nbLivres;i++)
		{
//fwrite(const void *ptr, size_t size, size_t nmemb, FILE *stream)
    fwrite(  &(ptrB->etagere[i])        ,sizeof(T_livre),1,fic);

		}
	fclose(fic);
	puts("SAUVEGARDE REUSSIE ..............");



	}
	else puts("ECHEC DE SAUVEGARDE  !!!!!  ");




}



void chargement(T_Bibliotheque *ptrB)
{
FILE *fic=NULL; //le type FILE
int i=0;
fic=fopen("baseLivres","r"); // r = le mode read
//fopen renvoie NULL si probleme (disque plein, disque non accessible ...
if (fic!=NULL)
	{
	do
		{

		fread(  &(ptrB->etagere[i]) ,sizeof(T_livre),1,fic);
		i++;
		}
		while(!feof(fic));
	fclose(fic);
	ptrB->nbLivres=i-1;
	puts("CHARGEMENT  REUSSI ..............");
	}
	else puts("ECHEC DE CHARGEMENT  !!!!!  ");

}


int main()
{
T_Titre nom;
T_Aut aut;
int reponse,chx;
T_Bibliotheque B; 
init( &B );
chargement(&B);
T_Aut emp;
do
{
chx= menu();
switch(chx)
	{
	case  1 : reponse = ajouterLivre(   &B  );
				if (reponse==1)
					printf(" ajout reussi !!");
					else
					printf("impossible d ajouter (bibliotheque pleine)");
			break;
	case 2 : reponse=afficherBibliotheque(&B);
			if (reponse==0)	
					printf("La bibliotheque est vide");

			break;	
	
	case  3 :
	lireChaine("sausissez votre titre :",nom,MAX_TITRE);
	reponse = rechercheLivre(   &B , nom );
				if (reponse!=-1){
					printf(" livre present a l'indice %d!!",reponse);}
				else
				printf("Le livre n'est pas present");
			break;
	
	case  4 :
	lireChaine("saisissez l'auteur :",aut,MAX_TITRE);
	reponse = rechercheAuteur(   &B , aut );
				if (reponse==0){
					printf("Aucun livre pour cette auteur !! ");}
				
			break;
	
	

	case  5 :
	lireChaine("saisissez le titre a supprimer :",nom,MAX_TITRE);
	reponse = supprimerLivre(   &B , nom );
				if (reponse==0){
					printf("livre invalide !! ");}
				else
					printf("suppresion reussi !!");
				
			break;
	
	case  6 :
	lireChaine("saisissez le titre a emprunter :",nom,MAX_TITRE);
	lireChaine("saisissez votre nom :",emp, MAX);
	reponse = emprunterLivre( &B , nom, emp );
				if(reponse==-1) printf("livre inconnu !! ");
				if (reponse==0){
					printf("livre deja emprunter !! ");}
				else
					printf("reussi !!");
				
			break;
	case  7 :
	lireChaine("saisissez le titre a rendre :",nom,MAX_TITRE);
	reponse = rendreUnLivre( &B , nom);
				if(reponse==-1) printf("livre inconnu !! ");
				
				if (reponse==0){
					printf("livre pas encore emprunter !! ");}
				if (reponse==1)
					printf("livre rendu !!");
				
			break;
	case  8 :
	triTitre(&B);
	printf("trie realiser");
	break;
	case  9 :
	triAuteur(&B);
	printf("trie realiser");
	break;
	case  10 :
	triAnnee(&B);
	printf("trie realiser");
	break;
	
	}
}while(chx!=0);


sauvegarde(&B);



return 0;

}
