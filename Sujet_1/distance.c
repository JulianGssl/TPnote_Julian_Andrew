#include "structure.h"
#include <math.h>
#include<stdio.h>
#include "tableau.h"
#include "distance.h"
float calcule_distance(int y,float tableau_logement[7918][9]){
    float distance=0;
    for (int i=0;i<8;i++){
        if(i!=4){
            distance+=pow((tableau_logement[7917][i]-tableau_logement[y][i]),2);      
        }
    }
    distance=sqrtf(distance);
    return distance;
}

void calcul_tableau_distance(float tableau_logement[7918][9]){
    for (int i=0;i<7917;i++){
        tableau_logement[i][8]=calcule_distance(i,tableau_logement);
    }
}

float moyenne_k_pre(int K,float tableau_logement[7918][9]){
    float s=0;

    for (int i=0;i<K;i++){
        s+=tableau_logement[i][4];
    }
    s=s/K;
    return s;
}
void calcul_tableau_distance_d(Logement_d tab[7917],Logement_d x){
    for (int i=0;i<7917;i++){//on calcule la différence carré entre chaque caractéristique du logement et x avant de le placer dans sa case du tableau de distance 
        tab[i].tableau_dist[0]= pow((tab[i].accomodates-x.accomodates),2); 
        tab[i].tableau_dist[1]= pow((tab[i].bedrooms-x.bedrooms),2); 
        tab[i].tableau_dist[2]= pow((tab[i].beds-x.beds),2); 
    }
}

float distance(Logement_d logement){
    float s=0;
    for(int j=0;j<3;j++){//on somme les 3 carré de distance pour obtenir la distance totale au carré
        s+=logement.tableau_dist[j];
    }
    return sqrtf(s);//on renvoie la racine carré pour obtenir la distance totale du logement et x
}
float moyenne_k_pre_d(int K,Logement_d tableau_logement[7917]){
    float s=0;
    for (int i=0;i<K;i++){// on somme les pric des K premier éléments du tableau
        s+=tableau_logement[i].price;

    }
    s=s/K;
    return s;
}