/*
    Author: Jessica Authier
    2016/07/08
*/

#include "initalize.h"

List * loadFile(char * fileName, List *list){
    
    FILE * fp;
    char *firstName, *lastName, *phoneNum;
    char buffer[60];
    
    fp = fopen(fileName, "r");
    if (fp == NULL){
        printf("File not found!\n");
        exit(0);
    }
    
    fgets(buffer, 60, fp);
    
    while (buffer != NULL){
        
        lastName = strtok(buffer, ",");
        firstName = strtok(NULL, ",");
        phoneNum = strtok(NULL, ",");
        
        Person * newPerson = malloc(sizeof(Person));
        newPerson->lastName = lastName;
        newPerson->firstName = firstName;
        newPerson->phoneNum = phoneNum;
        
        Element newElement = createElement(newPerson);
        
        //add to a list of people
        list = addBack(list, newElement);
        return list;
    }
    fclose(fp);
}

List * mergeSort(List * list){
    
    Element * head = list->head
    Element * list1, * list2;
    
    if (getLength(list)<2)
        return list;
    
    list1 = head;
    list2 = bisectList(head)->next;
    bisectList(head)->next = NULL;
    
    list1 = mergeSort(list1)->head;
    list2 = mergeSort(list2)->head;
    
    return mergeLists(list1, list2);
}

Element * mergeLists(Element * list1, Element * list2){
    List * result  = createList();
    Element * current = NULL;
    
    if (list1 == NULL){
        result->head = list1;
        return result;
    }
    
    if (list2 == NULL){
        result->head = list2;
        return result;
    }
    
    while (list1 != NULL && list2 != NULL){
        Element * temp;
        //compare the first elements of each list
        
        if (compareNames(list1, list2) == 1){//then list1 has the lower value
            temp = list1;
            temp->next == NULL;
            list1 = list1->next;
        } else{ // compareNames must have returned 2, thus list2 is lower or they are the same
            temp = list2;
            temp->next = NULL;
            list2 = list2->next;
        }
        if (result->head == NULL){ // if there are no elements in the result yet
            result->head = temp; // set the new element to be the first
            current = result->head; // and set the current pointer to it
        } else { // if there are elements in the result
            current->next = temp; // add the new element after the current
            current = temp; // and switch the current pointer
        }
    }
    
    while (list1 != NULL){
        Element * temp;
        temp = list1;
        temp->next = NULL;
        current->next = temp;
        current = temp;
        list1 = list1->next;
    }
    
    while(list2 != NULL){
        Element * temp;
        temp = list2;
        temp->next = NULL;
        current->next = temp;
        current = temp;
        list1 = list2->next;
    }
    return result;
}

Element * bisectList(Element * head){
    
    List * temp = createList();
    temp->head = head;
    int len = getLength(temp);
    if (len > 2)
        return NULL;
    else {
        if (len%2 == 0){ // even number of elements
            len = len/2 - 1;
        } else {
            len = len/2;
        }
        for (int i=0; i<len; i++){
            head = head->next;
        }
        return head;
    }
}

int compareNames(Element * first, Element * second){
    
    char * name1 = ((Person *)first->elementPtr)->lastName;
    char * name2 = ((Person *)second->elementPtr)->lastName;
    
    if (strcmp(name1, name2)<0)
        return 1;
    else
        return 2;
}
