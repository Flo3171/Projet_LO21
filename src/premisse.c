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

#include "main.h"

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
    free(premisseToDelete);
    
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
        deleteProposition(aSuppr->valeur);
        free(aSuppr);
        premisseToDelete->nbElem --;
    }
}

void addTailPremisse(Premisse *premisse, Proposition proposition)
{
    PremisseElem* newElem = (PremisseElem*)malloc(sizeof(PremisseElem));
    newElem->valeur = proposition;
    newElem->elemSuivant = NULL; //on ajoute en queue donc il n'y à pas d'élément suivant

    if (premisse->nbElem == 0)
    {
        premisse->premierElem = newElem;
    }
    else
    {
        premisse->dernierElem->elemSuivant = newElem;
    }
    premisse->dernierElem = newElem;
    premisse->nbElem ++;
}

void affichePremisse(PremisseElem *elem)
{
    if (elem == NULL)
    {
        printf("premisse vide\n");
    }
    else if (elem->elemSuivant == NULL)
    {
        printf("\"");
        affichePropositon(elem->valeur);
        printf("\"\n");
    }
    else
    {
        printf("\"");
        affichePropositon(elem->valeur);
        printf("\" & ");
        affichePremisse(elem->elemSuivant); 
    }
    
        
}

bool propositionDansPremisse(PremisseElem* elem, Proposition proposition)
{
    if (elem = NULL)
    {
        return false;
    }
    else if(strcmp(proposition, elem->valeur))
    {
        return 1;
    }
    else
    {
        return propositionDansPremisse(elem->elemSuivant, proposition);
    }
}