#include "linkedlist.h"

int main(int argc, char *argv[]){
    
    List * testList;
    testList = createList(); //test createList
    
    int first, second, third, len;
    Element *e1, *e2, *e3;
    
    first = 1;
    second = 2;
    third = 3;
    
    e1 = createElement(&first);
    e2 = createElement(&second);
    e3 = createElement(&third);
    
    
    /*  testing addFront, getLength and getFront:
    should print out:
    the list has 1 element(s)
    The first element: 1
    the list has 2 element(s)
    The first element: 2
    the list has 3 element(s)
    The first element: 2
    */
    testList = addFront(e1, testList);
    len = getLength(testList);
    printf("the list has %d element(s)\n", len);
    Element * temp = getFront(testList);
    printf("The first element: %d\n", *(int *)temp->elementPtr);
    
    testList = addFront(e2, testList);
    len = getLength(testList);
    printf("the list has %d element(s)\n", len);
    temp = getFront(testList);
    printf("The first element: %d\n", *(int *)temp->elementPtr);
    
    testList = addBack(e3, testList);
    len = getLength(testList);
    printf("the list has %d element(s)\n", len);
    temp = getFront(testList);
    printf("The first element: %d\n\n", *(int *)temp->elementPtr);
    
    /*  testing removeBack and removeFront:
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
    printf ("%d\n", *(int*)list->head->next->next->elementPtr );
    
    
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
    
    temp = removeFront(testList);
    printf("The element removed: %d\n", *(int *)temp->elementPtr);
    len = getLength(testList);
    printf("the list has %d element(s)\n", len);
    temp = getFront(testList);
    if (temp == NULL) 
        printf("The list is empty!\n");
    
    
    return 0;
}
