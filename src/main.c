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

    /* liste de Porpriété */

    Premisse listeProposition = NULL;
    /*listeProposition = addPropositionUnique(listeProposition, "La voiture est verte", false);
    listeProposition = addPropositionUnique(listeProposition, "La voiture est bleu", false);
    listeProposition = addPropositionUnique(listeProposition, "La voiture est rouge", false);
    listeProposition = addPropositionUnique(listeProposition, "La voiture est verte", false);
    listeProposition = addPropositionUnique(listeProposition, "T'es sur l'autoroute bg", false);

    printf("\nLa liste de Proposition contient les proposition suivantes : \n");
    affichePremisse(listeProposition);

    affichePropositon(rechercheListProposition(listeProposition, "T'es sur l'autoroute bg"));*/
    

    /* Regle */

    /* Méthode pour construire une règle*/

    // Regle *regle = NULL;
    // char *prem[2] = {"Il y a des nuages", "On est a Belfort"};

    // regle = createRegle(&listeProposition, prem, 2, "Il pleut");

    // printf("\nRegle : ");
    // afficheRegle(regle);

    // deleteRegle(regle);

    /* Bases de connaissaces */

    BDConnaissances bdc = NULL; /* TOUJOURS METTRE A NULL !!!!!!!!!!!!! */
    // char *prem[2] = {"Il y a des nuages", "On est a Belfort"};
    
   /* Méthode à appliquer pour ajouter une règle à la bdc */ 
    long nbProp = 2;
    char **prem = (char**)malloc(sizeof(char*)*nbProp);
    for (long i = 0; i < nbProp; i++)
    {
        prem[i] = (char*)malloc(sizeof(char)*(TAILLE_MAXI_PROPOSITION + 1));
        // strcpy(prem[i], **lecture dans le fichier**);
    }
    
    strcpy(prem[0], "Il y a des nuages");
    strcpy(prem[1], "On est a Belfort");


    bdc = addRegleBDC(bdc, &listeProposition , prem, 2, "Il pleut");

    for (long i = 0; i < nbProp; i++)
    {
        free(prem[i]);
    }
    free(prem);

    char *prem1[2] = {"Il pleut", "J'ai un parapluis"};
    bdc = addRegleBDC(bdc, &listeProposition , prem1, 2, "Je peux sortir");
    

    
    printf("\nLa base de connaissances contient les regles suivantes : \n");
    afficheBDC(bdc);

    /* Base de Véritée */

    setValidite(rechercheListProposition(listeProposition, "Il y a des nuages"), true);
    setValidite(rechercheListProposition(listeProposition, "On est a Belfort"), true);
    Premisse baseVerite = createBDVerite(listeProposition, NULL);
    
    printf("\n\nLa base de verite contient les propositions suivantes : \n\n");
    affichePremisse(baseVerite);

    /* Moteur d'inférence */

    Premisse conclusionM = moteurDInference(baseVerite, bdc);
    printf("\n\nLe moteur d'inference a prouve les propositions suivantes : \n");
    affichePremisse(conclusionM);


    /* On libère bien la mémoire */
    deletePremisseProposition(listeProposition);
    deleteAllBDC(bdc);
    deletePremisse(baseVerite);
    deletePremisse(conclusionM);



    /*************Version fonctionel************/


    //Premisse listeProposition = NULL;

    /* Génération de la base de connaissance à partir d'un ficher */
    /* Carlo c'est à toi de jouer */

    /* Génération de la base de véritée en pausant des question a l'utilisateur */

    /* Execution du moteur d'inférence */

    /* Affichage des résultat */

    /* Libération de toutes les addresse en mémoire */








    

    printf("\n\n************FINISH***************\n");
    return EXIT_SUCCESS;
}