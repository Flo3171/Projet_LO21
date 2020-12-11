/**
 * @file proposition.c
 * @author Florian Cloarec
 * @brief fichier contenant les implémentation des fonctions associée à la structure de donnée  Propositon
 * @version 0.1
 * @date 16 November 2020
 * 
 * @copyright GNU GENERAL PUBLIC LICENSE
 * 
 */

#include "main.h"

Proposition* newProposition(char valueProposition[], bool validite)
{
    Proposition* nouvelleProposition = (Proposition*)malloc(sizeof(Proposition));
    if (nouvelleProposition == NULL)
    {
        printf("ERREUR alocation dynamique");
        exit(0);
    }

    char *value = (char*)malloc(sizeof(char)*strlen(valueProposition));
    if (value == NULL)
    {
        printf("ERREUR alocation dynamique");
        exit(0);
    }

    strcpy(value, valueProposition);
    nouvelleProposition->description = value;

    nouvelleProposition->validite = validite;

    return nouvelleProposition;
}

void deleteProposition(Proposition *propositionToDelete)
{
    free(propositionToDelete->description);
    free(propositionToDelete);
}

void affichePropositon(Proposition *proposition)
{
    printf("%s", proposition->description);
}

void setValidite(Proposition *prop, bool val)
{
    if (prop != NULL)
    {
        prop->validite = val;
    }
    
    
}