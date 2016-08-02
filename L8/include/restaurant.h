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


/*
    Purpose: to initalize and allocate memory for a Restaurant variable and return it to the calling function
    Preconditions: name(char *), type(char *) and rating(int) must be passed as parameters
    Postconditions: Restaurant data type is created and returned
*/
Restaurant * createRestaurant(char * name, char * type, int rating);

/*
    Purpose: to destory a Restaurant variable and free the memory it was using
    Preconditions: an initalized Restaurant variable
    Postconditions: the Restaurant variable is destoryed and its memory is freed
*/
void destroyRestaurant(void * toDestory);

/*
    Purpose: to compare two Restaurant variables by name, returning 1 if the first variable comes first in alphabetical
    order, 0 if the names are identical, and -1 if the second variable comes first in alphabetical order
    Preconditions: two initalized Restaurant vaibles exist
    Postconditions: none
*/
int compareName(void * data1, void * data2);

/*
    Purpose: to compare two Restaurant variables by rating, returning >0 if the first rating is greater than the second, 0
    if the two ratings are equal, and <0 if the second rating is greater than the first.
    Preconditions: two initalized Restaurant vaibles exist
    Postconditions: none
*/
int compareRating(void * data1, void * data2);

#endif
