/*
    Author: Jessica Authier
    2016/06/03
*/

#include "stack.h"

Stack * createStack(){
    
    Stack * newStack;
    newStack = malloc(sizeof(Stack));
    
    newStack->top = createList();
    
    return newStack;
}

int isEmpty(Stack * stack){
    
    int len = getLength(stack->top);
    printf("%d\n",len);
    if (len == 0)
        return 0;
    else 
        return 1;
}

void push(Stack * stack, Element * element){
    
    addFront(stack->top, element);
}
Element * pop(Stack * stack){
    
    Element * topElement;
    topElement = removeFront(stack->top);
    return topElement;
}

Element * peek(Stack * stack){
    
    Element * topElement;
    topElement = getFront(stack->top);
    return topElement;
}

void destroyStack(Stack * stack){
    
    destroyList(stack->top);
    free(stack);
}
