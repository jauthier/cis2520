/*
    restaurantFunctions.c
    
    Author: Jessica Authier
    2016/08/01    
*/

#include "restaurantFunctions.h"

List * parseFile(char * fileName, List * list){
    
    FILE * fp;
    char *name, *type, *temp;
    int rating;
    char buffer[200];
    
    fp = fopen(fileName, "r");
    if (fp == NULL)
        printf("The file was not loaded.\n");
    
    while (fgets(buffer, 200, fp) != NULL){
        name = strtok(buffer, ",");
        type = strtok(NULL, ",");
        rating = strtol(strtok(NULL, ",\n"), &temp, 10);
        
        Restaurant * newRest = createRestaurant(name, type, rating);
        Element * newElement = createElement(newRest);
        list = addBack(list, newElement);
        
    }
    fclose(fp);
    return list;
}

void printRestaurant(void * toPrint) {
    Restaurant * temp = (Restaurant*) toPrint;
    printf("Name: %s\n",temp->name);
    printf("Type: %s\n", temp->type);
    printf("Rating: %d/5\n", temp->rating);
}

int maxHeight(Tree * tree){
    
    if (tree == NULL)
        return 0;
    int left = maxHeight(getLeftSubtree(tree));
    int right = maxHeight(getRightSubtree(tree));
    if (left < right)
        return right + 1;
    else
        return left + 1;
}

void printTree(Tree * tree, int level){
    
    Restaurant * root = getRootData(tree);
    
    Tree * right = getRightSubtree(tree); // set set the right side as a subtree
    Tree * left = getLeftSubtree(tree); // set set the left side as a subtree
    
    if (right != NULL) // if there is a node on the right
        printTree(right, level+1); // evaluate that node
    
    for (int i=0; i<(level*5); i++){
        printf(" ");
    }
    
    printf(" %s(%d)\n", root->name, root->rating);
    
    if (left != NULL) // if there is a node on the right
        printTree(left, level+1);
}
