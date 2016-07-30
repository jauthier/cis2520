
#include <stdio.h>
#include "restaurant.h"
#include "linkedlist.h"

List * parseFile(char * fileName, List * list);
void printList(List * list);

int main(int argc, char *argv[]) {
    
    char * fileName;
    
    if (argc < 1){
        fileName = argv[1];
    } else {
        printf("Please enter the name of a file.\n");
        exit(0);
    }
    
    List * list = createList();
    list = parseFile(fileName, list);
    printList(list);
    
    return 0;
}

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

void printList(List * list) {
    
    Element * hold = list->head;
    
    while (hold != NULL){
        Rsetaurant * temp = (Restaurant *)hold->elementPtr;
        printf("%s, %s, %d\n", temp->name, temp->type, temp->rating);
        
    }
}
