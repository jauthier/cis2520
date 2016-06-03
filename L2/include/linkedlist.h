#include <stdio.h>
#include <stdlib.h>

typedef struct Element {
    void * elementPtr;
    struct Element * next;
    
} Element;

typedef struct List {
    Element * head ;
    
} List;


List * createList();
/*
    purpose: to create and initialize a variable of type List
    preconditions: none
    postconditions: an initialized List with a head set to NULL
*/

void destroyList(List * toDestroy);
/*
    purpose: to destroy and free the memory of a List variable and all of the Elements it contains
    preconditions: initialized List
    postconditions: the List is destroyed and the memory is freed
*/

Element * createElement(void * contents);
/*
    purpose: to create and initialize a variable of type Element
    preconditions: a pointer to the information the Element will contain
    postconditions: an initialized Element with elementPtr set to the contents given and next set to NULL
    
*/

void destroyElement(Element * toDestroy);
/*
    purpose: to destroy and free the memory of an Element variable
    preconditions: initialized Element
    postconditions: the Element is destroyed and the memory is freed
*/

List * addFront(Element * toAdd, List * list);
/*
    purpose: to add an Element to the front of a List and return the List to the calling function
    preconditions: an initialized List and an initialized Element
    postconditions: the Element is added to the front of the List
*/

List * addBack(Element * toAdd, List * list);
/*
    purpose: to add an Element to the end of a List and return the List to the calling function
    preconditions: an initialized List and an initialized Element
    postconditions: the Element is added to the end of the List
*/

Element * removeFront(List * list);
/*
    purpose: to remove the Element at the front of a List and return it to the calling function
    preconditions: an initialized, non-empty List
    postconditions: the first Element is removed from the List but not destroyed
*/

Element * removeBack(List * list);
/*
    purpose: to remove the Element at the end of a List and return it to the calling function
    preconditions: an initialized, non-empty List
    postconditions: the last Element is removed from the List but not destroyed
*/

Element * getFront(List * list);
/*
    purpose: to return the first Element of a List to the calling function
    preconditions: an initialized, non-empty List
    postconditions: none
*/

int getLength(List * list);
/*
    purpose: to return the length of a List to the calling function
    preconditions: an initialized List
    postconditions: none
*/