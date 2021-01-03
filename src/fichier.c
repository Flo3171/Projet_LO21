/**
 * @file fichier.c
 * @author Carlo AZANCOTH
 * @brief fichier contenant les implémentations des fonctions liée à lacréation de la base de connaissances via la lectures de fichier
 * @version 0.1
 * @date 18 décembre 2020
 * 
 * @copyright GNU GENERAL PUBLIC LICENSE
 * 
 */

#include "main.h"

BDConnaissances ReadBDC(BDConnaissances bdc, Premisse* listeProposition, char cheminFichier[])
{
    /*ouverture du fichier avec le chemin indiqué*/
    FILE *fichier=NULL;
    fichier= fopen(cheminFichier,"r+");

    /*on vérifie la bonne ouverture du fichier sinon on sort de la fonction*/
    if (fichier == NULL)
    {
        printf("ERREUR ouverture ficher");
        exit(0);
    }

    
    long nbProp ;
    /*on commence la lecture du fichier en lisant le nombre de proposition de la première règle */
    fscanf(fichier,"%d;",&nbProp);

    /*lis le fichier tant qu'il reste des lignes à lire*/
    while(nbProp != 0){
        /*allocation en mémoire de la variables pour lire une ligne du fichier*/
        char *chaine = (char*)malloc(sizeof(char)*(TAILLE_MAXI_PROPOSITION + 1)*(nbProp +1));
        if (chaine == NULL)
        {
            printf("ERREUR alocation dynamique");
            exit(EXIT_FAILURE);
        }

        /*lecture de la ligne*/
        fgets(chaine,(TAILLE_MAXI_PROPOSITION+ 1)*(nbProp+1),fichier);
        
        /*declaration en mémoire des variables permettant de stocker les diférentes proposition et la conclusion*/
        char **prem = (char**)malloc(sizeof(char*)*nbProp);
        if (prem == NULL)
        {
            printf("ERREUR alocation dynamique");
            exit(EXIT_FAILURE);
        }

        char *conclusion = (char*)malloc(sizeof(char)*(TAILLE_MAXI_PROPOSITION + 1));
        if (conclusion == NULL)
        {
            printf("ERREUR alocation dynamique");
            exit(EXIT_FAILURE);
        }

        /* découpage de la ligne lue dans le fichier*/
        int j = 0 ;
        for (long i = -1; i < nbProp; i++){
            /*renitialisation de la position d'ecriture dans les variable*/
            int position = 0;

            /*cas de la lecture de la conclusion*/
            if(i==-1){
                /*retranscrit la conclusion lue dans le fichier dans la variable conclusion jusqu'à trouver le premier ";"*/
                while(chaine[j] != ';'){
                    conclusion[position]=chaine[j];
                    position++;
                    j++;
                }
                /*ajout du "\0" pour indiquer la fin du texte*/
                conclusion[position]='\0';
            /*cas de la lecture des propositions */
            }else{
                /*declaration en memoire de la proposition lue*/
                prem[i] = (char*)malloc(sizeof(char)*(TAILLE_MAXI_PROPOSITION + 1));
                if (prem[i] == NULL)
                {
                    printf("ERREUR alocation dynamique");
                    exit(EXIT_FAILURE);
                }

                /*retranscrit la proposition lue dans le fichier dans la variable prem jusqu'à trouver le ";" suivant*/
                while(chaine[j] != ';'){
                    prem[i][position]=chaine[j];
                    position++;
                    j++;
                }
                prem[i][position]='\0';
            }
            j++;
        }
        
        /*ajout de la nouvelle règle à la base de connaissance*/
        bdc = addRegleBDC(bdc, listeProposition , prem, nbProp, conclusion);

        /*liberation de l'espace en mémoire des différentes variables*/
        free(chaine);
        free(conclusion);
        for (long i = 0; i < nbProp; i++)
        {
            free(prem[i]);
        }
        free(prem);

        /*rénitialisation du nombre de proposition*/
        nbProp = 0;

        /*lecture de la ligne suivante si il y en a encore une*/
        fscanf(fichier,"%d;",&nbProp);
    }
    /*fermeture du fichier*/
    fclose(fichier);

    return bdc;
}

BDConnaissances WriteBDC(BDConnaissances bdc, Premisse* listeProposition, char cheminFichier[])
{
    /*ouverture du fichier avec le chemin indiqué*/
    FILE *fichier=NULL;
    fichier= fopen(cheminFichier,"a+");

    /*on vérifie la bonne ouverture du fichier sinon on sort de la fonction*/
    if (fichier == NULL)
    {
        printf("ERREUR ouverture ficher");
        exit(0);
    }
    
    /*allocation en mémoire de la variables pour lire une ligne du fichier*/
    char **prem = (char**)malloc(sizeof(char*)*3);
    if (prem == NULL)
    {
        printf("ERREUR allocation dynamique");
        exit(EXIT_FAILURE);
    }

    char *conclusion = (char*)malloc(sizeof(char)*(TAILLE_MAXI_PROPOSITION + 1));
    if (conclusion == NULL)
    {
        printf("ERREUR allocation dynamique");
        exit(EXIT_FAILURE);
    }

    /*initialisation des variables*/
    int correct = 0, clean_stdin, nbProp= 0, sortie = 0;
    /*déclaration de la variables pour l'acquisition d'un texte par l'utilisateur*/
    char prop[TAILLE_MAXI_PROPOSITION+2];

    /*on demande à l'utilisateur d'indiquer le nombre de proposition qu'il veut entrer*/
    sortie=  acquisitionEntierSansMessageAvecConsigne(1,254,"\n\nCombien de propositions voulez vous ajouter ? :\n entre 2 et 254 \n--> ");

    /*demande l'aquisition d'une proposition tant que le nombre de prpoposition indiqué n'est pas atteint*/
    while(nbProp < sortie){
        /* remise à zero de la variable pour vérifier la bonne acquisition des informations */
        correct = 0;
        printf("\nVeuillez entrer la proposition %d :\n\t",nbProp+1);

        /* demande l'acquisition de la proposition tant que l'utilisateur n'as pas rentré une phrase valide*/
        while(correct == 1 || correct == 0){
            fgets(prop,TAILLE_MAXI_PROPOSITION+2,stdin);
            /*verifie si la proposition entrée par l'utilisateur respecte les règles*/
            correct=verificationPropositionAvecMessage(prop);

            /* si l'utilisateur à entrée trop de carractères on vide tout les carractères qui n'ont pas été lu*/
            if(correct == 0){
                do { 
                    clean_stdin = getchar(); 
                } while (clean_stdin != '\n' && clean_stdin != EOF); 
            }
        }
        
        /*allocation en mémoire d'une nouvelle proposition */
        prem[nbProp] = (char*)malloc(sizeof(char)*(TAILLE_MAXI_PROPOSITION + 1));

        /* on remplace le '\n' recupéré par le fgets par '\0' de fin de char */ 
        prop[strlen(prop)-1]='\0';
        /*on transfert l'acquisition de l'utilisateur dans une variable*/
        strcpy(prem[nbProp],prop);

        /* on vide la variable prop pour l'acquisition suivante*/ 
        for(int i = 0; i<TAILLE_MAXI_PROPOSITION+2; i++){
            prop[i]=' ';
        }

        /*on incremente le numéro de propositions*/
        nbProp++;

        /* lorsque le nombre de propositoons indiqué par l'utilisateur on lui demande si si veut passer à la conclusion ou continuer d'ajouter des propositions*/
        if (nbProp == sortie){
            if (acquisitionEntierSansMessageAvecConsigne(1,2,"voulez vous ajouter une proposition ?\n1-oui\n2-non\n")== 1){
                sortie++;
            }
        }
    }

    correct = 0;
    printf("\nVeuillez entrer la conclusion :\n\t");

    /* demande l'acquisition de la conclusion tant que l'utilisateur n'as pas rentré une phrase valide*/
    while(correct == 1 || correct == 0){
        fgets(prop,TAILLE_MAXI_PROPOSITION+2,stdin);

        /*verifie si la proposition entrée par l'utilisateur respecte les règles*/
        correct=verificationPropositionAvecMessage(prop);

        /*verifie si la proposition entrée par l'utilisateur respecte les règles*/
        if(correct == 0){
            do { 
                clean_stdin = getchar(); 
            } while (clean_stdin != '\n' && clean_stdin != EOF); 
        }
    }

    /* on remplace le '\n' recupéré par le fgets par '\0' de fin de char */ 
    prop[strlen(prop)-1]='\0';
    /*on transfert l'acquisition de l'utilisateur dans une variable*/
    strcpy(conclusion,prop);

    /*ajout de la nouvelle règle à la base de connaissance*/
    bdc = addRegleBDC(bdc, listeProposition , prem, nbProp, conclusion);
    
    /*ecriture de la nouvelle règle dans le fichier*/
    fprintf(fichier,"\n%1d;",nbProp);
    fprintf(fichier,"%s;",conclusion);
    for (int i = 0; i<nbProp; i++){
        fprintf(fichier,"%s;",prem[i]);
    }


    /* on libère les variables*/
    free(conclusion);
    for (long i = 0; i < nbProp; i++)
    {
        free(prem[i]);
    }
    free(prem);

    /*on ferme le fichier*/
    fclose(fichier);
    
    return bdc;
}