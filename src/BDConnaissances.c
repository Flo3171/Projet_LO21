/**
 * @file BDConnaissances.c
 * @author Florian Cloarec
 * @brief fichier contenant les implémentations des fonctions lié à la structure de donnée Base de Connaissances
 * @version 0.1
 * @date 21 November 2020
 * 
 * @copyright GNU GENERAL PUBLIC LICENSE
 * 
 */

#include "main.h"

bool isEmptyBDC(BDConnaissances bdc)
{
    return (bdc == NULL);
}

BDConnaissances addHeadBDC(BDConnaissances bdc, Regle *aAjouter)
{
    BDConnaissancesElem* newElem = (BDConnaissancesElem*)malloc(sizeof(BDConnaissancesElem));
    if (newElem == NULL)
    {
        printf("ERREUR alocation dynamique");
        exit(EXIT_FAILURE);
    }
    

    newElem->valeur = aAjouter;
    newElem->suivant = bdc;

    return newElem;

}

BDConnaissances deleteHeadBDC(BDConnaissances bdc)
{
    if (!isEmptyBDC(bdc))
    {
        BDConnaissancesElem *toDeleteNext = bdc->suivant;
        deleteRegle(bdc->valeur);
        free(bdc);

        return toDeleteNext;
    }
    else
    {
        return NULL;
    }
}

void deleteAllBDC(BDConnaissances bdc)
{
    if (!isEmptyBDC(bdc)){
        bdc = deleteHeadBDC(bdc);
        deleteAllBDC(bdc);
    }
}

void afficheBDC(BDConnaissances bdc)
{
    if (!isEmptyBDC(bdc)){
        printf("\n-->");
        afficheRegle(bdc->valeur);
        afficheBDC(bdc->suivant);
    }
}

BDConnaissances addRegleBDC(BDConnaissances bdc, Premisse* pListProp, char* descriptionPremisse[], long nbElemPremisse,  char* descriptionConclusion)
{
    return addHeadBDC(bdc, createRegle(pListProp, descriptionPremisse, nbElemPremisse, descriptionConclusion));
}

Premisse moteurDInference(Premisse baseVerite, BDConnaissances bdc)
{
    Premisse conclusion = NULL;
    bool poursuit = true;
    while (poursuit)
    {
        BDConnaissancesElem *regle = bdc;
        poursuit = false;
        while (regle != NULL)
        {
            if (isPremisseTrue(regle->valeur->premisse))    
            {
                setValidite(regle->valeur->conclusion, true);
                

                if (!propositionDansPremisse(conclusion, regle->valeur->conclusion))
                    {
                        poursuit = true;
                        conclusion = addTailPremisse(conclusion, regle->valeur->conclusion);
                    }
            }
            
            regle = regle->suivant;
        }
    }
    return conclusion;
}

Premisse createBDVerite(Premisse listProp, Premisse BDVerite)
{
    if (listProp != NULL)
    {
        if (listProp->valeur->validite == true)
        {
            BDVerite = addTailPremisse(BDVerite, listProp->valeur);
        }
        createBDVerite(listProp->elemSuivant, BDVerite);
    }
    return BDVerite;
    
}

bool isPropositionInConclusion(BDConnaissances bdc, Proposition* prop)
{
    if (bdc == NULL)
    {
        return false;
    }
    else if (prop == bdc->valeur->conclusion)
    {
        return true;
    }
    else
    {
        return isPropositionInConclusion(bdc->suivant, prop);
    }
    
    
}