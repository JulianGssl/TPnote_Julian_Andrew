# Sujet 1 Prédiction prix Airbnb
Le sujet est réparti de la façon suivante :
- **main.c** : Contient le programme principal
- **tableau.c** : Contient toutes les fonctions qui crée et modifie le tableau de structure 
- **structure.h** : Contient les structures logement et logement_d pour la question d.
- **Makefile** : Makefile qui sert à compiler et à exécuter le programme.
  les commandes du Makefile sont make et make clean
  
  Le programme fonctionne comme suit :
    Le programme découpe chaque ligne du document csv en donné délimité par des virgule pour les mettres dans les cases du tableau de structure 
    
    Le programme demande à l'utilisateur de donner les différentes caractéristique du logement (dans la première partie dans l'ordre : accommodates bedrooms bathrooms beds minimum nights maximum nights number of reviews et dans la question d uniquement accommodates bedrooms et beds)
    
    Le programme randomise le tableau de structure pour lisser les cas d'égalité de distance puis calcul la distance entre le logement décrit et chaque logement du fichier csv avant d'être triées par distance croissante.
    
    Le programme calcul ensuite la moyenne des prix des K premier logement afin de donner le prix prédit du logement définis par l'utilisateur.
