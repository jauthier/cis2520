
#include <stdio.h>
#include "restaurant.h"
#include "restaurantFunctions.h"
#include "treeInterface.h"
#include "linkedlist.h"

int main(int argc, char *argv[]){
    
    char * fileName;
    if (argc > 1){
        fileName = argv[1];
    } else {
        printf("Please enter the name of a file.\n");
        exit(0);
    }
    
    Tree * nameTree = createBinTree(&compareName, &destroyRestaurant);
    Tree * ratingTree = createBinTree(&compareRating, &destroyRestaurant);
    List * list = createList();
    list = parseFile(fileName, list);
    
    
    
    Element * hold = list->head;
    while (hold != NULL){
        
        addToTree(nameTree, hold->elementPtr);
        addToTree(ratingTree, hold->elementPtr);
        
        hold = hold->next;
    }
    
    printf("Sort By Name\n------------\n");
    printInOrder(nameTree, &printRestaurant); // print in order
    printf("\n");
    printTree(nameTree, 0); // print as a tree
    printf("\n");
    
    printf("Sort By Rating\n---------------\n");
    printInOrder(ratingTree, &printRestaurant); //print in order
    printf("\n");
    printTree(ratingTree, 0); // print as a tree
    printf("\n");
    
    hold = list->head;
    while (hold != NULL){
        
        removeFromTree(nameTree, hold->elementPtr);
        removeFromTree(ratingTree, hold->elementPtr);
        
        hold = hold->next;
    }
    
    //destroyList(list);
    //destroyBinTree(nameTree);
    //destroyBinTree(ratingTree);
    
    return 0;
}