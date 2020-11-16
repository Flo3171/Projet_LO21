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

#include "proposition.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

Proposition newProposition(char valueProposition[])
{
    Proposition nouvelleProposition = (Proposition)malloc(sizeof(char) * strlen(valueProposition));
    strcpy(nouvelleProposition, valueProposition);
    return nouvelleProposition;
}

void deleteProposition(Proposition propositionToDelete)
{
    free(propositionToDelete);
}

void affichePropositon(Proposition proposition)
{
    printf("%s", proposition);
}