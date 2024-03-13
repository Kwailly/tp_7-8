#include "biblio.h"

void init (T_Bibliotheque *ptrB)
{
    ptrB->nbLivres=0;
}


int ajouterLivre(T_Bibliotheque  *ptrB)
{
    if(ptrB->nbLivres<CAPACITE_BIBLIO){
        saisirLivre(&(ptrB->etagere[ptrB->nbLivres]));
        ptrB->nbLivres++;
        return 1;
    }

    return 0;
}


int  afficherBibliotheque(const T_Bibliotheque  *ptrB)
{
    int i ;
    
    if(ptrB->nbLivres!=0)
    {
        for(i=0 ; i< ptrB->nbLivres;i++){
             afficherLivre(  &(ptrB->etagere[i]) );
        }
        return 1;
    }
    
    
    return 0;
}


int rechercheLivre(const T_Bibliotheque  *ptrB, T_Titre nomLivre)
{
    int i;
    int nb=-1;

    for(i=0 ; i< ptrB->nbLivres;i++){
        if(strcmp(nomLivre,ptrB->etagere[i].titre)==0){
            nb=i;
            return i;
        }
    }
    return nb;
}



int rechercheAuteur(const T_Bibliotheque  *ptrB, T_Aut nomAut){
    int i;
    int rep=0;

   for(i=0 ; i< ptrB->nbLivres;i++){
        if(strcmp(nomAut,ptrB->etagere[i].auteur)==0){
            printf("Titre : %s \n", ptrB->etagere[i].titre);
            rep++;
            
        }
   }
   if(rep==0)
   return 0;

   return 1;
}


int supprimerLivre(T_Bibliotheque  *ptrB, T_Titre nomLivre){
 
    int position = rechercheLivre(ptrB , nomLivre);
    if(position==-1) return 0;


        printf("\n POSITION = %d ",position);

    
    for( ; position < ptrB->nbLivres-1 ;position++){
        ptrB->etagere[position]=ptrB->etagere[position+1];
    }
    ptrB->nbLivres=ptrB->nbLivres-1;
    return 1;


}

int emprunterLivre(T_Bibliotheque *ptrB, T_Titre nomLivre, T_Emp emp) {

    int position = rechercheLivre(ptrB, nomLivre);
    if (position == -1)return -1;

    if (strcmp("" , ptrB->etagere[position].emprunteur.nomemprunteur)==0) {
        
        lireDateSysteme(emp);

        //strcpy(ptrB->etagere[position].emprunteur ,emp );
        return 1; 

    } else {
        
        return 0; 
    }
}


int rendreUnLivre(T_Bibliotheque *ptrB, T_Titre nomLivre){

    int position = rechercheLivre(ptrB, nomLivre);
    if (strcmp("" , ptrB->etagere[position].emprunteur.nomemprunteur)==0) return 0;

    if (position != -1 ) {
        
        strcpy(ptrB->etagere[position].emprunteur.nomemprunteur , "" );
        return 1; 

    } else {
        
        return -1; 
    }
}


void triTitre(T_Bibliotheque *ptrB){
    T_livre aux;
    int i;
    int modif=1;
    while(modif==1){
        modif=0;
        for(i=0 ;i < (ptrB->nbLivres-1) ;i++)
            if(strcmp(ptrB->etagere[i].titre ,ptrB->etagere[i+1].titre)>0){
                aux = ptrB->etagere[i] ;
                ptrB->etagere[i] = ptrB->etagere[i+1] ;
                ptrB->etagere[i+1] = aux ;
                modif=1;
            }
    }

}

            
void triAuteur(T_Bibliotheque *ptrB){
    T_livre aux;
    int i;
    int modif=1;
    while(modif==1){
        modif=0;
        for(i=0 ;i < (ptrB->nbLivres-1) ;i++)
            if(strcmp(ptrB->etagere[i].auteur ,ptrB->etagere[i+1].auteur)>0){
                aux = ptrB->etagere[i] ;
                ptrB->etagere[i] = ptrB->etagere[i+1] ;
                ptrB->etagere[i+1] = aux ;
                modif=1;
            }
    }

}
void triAnnee(T_Bibliotheque *ptrB){
    T_livre aux;
    int i;
    int modif=1;
    while(modif==1){
        modif=0;
        for(i=0 ;i < (ptrB->nbLivres-1) ;i++)
            if(ptrB->etagere[i].annee > ptrB->etagere[i+1].annee){
                aux = ptrB->etagere[i] ;
                ptrB->etagere[i] = ptrB->etagere[i+1] ;
                ptrB->etagere[i+1] = aux ;
                modif=1;
            }
    }

}

    

char * lireChaine(const char *  nomChamps,  char *chaine,int nbcarac)
{
printf("%s  ",nomChamps);
lire(chaine,nbcarac); // lire du TP4 (modifiée)
return chaine;
}

void afficherChaine(const char *nomChamp, const char *valeur)
{
printf("%s %s",nomChamp,valeur);

}

void lireDateSysteme(T_Emp *E)
{
char j[4],m[4],h[9],mer[11],vir[2];
int d,a;


system("date > ladate"	);
FILE * fic=NULL;  // pointeur de fichier
fic=fopen("ladate","r"); //fileOpen en mode 'r'EAD

//ici , si fic vaut NULL, alors le fopen a indiqué
//que le fichier ladate n'est pas accessible
if (fic!=NULL)
	{
	while(!feof(fic))	
		{
		fscanf(fic,"%s %d %s %d",j,&d,m,&a);		
		if (!feof(fic)) 
			printf("\n-->LU : %s- %d- %s- %d- %s- %s",j,d,m,a,h,mer);		

		}
	fclose(fic);
	
if (strcmp(j,"Mon")==0) E->lejour=lu;
if (strcmp(j,"Tue")==0) E->lejour=ma;
if (strcmp(j,"Wed")==0) E->lejour=me;
if (strcmp(j,"Thu")==0) E->lejour=je;
if (strcmp(j,"Fri")==0) E->lejour=ve;
if (strcmp(j,"Sat")==0) E->lejour=sa;
if (strcmp(j,"Sun")==0) E->lejour=di;

E->ladate=d;

if (strcmp(m,"Jan")==0) E->lemois=janv;
if (strcmp(m,"fevrier")==0) E->lemois=fevr;
if (strcmp(m,"mars")==0) E->lemois=mars;
if (strcmp(m,"avril")==0) E->lemois=avri;
if (strcmp(m,"mai")==0) E->lemois=mai;
if (strcmp(m,"juin")==0) E->lemois=juin;
if (strcmp(m,"juillet")==0) E->lemois=juil;
if (strcmp(m,"aout")==0) E->lemois=aout;
if (strcmp(m,"septembre")==0) E->lemois=sept;
if (strcmp(m,"octobre")==0) E->lemois=octo;
if (strcmp(m,"novembre")==0) E->lemois=nove;
if (strcmp(m,"decembre")==0) E->lemois=dece;

	}
}

