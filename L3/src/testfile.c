
#include <stdio.h>
#include "linkedlist.h"
#include "stack.h"


int main(){
    
    Stack * stack1;
    stack1 = createStack();
    
    Element e1, e2, e3, e4, e5;
    int a, b, c, d, e;
    
    
    a = 1;
    b = 2;
    c = 3;
    d = 4;
    e = 5;
    
    e1 = createElement(&a);
    e2 = createElement(&b);
    e3 = createElement(&c);
    e4 = createElement(&d);
    e5 = createElement(&e);
    
    int empty = isEmpty(stack1);
    if (empty == 0)
        printf("The stack is empty!\n");
    else 
        printf("Why is the stack not empty?\n");
    
    stack1 = push(stack1, e1);
    
    if (empty == 0)
        printf("Why is the stack empty!\n");
    else 
        printf("The stack is not empty?\n");
    
    
    
}


