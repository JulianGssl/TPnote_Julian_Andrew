#ifndef __FONCTION__H__
#define __FONCTION__H__

    /* Définition d'un Booléen*/
    typedef enum Bool
    {
        false,
        true
    }Bool;

    /* Définition d'un processus */
    typedef struct Processus
    {
        char name[4];
        double execution_time;
        int priority;
    }Processus;

    /* Définition d'un élement de l'ordonnanceur */
    typedef struct Element Element;
    struct Element
    {
        Processus Process;
        Element *suivant;
    }; 

    /* Définition d'un Ordonnanceur (liste) */
    typedef struct Ordonnanceur
    {
        Element *premier;
    }Ordonnanceur;



    /* Prototypes des fonctions */
    char* GenerateName(char *name);
    int GeneratePriority(void);
    float GenerateExecutionTime(void);
    int GenerateProcessus(Processus *p);

    Ordonnanceur *initialisation();
    Bool empty_ordonnanceur(Ordonnanceur *ordo);
    Ordonnanceur ajout_activite(Ordonnanceur *ordo, Processus p);
    void loading(float execuiontTime);
    void sort(Ordonnanceur *ordo);
    void step(Ordonnanceur *ordo); 
    void run(Ordonnanceur *ordo);

#endif