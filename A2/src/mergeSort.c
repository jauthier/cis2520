/*
    Auhtor: Jessica Authier
    2016/07/08
*/

#include "mergeSort.h"

List * mergeSort(List * list){
    
    Element * head = list->head;
    List * list1 = createList();
    List * list2 = createList();
    
    if (getLength(list)<2)
        return list;

    list1->head = head;
    list2->head = bisectList(head)->next;
    bisectList(head)->next = NULL;

    list1 = mergeSort(list1);
    list2 = mergeSort(list2);

    return mergeLists(list1->head, list2->head);
}

List * mergeLists(Element * list1, Element * list2){
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
        
        if (compareNames(list1, list2) == 1){//then list1 has the lower value
            temp = list1;
            list1 = list1->next;
            temp->next = NULL;
        } else{ // compareNames must have returned 2, thus list2 is lower or they are the same
            temp = list2;
            list2 = list2->next;
            temp->next = NULL;
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
        list1 = list1->next;
        temp->next = NULL;
        current->next = temp;
        current = temp;
    }
    
    while(list2 != NULL){
        Element * temp;
        temp = list2;
        list2 = list2->next;
        temp->next = NULL;
        current->next = temp;
        current = temp;
    }
    
    return result;
}

Element * bisectList(Element * head){
    
    List * temp = createList();
    temp->head = head;
    int len = getLength(temp);
    if (len < 2)
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