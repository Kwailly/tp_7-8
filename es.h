#ifndef ES_H   //compilation conditionnelle
#define ES_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "livre.h"


char *lire(char *lachaine,int nbMAXcaracAsaisir);
char *lireChaine(const char *, char * , int );
void afficherChaine(const char *,const char *);
void lireDateSysteme(T_Emp *E);
#endif
