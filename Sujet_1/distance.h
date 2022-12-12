
#ifndef H_X
#define H_X
#include "structure.h"
float calcule_distance(int y,float tableau_logement[7918][9]);
void calcul_tableau_distance(float tableau_logement[7918][9]);
float moyenne_k_pre(int K,float tableau_logement[7918][9]);
void calcul_tableau_distance_d( Logement_d tab[7917], Logement_d x);
float distance(Logement_d logement);
float moyenne_k_pre_d(int K,Logement_d tableau_logement[7917]);
#endif