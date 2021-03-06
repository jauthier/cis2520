/*
    Author: Jessica Authier
    2016\05\27
*/
#include <stdio.h>
#include "linkedlist.h"

int main(int argc, char *argv[]){
    
    List * testList;
    testList = createList(); //test createList
    if (testList == NULL)
        printf("the list was not created!\n\n");
    
    
    int first, second, third, len;
    Element *e1, *e2, *e3, *e4;
    char c = '!';
    
    first = 1;
    second = 2;
    third = 3;
    
    e1 = createElement(&first);
    e2 = createElement(&second);
    e3 = createElement(&third);
    e4 = createElement(&c);
    
    printf("the value: %c\n\n", *(char*)e4->elementPtr);
    
    /*  testing addFront, addBack, getLength and getFront:
    should print out:
    the list has 1 element(s)
    The first element: 1
    the list has 2 element(s)
    The first element: 2
    the list has 3 element(s)
    The first element: 2
    */
    testList = addFront(testList, e1);
    len = getLength(testList);
    printf("the list has %d element(s)\n", len);
    Element * temp = getFront(testList);
    printf("The first element: %d\n", *(int *)temp->elementPtr);
    
    testList = addFront(testList, e2);
    len = getLength(testList);
    printf("the list has %d element(s)\n", len);
    temp = getFront(testList);
    printf("The first element: %d\n", *(int *)temp->elementPtr);
    
    testList = addBack(testList, e3);
    len = getLength(testList);
    printf("the list has %d element(s)\n", len);
    temp = getFront(testList);
    printf("The first element: %d\n\n", *(int *)temp->elementPtr);
    
    // check the last element is 3
    printf ("The last element: %d\n\n", *(int*)testList->head->next->next->elementPtr );
    
    /*  testing removeBack:
    should print out:
    The element removed: 3
    the list has 2 element(s)
    The first element: 2
    
    The element removed: 1
    the list has 1 element(s)
    The first element: 2
    
    The element removed: 2
    the list has 0 element(s)
    The list is empty!
    */
    
    temp = removeBack(testList);
    printf("The element removed: %d\n", *(int *)temp->elementPtr);
    len = getLength(testList);
    printf("the list has %d element(s)\n", len);
    temp = getFront(testList);
    printf("The first element: %d\n", *(int *)temp->elementPtr);
    
    temp = removeBack(testList);
    printf("The element removed: %d\n", *(int *)temp->elementPtr);
    len = getLength(testList);
    printf("the list has %d element(s)\n", len);
    temp = getFront(testList);
    printf("The first element: %d\n", *(int *)temp->elementPtr);
    
    temp = removeBack(testList);
    printf("The element removed: %d\n", *(int *)temp->elementPtr);
    len = getLength(testList);
    printf("the list has %d element(s)\n", len);
    temp = getFront(testList);
    if (temp == NULL) 
        printf("The list is empty!\n");
    temp = removeBack(testList);
    
    testList = addBack(testList, e1);
    testList = addBack(testList, e2);
    
    /*  testing removeFront:
    should print out:
    The element removed: 1
    the list has 1 element(s)
    The first element: 2
    
    The element removed: 2
    the list has 0 element(s)
    The list is empty!
    */
    
    temp = removeFront(testList);
    printf("\nThe element removed: %d\n", *(int *)temp->elementPtr);
    len = getLength(testList);
    printf("the list has %d element(s)\n", len);
    temp = getFront(testList);
    printf("The first element: %d\n", *(int *)temp->elementPtr);
    
    temp = removeFront(testList);
    printf("The element removed: %d\n", *(int *)temp->elementPtr);
    len = getLength(testList);
    printf("the list has %d element(s)\n", len);
    temp = getFront(testList);
    if (temp == NULL) 
        printf("The list is empty!\n");   
    temp = removeFront(testList);
    
    destroyElement(e1);
    destroyElement(e2);
    destroyElement(e3);
    destroyList(testList);
    
    return 0;
}
