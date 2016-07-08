#include <stdio.h>
#include <stdlib.h>
#include "hashtable.h"

int main(){
    
    int check;
    int value1, value2;
    Entry ** ht = create();
    long key1, key2;
    
    key1 = 5199961212;
    value1 = 11;
    insert(ht, key1, &value1);
    check = exists(ht, key1);
    if (check == 1)
        printf("the key exists\n");
    else 
        printf("the key doesn't exist\n");
    
    check = *(int *)lookup(ht, key1);
    
    printf("the value should be: %d, the value is: %d\n", value1, check);
    //if exists returns 1 and lookup returns the same value as expected then we know insert worked
    
    key2 = 5199961212; // same key to test if insert can handle it
    value2 = 12;
    insert(ht, key2, &value2);
    //  should output: the key you wish to add already exists
    
    update(ht, key1, &value2); //update key1
    check = *(int *)lookup(ht, key1);
    printf("the value should be: 12, the value is: %d\n", check);
    
    // add another with the same index
    key2 = 5199961232;
    value2 = 13;
    insert(ht, key2, &value2);
    printf("here\n");
    check = *(int *)lookup(ht, key2);
    printf("the value should be: 13, the value is: %d\n", check);
    
    
    return 0;
}

