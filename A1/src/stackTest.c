
#include <stdio.h>
#include "linkedlist.h"
#include "stack.h"


int main(){
    
    Stack * stack1;
    stack1 = createStack();
    
    int a, b, c;
    
    a = 1;
    b = 2;
    c = 3;
    
    int empty = isEmpty(stack1);
    if (empty == 1)
        printf("The stack is empty!\n");
    else 
        printf("Why is the stack not empty?\n");
    
    /* Add a Element to the stack and check if the stack is empty*/
    push(stack1, &a);
    
    empty = isEmpty(stack1);
    
    if (empty == 1)
        printf("Why is the stack empty?\n");
    else 
        printf("The stack is not empty!\n");
    
    /* Add another Element to the stack and check it is at the top 
    by calling peek() the top value should be 2*/
    
    push(stack1, &b);
    Element * test;
    test = peek(stack1);
    printf("The top element is: %d\n", *(int *)(test->elementPtr));
    
    /* remove the top element and test with peek() the top value should be 1*/
    test = pop(stack1);
    test = peek(stack1);
    printf("The top element is: %d\n", *(int *)(test->elementPtr));
    
    /* Add another and check with peek() the top value should be 3 */
    push(stack1, &c);
    test = peek(stack1);
    printf("The top element is: %d\n", *(int *)(test->elementPtr));
    
    destroyStack(stack1);
    
    return 0;
}


