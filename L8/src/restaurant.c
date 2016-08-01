/*
    Restaurant Data Type
    
    Author: Jesica Authier
    08/01/2016
*/

#include "restaurant.h"

Restaurant * createRestaurant(char * name, char * type, int rating) {
    
    Restaurant * newR;
    newR = malloc(sizeof (Restaurant));
    newR->name = malloc(sizeof(char)*strlen(name));
    strcpy(newR->name, name);
    
    newR->type = malloc(sizeof(char)*strlen(type));
    strcpy(newR->type, type);
    
    newR->rating = rating;
    
    return newR;
}

void destroyRestaurant(void * toDestroy) {
    
    Restaurant * temp = (Restaurant *)toDestroy;
    free(temp->name);
    free(temp->type);
    free(temp);
}

int compareName(void * data1,void * data2){
    
    char *name1, *name2;
    
    name1 = ((Restaurant *)data1)->name;
    name2 = ((Restaurant *)data2)->name;
    
    if (strcmp(name1, name2) < 0) //name1 goes before name2
        return 1;
    else if (strcmp(name1, name2) == 0)//same name
        return 0;
    else 
        return -1;
}

int compareRating(void * data1, void * data2){
    
    int rating1, rating2;
    
    rating1 = ((Restaurant *)data1)->rating;
    rating2 = ((Restaurant *)data2)->rating;
    
    return rating1 - rating2;
}
