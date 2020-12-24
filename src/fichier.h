#ifndef FICHIER_H_
#define FICHIER_H_

/**
 * @file fichier.h
 * @author Carlo AZANCOTH
 * @brief fichier contenant les prototype des fonctions liée à lacréation de la base de connaissances via la lectures de fichier
 * @version 0.1
 * @date 18 décembre 2020
 * 
 * @copyright GNU GENERAL PUBLIC LICENSE
 * 
 */


/**
 * @brief lis le fichier de BDC.csv qui contient toutes les connaissance et l'ajoute à la base de Connaisance
 * 
 * @param listeProposition : liste de toute les proposition
 * @param bdc : base de connaissance, liste chainé des regles qui permetent de déduire des proposition vraie
 * @param cheminFichier : chemin vers le ficher qui contient les règle de la bdc
 * @return 0 si le fichier ne s'est pas ouvert 
 * @author Carlo AZANCOTH
 */
BDConnaissances ReadBDC(BDConnaissances bdc, Premisse* listeProposition, char cheminFichier[]);

/**
 * @brief écris de nouvelles règles entrées par l'utilisateur dans le fichier de BDC.csv qui contient toutes les connaissance et l'ajoute à la base de Connaisance
 * 
 * @param listeProposition : liste de toute les proposition
 * @param bdc : base de connaissance, liste chainé des regles qui permetent de déduire des proposition vraie
 * @param cheminFichier : chemin vers le ficher qui contient les règle de la bdc
 * @return 0 si le fichier ne s'est pas ouvert 
 * @author Carlo AZANCOTH
 */
BDConnaissances WriteBDC(BDConnaissances bdc, Premisse* listeProposition, char cheminFichier[]);

#endif