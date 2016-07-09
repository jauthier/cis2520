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
    Purpose:
    Preconditions:
    Postconditions:
*/
List * mergeSort(List * list);

/*
    Purpose:
    Preconditions:
    Postconditions:
*/
List * mergeLists(Element * list1, Element * list2);

/*
    Purpose:
    Preconditions:
    Postconditions:
*/
Element * bisectList(Element * head);

/*
    Purpose:
    Preconditions:
    Postconditions:
*/
int compareNames(Element * first, Element * second);

#endif
