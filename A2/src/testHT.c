#include <stdio.h>
#include <stdlib.h>
#include "hashtable.h"

int main(){
    
    int check;
    int value1, value2;
    long key1, key2;
    Entry ** ht = create();
    
    key1 = 5199961212;
    value1 = 11;
    insert(ht, key1, &value1);
    printf("checking the hash function:\n");
    printf("    the index should be: %ld, the index is: %d\n",key1%20, hash(key1));
    printf("checking the insert, exists, and lookup functions:\n");
    printf("  if the key exists then insert and exists worked:\n");
    check = exists(ht, key1);
    if (check == 1)
        printf("    the key exists\n");
    else 
        printf("    the key doesn't exist\n");
    
    check = *(int *)lookup(ht, key1);
    printf("  if the value is correct then insert and lookup worked:\n");
    printf("    the value should be: %d, the value is: %d\n", value1, check);
    //if exists returns 1 and lookup returns the same value as expected then we know insert worked
    
    key2 = 5199961212; // same key to test if insert can handle it
    value2 = 12;
    printf("checking how insert and exists functions handle the same key,\n should output: the key you wish to add already exists\n");
    insert(ht, key2, &value2);
    
    printf("Checking update function:\n");
    update(ht, key1, &value2); //update key1
    check = *(int *)lookup(ht, key1);
    printf("  the value should be: 12, the value is: %d\n", check);
    
    // add another with the same index
    printf("Checking how insert and exist handle a different key with the same index:\n");
    key2 = 5199961192;
    value2 = 13;
    insert(ht, key2, &value2);
    check = *(int *)lookup(ht, key2);
    printf("  the value should be: 13, the value is: %d\n", check);
    
    printf("Checking the isFull function: \n  right now its not full so isFull should return false:\n");
    int full = isFull(ht);
    if (full == 0)
        printf("    false\n");
    else 
        printf("    true\n");
    long key3 = 5199961220;
    
    for(int i=0;i<MAXSIZE;i++){
        
        int * value3 = malloc(sizeof(int));
        * value3 = i+1;
        insert(ht, key3, value3);
        
        value3++;
        key3++;
    }
    
    
    return 0;
}

