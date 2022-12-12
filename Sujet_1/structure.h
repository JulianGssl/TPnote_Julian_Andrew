#ifndef NOM_DU_FICHIER_H
#define NOM_DU_FICHIER_H
typedef struct  {
    int accomodates;
    int bedrooms;
    float beds;
    float price;
    float tableau_dist[3];
}Logement_d;
struct logement {
    int accomodates;
    int bedrooms;
    float bathrooms;
    float beds;
    float price;
    int min_nights;
    int max_nights;
    int number_reviews;
    float distance;
};
#endif

