#ifndef PREMISSE_H_
#define PREMISSE_H_

/**
 * @file premisse.h
 * @author Florian Cloarec
 * @brief fichier contenant les prototype des fonctions liées à la structure de données Premisse et la définition de la structure Premisse
 * @version 0.1
 * @date 16 November 2020
 * 
 * @copyright GNU GENERAL PUBLIC LICENSE
 * 
 */

#include "proposition.h"


/**
 * @brief structure de donnée permetant de stocker un élément de la liste chainé de Proposion qui représente la Prémisse
 * @struct PremisseElem
 * @author Florian CLOAREC
 */
typedef struct PremisseElem
{
    Proposition         *valeur;        /*! valeur de l'élément de la liste chainé */
    struct PremisseElem *elemSuivant;   /*! Pointeur sur l'élément suivant dans la liste chainée */
}PremisseElem;

/**
 * @brief strucutre de donné permetant de représenter une prémisse par une liste chainé de propositon
 * @struct Premisse
 * 
 * @author Florian CLOAREC
 */
typedef struct Premisse
{
    PremisseElem*   premierElem; /*! pointeur sur le premier élément de la liste chainée */
    PremisseElem*   dernierElem; /*! pointeur sur le dernier élément de la liste chainée */
    long            nbElem;      /*! nombre d'élément contenue dans la liste chainé, ici le nombre de propostion que contient la prémisse */
}Premisse;


/**
 * @brief crée une nouvelle prémisse vide
 * 
 * @return Premisse* 
 * @author Florian CLOAREC
 */
Premisse* newPremisse();


/**
 * @brief supprime de la mémoire une prémisse
 * 
 * @param premisseToDelete 
 * @author Florian CLOAREC
 */
void deletePremisse(Premisse* premisseToDelete);


/**
 * @brief supprime l'élément en tête de la prémisse
 * 
 * @param premisseToDelete 
 * @author Florian CLOAREC
 */
void deleteHeadPremisse(Premisse* premisseToDelete);


#endif