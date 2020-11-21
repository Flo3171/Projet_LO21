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
    supprimeElemPremisse(premisseToDelete->premierElem);
    free(premisseToDelete);
    
}

void supprimeElemPremisse(PremisseElem *elem)
{
    if (elem != NULL){
        supprimeElemPremisse(elem->elemSuivant);
        deleteProposition(elem->valeur);
        free(elem); 
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
        printf("premisse vide ");
    }
    else if (elem->elemSuivant == NULL)
    {
        printf("\"");
        affichePropositon(elem->valeur);
        printf("\" ");
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
    if (elem == NULL)
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

bool rechercheSupprimePremisse(PremisseElem* elem, Proposition proposition, Premisse* prem)
{
    if (elem == NULL)
    {
        /* Cas d'une prémisse vide */
        return false;
    }
    else if(prem->nbElem == 1)
    {
        /* Cas d'une prémisse avec un seul élément */
        if (strcmp(proposition, prem->premierElem->valeur))
        {
            deleteProposition(prem->premierElem->valeur);
            free(prem->premierElem);

            prem->premierElem = NULL;
            prem->dernierElem = NULL;
            prem->nbElem = 0;
        }
    }
    else if (elem->elemSuivant->elemSuivant == NULL)
    {
        /*Cas ou on évalue le dernier élément de la liste*/
        if (strcmp(proposition, elem->elemSuivant->valeur))
        {
            prem->dernierElem = elem;
            elem->elemSuivant = NULL;
            prem->nbElem --;

            deleteProposition(elem->elemSuivant->valeur);
            free(elem->elemSuivant);

            return true;


        }
        else
        {
            return false;
        }    
    }
    
    else if(strcmp(proposition, elem->elemSuivant->valeur))
    {
        elem->elemSuivant = elem->elemSuivant->elemSuivant;
        if (elem == prem->premierElem)
        {
            prem->premierElem = elem->elemSuivant;
        }
        deleteProposition(elem->elemSuivant->valeur);
        free(elem);
        prem->nbElem --;

        return true;
    }
    else
    {
        return rechercheSupprimePremisse(elem->elemSuivant, proposition, prem);
    }
    
}

bool premisseIsEmpty(Premisse *PremisseAVerif){
    if (PremisseAVerif->premierElem == NULL){
        return true;
    }else{
        return false;
    }
}