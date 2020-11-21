/**
 * @file main.c
 * @author Florian CLOAREC
 * @brief fichier contenant la fonction main
 * @version 0.1
 * @date 2020-11-14
 *  
*/

#include "main.h"

/**
 * @brief fonction main qui appelle toutes les autres fonction du programme
 * 
 * @param argc : nombre d'arguement
 * @param argv : tableu contenant les arguement
 * @return int : vaut EXIT_SUCCESS (0) si tout c'est bien passé et EXIT_FAILLURE (1) si il y à eut un problème lors de l'éxécution
 */
int main(int argc, char *argv[])
{
    printf("************START***************\n");
    /* démo */

    /* Proposion */
    /*Proposition prop = newProposition("La voiture est bleue");
    affichePropositon(prop);
    deleteProposition(prop);*/

    /* Premisse 
    Premisse* prem = newPremisse();
    affichePremisse(prem->premierElem);
    Proposition prop = newProposition("La voiture est jaune");
    addTailPremisse(prem, prop);
    affichePremisse(prem->premierElem);
    prop = newProposition("La voiture est rouge");
    addTailPremisse(prem, prop);
    affichePremisse(prem->premierElem);
    deletePremisse(prem);
    */

    /* Regle */
    Regle *regle = newRegle();
    printf("\nPremisse : ");
    affichePremisse(regle->premisse->premierElem);

    Proposition propV = newProposition("La voiture est verte"), propR = newProposition("La voiture est rouge"),propB = newProposition("La voiture est bleu"), propV1 = newProposition("La voiture est verte"), propR1 = newProposition("La voiture est rouge"), propB1 = newProposition("La voiture est bleu");

    addTailPremisse(regle->premisse, propV);
    printf("\nPremisse : ");
    affichePremisse(regle->premisse->premierElem);

    addTailPremisse(regle->premisse, propR);
    addTailPremisse(regle->premisse, propB);

    Proposition conclusion = newProposition("t'es sur l'autoroute bg");
    addConclusion(conclusion, regle);
    printf("\nRegle : ");
    afficheRegle(regle);

    supprimePropositionPremisseRegle(regle, propV1);
    printf("\nRegle : ");
    afficheRegle(regle);

    supprimePropositionPremisseRegle(regle, propR1);
    printf("\nRegle : ");
    afficheRegle(regle);

    supprimePropositionPremisseRegle(regle, propB1);
    printf("\nRegle : ");
    afficheRegle(regle);




    deleteRegle(regle);

    printf("\n************FINISH***************\n");
    return EXIT_SUCCESS;
}