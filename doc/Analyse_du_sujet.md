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
    nouvelRegle.premise <-- newPremise()
    nouvelRegle.conclusion <-- NULL
fin fonction
```

* deleteRegle : suprimer une règle et toutes ces composantes (fait)
    * donnée : regleToDelete, un pointeur sur règle, la règle que l'on veut supprimer
    * résultat : supprime de la mémoire la règle

```algo
procédure : deletRegle(Regle *regleToDelete)
    deletePremisse(regleToDelete.premisse)
    deleteProposition(regleToDelete.conclution)
    libère(regleToDelete)
fin procédure
```


* newPremisse : réer une nouvelle prémise vide (fait)
    * donné : rien
    * résultat : un pointeur sur la prémisse qui viens d'être créée
```algo
trivial
```

* deletePremisse : supriemer de la mémoire une prémisse et toutes ces variables associée
    * donné : un pointeur sur la prémisse à supprimer
    * résutat : supprime de la mémoire la prémisse
```algo
trivial
```


* Ajouter une Proposition à la prémisse d'une règle en queue
    * donnée : la proposition à ajouter et la Prémisse à laquelle l'ajouter
    * résutat : ajoute la proposion à la liste chainé en queue en faisant le lien entre les élément
```algo
procédure : addTailPremisse(Prémisse* premisse, Proposition proposition)
    Soit newElemPremisse un PremisseElem;
    newElemPremisse.valeur <-- propositon
    newElemPremisse.suivant <-- NULL;
    premisse.dernierElem.suivant <-- newElemPremisse
    premisse.derinerElem <-- newElemPremisse
    premisse.nbElem <-- premisse.nbElem + 1
fin procédure
```

* Créer la conclusion d'une règle

* propositionDansPremisse: Tester si une Proposition appartient à la prémisse d'une règle recursivement
    * donnée : un pointeur sur le premier élément de la prémisse dans laquel on veut rechercher, la propositon à rechercher
    * résulat : renvoie 1 si la proposion à été trouvée dans la prémisse et 0 sinon




* Supprimer une Proposition de la prémisse d'une règle

* Tester si la prémisse d'une règle est vide

* Accéder à la proposition ce trouvante en tête d'une prémisse

* Accéder à la conclusion d'une règle

## Basse de connaissances
### Definition des structures

### Fonctions associées

## Moteur d'inférence

### Fonctionement général

on crée une liste chainée de proposition de type Premisse qui contiendra toute les propostion considéréer comme vrai, pou chaque proposition de cette liste, on cherche si elle font partie de la prémisse de chaque règle, si c'est le cas, on supprime la proposition de la prémisse et si la prémisse ne contient plus aucun élément alors on ajoute la conclusion de cette règle dans la liste des proposition vraie. Pour finir on affiche toute les propositions que on à réussi à conclure. 

### Definition des structures

### Fonctions associées

* moteurDInference : recherche à partir de la base de conaissannce et de la liste de règles les proposition qui sont vraie

    * donnée : base de connaissance (une liste chainée de proposition), liste de règles (liste chainée de règle)
    * résultat : renvoie une liste chainée de proposition qui ont été déduite grace à l'éxécution de cette fonction

```algo
fonction : moteurDInference(Premisse baseConnaissance, ListeRegle) : Premisse

    Soit conclusion une Premisse
    Pour chaque proposition dans baseConnaissance
        Pour chaque regle dans ListeRegle

            si (propositionDansPremisse(regle, proposition))
                supprimeUneProposition(regle, proposition)

                si (premisseVide(regle))
                    addTailPremisse(conclusion, regle.conclusion)
                fin si
            fin si
        fin pour
    fin pour            

    affiche(conclusion)

fin fonction


```
