/**
 * @file premisse.c
 * @author Florian Cloarec
 * @brief fichier contenant les implémentation des fonction associé à la structure de donnée Premisse
 * @version 0.1
 * @date 16 November 2020
 * 
 * @copyright GNU GENERAL PUBLIC LICENSE
 * 
 */

#include "stdio.h"
#include "stdlib.h"
#include "premisse.h"
#include "proposition.h"

Premisse* newPremisse()
{
    Premisse* nouvellePremisse = (Premisse*)malloc(sizeof(Premisse));
    nouvellePremisse->premierElem = NULL;
    nouvellePremisse->dernierElem = NULL;
    nouvellePremisse->nbElem = 0;

    return nouvellePremisse;
}

void deletePremisse(Premisse* premisseToDelete)
{
    while (premisseToDelete->nbElem != 0)
    {
        deleteHeadPremisse(premisseToDelete);
    }
    
}

void deleteHeadPremisse(Premisse* premisseToDelete)
{
    if (premisseToDelete != NULL && premisseToDelete->nbElem != 0)
    {
        PremisseElem* aSuppr = premisseToDelete->premierElem;
        premisseToDelete->premierElem = premisseToDelete->premierElem->elemSuivant;
        if (premisseToDelete->nbElem == 1)
        {
            premisseToDelete->dernierElem == NULL;
        }
        free(aSuppr);
    }
}