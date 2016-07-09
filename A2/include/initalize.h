

#ifndef INITALIZE_H
#define INITALIZE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedlist.h"

typedef struct Person{
    
    char *firstName;
    char *lastName;
    long phoneNum;
    
}Person;


/*
    Purpose:
    Preconditions:
    Postconditions:
*/
List * loadFile(char * fileName, List *list);

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

/*
    Purpose:
    Preconditions:
    Postconditions:
*/
void printList(List * list);


#endif
