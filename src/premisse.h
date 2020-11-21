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
    Proposition         valeur;        /*! valeur de l'élément de la liste chainé */
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
 * @brief suprime tout les élément d'une prémisse récursivement
 * 
 * @param elem : pointeur sur le premier élément de la prémisse à suprimer 
 * @author Florian CLOAREC
 */
void supprimeElemPremisse(PremisseElem *elem);


/**
 * @brief ajoute une proposition en queue à la liste chianée de proposition qu'est la prémisse
 * 
 * @param premisse : prémisse à qui on veut ajouter une proposition
 * @param proposition : proposotion à ajouter
 * @author Florian CLOAREC
 */
void addTailPremisse(Premisse *premisse, Proposition proposition);


/**
 * @brief affiche une Prémisse de manière récursive
 * 
 * @param elem : pointeur sur le premier élément de la prémisse à afficher
 * @author Florian CLOAREC
 */
void affichePremisse(PremisseElem *elem);


/**
 * @brief teste si une Poposition appartient à une prémisse
 * 
 * @param elem : pointeur sur le premier élément de la prémisse à tester
 * @param proposition : propostion à rechercher
 * @return true : si la propostion à été trouvée dans la premisse
 * @return false : si la propostion n'à pas été trouvée dans la premisse
 * @author Florian CLOAREC
 */
bool propositionDansPremisse(PremisseElem* elem, Proposition proposition);

/**
 * @brief supprime une proposition dans la prémisse d'une règle
 * 
 * @param elem : pointeur sur le premier élément de la prémisse dont on veut suprimer
 * @param proposition : proposition à supprimer
 * @param prem : pointeur sur la prémisse 
 * @return true : si la proposition à été supprimée dans la prémisse
 * @return false : si la proposition n'a pas été trouvée
 * @author Florian CLOAREC
 */
bool rechercheSupprimePremisse(PremisseElem* elem, Proposition proposition, Premisse* prem);


/**
 * @brief vérifie si une premisse est vide ou ne l'est pas 
 * 
 * @param PremisseAVerif : premisse à vérifier
 * @return 1 : si la premisse est vide
 * @return 0 : si la premisse n'est pas vide
 * @author Carlo AZANCOTH
 */
bool premisseIsEmpty(Premisse *PremisseAVerif);

#endif