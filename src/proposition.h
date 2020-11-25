#ifndef PROPOSITION_H_
#define PROPOSITION_H_



/**
 * @file proposition.h
 * @author Florian Cloarec
 * @brief fichier header contenant les prototypes des fonctions associer à la structure de donnée proposition ainsi que la déclarion de la structure de donnée proposition elle même
 * @version 0.1
 * @date 16 November 2020
 * 
 * @copyright GNU GENERAL PUBLIC LICENSE
 * 
 */


/**
 * @brief structure de donnée permetant de stocker ou une Propositon 
 * @struct Proposition
 * 
 */
typedef struct Proposition
{
    char *description; /*! chaine de caracère qui contient la description en laguage naturel de la Proposition*/ 
    bool validite; /*! vaut 1 si la proposition est vraie et 0 si elle est fausse ou indéterminé */
}Proposition;

/**
 * @brief structure de donnée Proposition qui est une chaine de caractère 
 * 
 * @author Florian CLOAREC
 */
//typedef char* Proposition;


/**
 * @brief crée une variable de type proposiont
 * 
 * @param valuePropositon[] : chaine de caractère qui contient la valuer de la propositon à créer
 * @param validite : 1 si la propositon est vraie, 0 si elle est fausse
 * @return Proposition : pointeru sur la propositon qui viens d'être crée 
 * @author Florian CLOAREC
 */
Proposition* newProposition(char valueProposition[], bool validite);

/**
 * @brief suprime de la mémoire une variable de type proposition
 * 
 * @param propositionToDelete : pointeur sur la proposition à supprimer
 * @author Florian CLOAREC
 */

void deleteProposition(Proposition *propositionToDelete);

/**
 * @brief afficher le contenue d'une propositon
 * 
 * @param prposition : pointeur sur la proposition à afficher
 * 
 * @author Florian CLOAREC
 */
void affichePropositon(Proposition *proposition);




#endif