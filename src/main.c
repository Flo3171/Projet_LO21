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
    /*Proposition* prop = newProposition("La voiture est bleue", false);
    affichePropositon(prop);
    deleteProposition(prop);*/

    /* Premisse */
    /*Premisse prem = NULL;
    affichePremisse(prem);
    Proposition* prop = newProposition("La voiture est jaune", false);
    prem = addTailPremisse(prem, prop);
    affichePremisse(prem);
    prop = newProposition("La voiture est rouge", false);
    prem = addTailPremisse(prem, prop);
    affichePremisse(prem);
    deletePremisse(prem);*/
    

    /* Regle */

    /*Regle *regle = newRegle();
    printf("\nPremisse : ");
    affichePremisse(regle->premisse);

    Proposition     *propV = newProposition("La voiture est verte", false), 
                    *propR = newProposition("La voiture est rouge", false),
                    *propB = newProposition("La voiture est bleu", false), 
                    *propV1 = newProposition("La voiture est verte", false), 
                    *propR1 = newProposition("La voiture est rouge", false), 
                    *propB1 = newProposition("La voiture est bleu", false);

    instertHeadPremisseRegle(regle, propV);
    printf("\nPremisse : ");
    affichePremisse(regle->premisse);

    instertHeadPremisseRegle(regle, propR);
    instertHeadPremisseRegle(regle, propB);

    Proposition* conclusion = newProposition("t'es sur l'autoroute bg", false);
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

    deleteRegle(regle);*/

    /* liste de Porpriété */

    Premisse listeProposition = NULL;
    listeProposition = addPropositionUnique(listeProposition, "La voiture est verte", false);
    listeProposition = addPropositionUnique(listeProposition, "La voiture est bleu", false);
    listeProposition = addPropositionUnique(listeProposition, "La voiture est rouge", false);
    listeProposition = addPropositionUnique(listeProposition, "La voiture est verte", false);
    listeProposition = addPropositionUnique(listeProposition, "T'es sur l'autoroute bg", false);

    printf("\nLa liste de Proposition contient les proposition suivantes : \n");
    affichePremisse(listeProposition);

    affichePropositon(rechercheListProposition(listeProposition, "T'es sur l'autoroute bg"));

    deletePremisse(listeProposition);



    /* Bases de connaissaces */

    /*Regle *regle = newRegle();
    Proposition     *propV = newProposition("La voiture est verte", false), 
                    *propR = newProposition("La voiture est rouge", false),
    
    
                    *propB = newProposition("La voiture est bleu", false);

    instertHeadPremisseRegle(regle, propV);
    instertHeadPremisseRegle(regle, propR);
    instertHeadPremisseRegle(regle, propB);

    Proposition *conclusion = newProposition("t'es sur l'autoroute bg", false);
    addConclusion(conclusion, regle);

    BDConnaissances bdc = NULL; *//* TOUJOURS METTRE A NULL *//*
    bdc = addHeadBDC(bdc, regle);
    printf("\nLa base de connaissances contient les regles suivantes : \n");
    afficheBDC(bdc);*/

    /* Base de Véritée *//*

    Premisse baseVerite = NULL;
    
    Proposition     *propV1 = newProposition("La voiture est verte", true),
                    *propR1 = newProposition("La voiture est rouge", true),
                    *propB1 = newProposition("La voiture est bleu", true);
    baseVerite = addTailPremisse(baseVerite, propV1);
    baseVerite = addTailPremisse(baseVerite, propR1);
    baseVerite = addTailPremisse(baseVerite, propB1);

    printf("\nLa base de verite contient les proposition suivantes : \n");
    affichePremisse(baseVerite);*/

    /* Moteur d'inférence */

    /*Premisse conclusionM = moteurDInference(baseVerite, bdc);
    printf("\nLe moteur d'inference a prouve les propiete suivantes : \n");
    affichePremisse(conclusionM);*/


    /* On libère bien la mémoire */
    /*deleteAllBDC(bdc);
    deletePremisse(baseVerite);
    deletePremisse(conclusionM);*/



    /*************Version fonctionel************/


    //Premisse listeProposition = NULL;

    /* Génération de la base de connaissance à partir d'un ficher */
    /* Carlo c'est à toi de jouer */

    /* Génération de la base de véritée en pausant des question a l'utilisateur */

    /* Execution du moteur d'inférence */

    /* Affichage des résultat */








    

    printf("\n************FINISH***************\n");
    return EXIT_SUCCESS;
}