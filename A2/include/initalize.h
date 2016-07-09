/*
    Author: Jessica Authier
    2016/07/08
*/

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
    Purpose: to loop through the menu and action selection until the user wishes to exit
    Preconditions: an initalized linked list and hash table
    Postconditions:
*/
void menuLoop(List * list, Entry ** ht);

/*
    Purpose: to print the menu text
    Preconditions: none
    Postconditions: none
*/
void printMenu();

/*
    Purpose: to seach through a linked list and return the element that's elementPtr equals the void* given 
    Preconditions: an initalized linked list which contains an Element matching the void* given as a parameter 
    Postconditions: none
*/
Element * searchByValue(List * list, void * value);

/*
    Purpose: to return user input of type long
    Preconditions: none
    Postconditions: the message  given as a parameter is printed
*/
long getInputLong(char * message);

/*
    Purpose: to return user input of type char* (string)
    Preconditions: none
    Postconditions: the message  given as a parameter is printed
*/
char * getInputStr(char * message);

/*
    Purpose: to initalize a Person variable and set its vales to the values passed as parameters
    Preconditions: none
    Postconditions: a Person variable is created an is allocated the right amount of memory
*/
Person * createPerson(char * ln, char * fn, long pn);

/*
    Purpose: to take the name of a file and load the contents of the file into a linked list
    Preconditions: a properly formated file is given
    Postconditions: each line of the file is used to create a person and is added to the list
*/
List * loadFile(char * fileName, List *list, Entry ** ht);

/*
    Purpose: to print a linked list that has elementPtr's of type Person
    Preconditions: an initalized none empty linked list
    Postconditions: none
*/
void printList(List * list);


#endif
