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
    if (nouvelRegle == NULL)
    {
        printf("ERREUR alocation dynamique");
        exit(EXIT_FAILURE);
    }

    nouvelRegle->premisse = NULL;
    nouvelRegle->conclusion = NULL;
    return nouvelRegle;
}

void deleteRegle(Regle *regleToDelete)
{
    deletePremisse(regleToDelete->premisse);
    free(regleToDelete);
}

Premisse addConclusion(Regle *regle, Premisse listProp, char* description)
{
    regle->conclusion = rechercheListProposition(listProp, description);
    if (regle->conclusion == NULL)
    {
        listProp = addPropositionUnique(listProp, description, false);
        regle->conclusion = rechercheListProposition(listProp, description);
    }
    return listProp;
}

void afficheRegle(Regle *regle)
{
    affichePremisse(regle->premisse);
    
    if (regle->conclusion==NULL || regle->conclusion->description == NULL)
    {
        printf("pas de conclusion");
    }
    else
    {
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

Premisse instertHeadPremisseRegle(Regle* regle, Premisse listProp, char* description)
{
    Proposition* propAAjouter = rechercheListProposition(listProp, description);
    if (propAAjouter == NULL)
    {
        listProp = addPropositionUnique(listProp, description, false);
        propAAjouter = rechercheListProposition(listProp, description);
    }
    regle->premisse = addHeadPremisse(regle->premisse, propAAjouter);

    return listProp;
    
}

Regle* createRegle(Premisse* pListProp, char* descriptionPremisse[], long nbElemPremisse,  char* descriptionConclusion)
{
    Regle* regle = newRegle();

    for (long countPrem = 0; countPrem < nbElemPremisse; countPrem++)
    {
        *pListProp = instertHeadPremisseRegle(regle, *pListProp, descriptionPremisse[countPrem]);
    }
    
    *pListProp = addConclusion(regle, *pListProp, descriptionConclusion);

    return regle;

}