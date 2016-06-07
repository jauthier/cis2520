/*
    Author: Jessica Authier
    2016\06\03
*/

#ifndef STACK_H 
#define STACK_H

#include <stdio.h>
#include "linkedlist.h"

typedef struct Stack {
    List * top;
    
} Stack;

/*
    Purpose: declare and initalized a new stack variable
    Preconditions: none
    postconditions: initalized, empty stack variable returned to calling function

*/
Stack * createStack();

/*
    Purpose: to determine if the stack is empty
    Preconditions: initalized stack variable
    postconditions: none

*/
int isEmpty(Stack * stack);

/*
    Purpose: add a new element to the top of the stack
    Preconditions: initalized stack variable
    postconditions: new element become the top of the stack

*/
void push(Stack * stack, Element * element);

/*
    Purpose: remove the top element from the stack and return it to the calling function
    Preconditions: initalized, non-empty stack
    postconditions: top element returned and removed from the stack

*/
Element * pop(Stack * stack);

/*
    Purpose: return the top element
    Preconditions: initalized, non-empty stack
    postconditions: top element returned but not removed

*/
Element * peek(Stack * stack);

/*
    Purpose: destroys the stack and everything in it, freeing the memory
    Preconditions: initalized stack variable
    postconditions: stack is destroyed and the memory is freed

*/
void destroyStack(Stack * stack);

#endif
