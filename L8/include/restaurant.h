/*
    Restaurant Data Type
    
    Author: Jessica Authier
    07/26/2016
*/

#ifndef RESTAURANT_H
#define RESTAURANT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Restaurant {
    
    char * name;
    char * type;
    int rating; //0-5
    
} Restaurant;



Restaurant * createRestaurant(char * name, char * type, int rating);


void destroyRestaurant(void * toDestory);


int compareName(void * data1, void * data2);


int compareRating(void * data1, void * data2);

#endif
