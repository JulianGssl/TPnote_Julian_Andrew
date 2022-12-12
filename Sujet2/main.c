#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "fonction.h"

int main()
{
    srand(time(NULL)); // Initialisation du générateur de nombre aléatoire

    // On demande à l'utilisateur combien de processus il veut dans l'ordonnanceur
    printf("Veuillez entrer le nombre de processus à générer: ");
    int nb_process;
    scanf("%d", &nb_process);

    // On initalise l'ordonnanceur
    Ordonnanceur *ordo = initialisation();

    // On génère le nombre de processus demandé par l'utilisateur et on les ajoutes dans l'ordonnanceur
    for (int i = 1; i <= nb_process; i++)
    {   
        Processus p;
        GenerateProcessus(&p);
        ajout_activite(ordo, p);
        sort(ordo);
    }

    // On fait un tour de l'ordonnanceur tant qu'il n'est pas vide
    run(ordo);
    return 0;
}