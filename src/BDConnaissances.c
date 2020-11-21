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
    newElem->valeur = aAjouter;
    newElem->suivant = bdc;

    return newElem;

}

BDConnaissances deleteHeadBDC(BDConnaissances bdc)
{
    if (isEmptyBDC(bdc))
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
        afficheRegle(bdc->valeur);
        afficheBDC(bdc->suivant);
    }
}
