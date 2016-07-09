/*
    Auhtor: Jessica Authier
    2016/07/08
*/

#ifndef MERGESORT_H
#define MERGESORT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedlist.h"
#include "hashtable.h"
#include "initalize.h"

/*
    Purpose: to sort a linked list
    Preconditions: an initalized linked list exists
    Postconditions: the given linked list is sorted alphabetically and returned
*/
List * mergeSort(List * list);

/*
    Purpose: to take two lists and merge them into one list which is in alphabetical order
    Preconditions: two initalized lists are given as parameters 
    Postconditions: the new list is in alphabetical order
*/
List * mergeLists(Element * list1, Element * list2);

/*
    Purpose: to find the middle of a linked list so the list can be spilt in two
    Preconditions: an initalized linked list exists
    Postconditions: the element in the middle of the list is returned
*/
Element * bisectList(Element * head);

/*
    Purpose: to take two strings and detrmine which comes first in aphabetically
    Preconditions: two initalized strings exist
    Postconditions: 1 is returned if the first sting is first and 2 is returned if the second string comes first
*/
int compareNames(Element * first, Element * second);

#endif
