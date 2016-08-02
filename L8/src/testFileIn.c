
#include <stdio.h>
#include "restaurant.h"
#include "linkedlist.h"
#include "restaurantFunctions.h"

void printList(List * list);

int main(int argc, char *argv[]) {
    
    char * fileName;
    if (argc > 1){
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

void printList(List * list) {
    
    Element * hold = list->head;
    
    while (hold != NULL){
        Restaurant * temp = (Restaurant *)hold->elementPtr;
        printf("%s, %s, %d\n", temp->name, temp->type, temp->rating);
        hold = hold->next;
    }
}
