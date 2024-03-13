#include "es.h"


char *lire(char* lachaine,int nbMAXcaracAsaisir)
{
char car;
int i=0,nbesp=0;
do
{
 	car=getchar();
	//printf("\n>>%c",car);
	if (car!='\n')
		{	
	 	if (car!=' ' ) //ou if (car!=32)
	 		{lachaine[i++]=car;nbesp=0;}
	 	else
	 	{ // c'est un espace
	 	 if (i!=0 && nbesp==0)
	 	 	{	
	 	 	lachaine[i++]=car;nbesp++;	
	 	 	}
	 	}
		}
 }
while(car!='\n' && i<nbMAXcaracAsaisir);
// le caractere \n est rangé dans lachaine !!
lachaine[i]='\0';

if (i==nbMAXcaracAsaisir) 
	if (lachaine[i-2]==' ')
		lachaine[i-2]='\0';
	else
		lachaine[i-1]='\0';
else //i<MAX
if (lachaine[i-1]==' ')
	lachaine[i-1]='\0';

return lachaine;
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
	
if (strcmp(j,"Mon")==0) E->lejour=lundi;
if (strcmp(j,"Tue")==0) E->lejour=mardi;
if (strcmp(j,"Wed")==0) E->lejour=mercredi;
if (strcmp(j,"Thu")==0) E->lejour=jeudi;
if (strcmp(j,"Fri")==0) E->lejour=vendredi;
if (strcmp(j,"Sat")==0) E->lejour=samedi;
if (strcmp(j,"Sun")==0) E->lejour=dimanche;

E->ladate=d;

if (strcmp(m,"Jan")==0) E->lemois=janvier;
if (strcmp(m,"fevrier")==0) E->lemois=fevrier;
if (strcmp(m,"mars")==0) E->lemois=mars;
if (strcmp(m,"avril")==0) E->lemois=avril;
if (strcmp(m,"mai")==0) E->lemois=mai;
if (strcmp(m,"juin")==0) E->lemois=juin;
if (strcmp(m,"juillet")==0) E->lemois=juillet;
if (strcmp(m,"aout")==0) E->lemois=aout;
if (strcmp(m,"septembre")==0) E->lemois=septembre;
if (strcmp(m,"octobre")==0) E->lemois=octobre;
if (strcmp(m,"novembre")==0) E->lemois=novembre;
if (strcmp(m,"decembre")==0) E->lemois=decembre;


E->lannee=a;
	}
	else
	{
		printf("n souci avec la date systeme !!");
		//on range une date irréelle 
		E->lejour=dimanche;
		E->ladate=99;
		E->lemois=decembre;
		E->lannee=-999;


	}

}