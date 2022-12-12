#include "structure.h"
#include "tableau.h"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <string.h> 
#include "distance.h"


void lecture(float tableau_logement[7918][9]){
    FILE *fichier=NULL;
    fichier=fopen("airbnb_donnees_propre.csv", "rt");
    char *ptr_chaine;
    char ligne[1024];
    if (fichier==NULL){
        printf("Erreur fopen\n");
        return ;
    }
    
    fgets(ligne,1024,fichier);
    int i=0;
        while ( fgets( ligne, 1024, fichier) != NULL ){
        ptr_chaine=strtok(ligne,",");
        ptr_chaine = strtok (NULL, ",");
        for (int j=0;j<8;j++){
            sscanf(ptr_chaine,"%f",&tableau_logement[i][j]);
            ptr_chaine = strtok (NULL, ",");
        }
        i++;
    }
    fclose(fichier);
}


void permuter(float *a, float *b) {
    float tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

void triRapid(float tab[][9], int first, int last) {
    int pivot, i, j;
    if(first < last) {
        pivot = first;
        i = first;
        j = last;
        while (i < j) {
            while(tab[i][8] <= tab[pivot][8] && i < last)
                i++;
            while(tab[j][8] > tab[pivot][8])
                j--;
            if(i < j) {
                for(int m=0;m<9;m++){
                    permuter(&tab[i][m], &tab[j][m]);
                }
            }
        }
        for(int m=0;m<9;m++){
        permuter(&tab[pivot][m], &tab[j][m]);
        }

        triRapid(tab, first, j - 1);
        triRapid(tab, j + 1, last);
    }
}

void randomiser(float tableau_logement[7918][9]){
    srand(time( NULL));
    int a;
    for (int i=0;i<7917;i++){
        a=rand()%7917;
        for (int j=0;j<8;j++){
            permuter(&tableau_logement[i][j],&tableau_logement[a][j]);          
        }
    }
}

void lecture_d( Logement_d tableau_logement[7917]){
    FILE *fichier=NULL;
    fichier=fopen("airbnb_donnees_propre.csv", "r");//on ouvre le fichier en lecture 
    char *ptr_chaine;
    char ligne[1024];//on définie la longueur max d'une ligne 
    if (fichier==NULL){//erreur si problème de l'ouverture du fichier 
        printf("Erreur fopen\n");
        return ;
    }
    
    fgets(ligne,1024,fichier);
    int i=0;
        while ( fgets( ligne, 1024, fichier) != NULL ){ //on prend la ligne du fichier tant que celui ci n'est as finie
        ptr_chaine=strtok(ligne,",");// on initialise le pointeur au début de la chaine de caractère 
        ptr_chaine = strtok (NULL, ",");// on passe le premier élément(numéros du logement)
        sscanf(ptr_chaine,"%d",&tableau_logement[i].accomodates);//on place le contenue de la premiere virgule a la seconde dans accomodate 
        ptr_chaine = strtok (NULL, ",");//on repart de la virugule suivante etc
        sscanf(ptr_chaine,"%d",&tableau_logement[i].bedrooms);
        ptr_chaine = strtok (NULL, ",");
        ptr_chaine = strtok (NULL, ",");
        sscanf(ptr_chaine,"%f",&tableau_logement[i].beds);
        ptr_chaine = strtok (NULL, ",");
        sscanf(ptr_chaine,"%f",&tableau_logement[i].price);
        ptr_chaine = strtok (NULL, ",");
        i++;
        }
    fclose(fichier);//fermeture du fichier 
}


void triRapid_d(Logement_d tab[], int first, int last) {
    int pivot, i, j;
    if(first < last) {
        pivot = first;
        i = first;
        j = last;
        while (i < j) {
            while(distance(tab[i]) <= distance(tab[pivot]) && i < last)
                i++;

            while(distance(tab[j]) > distance(tab[pivot]))
                j--;
            if(i < j) {
                permuter_d(&tab[i], &tab[j]);
            }

        }
        permuter_d(&tab[pivot], &tab[j]);
        triRapid_d(tab, first, j - 1);
        triRapid_d(tab, j + 1, last);
    }
}

void randomiser_d(Logement_d tableau_logement[7917]){
    srand(time( NULL));
    int a;
    for (int i=0;i<7917;i++){//on permute une fois chaque ligne du tableau vaec une ligne aléatoire 
        a=rand()%7916;
            permuter_d(&tableau_logement[i],&tableau_logement[a]);          
    }
}

void permuter_d(Logement_d *a, Logement_d *b) {// on permute les adresse des deux structure 
    Logement_d tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}