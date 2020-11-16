/**
 * @file regle.c
 * @author Florian Cloarec
 * @brief fichier contenant les implémentation des fonctions relative à la structure de donnée Regle
 * @version 0.1
 * @date 14 November 2020
 * 
 * @copyright GNU GENERAL PUBLIC LICENSE
 * 
 */

#include "regle.h"
#include "proposition.h"
#include "premisse.h"
#include "stdio.h"
#include "stdlib.h"

Regle* newRegle()
{
    Regle* nouvelRegle = (Regle*)malloc(sizeof(Regle));
    nouvelRegle->premisse = newPremisse();
    nouvelRegle->conclusion = NULL;
    return nouvelRegle;
}

void deleteRegle(Regle *regleToDelete)
{
    deletePremisse(regleToDelete->premisse);
    deleteProposition(regleToDelete->conclusion);
    free(regleToDelete);
}