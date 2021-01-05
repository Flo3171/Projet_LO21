/**
 * @file interface.c
 * @author Florian Cloarec
 * @brief fichier contenant les implémentation des fonctions lié à l'interface avec l'utilisateur
 * @version 0.1
 * @date 07 December 2020
 * 
 * @copyright GNU GENERAL PUBLIC LICENSE
 * 
 */

#include "main.h"

void menuPrincipal()
{
    char cheminFichier[100] = "../../file/bdc.csv";
    bool retour = false;
    int choix;
    while (!retour)
    {
        choix = acquisitionEntierSansMessageAvecConsigne(1,3, "Quel action souhaitez vous realiser :\n1-Lancer le systeme expert\n2-Gerer la base de connaissance\n3-Quitter\n");

        switch (choix)
        {
        case 1:
            systemExpert(cheminFichier);
            break;
        case 2:
            {
                bool retourSousMenu = false;
                while (!retourSousMenu)
                {
                    int choixSousMenu = acquisitionEntierSansMessageAvecConsigne(1, 4, "\nQuel action souhaitez vous realiser:\n1-Afficher la Base de Connaissance\n2-Ajouter une regle a la base de connaissances\n3-Changer le chemin d'acces du fichier contenant la bdc\n4-Retour\n");
                    switch (choixSousMenu)
                    {
                    case 1:
                        {
                            Premisse listProp = NULL;
                            BDConnaissances bdc = NULL;
                            bdc = ReadBDC(bdc, &listProp, cheminFichier);

                            printf("\nLa base de connaissance contient les regle suivantes :\n");
                            afficheBDC(bdc);
                            printf("\n");

                            deleteAllBDC(bdc);
                            deletePremisseProposition(listProp);
                        }
                        break;
                    case 2:
                        {
                            Premisse listProp = NULL;
                            BDConnaissances bdc = NULL;
                            bdc = ReadBDC(bdc, &listProp, cheminFichier);
                            
                            WriteBDC(bdc, &listProp, cheminFichier);
                            printf("\nLa base de connaissance contient les regle suivantes :\n");
                            afficheBDC(bdc);
                            printf("\n");

                            deleteAllBDC(bdc);
                            deletePremisseProposition(listProp);
                        }
                        break;
                    case 3:
                        {
                            char lecture[100];
                            printf("Le chemin actuel est %s\nEntrer le nouveau chemin d'acces :", cheminFichier);
                            fgets(lecture, 100, stdin);
                            strcpy(cheminFichier, lecture);
                        }
                        break;
                    
                    default:
                        retourSousMenu = true;
                        break;
                    }
                }
                
                
            }
            break;
        default:
            retour =  true;
            break;
        }
    }
    
}

int acquisitionEntierSecurise()
{
    char num[50];
    int NB = 0;
    /** Lecture de l'entrée du joueur de type char **/
    fgets(num, 50, stdin);
    /** Test si le premier caractère est un 0 **/
    if(num[0] == '0'){
        NB = strtol(num, NULL, 10);
    }else{
        /** Conversion du char en int **/
        NB = strtol(num, NULL, 10);
        if(NB == 0){
            NB = -1;
        }
    }
    return NB;
}

int acquisitionEntierSansMessageAvecConsigne(int min, int max, char consigne[])
{
    int valeur;
    do{
        printf("%s ", consigne);
        valeur=acquisitionEntierSecurise();
    }while (valeur < min || valeur > max);
    return valeur;
}

void genereBDVerite(Premisse listProp, BDConnaissances bdc)
{
    if (listProp != NULL)
    {
        if (isPropositionInConclusion(bdc, listProp->valeur))
        {
            listProp->valeur->validite = false;
        }
        else
        {
            printf("\n");
            affichePropositon(listProp->valeur);
            int choix = acquisitionEntierSansMessageAvecConsigne(1, 3, "\nQuel est la validite de cette proposition :\n1-Vraie\n2-Faux\n3-Je ne sais pas\n");
            if (choix == 1)
            {
                listProp->valeur->validite = true;
            }
            else
            {
                listProp->valeur->validite = false;
            }
        }
        
        genereBDVerite(listProp->elemSuivant, bdc); 
    }
}

void systemExpert(char cheminFicher[])
{
    Premisse listProp = NULL;
    BDConnaissances bdc = NULL;
    Premisse conclusion = NULL;

    bdc = ReadBDC(bdc, &listProp, cheminFicher);

    printf("\nVeuillez repondre a ces question afin de generer la base de verite\n");
    genereBDVerite(listProp, bdc);

    printf("\n\nLa base de verite contient les regle suivantes :\n");
    afficheBDC(bdc);

    printf("\n\nLa base de verite contient les proposition suivantes:\n");
    affichePremisseTrue(listProp);

    conclusion =  moteurDInference(bdc);

    printf("\n\nLe moteur d'inference a prouve les propositions suivantes : \n");
    affichePremisse(conclusion);

    deleteAllBDC(bdc);
    deletePremisse(conclusion);
    deletePremisseProposition(listProp);

    printf("\n\n");
}

 int verificationPropositionAvecMessage(char *proposition)
 {
    /*initialisation de la variable de contrôle*/
    int controle=0;

    /*on verifie que tout les carractères saisis sont autorisés */
    for(int i=0; i< strlen(proposition)-1 && i < TAILLE_MAXI_PROPOSITION ;i++){
        if ((proposition[i]<'0' || proposition[i]>'9') && (proposition[i]<'A' || proposition[i]>'Z') && (proposition[i]<'a' || proposition[i]>'z') && (proposition[i] < ' ' || proposition[i] > ' ') && (proposition[i] < '\'' || proposition[i] > '\'') && (proposition[i] < '-' || proposition[i] > '-') ){
            controle=1;
        }
    }

    /*on vérifie que le texte fait la bonne  longueur*/
    if (strlen(proposition)> TAILLE_MAXI_PROPOSITION || strlen(proposition)< 2){
        controle = controle +2;
    }

    /*on passe à la phase de contrôle, en fonction du score obtenu on determine si un message d'erreur doit être envoyé*/
    switch (controle)
    {
        case 1 : printf("Votre proposition possede un/des carracteres interdis. Entrez votre proposition:\n\t");
            break;
        case 2 : printf("Votre proposition n'as pas le nombre de carracteres recquis. Entrez votre proposition:\n\t");
            break;
        case 3 : printf("Votre proposition ne respecte pas les criteres d'entree. Entrez votre proposition:\n\t");
    }
    
    /*on retourne la valeur correspondante à l'etat corect ou incorect de la saisie*/
    if(controle == 0){
        return 2;
    }else if (controle == 1){
        return 1;
    }else{
        return 0;
    }
    
 }