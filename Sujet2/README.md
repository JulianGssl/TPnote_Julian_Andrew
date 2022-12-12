# Sujet 2 : Ordonnancement de processus
## Répartition des fichiers

- **main.c** : Contient le programme principal
- **fonction.c** : Contient toutes les fonctions utilisé dans le projet
- **fonction.h** : Contient les structures et le protoypage des fonctions.
- **Makefile** : Makefile qui sert à compiler et à executer le programme.
  - Commandes du Makefile : 
    - `make` pour compiler.
    - `make prog` pour executer le programme.
    - `make clean` pour supprimer les fichiers objets.
    - `make cleanall` pour supprimer les fichiers objets et le fichier prog.

## Fonctionnement programme

Le programme génère

---
La priorité des processus a été définit comme suit :

  0. Temps réel
  1. Haute
  2. Supérieure à la normale
  3. Normale
  4. Inférieure à la normale
  5. Basse

La priorité est donc inversé, 0 étant le niveau ayant la plus haute priorité et inversement 5 ayant la plus faible.
