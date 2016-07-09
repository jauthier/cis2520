

#ifndef INITALIZE_H
#define INITALIZE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedlist.h"
#include "hashtable.h"
#include "mergeSort.h"

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
void menuLoop(List * list, Entry ** ht);

void printMenu();

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
void printList(List * list);


#endif
