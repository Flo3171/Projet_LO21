#ifndef REGLE_H_
#define REGLE_H_

/**
 * @file regle.h
 * @author Florian Cloarec
 * @brief fichier contenant les protoype lier à la structure de donnée Regle ainsi que les déclaration des structure de donnée Regle et ces composée
 * @version 0.1
 * @date 14 November 2020
 * 
 * @copyright GNU GENERAL PUBLIC LICENSE
 * 
*/

#include "proposition.h"
#include "premisse.h"
/*! Définition des structure liée à une Règle*/


/**
 *  @struct Regle
 *  @brief structure de donnée qui représente une règle
 * 
 */
typedef struct Regle
{
    Premisse*        premisse;   /*! pointeur sur la liste chainé contenant les Proposition qui forment la prémisse de la règle*/
    Proposition    conclusion; /*! Proposition qui est conclue grâce à la règle*/
}Regle;



/*! Définition des prototypes des fonctions lié à une Règle */

/**
 * @brief crée une règle vide
 * 
 * @return Regle* 
 * @author Florian CLOAREC
 */
Regle* newRegle();

/**
 * @brief suprime une règle ainsi que tout ces composant
 * 
 * @param regleToDelete : regle que l'on veut suprimer
 * @author Florian CLOAREC
 */
void deleteRegle(Regle *regleToDelete);

/**
 * @brief ajoute la conclusion d'une règle
 * 
 * @param conclusionToAdd : conclusion à ajouter dans la règle 
 * @param regle : pointeur vers la règle ou doit être ajoutée la conclusion 
 * @author Carlo AZANCOTH
 */
void addConclusion(Proposition conclusionToAdd,Regle *regle);

/**
 * @brief affiche une règle
 * 
 * @param regle : pointeur vers la régle à afficher 
 * @author Carlo AZANCOTH
 */
void afficheRegle(Regle *regle);

/**
 * @brief vérifie si la premisse d'une règle est vide ou ne l'est pas 
 * 
 * @param regleAVerif : regle ou se trouve la premisse à vérifier
 * @return 1 : si la premisse est vide
 * @return 0 : si la premisse n'est pas vide
 * @author Carlo AZANCOTH
 */
bool ReglePremisseIsEmpty(Regle* regleAVerif);


/**
 * @brief supprime la proposition de la prémisse d'une règle 
 * 
 * @param regle : règle dans laquele on veut supprimer
 * @param prop : propostion à rechercher et supprimer
 * @return true : si la proposition à été trouvée et supprimer
 * @return false : si la proposition n'as pas été trouvé
 * @author Florian CLOAREC
 */
bool supprimePropositionPremisseRegle(Regle *regle, Proposition prop);


/**
 * @brief revoie la conclution d'une règle
 * 
 * @param regle : règle dont on veut obtenir la conclusion
 * @return Proposition 
 * @author Florian CLOAREC
 */

Proposition	conlusionRegle(Regle *regle);


#endif