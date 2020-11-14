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

#include "struct.h"

/**
 *  @struct Regle
 *  @brief structure de donnée qui représente une règle
 * 
 */
typedef struct Regle
{
    Premisse    premisse;   /*! liste chainé contenant les Assertion qui forment la prémisse de la règle*/
    Assertion   conclusion; /*! assertion qui est conclue grâce à la règle*/
}Regle;

/**
 * @brief liste chainé d'Assertion 
 * @struct Premisse
 * 
 */
typedef struct Premisse
{
    PremisseElem*   premierElem;    /*! pointeur sur le premier element de la liste chainée */
    PremisseElem*   dernierElem;    /*! pointeur sur le dernier élément de la liste chainée */
    long            nbElem;         /*! nombre d'élément contenue dans la liste chainée */
}Premisse;

/**
 * @brief un élément de la liste chainée de type Premisse
 * @struct PremisseElem
 * 
 */
typedef struct PremisseElem
{
    Assertion valeur; /*! valeur de cet élément de la liste chainée de type Assertion */
    struct PremisseElem* elemSuivant; /*! pointeur sur l'élément suivant de la liste chainé */
}PremisseElem;



