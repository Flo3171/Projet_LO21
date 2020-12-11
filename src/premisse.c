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


void deletePremisse(Premisse prem)
{
    if (prem != NULL){
        deletePremisse(prem->elemSuivant);
        free(prem); 
    }
}


Premisse addHeadPremisse(Premisse prem, Proposition *prop)
{
    PremisseElem* new = (PremisseElem*)malloc(sizeof(PremisseElem));
    if (new == NULL)
        {
            printf("ERREUR alocation dynamique");
            exit(0);
        }

    new->elemSuivant = prem;
    new->valeur = prop;

    return new;
}

Premisse addTailPremisse(Premisse prem, Proposition *prop)
{
    if (prem == NULL)
    {
        PremisseElem* newElem = (PremisseElem*)malloc(sizeof(PremisseElem));
        if (newElem == NULL)
        {
            printf("ERREUR alocation dynamique");
            exit(0);
        }

        newElem->valeur = prop;
        newElem->elemSuivant = NULL; //on ajoute en queue donc il n'y à pas d'élément suivant

        return newElem;
    }

    else if (prem->elemSuivant == NULL)
    {
        PremisseElem* newElem = (PremisseElem*)malloc(sizeof(PremisseElem));
        if (newElem == NULL)
        {
            printf("ERREUR alocation dynamique");
            exit(0);
        }

        newElem->valeur = prop;
        newElem->elemSuivant = NULL; //on ajoute en queue donc il n'y à pas d'élément suivant

        prem->elemSuivant = newElem;
        return prem;
    }

    else
    {
        addTailPremisse(prem->elemSuivant, prop);
        return prem;
    }
    
    
    
   

}

void affichePremisse(Premisse prem)
{
    if (prem == NULL)
    {
        printf("element vide");
    }
    else if (prem->elemSuivant == NULL)
    {
        printf("\"");
        affichePropositon(prem->valeur);
        printf("\" ");
    }
    else
    {
        printf("\"");
        affichePropositon(prem->valeur);
        printf("\" & ");
        affichePremisse(prem->elemSuivant); 
    }
    
        
}

bool propositionDansPremisse(Premisse prem, Proposition* prop)
{
    if (prem == NULL)
    {
        return false;
    }
    else if(prem->valeur == prop)
    {
        return 1;
    }
    else
    {
        return propositionDansPremisse(prem->elemSuivant, prop);
    }
}

Premisse rechercheSupprimePremisse(Premisse prem, Proposition *prop)
{
    if (prem == NULL)
    {
        /* Cas d'une prémisse vide */
        return NULL;
    }
    else if(prem->elemSuivant  == NULL)
    {
        /* Cas d'une prémisse avec un seul élément */
        if (!strcmp(prop->description, prem->valeur->description))
        {
            free(prem);
            return NULL;
        }
    }
    else if (!strcmp(prop->description, prem->elemSuivant->valeur->description))
    {
        Premisse toDelete = prem->elemSuivant;

        prem->elemSuivant = toDelete->elemSuivant;

        free(toDelete);

        return prem;  
    }
    else
    {
        rechercheSupprimePremisse(prem->elemSuivant, prop);
        return prem;
    }
    
}

bool premisseIsEmpty(Premisse prem)
{
    return prem == NULL;
}

Premisse addPropositionUnique(Premisse listProp, char desciption[], bool validite)
{
    if (listProp == NULL)
    {
        PremisseElem* newElem = (PremisseElem*)malloc(sizeof(PremisseElem));
        if (newElem == NULL)
        {
            printf("ERREUR alocation dynamique");
            exit(0);
        }

        newElem->valeur = newProposition(desciption, validite);
        newElem->elemSuivant = NULL;

        return newElem;
    }
    else if (listProp->elemSuivant == NULL && strcmp(listProp->valeur->description, desciption))
    {
        PremisseElem* newElem = (PremisseElem*)malloc(sizeof(PremisseElem));
        if (newElem == NULL)
        {
            printf("ERREUR alocation dynamique");
            exit(0);
        }

        newElem->valeur = newProposition(desciption, validite);
        newElem->elemSuivant = NULL;

        listProp->elemSuivant = newElem;

        return listProp;
    }
    else if (strcmp(listProp->valeur->description, desciption))
    {
        addPropositionUnique(listProp->elemSuivant, desciption, validite);
        
        return listProp;
    }
    else
    {
        return listProp;
    }
}

Proposition* rechercheListProposition(Premisse listProp, char desciption[])
{
    if (listProp == NULL)
    {
        return NULL;
    }
    else if (!strcmp(listProp->valeur->description, desciption))
    {
        return listProp->valeur;
    }
    else
    {
        return rechercheListProposition(listProp->elemSuivant, desciption);
    }
}

void deletePremisseProposition(Premisse prem)
{
    if (prem != NULL){
        deletePremisse(prem->elemSuivant);
        deleteProposition(prem->valeur);
        free(prem); 
    }
}

bool isPremisseTrue(Premisse prem)
{
    if (prem == NULL)
    {
        return true;
    }
    else
    {
        return prem->valeur->validite && isPremisseTrue(prem->elemSuivant);
    }    
}