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

void addConclusion(Proposition conclusionToAdd,Regle *regle){
    regle->conclusion = conclusionToAdd;
}

void afficheRegle(Regle *regle)
{
    Premisse *prem = regle->premisse;
    Proposition conclu = regle->conclusion; 
    affichePremisse(prem->premierElem);
    
    if (conclu==NULL || conclu[0]=='\0'){
        printf("pas de conclusion");
    }else{
        printf("donc : \"");
        affichePropositon(conclu);
        printf("\"");
    }
}

bool ReglePremisseIsEmpty(Regle* regleAVerif){
    return premisseIsEmpty(regleAVerif->premisse);
}

bool supprimePropositionPremisseRegle(Regle *regle, Proposition prop)
{
    PremisseElem *actuel = regle->premisse->premierElem;
    bool trouve = false;

    if(strcmp(prop, actuel->valeur) == 0)
    {
        regle->premisse->premierElem = actuel->elemSuivant;
        if (regle->premisse->nbElem == 1)
        {
            regle->premisse->dernierElem == NULL;
        }

        deleteProposition(actuel->valeur);
        free(actuel);

        regle->premisse->nbElem --;
        trouve = true;    
    }
    while (actuel->elemSuivant != NULL && trouve == false)
    {
        if(strcmp(prop, actuel->elemSuivant->valeur) == 0)
        {
            if (actuel->elemSuivant->elemSuivant == NULL)
            {
                regle->premisse->dernierElem = actuel;
            }
            actuel->elemSuivant = actuel->elemSuivant->elemSuivant;
            deleteProposition(actuel->elemSuivant->valeur);
            free(actuel->elemSuivant);

            regle->premisse->nbElem --;
            trouve = true;  
        }
        actuel = actuel->elemSuivant;
    }

    return trouve;
    

}