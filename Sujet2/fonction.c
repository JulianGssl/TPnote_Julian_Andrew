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
    printf("\033[?25l");  // on cache le curseur
    time(&start);
    while(1) {
        for (i = 0; i < 4; i++) {
            printf("\33[2K\r");          // on efface la ligne
            printf("[");      
            for (j = 0; j < 10; j++) {  // largeur de l'animation 
                printf("%c", a[i]);
            }
			printf("]");
            fflush(stdout);
            nanosleep(&delay, NULL);
        }
        // stop après que executionTime soit atteint
        time(&now);
        if (difftime(now, start) >= executionTime ) 
        {
            printf("\33[2K\r");  // on efface la ligne
            printf("Done.\n");
            break;
        }
    }
    printf("\033[?25h"); // on restaure le curseur
}
//--------------------------------------------------------------//


//  Fonction qui trie les processus dans l'ordonnanceur par ordre de priorité //
void sort(Ordonnanceur *ordo)
    {
    struct Element *node, *temp;
    Processus tempProcess;//temp variable to store node data
    node = ordo->premier;
    while(node != NULL)
    {
        temp=node; 
        while (temp->suivant !=NULL)//travel till the second last element 
        {
            if(temp->Process.priority > temp->suivant->Process.priority)// compare the priority of the process 
            {
                tempProcess = temp->Process;
                temp->Process = temp->suivant->Process;// swap the data
                temp->suivant->Process = tempProcess;
            }
            if((temp->Process.priority == temp->suivant->Process.priority) && temp->Process.execution_time > temp->suivant->Process.execution_time)
            {
                tempProcess = temp->Process;
                temp->Process = temp->suivant->Process;// swap the data
                temp->suivant->Process = tempProcess;
            }
         temp = temp->suivant;    // move to the next element 
        }
        node = node->suivant;    // move to the next node
    }
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
	printf(" Temps d'execution: [%.2f] |", actuel->Process.execution_time);
    printf(" Priorité: [%d]\n", actuel->Process.priority);
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