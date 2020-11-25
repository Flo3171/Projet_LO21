#ifndef B_D_CONNAISSANCES_H_
#define B_D_CONNAISSANCES_H_

/**
 * @file BDConnaissances.h
 * @author Florian Cloarec
 * @brief fichier contenant les prototype des fonctions liée à la base de connaissances ainsi que la définition de la structure elle meme
 * @version 0.1
 * @date 21 November 2020
 * 
 * @copyright GNU GENERAL PUBLIC LICENSE
 * 
 */

#include "regle.h"

/**
 * @brief un élément de la liste chainé de Règles
 * 
 * @struct BDConnaissanceselem
 * @author Florian CLOAREC
 */
typedef struct BDConnaissancesElem
{
    Regle* valeur; /*! valeur de l'élément de la liste chainée ici un pointeur sur Regle */
    struct BDConnaissancesElem* suivant; /*! pointeur sur l'élémen suivant dans la liste chainée */
}BDConnaissancesElem;

/**
 * @brief pointeur sur le premier élément de la liste chainée 
 * 
 * @author Florian CLOAREC
 */
typedef BDConnaissancesElem* BDConnaissances;

/**
 * @brief teste si une BDConnaissances est vide
 * 
 * @param bdc : base de connaissances que l'on veut tester 
 * @return true : si la structure est vide
 * @return false : si la structure n'est pas vide
 * @author Florian CLOAREC
 */
bool isEmptyBDC(BDConnaissances bdc);

/**
 * @brief ajoute une règle à une base de connaissances en tête 
 * 
 * @param bdc : bdc à laquelle on veut ajouter la règle
 * @param aAjouter : pointeur sur la règle à ajouter 
 * @return BDConnaissances : renvoie la BDC
 * @author Florian CLOAREC
 */
BDConnaissances addHeadBDC(BDConnaissances bdc, Regle *aAjouter);


/**
 * @brief supprime l'élément en tête de la bdc
 * 
 * @param bdc : structure dont on veut supprimer l'élément
 * @return BDConnaissances : pointeur sur le premier élément de la base de connaissances
 * @author Florian CLOAREC
 */
BDConnaissances deleteHeadBDC(BDConnaissances bdc);

/**
 * @brief supprime récursivement la totalitée d'une base de connaissance
 * 
 * @param bdc : bdc à supprimer
 * @author Florian CLOAREC
 */
void deleteAllBDC(BDConnaissances bdc);

/**
 * @brief affiche la totalitée d'une base de connaissances
 * 
 * @param bdc : bdc à afficher
 * @author Florian CLOAREC
 */
void afficheBDC(BDConnaissances bdc);


/**
 * @brief recherche à partir de la base de véritée et de la base de connaissances les propositions qui sont vraie
 * 
 * @param baseVerite : la liste chainé de Porposition qui sont vraie
 * @param bdc : base de connaissance, liste chainé des regles qui permetent de déduire des proposition vraie
 * @return Premisse : une liste chainée de propositions qui sont les proposition qui on été trvouée par la fonction
 * @author Florian CLOAREC
 */
Premisse moteurDInference(Premisse baseVerite, BDConnaissances bdc);




#endif