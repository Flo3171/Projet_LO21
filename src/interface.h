#ifndef INTERFACE_H_
#define INTERFACE_H_

/**
 * @file interface.h
 * @author Florian Cloarec
 * @brief fichier contenant les prototype des fonction liées à l'interface avec l'utilisateur
 * @version 0.1
 * @date 07 December 2020
 * 
 * @copyright GNU GENERAL PUBLIC LICENSE
 * 
 */

/**
 * @brief lance le menu principal du prgramme
 * 
 * @author Florian CLOAREC
 */
void menuPrincipal();


/**
 * @brief acquèrt auprès de l'utilisateur un entier de manière sécurisé
 * 
 * @return int : entier saisi par l'utilisateur
 * @author Florian CLOAREC && Carlo AZANCOTH
 */
int acquisitionEntierSecurise();

/**
 * @brief acquièrt un entier saisi par l'utilisateur avec contrôle d'érreur mais sans message en affichant une consigne
 * 
 * @param min : valeur minimum que l'utilisateur doit saisir
 * @param max : valeur maximum que l'utilisateur doit saisir
 * @param consigne : consigle à afficher à l'utilsateur
 * @return int : revoie la valeur saisi par l'utilsateur et contôlée
 * @author Florian CLOAREC && Carlo AZANCOTH
 */
int acquisitionEntierSansMessageAvecConsigne(int min, int max, char consigne[]);

/**
 * @brief genere la base de Verite en posant des question à l'utilisateur
 * 
 * @param listProp : liste de toute les proposition qui on été enregistré
 * @param bdVerite : liste de toute les propostion qui sont vraie
 * @return Premisse : renvoie une liste chainée de proposition qui est la liste de toute les proposition qui sont vraie
 * @author Florian CLOAREC
 */
Premisse genereBDVerite(Premisse listProp, Premisse bdVerite);

/**
 * @brief lance le system expert
 * 
 * @param cheminFicher : chaine de caracète qui contient le chemin vers le ficher qui permet de générer la bdc
 * @author Florian CLOAREC
 */
void systemExpert(char cheminFicher[]);

/**
 * @brief verifie si une proposition entrée par l'utilisateur à été correctement ecrite
 * 
 * @param proposition : ponteur vers la proposition à vérifier
 * @author Carlo AZANCOTH
 */
int verificationPropositionAvecMessage(char *proposition);

#endif