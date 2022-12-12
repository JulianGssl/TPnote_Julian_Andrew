#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "fonction.h"

//--------------------------------------------------------------//
//  Génère aléatoirement un mot de 4 lettres //
char* GenerateName(char *name)
{ 
    static const int namelen = 4;
	
	static const char* letters[2] = { "bcdfghjklmnpqrstvwxz", "aeiouy" };
	static const int letterlen[2] = { 20, 6 };
    
	for (int i=0; i<namelen; i++)
    {
        int j = rand();
		name[i] = letters[j%2][random()%letterlen[j%2]];
    }
	name[0] = toupper(name[0]);
    
    return name;
}
//--------------------------------------------------------------//


//  Génère aléatoirement un chiffre compris entre 0 et 5  //
int GeneratePriority(void)
{
    int priority = rand()%6;
    return priority;
}
//--------------------------------------------------------------//


//  Génère aléatoirement un mot nombre flottant compris entre 0 et 5  //
float GenerateExecutionTime(void)
{
    float executionTime = 5 * ((float)rand()/RAND_MAX);
    return executionTime;
}
//--------------------------------------------------------------//


//  Génère un processus avec un nom, une priorité, un temps d'éxécution aléatoire  //
int GenerateProcessus(Processus *p)
{
    char* GeneName = (char*)malloc(sizeof(char)*4);
	GenerateName(GeneName);
    strcpy(p->name, GeneName);
    p->priority = GeneratePriority();
    p->execution_time = GenerateExecutionTime();
	free(GeneName);
    return 0;
}
//--------------------------------------------------------------//


//  Fonction qui test si l'ordonnanceur est vide  //
Bool empty_ordonnanceur(Ordonnanceur *ordo)
{
	if(ordo == NULL)
		return true;

	return false;
}
//--------------------------------------------------------------//


//  Fonction qui initialise un ordonnanceur (une liste)  //
Ordonnanceur *initialisation()
{
    Ordonnanceur *ordo = malloc(sizeof(*ordo));
    Element *element = malloc(sizeof(*element));

    if (ordo == NULL || element == NULL)
    {
        exit(EXIT_FAILURE);
    }

    element->suivant = NULL;
    //ordo->premier->Process.priority = 0;

    return ordo;
}
//--------------------------------------------------------------//


//  Fonction  //
void sort(Ordonnanceur *ordo)
{
	Element *index;
	Processus temp;
	while(ordo->premier != NULL)
	{
		index = ordo->premier->suivant;

		while(index!=NULL)
		{
			if(ordo->premier->Process.priority > index->Process.priority)
			{
				temp = ordo->premier->Process;
				ordo->premier->Process = index->Process;
				index->Process = temp;
			}
			index = index->suivant;
		}
		ordo->premier = ordo->premier->suivant;
	}
}
//--------------------------------------------------------------//


//  Fonction qui ajoute un processus à l'ordonnanceur  //
Ordonnanceur ajout_activite(Ordonnanceur *ordo, Processus p)
{
	/* Création nouvel élément/processus */
	Element *nouveau = malloc(sizeof(*nouveau));

	if(ordo == NULL)
	{
		fprintf(stderr, "Erreur : probleme allocation dynamique.\n");
		exit(EXIT_FAILURE);
	}
	if(empty_ordonnanceur(ordo))
	{	
		initialisation();
	}
	/* Allocation du processus au nouvelle élément */
	nouveau->Process = p;
	/* Insertion de l'élement au début de la liste */
	nouveau->suivant = ordo->premier;	
	ordo->premier = nouveau;
}
//--------------------------------------------------------------//


//  Fonction qui supprime un processus de l'ordonnanceur  //
void suppression(Ordonnanceur *ordo)
{
    if (ordo == NULL)
    {
        exit(EXIT_FAILURE);
    }

    if (ordo->premier != NULL)
    {
        Element *aSupprimer = ordo->premier;
        ordo->premier = ordo->premier->suivant;
        free(aSupprimer);
    }
}
//--------------------------------------------------------------//


//  Fonction qui affiche une animation de chargement le temps que le processus finisse son temps d'éxécution  //
void loading(float executionTime)
{
    int i, j, ms = 250;    
    const char *a = "|/-\\";
    time_t start, now;
    struct timespec delay;
    delay.tv_sec = 0;
    delay.tv_nsec = ms * 500000;
    printf("\033[?25l");  // hide the cursor
    time(&start);
    while(1) {
        for (i = 0; i < 4; i++) {
            printf("\33[2K\r");          // clear line
            printf("[");      
            for (j = 0; j < 10; j++) {  // 10 character terminal width
                printf("%c", a[i]);
            }
			printf("]");
            fflush(stdout);
            nanosleep(&delay, NULL);
        }
        // stop after executionTime is reached
        time(&now);
        if (difftime(now, start) >= executionTime ) 
        {
            printf("\33[2K\r");  //clear line
            printf("Done.\n");
            break;
        }
    }
    printf("\033[?25h"); // restore the cursor
}
//--------------------------------------------------------------//


//  Fonction qui fait un tour de l'ordonnanceur et affiche les caractéristiques du processus en cours  //
void step(Ordonnanceur *ordo)
{
	if(empty_ordonnanceur(ordo))
	{
		printf("Rien a afficher, l'Ordonnanceur est vide.\n");
		return;
	}

	Element *actuel = ordo->premier;
	
	printf("Processus: [%s] |", actuel->Process.name);
	printf(" Temps d'execution: [%.2f]\n", actuel->Process.execution_time);
	loading(actuel->Process.execution_time);
	printf("\n");

	actuel = actuel->suivant;
	suppression(ordo);
}
//--------------------------------------------------------------//


//  Fonction qui défile les processus de l'ordonnanceur jusqu'à ce qu'il soit vide  //
void run(Ordonnanceur *ordo)
{
	while(ordo->premier != NULL)
	{
		step(ordo);
	}
}
//-------------------------------------------------------------//