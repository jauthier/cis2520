

#ifndef INITALIZE_H
#define INITALIZE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedlist.h"
#include "hashtable.h"

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
void menu(List * list, Entry ** ht);

Element * searchByValue(List * list, void * value);

/*
    Purpose:
    Preconditions:
    Postconditions:
*/
long getInputLong(char * message);

/*
    Purpose:
    Preconditions:
    Postconditions:
*/
char * getInputStr(char * message);

/*
    Purpose:
    Preconditions:
    Postconditions:
*/
Person * createPerson(char * ln, char * fn, long pn);

/*
    Purpose:
    Preconditions:
    Postconditions:
*/
List * loadFile(char * fileName, List *list, Entry ** ht);

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
