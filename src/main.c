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
    printf("************START***************\n\n");
   
    /*menuPrincipal();*/
    
    Premisse listProp = NULL;
    BDConnaissances bdc = NULL;
    
    bdc = ReadBDC(bdc, &listProp, "../../file/bdc.csv");

    printf("La bdc contient :\n");
    afficheBDC(bdc);
    

    WriteBDC(bdc, &listProp, "../../file/bdc.csv");
    
    deleteAllBDC(bdc);
    deletePremisseProposition(listProp);
    
    
    
    printf("\n\n************FINISH***************\n");
    return EXIT_SUCCESS;
}