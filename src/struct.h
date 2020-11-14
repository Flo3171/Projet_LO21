/**
 * @file struct.h
 * @author Florian Cloarec
 * @brief fichier contenant les structures de données et les énumérations
 * @version 0.1
 * @date 14 November 2020
 * 
 * @copyright GNU GENERAL PUBLIC LICENSE
 * 
 */

/**
 * @brief structure de donnée permetant de stocker une Assetion ou une propositon 
 * @struct Assertion
 * 
 */
typedef struct Assertion
{
    long inode; /*! numéro unique à cet assertion qui permet de l'indentifier */
    char description[]; /*! chaine de caracère qui contient la description en laguage naturel de l'Assertion*/ 
};



