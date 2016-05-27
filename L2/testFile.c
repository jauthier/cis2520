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
    
    testList = addFront(e1, testList);
    len = getLength(testList);
    printf("the list has %d element(s)\n", len);
    Element * temp = getFront(testList);
    printf("The first element: %d\n", *(int *)temp->elementPtr);
    
    
    
    return 0;
}
