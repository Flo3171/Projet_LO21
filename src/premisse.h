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

typedef PremisseElem* Premisse;



/**
 * @brief supprime de la mémoire une prémisse
 * 
 * @param prem : premisse que l'on veut supprimer
 * @author Florian CLOAREC
 */
void deletePremisse(Premisse prem);

/**
 * @brief ajouter une proposition en tête d'une prémisse
 * 
 * @param prem : prémisse dans laquel on veut ajouter
 * @param prop : pointeur sur la proposition à ajouter
 * @return Premisse : renvoit la pemisse
 * @author Florian CLOAREC
 */
Premisse addHeadPremisse(Premisse prem, Proposition *prop);

/**
 * @brief ajoute une proposition en queue à la liste chianée de proposition qu'est la prémisse
 * 
 * @param prem : prémisse à qui on veut ajouter une proposition
 * @param prop : proposotion à ajouter
 * @return Premisse : renvoit la pemisse
 * @author Florian CLOAREC
 */
Premisse addTailPremisse(Premisse prem, Proposition *prop);


/**
 * @brief affiche une Prémisse de manière récursive
 * 
 * @param prem : prémisse que l'on veut afficher
 * @author Florian CLOAREC
 */
void affichePremisse(Premisse prem);


/**
 * @brief teste si une Poposition appartient à une prémisse
 * 
 * @param prem : prémisse à tester
 * @param prop : propostion à rechercher
 * @return true : si la propostion à été trouvée dans la premisse
 * @return false : si la propostion n'à pas été trouvée dans la premisse
 * @author Florian CLOAREC
 */
bool propositionDansPremisse(Premisse prem, Proposition* prop);

/**
 * @brief supprime une proposition dans la prémisse d'une règle
 * 
 * @param prem : prémisse dont on veut suprimer une proposition
 * @param prop : proposition à supprimer
 * @return renvoie la prémisse
 * @author Florian CLOAREC
 */
Premisse rechercheSupprimePremisse(Premisse prem, Proposition *prop);


/**
 * @brief vérifie si une premisse est vide ou ne l'est pas 
 * 
 * @param Prem : premisse à vérifier
 * @return 1 : si la premisse est vide
 * @return 0 : si la premisse n'est pas vide
 * @author Carlo AZANCOTH
 */
bool premisseIsEmpty(Premisse prem);

#endif