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

    



