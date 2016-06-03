
#include <stdio.h>
#include "linkedlist.h"
#include "stack.h"


int main(){
    
    Stack * stack1;
    stack1 = createStack();
    
    Element *e1, *e2, *e3, *e4, *e5;
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
    
    /* Add a Element to the stack and check if the stack is empty*/
    push(stack1, e1);
    
    empty = isEmpty(stack1);
    
    if (empty == 0)
        printf("Why is the stack empty?\n");
    else 
        printf("The stack is not empty!\n");
    
    /* Add another Element to the stack and check it is at the top 
    by calling peek() */
    
    push(stack1, e2);
    Element * test;
    test = peek(stack1);
    printf("The top element is: %d\n", *(int *)(test->elementPtr));
    
    
    
    return 0;
}


