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
        return 1;
    else 
        return 0;
}

void push(Stack * stack, void * data){
    
    Element * element;
    element = createElement(data);
    addFront(stack->top, element);
}

void * pop(Stack * stack){
    
    void * data;
    Element * topElement;
    topElement = removeFront(stack->top);
    data = topElement->elementPtr;
    
    return data;
}

void * peek(Stack * stack){
    
    void * data;
    Element * topElement;
    topElement = getFront(stack->top);
    data = topElement->elementPtr;
    
    return topElement;
}

void destroyStack(Stack * stack){
    
    destroyList(stack->top);
    free(stack);
}
