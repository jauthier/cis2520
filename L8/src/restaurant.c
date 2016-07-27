/*
    Restaurant Data Type
    
    Author: Jesica Authier
    07/26/2016
*/

#include "restaurant.h"

Restaurant * createRestaurant(char * name, char * type, int rating) {
    
    Restaurant * newR;
    newR = malloc(sizeof (Restaurant));
    newR->name = malloc(sizeof(char)*strlen(name));
    stpcpy(newR->name, name);
    
    newR->type = malloc(sizeof(char)*strlen(type));
    stpcpy(newR->type, type);
    
    newR->rating = rating;
    
    return newR;
}

void destroy(Restaurant * toDestroy) {
    
    free(toDestroy->name);
    free(toDestroy->type);
    free(toDestroy);
}

int compareName(void * data1,void * data2){
    
    char *name1, *name2;
    
    name1 = (restaurant *)data1->name;
    name2 = (restaurant *)data2->name;
    
    if (strcmp(name1, name2) < 0) //name1 goes before name2
        return 1;
    else if (strcmp(name1, name2) == 0)//same name
        return 0;
    else 
        return -1;
}

int compareRating(void * data1, void * data2){
    
    int rating1, rating2;
    
    rating1 = (restaurant *)data1->rating;
    rating2 = (restaurant *)data2->rating;
    
    if (rating1 > rating2)
        return 1;
    else if (rating1 == rating2)
        return 0;
    else 
        return -1;
}
