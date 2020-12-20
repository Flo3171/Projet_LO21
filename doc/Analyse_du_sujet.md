# ANALYSE DU SUJET

## Regle
### Definition des structures
* La structure de donnée abstraite qui va nous permetre représenter une Regle est composée de 2 sous éléments : la prémisse et la conclusion. 
    * Premisse est du type Premisse que nous définirons ci dessous.
    * Conclusion est de type pointeur sur une Proposition que nous définirons ci dessous.

```c
struct Regle{
    Premisse *premisse;
    Proposition *conclusion;
}
```

* La structure de donnée abstraite qui va nous permetre de représenter une Premisse est une liste chainée d'Proposition. La Premisse est donc composé un pointeur sur le premier élément de la liste, un pointeur sur le dernier élément de la liste et une entier qui stocke le nombre d'élément dans la liste.
    * premierElem est de type pointeur sur PremisseElem que nous définirons ci-dessous
    * dernierElem est de type pointeur sur PremisseElem que nous définirons ci-dessous
    * nbElem est de type entier (long en C)

```c
struct Premisse{
    PremisseElem* premierElem;
    PremisseElem* dernierElem;
    long nbElem;
}
```

* La structure de donnée abstraite PremisseElem est constituer de 2 sous variables : la valeur et le pointeur sur l'élément suivant de la liste chainée suivant
    * valeur est de type pointeur sur une Proposition que nous définirons ci-dessous
    * elemSuivant est un pointeur sur PremisseElem

```c
struct PremisseElem{
    Proposition *valeur;
    struct PremisseElem *elemSuivant;
}
```

* La structure de donnée abstraite qui va nous peretre de stocker les Proposition est composée de 2 sous variable : une inode et une description
    * inode est un entier qui permet d'identifier de manière unique l'Proposition
    * description est une chaine de carractère (tableau de char en C) qui explicite en laguage naturel l'Assetion

```c
struct Proposition{
    long inode;
    char description[];
}
```


### Fonctions associées

* newRegle : créer une nouvele règle vide (fait)
    * donnée : rien
    * résultat : un pointeur sur la règle qui vient d'être créée

```algo
fonction : newRegle(): *Regle
    Soit nouvelRegle une Regle
    nouvelRegle.premise <-- NULL
    nouvelRegle.conclusion <-- NULL
    newRegle <-- nouvelRegle
fin fonction
```

* deleteRegle : suprimer une règle et toutes ces composantes (fait)
    * donnée : regleToDelete, un pointeur sur règle, la règle que l'on veut supprimer
    * résultat : supprime de la mémoire la règle

```algo
procédure : deletRegle(Regle *regleToDelete)
    deletePremisse(regleToDelete.premisse)
    libère(regleToDelete)
fin procédure
```


* deletePremisse : suprimer de la mémoire une prémisse
    * donné : un pointeur sur la prémisse à supprimer
    * résutat : supprime de la mémoire la prémisse
```algo
procédure : deletePremisse(Premisse prem)
    si (premisseNonVide(prem))
        deletePremisse(suivant(prem))
        libère(prem)
    fin si
fin procédure
```


* Ajouter une Proposition à la prémisse d'une règle en queue
    * donnée : la proposition à ajouter et la règle à laquelle l'ajouter
    * résutat : ajoute la proposion à la liste chainé en queue en faisant le lien entre les élément et renvoie la règle qui à été modifié
```algo
fonction :  insertTailPremisseRegle(Regle* regle, Proposition *prop)
    premisse(regle) <-- inseretTailPremisse(premisse(regle), prop)
    insertTailPremisseRegle <-- regle
fin fonction
```

```algo
fonction : insertTailPremisse(Premisse prem, Proposition* prop)
    si premisseVide(prem)
        soit newElem un PremisseElem
        valeur(newElem) <-- prop
        elmSuivant(newElem) <-- NULL

        insertTailPremisse <-- newElem

    sinon si premisseVide(elemSuivant(newElem))
        soit newElem un PremisseElem
        valeur(newElem) <-- prop
        elmSuivant(newElem) <-- NULL

        elemSuivant(prem) <-- newElem
        instertTailPremisse <-- prem

    sinon
        insertTailPremisse(elemSuivant(prem), prop)
        insertTailPremisse <-- prem
    fin si
fin fonction
```

* addConclusion : Créer la conclusion d'une règle
    * donné : la règle que l'on veut modifier et la proposition à donner à la conclusion
    * résultat modifie ou initialise la conclution de la règle

```algo
procédure : addConclusion(Regle* regle, Proposition* prop)
    conclusion(regle) <-- prop
fin procédure 
```

* propositionDansPremisse: Tester si une Proposition appartient à la prémisse d'une règle recursivement
    * donnée : un pointeur sur le premier élément de la prémisse dans laquel on veut rechercher, la propositon à rechercher
    * résulat : renvoie 1 si la proposion à été trouvée dans la prémisse et 0 sinon

```algo
fonction : propositionDandPremisse(Premisse prem, Proposition* prop) 
: booléen
    si premisseVide(prem)
        propositionDansPremisse <-- faux
    sinon si valeur(prem) = prop
        propositionDansPremisse <-- vrai
    sinon
        propostionDansPremisse <-- 
        propostionDansPremisse(elemSuivant(prem))
    fin si
fin fonction
```


* rechercheSupprimePremisse :Supprimer une Proposition de la prémisse d'une règle
    * donnée : la prémisse dans laquel on veut suprimmer, la proposition à suprimmer
    *résultat : supprime la proposions si elle a été trouvée et renvoie la prémisse sur laquelle on travail

```algo
fonction : rechercheSupprimePremisse(Premisse prem,
 Propostion* prop) : Premisse
    si premisseVide(prem)
        rechercherSupprimePremisse <-- NULL
    sinon si premisseVide(elemSuivant(prem)) et description(prop) = description(valeur(prem))
        libère prem
        rechercherSypprimePremisse <-- NULL
    sinon si description(prop) = description(valeur(elemSuivant(prem)))
        Soit toDelete une Premisse
        toDelete <-- elemSuivant(prem)
        elemSuivant(prem) <-- elemSuivant(toDelete)
        libérer toDelete
        rechercherSupprimePremisse <--  prem
    sinon
        rechercheSupprimePremisse(elemSuivant(prem), prop)
        rechercheSupprimePremisse <-- prem
    fin si
fin fonction
```

* reglePremisseIsEmpty :Tester si la prémisse d'une règle est vide
    * Donées : un pointeur sur la règle à tester
    * Resultat : renvoie vrai si la prémisse est vide et faux sinon
```algo 
fonction : reglePremisseIsEmpty(Regle *regle) : booléen
    reglePremisseIsEmpty <-- premisseIsEmpty(premisse(regle))
fin fonction
```

* returnHeadPremisse : Accéder à la proposition ce trouvant en tête d'une prémisse
    * donnée : la premisse sur laquelle on veut travailler
    * renvoie : pointeur sur la proposition en tête de la premisse

```algo
fonction : returnHeadPremisse(Premisse prem) : Proposition *
    returnHeadPremisse <-- valeur(prem)
fin fonction
```

* conclutionRegle : Accéder à la conclusion d'une règle
    * donnée : un pointeur sur la règle dont on veut connaitre la conclusion
    * résultat : renvoie un pointeur sur la proposition qui est la conclusion de la règle

```algo
fonction : conclutionRegle(Regle* regle) : Proposition*
    conclutionRegle <-- conclution(regle)
fin fonction
```

## Basse de connaissances
### Definition des structures

La base de connaissances est une liste chainée de Règle, nous avons déjà définit la structure de donnée règle ainsi que toutes les fonction qui lui sont associer, il faut maintenant rajouter une structure permetant de stocker un élément de cette liste chainée et la structure qui fera office de tête de liste

* La structure de donnée abstraite BDConnaissancesElem permet de représenter un élément de la liste chainée de règles. Elle est composée de deux sous-variables, un pointeur sur Règle ainsi que un pointeur sur l'élément suivant dans la liste chainée

```c
struct BDConnaissancesElem{
    Regle valeur;
    struct BDConnaissancesElem* suivant;
};
```

* La structure de donnée abstraite BDConnaissances permet de représenter la base de connaissance, c'est un pointeur sur le premier élément de la liste chainé de règle.

```c
typedef BDConnaissancesElem* BDConnaissances;
```

### Fonctions associées

* isEmptyBDC : tester si la base de connaissances est vide
    * donnée : la base de connaissances que l'on veut tester
    * résultat : renvoie vrai si la basse de connaissance est vide et faux sinon

```algo 
fonction : isEmptyBDC(BDConnaisances bdc)
    si bdc = NULL
        isEmptyBDC <-- vrai
    sinon
        isemptyBDC <-- faux
fin fonction
```

* addHeadBDC : insérer en tête une nouvelle règle
    * donnée : la base de connaissance avec laquelle on travail et un pointeur sur la règle à ajouter
    * résultat : ajoute la règle à la base de connaissance et renvoie la base de connaissance

```algo 
fonction : addHeadBDC(BDConnaissance bdc, Regle regle) : BDConnaissances
    soit newElem un pointeur sur BDConnaissanceElem
    valeur(newElem) <-- regle
    suivant(newElem) <-- bdc
    addHeadBDC <-- newElem
fin fonction
```


* deleteHeadBDC : supprimer en tête une règle
    * donnée : la base de connaisance dont on veut supprimer le premier élément
    * supprime l'élément en tête de la liste chainée et renvoie la base de connaissance

```algo
fonction : deleteHeadBDC(BDConnaissances bdc) : BDConnaissances
    si isEmptyBDC(bdc) = faux
        soit toDeleteNext un pointeur sur un BDConnaissancesElem
        toDeleteNext <-- suivant(bdc)
        deleteRegle(valeur(bdc))
        libère bdc
        deleteHeadBDC <-- toDeleteNext
    sinon
        deleteHeadBDC <-- NULL
fin fonction
```

* returnHeadBDC : Accéder à la règle se trouvant en tête de la base
    * donné : la base de connaissances dont on veut connaitre la prémière règle
    * résultal : renvoie un pointeur sur la règle en tête

```algo 
fonction : returnHeadBDC(BDConnaissances bdc) : Regle*
    returnHeadBDC <-- valeur(bdc)
fin fonction
```

*  supprimer récurivement toute la base de connaissance

* afficher la base de connaissances

* construire la base de connaissances et tout ces composantes à partir d'un fichier

## Moteur d'inférence

### Fonctionement général

on crée une liste chainée de proposition de type Premisse qui contiendra toute les propostion considéréer comme vrai, pou chaque proposition de cette liste, on cherche si elle font partie de la prémisse de chaque règle, si c'est le cas, on supprime la proposition de la prémisse et si la prémisse ne contient plus aucun élément alors on ajoute la conclusion de cette règle dans la liste des proposition vraie. Pour finir on affiche toute les propositions que on à réussi à conclure. 

### Definition des structures

### Fonctions associées

* moteurDInference : recherche à partir de la base de véritée et de la base de connaissances les propositions qui sont vraie

    * donnée : base de connaissance (une liste chainée règle), base de véritée  (liste chainée de proposition)
    * résultat : renvoie une liste chainée de proposition qui ont été déduite grace à l'éxécution de cette fonction

```algo
fonction : moteurDInference(Premisse baseVerite, BDConnaissances bdc) : Premisse

    Soit conclusion une Premisse
    Pour chaque proposition dans baseVerite
        Pour chaque regle dans bdc

            si (propositionDansPremisse(regle.premisse, proposition))
                setValidite(proposition, vraie)
                si (isPremisseTrue(regle.premisse)
                    addTailPremisse(conclusion, regle.conclusion)
                fin si
            fin si
        fin pour
    fin pour            

    affiche(conclusion)

fin fonction


```
