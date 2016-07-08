#include <stdio.h>
#include <stdlib.h>
#include "hashtable.h"

int main(){
    
    
    int value1, value2, value3, value4, check;
    Entry * ht = create();
    int key1 =519 996 1212;
    
    value1 = 11;
    insert(ht, key1, &value1);
    check = exists(ht, key1);
    if (check == 1)
        printf("the key exists\n");
    else 
        printf("the key doesn't exist\n");
    
    (void *)&check = lookup(ht, key1);
    
    printf("the value shouldbe: %d, the value is: %d", value1, check);
    
    
    //if exists returns 1 and lookup returns the value then we know insert worked
    return 0;
}

