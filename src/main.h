#ifndef MAIN_H_
#define MAIN_H_

/**
 * @file main.h
 * @author Florian Cloarec
 * @brief fichier contenant les inclusion de tout les fichier header du projet, à inclure au début de chaque ficher 
 * @version 0.1
 * @date 16 November 2020
 * 
 * @copyright GNU GENERAL PUBLIC LICENSE
 * 
 */

//Déclaration des constante

#define TAILLE_MAXI_PROPOSITION 100

//Inclusion des structures

#include "struct.h"

//Inclusion des bibliothèques standard

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>


//inclutions des bibliothèques crées pour le projet

#include "proposition.h"
#include "premisse.h"
#include "regle.h"
#include "BDConnaissances.h"
#include "interface.h"
#include "struct.h"


#endif