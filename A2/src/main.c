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
    
    List *peopleList;
    peopleList = createList();
    Entry ** ht = create();
    
    if (argc = 2){
        fileName = argv[1];
        peopleList = loadFile(fileName, peopleList);
        peopleList = mergeSort(peopleList);
    }
    
    menu (peopleList, ht);
    
   return 0; 
}
