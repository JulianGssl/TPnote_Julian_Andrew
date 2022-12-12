# Sujet 2 : Ordonnancement de processus
## I.Répartition des fichiers

- **main.c** : Contient le programme principal
- **fonction.c** : Contient toutes les fonctions utilisé dans le projet
- **fonction.h** : Contient les structures et le protoypage des fonctions.
- **Makefile** : Makefile qui sert à compiler et à executer le programme.
  - Commandes du Makefile : 
    - `make` pour compiler.
    - `make run` pour executer le programme.
    - `make clean` pour supprimer les fichiers objets.
    - `make cleanall` pour supprimer les fichiers objets et le fichier prog.

## II.Fonctionnement du programme

Le programme demande à l'utilisateur de choisir *n* nombre de processus qu'il souhaite générer.

Ensuite le programme génère les *n* processus avec nom, priorité, temps d'éxécution aléatoire.

Le programme ajoute les processus un par un à l'ordonnanceur puis trie la file de processus par priorité puis par temps d'éxécution.

Pour valider le trie, lors du fonctionnement du programme, on affiche la priorité en plus.

Ainsi on obtiendra par exemple : 

---
La priorité des processus a été définit comme suit :

  0. Temps réel
  1. Haute
  2. Supérieure à la normale
  3. Normale
  4. Inférieure à la normale
  5. Basse

La priorité est donc inversé, 0 étant le niveau ayant la plus haute priorité et inversement 5 ayant la plus faible.
