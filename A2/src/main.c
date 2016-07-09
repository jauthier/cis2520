/*
    Author: Jessica Authier
    2016/07/08
*/

#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"
#include "initalize.h"

int main(int argc, char * argv[]){
    
    char *fileName;
    
    //get command line input
    if (argc != 2){
        printf("Please enter the name of the file you wish to load.\n");
        exit(0);
    }
    fileName = argv[1];
    
    //create a linked list of people
    List *peopleList;
    peopleList = createList();
    
    //load in the people from the file
    peopleList = loadFile(fileName, peopleList);
    printf("here\n");
    printList(peopleList);
    //sortList
    List * sortedList = createList();
    sortedList = mergeSort(peopleList);
    // use the list to make the hash table
    printList(sortedList);
    
    
   return 0; 
}
