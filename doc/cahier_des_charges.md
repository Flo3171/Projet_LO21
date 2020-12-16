Cahier des charges: Projet LO21

Contextes et définition du problème

Le sujet de ce projet est de réaliser un système expert fonctionnel. D'après la définition donnée par la page Wikipédia sur ce sujet, un système expert est : "un logiciel capable de répondre à des questions, en effectuant un raisonnement à partir de faits et de règles connues."(source : https://fr.wikipedia.org/wiki/Syst%C3%A8me_expert). Pour cela le système expert va se comporter comme un humain expert dans un domaine d'activité comme la médecine ou l'automobile. En effet pour établir un diagnostic ou une analyse l'humain va faire des observation et à partir de ces observation il va appliquer des règles qu'il a apprise lors de sa formation ou par son expérience pour en tirer des déduction, comme par exemple la maladie dont souffre un patient dans le cas d'un médecin ou le problème qu'a la voiture pour un garagiste. Le système expert est donc composé de trois élément principaux, le premier est la base de connaissances. La base de connaissance permet de stocker toutes les règle qui permettront au programme de faire des déductions. Le second élément est la base de fait, elle permet de stocker les propositions qui sont considérée comme vrai au lancement du programme. Le dernier élément est le moteur d'inférence, c'est lui qui est chargé à partir de la base de connaissances et de la base de fait de déduire toute les proposition qui sont vraies.

Objectif du projet

L'objectif de ce projet est de développer une programme capable de remplir les fonction d'un système expert. Le projet doit pouvoir permettre à l'utilisateur de créer ou importer une base de connaissances, puis après avoir répondu à des questions permettant d'établir la base de fait de connaitre les résultats qui peuvent en être déduit. On souhaiterait permettre à un utilisateur n'ayant pas de connaissances en informatique de pouvoir utiliser notre projet une fois qu'il a été configuré en fonction de la situation.

Périmètre du projet

Le projet devra être réaliser en langage C et s'exécuter dans la console. Il sera au maximum portable c'est à dire capable de fonctionner sous différent systèmes d'exploitation (linux et Windows au moins). La vitesse d'exécution et la place prise en mémoire sera optimiser afin d'obtenir un programme le plus efficace possible. Nous limiterons les règle contenue dans la base de connaissances à des règle du type "A et B et ... implique C" et nous utiliserons uniquement les implication directe, pas de réciprocité ou de contraposée. 

Description fonctionnelle des besoins

•	Définir des structure de données abstraite pour les objets suivant : Proposition, Prémisse, Règle, Base de connaissance, Base de fait.

•	Implémenter les sous programmes permettant de manipuler les structure

•	Permettre à l'utilisateur de créer et de stocker une base de connaissances

•	Permettre à l'utilisateur de répondre au question et de créer la base de fais en fonction des réponses.

•	Implémenter le sous-programme qui remplit la fonction du moteur d'inférence

•	Afficher à l'utilisateur le contenue de la base de connaissance et les résultat du moteur d'inférence



Contrainte/ Normalisation et documentation du code

•	Le programme doit respecter la norme C99

•	Chaque fonction ou structure doit être documentée selon la formalisation imposée par doxigène. Ainsi une documentation du code sera générée par doxigène

•	Les fonction seront dans la mesure du possible implémenté de manière récursive

•	Les variable sont en normalisation CamelCase et les nom de structure commences par une majuscule

•	Le projet est versionner avec git et héberger sur git hub

•	La génération des make file et la compilation du programme ce fait avec Cmake

•	Le temps d'exécution et l'espace mémoire utilisé par le programme devront rester acceptable pour que le programme soit utilisable sur le plus grand nombre de machine
