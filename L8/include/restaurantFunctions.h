/*
    restaurantFunctions.c
    
    Author: Jessica Authier
    2016/08/01    
*/

#ifndef RESTAURANTFUNCTIONS_H
#define RESTAURANTFUNCTIONS_H

#include <stdio.h>
#include "restaurant.h"
#include "treeInterface.h"
#include "linkedlist.h"

/*
    Purpose: to read the contents of a text file and put the contents into a List of type Restaurant*
    Preconditions: a text file of the appropriate format is passed as a parameter
    Postconditions: the contents is put into an initalized List and returned to the calling function
*/
List * parseFile(char * fileName, List * list);

/*
    Purpose: to print the contents of the restaurant data type
    Preconditions: an initalized restaurant variable
    Postconditions: none
*/
void printRestaurant(void * toPrint);

/*
    Purpose: to return the max length of the tree (the length of the longest branch)
    Preconditions: an initalized binary tree
    Postconditions: none
*/
int maxHeight(Tree * tree);

/*
    Purpose: to print the contents of a binary tree, in tree form
    Preconditions: an initalized, non-empty binary tree exists
    Postconditions: none
*/
void printTree(Tree * tree, int level);

#endif
