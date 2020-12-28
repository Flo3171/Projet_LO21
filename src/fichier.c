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
    FILE *fichier=NULL;
    fichier= fopen(cheminFichier,"r+");
    if (fichier == NULL)
    {
        printf("ERREUR ouverture ficher");
        exit(0);
    }

    long nbProp ;
    fscanf(fichier,"%d;",&nbProp);

    while(nbProp != 0){
        //printf("\n\nnombre de propositions :%d\n",nbProp);
        
        char *chaine = (char*)malloc(sizeof(char)*(TAILLE_MAXI_PROPOSITION + 1)*(nbProp +1));
        if (chaine == NULL)
        {
            printf("ERREUR alocation dynamique");
            exit(EXIT_FAILURE);
        }
        fgets(chaine,(TAILLE_MAXI_PROPOSITION+ 1)*(nbProp+1),fichier);
        //printf("%s\n",chaine);
        
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

        int j = 0 ;
        for (long i = -1; i < nbProp; i++){

            int position = 0;
            if(i==-1){
                while(chaine[j] != ';'){
                    conclusion[position]=chaine[j];
                    position++;
                    j++;
                }
                conclusion[position]='\0';
                    //printf("conclusion:\n%s\npropositons:\n",conclusion);
            }else{
                prem[i] = (char*)malloc(sizeof(char)*(TAILLE_MAXI_PROPOSITION + 1));
                if (prem[i] == NULL)
                {
                    printf("ERREUR alocation dynamique");
                    exit(EXIT_FAILURE);
                }

                while(chaine[j] != ';'){
                    prem[i][position]=chaine[j];
                    position++;
                    j++;
                }
                prem[i][position]='\0';
            }
            j++;
        }
        
        bdc = addRegleBDC(bdc, listeProposition , prem, nbProp, conclusion);
        //printf("ok\n");
        free(chaine);
        free(conclusion);
        for (long i = 0; i < nbProp; i++)
        {
            free(prem[i]);
        }
        free(prem);
        nbProp = 0;
        fscanf(fichier,"%d;",&nbProp);
    }
    fclose(fichier);
    return bdc;
}

BDConnaissances WriteBDC(BDConnaissances bdc, Premisse* listeProposition, char cheminFichier[])
{
    FILE *fichier=NULL;
    fichier= fopen(cheminFichier,"a+");
    if (fichier == NULL)
    {
        printf("ERREUR ouverture ficher");
        exit(0);
    }
        
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


    int correct = 0, clean_stdin, nbProp= 0, sortie = 0;
    char prop[TAILLE_MAXI_PROPOSITION+2];

    sortie=  acquisitionEntierSansMessageAvecConsigne(2,3,"\n\nCombien de propositions voulez vous ajouter ? :\n 2 ou 3 \n--> ");

    while(nbProp < sortie){
        correct = 0;
        printf("\nVeuillez entrer la proposition %d :\n\t",nbProp+1);
    
        while(correct == 1 || correct == 0){
            fgets(prop,TAILLE_MAXI_PROPOSITION+2,stdin);
            correct=verificationPropositionAvecMessage(prop);
            if(correct == 0){
                do { 
                    clean_stdin = getchar(); 
                } while (clean_stdin != '\n' && clean_stdin != EOF); 
            }
        }
        prem[nbProp] = (char*)malloc(sizeof(char)*(TAILLE_MAXI_PROPOSITION + 1));
        prop[strlen(prop)-1]='\0';
        strcpy(prem[nbProp],prop);

        for(int i = 0; i<TAILLE_MAXI_PROPOSITION+2; i++){
            prop[i]=' ';
        }

        nbProp++;
    }

    correct = 0;
    printf("\nVeuillez entrer la conclusion :\n\t");

    while(correct == 1 || correct == 0){
        fgets(prop,TAILLE_MAXI_PROPOSITION+2,stdin);
        correct=verificationPropositionAvecMessage(prop);
        if(correct == 0){
            do { 
                clean_stdin = getchar(); 
            } while (clean_stdin != '\n' && clean_stdin != EOF); 
        }
        prop[strlen(prop)-1]='\0';
        strcpy(conclusion,prop);
    }

    bdc = addRegleBDC(bdc, listeProposition , prem, nbProp, conclusion);
    afficheBDC(bdc);
    
    if(nbProp == 2 ){
        fprintf(fichier,"\n%1d;%s;%s;%s;",nbProp,conclusion,prem[0],prem[1]);
    }else if (nbProp == 3){
        fprintf(fichier,"\n%1d;%s;%s;%s;%s;",nbProp,conclusion,prem[0],prem[1],prem[2]);
    }


    /* on libère les variables*/
    free(conclusion);
    for (long i = 0; i < 3; i++)
    {
        free(prem[i]);
    }
    free(prem);
    fclose(fichier);
    
    return bdc;
}