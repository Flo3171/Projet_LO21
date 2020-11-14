# ANALYSE DU SUJET

## Regle
### Definition des structures
* La structure de donnée abstraite qui va nous permetre représenter une Regle est composée de 2 sous éléments : la prémisse et la conclusion. 
    * Premisse est du type Premisse que nous définirons ci dessous.
    * Conclusion est de type Assertion que nous définirons ci dessous.

```c
struct Regle{
    Premisse premisse;
    Assertion conclusion;
}
```

* La structure de donnée abstraite qui va nous permetre de représenter une Premisse est une liste chainée d'Assertion. La Premisse est donc composé un pointeur sur le premier élément de la liste, un pointeur sur le dernier élément de la liste et une entier qui stocke le nombre d'élément dans la liste.
    * premierElem est de type pointeur sur PremisseElem que nous définirons ci-dessous
    * dernierElem est de type pointeur sur PremisseElem que nous définirons ci-dessous
    * nbElem est de type entier (long en C)

```c
struct Premisse{
    PremisseElem premierElem;
    PremisseElem dernierElem;
    long nbElem;
}
```

* La structure de donnée abstraite PremisseElem est constituer de 2 sous variables : la valeur et le pointeur sur l'élément suivant de la liste chainée suivant
    * valeur est de type Assertion que nous définirons ci-dessous
    * elemSuivant est un pointeur sur PremisseElem

```c
struct PremisseElem{
    Assertion valeur;
    struct PremisseElem *elemSuivant;
}
```

* La structure de donnée abstraite qui va nous peretre de stocker les Assertion (ou proposition) est composée de 2 sous variable : une inode et une description
    * inode est un entier qui permet d'identifier de manière unique l'assertion
    * description est une chaine de carractère (tableau de char en C) qui explicite en laguage naturel l'Assetion

```c
struct Assertion{
    long inode;
    char description[];
}
```


### Fonctions associées

* newRegle : créer une nouvele règle vide
    * donnée : rien
    * résultat : un pointeur sur la règle qui vient d'être créée

```algo
fonction : newRegle(): *Regle
    Soit nouvelRegle une Regle
    nouvelRegle.premise <-- newPremise()
    nouvelRegle.conclusion <-- NULL



```


* Créer une nouvelle prémise vide

* Ajouter une assertion à la prémisse d'une règle en queu

* Créer la conclusion d'une règle

* Tester si une assertion appartient à la prémisse d'une règle recursivement

* Supprimer une assertion de la prémisse d'une règle

* Tester si la prémisse d'une règle est vide

* Accéder à la proposition ce trouvante en tête d'une prémisse

* Accéder à la conclusion d'une règle

## Basse de connaissances
### Definition des structures

### Fonctions associées

## Moteur d'inférence
### Definition des structures

### Fonctions associées