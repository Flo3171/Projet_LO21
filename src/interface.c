/**
 * @file interface.c
 * @author Florian Cloarec
 * @brief fichier contenant les implémentation des fonction lié à l'interface avec l'utilisateur
 * @version 0.1
 * @date 07 December 2020
 * 
 * @copyright GNU GENERAL PUBLIC LICENSE
 * 
 */

#include "main.h"

void menuPrincipal()
{
    bool retour = false;
    int choix;
    while (!retour)
    {
        choix = acquisitionEntierSansMessageAvecConsigne(1,4, "Quel action souhaitez vous realiser :\n1-Lancer le systeme expert\n2-Gerer la base de connaissance\n3-Parametre\n4-Quiter\n");

        switch (choix)
        {
        case 1:
            systemExpert("");
            break;
        case 2:
            {
                bool retourSousMenu = false;
                while (!retourSousMenu)
                {
                    int choixSousMenu = acquisitionEntierSansMessageAvecConsigne(1, 2, "\nQuel action souhaitez vous realiser:\n1-Afficher la Base de Connaissance\n2-Ajouter une regle a la base de connaissances\n3-Retour\n");
                    switch (choixSousMenu)
                    {
                    case 1:
                        {
                            Premisse listProp = NULL;
                            BDConnaissances bdc = NULL;
                            bdc = ReadBDC(bdc, &listProp);

                            printf("\nLa base de connaissance contient les règle suivantes :\n");
                            afficheBDC(bdc);
                            printf("\n");

                            deleteAllBDC(bdc);
                            deletePremisseProposition(listProp);
                        }
                        break;
                    case 2:
                        /*  Pour toi Carlo */
                        break;
                    
                    default:
                        retourSousMenu = true;
                        break;
                    }
                }
                
                
            }
            break;
        case 3:
            
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

Premisse genereBDVerite(Premisse listProp, Premisse bdVerite)
{
    if (listProp == NULL)
    {
        return bdVerite;
    }
    else
    {
        printf("\n");
        affichePropositon(listProp->valeur);
        int choix = acquisitionEntierSansMessageAvecConsigne(1, 2, "\nQuel est la validite de cette proposition :\n1-Vraie\n2-Faux\n3-Je ne sais pas\n");
        if (choix == 1)
        {
            listProp->valeur->validite = true;
            bdVerite = addHeadPremisse(bdVerite, listProp->valeur);
        }
        else
        {
            listProp->valeur->validite = false;
        }
        

        return genereBDVerite(listProp->elemSuivant, bdVerite);
    }
}

void systemExpert(char cheminFicher[])
{
    Premisse listProp = NULL;
    Premisse bDVerite = NULL;
    BDConnaissances bdc = NULL;
    Premisse conclusion = NULL;

    bdc = ReadBDC(bdc, &listProp);
    bDVerite = genereBDVerite(listProp, bDVerite);

    conclusion =  moteurDInference(bDVerite, bdc);

    printf("\n\nLe moteur d'inference a prouve les propositions suivantes : \n");
    affichePremisse(conclusion);

    deleteAllBDC(bdc);
    deletePremisse(bDVerite);
    deletePremisse(conclusion);
    deletePremisseProposition(listProp);
}