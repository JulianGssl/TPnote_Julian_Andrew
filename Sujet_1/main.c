#include "distance.h"
#include "tableau.h"
#include<stdio.h>
#include "structure.h"
#define K 50



int main(){
    /*float tableau_logement[7918][9];
    lecture(tableau_logement);
    printf("donner les caracteristique de x");
    for (int i=0;i<8;i++){
         if (i!=4){
        scanf("%f",&tableau_logement[7917][i]);
        }
    }
    tableau_logement[7917][8]=0;
    randomiser(tableau_logement);
    calcul_tableau_distance(tableau_logement);
    triRapid(tableau_logement,0,7916);
    for(int j=0;j<80;j++){
        printf("%f \n",tableau_logement[j][8]);     
    }
    float prix;
    prix=moyenne_k_pre(K,tableau_logement);
    printf("                    %f",prix);*/
    
    float prix;
    Logement_d tab[7917]; 
    lecture_d(tab); //On lie le fichier csv que l'on met dans le tableau de structure
    Logement_d x;
    printf("définir le logement accomodate bedrooms beds : "); // définition du logement x a comparer avec la liste
    scanf("%d",&x.accomodates);
    scanf("%d",&x.bedrooms);
    scanf("%f",&x.beds);
    randomiser_d(tab); // on randomise le tableau pour lisser les cas d'égalité de valeur de distance
    calcul_tableau_distance_d(tab,x);// on cacule les trois distance entre x et chaque logement pour chaque caractéristiue 
    triRapid_d(tab,0,7916);// on tris le tableau de structure par distance totale 
    prix=moyenne_k_pre_d(K,tab);// on fais la moyenne de pris des K premier éléments 
    printf("\nprix prédit : %f\n",prix);

}