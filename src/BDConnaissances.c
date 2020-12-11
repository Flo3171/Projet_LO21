/**
 * @file BDConnaissances.c
 * @author Florian Cloarec
 * @brief fichier contenant les implémentations des fonctions lié à la structure de donnée Base de Connaissances
 * @version 0.1
 * @date 21 November 2020
 * 
 * @copyright GNU GENERAL PUBLIC LICENSE
 * 
 */

#include "main.h"

bool isEmptyBDC(BDConnaissances bdc)
{
    return (bdc == NULL);
}

BDConnaissances addHeadBDC(BDConnaissances bdc, Regle *aAjouter)
{
    BDConnaissancesElem* newElem = (BDConnaissancesElem*)malloc(sizeof(BDConnaissancesElem));
    if (newElem == NULL)
    {
        printf("ERREUR alocation dynamique");
        exit(0);
    }
    

    newElem->valeur = aAjouter;
    newElem->suivant = bdc;

    return newElem;

}

BDConnaissances deleteHeadBDC(BDConnaissances bdc)
{
    if (!isEmptyBDC(bdc))
    {
        BDConnaissancesElem *toDeleteNext = bdc->suivant;
        deleteRegle(bdc->valeur);
        free(bdc);

        return toDeleteNext;
    }
    else
    {
        return NULL;
    }
}

void deleteAllBDC(BDConnaissances bdc)
{
    if (!isEmptyBDC(bdc)){
        bdc = deleteHeadBDC(bdc);
        deleteAllBDC(bdc);
    }
}

void afficheBDC(BDConnaissances bdc)
{
    if (!isEmptyBDC(bdc)){
        printf("\n-->");
        afficheRegle(bdc->valeur);
        afficheBDC(bdc->suivant);
    }
}

BDConnaissances addRegleBDC(BDConnaissances bdc, Premisse* pListProp, char* descriptionPremisse[], long nbElemPremisse,  char* descriptionConclusion)
{
    return addHeadBDC(bdc, createRegle(pListProp, descriptionPremisse, nbElemPremisse, descriptionConclusion));
}

Premisse moteurDInference(Premisse baseVerite, BDConnaissances bdc)
{
    Premisse conclusion = NULL;
    PremisseElem *propositionActuel = baseVerite;
    BDConnaissancesElem *regleActuel = bdc;

    while (propositionActuel != NULL)
    {
        while (regleActuel != NULL)
        {
            if(propositionDansPremisse(regleActuel->valeur->premisse, propositionActuel->valeur))
            {
                setValidite(propositionActuel->valeur, true);
                if (isPremisseTrue(regleActuel->valeur->premisse))
                {
                    conclusion = addTailPremisse(conclusion, regleActuel->valeur->conclusion);
                }
                
            }
            regleActuel = regleActuel->suivant;
        }
        propositionActuel = propositionActuel->elemSuivant;    
    }
    return conclusion;    
}

Premisse createBDVerite(Premisse listProp, Premisse BDVerite)
{
    if (listProp != NULL)
    {
        if (listProp->valeur->validite == true)
        {
            BDVerite = addTailPremisse(BDVerite, listProp->valeur);
        }
        createBDVerite(listProp->elemSuivant, BDVerite);
    }
    return BDVerite;
    
}
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
        
        char *chaine = malloc(sizeof(char)*(TAILLE_MAXI_PROPOSITION+ 1)*(nbProp+4));
        if (chaine == NULL)
        {
            printf("ERREUR alocation dynamique");
            exit(0);
        }
        fgets(chaine,(TAILLE_MAXI_PROPOSITION+ 1)*(nbProp+1),fichier);
        //printf("%s\n",chaine);
        
        char **prem = (char**)malloc(sizeof(char*)*nbProp);
        if (prem == NULL)
        {
            printf("ERREUR alocation dynamique");
            exit(0);
        }

        char *conclusion = malloc(sizeof(char)*(TAILLE_MAXI_PROPOSITION+ 1));
        if (conclusion == NULL)
        {
            printf("ERREUR alocation dynamique");
            exit(0);
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
                    exit(0);
                }

                while(chaine[j] != ';'){
                    prem[i][position]=chaine[j];
                    position++;
                    j++;
                }
                prem[i][position]='\0';
                //printf("%s\n",prem[i]);
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
    return bdc ;
}
