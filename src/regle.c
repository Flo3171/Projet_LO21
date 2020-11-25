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

#include "main.h"

Regle* newRegle()
{
    Regle* nouvelRegle = (Regle*)malloc(sizeof(Regle));
    nouvelRegle->premisse = NULL;
    nouvelRegle->conclusion = NULL;
    return nouvelRegle;
}

void deleteRegle(Regle *regleToDelete)
{
    deletePremisse(regleToDelete->premisse);
    deleteProposition(regleToDelete->conclusion);
    free(regleToDelete);
}

void addConclusion(Proposition *conclusionToAdd,Regle *regle){
    regle->conclusion = conclusionToAdd;
}

void afficheRegle(Regle *regle)
{
    affichePremisse(regle->premisse);
    
    if (regle->conclusion==NULL || regle->conclusion->description == NULL){
        printf("pas de conclusion");
    }else{
        printf("donc : \"");
        affichePropositon(regle->conclusion);
        printf("\"");
    }
}

bool ReglePremisseIsEmpty(Regle* regleAVerif){
    return premisseIsEmpty(regleAVerif->premisse);
}

Regle* supprimePropositionPremisseRegle(Regle *regle, Proposition *prop)
{
    regle->premisse = rechercheSupprimePremisse(regle->premisse, prop);

    return regle;
}

Proposition* conlusionRegle(Regle *regle)
{
    return regle->conclusion;
}

void instertHeadPremisseRegle(Regle* regle, Proposition *prop)
{
    regle->premisse = addHeadPremisse(regle->premisse, prop);
}