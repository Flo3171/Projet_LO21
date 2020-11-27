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
    Premisse       premisse;   /*!  la liste chainé contenant les Proposition qui forment la prémisse de la règle*/
    Proposition    *conclusion; /*!  pointeur sur Proposition qui est conclue grâce à la règle*/
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
 * @brief défini une popotion comme la conclution d'une règle
 * 
 * @param regle : regle pour laquel on définit la conclution
 * @param listProp : liste de toute les proposition
 * @param description : destription que l'on veut donner à la conclusion
 * @return revoie listProp au cas ou il ait changé
 * @author Florian CLOAREC && Carlo AZANCOTH
 */
Premisse addConclusion(Regle *regle, Premisse listProp, char* description);

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
 * @return pointeur sur la règle avec laquel on à travaillé
 * @author Florian CLOAREC
 */
Regle* supprimePropositionPremisseRegle(Regle *regle, Proposition *prop);


/**
 * @brief revoie la conclution d'une règle
 * 
 * @param regle : règle dont on veut obtenir la conclusion
 * @return Proposition 
 * @author Florian CLOAREC
 */

Proposition* conlusionRegle(Regle *regle);

/**
 * @brief ajoute en tete une propostion à la prémisse d'une règle
 * 
 * @param regle : règle à laquelle on veux ajouter une proposition
 * @param listProp : liste de toute les propositions
 * @param description : description de la proposition à ajouter
 * @return revoie listProp au cas ou il ait changé
 * @author Florian CLOAREC
 */
Premisse instertHeadPremisseRegle(Regle* regle, Premisse listProp, char* description);

/**
 * @brief crée une règle à partir de chaine de caractère
 * 
 * @param pListProp : pointeur sur la liste de toute les proposition qui on déjà été ulitilisé
 * @param descriptionPremisse : tableau de chaine de caracètre contenant toutes les descriptions des prémisses à ajouter à la règle 
 * @param nbElemPremisse : nombre d'élément que l'on veut mettre dans la prémisse
 * @param descriptionConclusion : desciption à donner à la conlusion
 * @return Regle* : renvoie un pointeur sur la règle qui à été crée
 * @author Florian CLOAREC
 */
Regle* createRegle(Premisse* pListProp, char* descriptionPremisse[], long nbElemPremisse,  char* descriptionConclusion);


#endif