#include <stdio.h>
#include <stdlib.h>
#include "hashtable.h"

int main(){
    
    int check;
    int value1, value2, value3;
    long key1, key2;
    Entry ** ht = create();
    
    key1 = 5199961212;
    value1 = 11;
    insert(ht, key1, &value1);
    printf("\nchecking the hash function:\n");
    printf("    the index should be: %ld, the index is: %d\n",key1%20, hash(key1));
    printf("\nchecking the insert, exists, and lookup functions:\n");
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
    
    // using same key to test if insert can handle it
    value2 = 12;
    printf("\nchecking how insert and exists functions handle the same key,\n should output: the key you wish to add already exists\n");
    insert(ht, key1, &value2);
    
    printf("\nChecking update function:\n");
    update(ht, key1, &value2); //update key1
    check = *(int *)lookup(ht, key1);
    printf("  the value should be: 12, the value is: %d\n", check);
    
    // add another with the same index
    printf("\nChecking how insert and exist handle a different key with the same index:\n");
    key2 = 5199961192;
    value2 = 13;
    insert(ht, key2, &value2);
    check = *(int *)lookup(ht, key2);
    printf("  the value should be: 13, the value is: %d\n", check);
    
    printf("\nChecking the isFull function: \n  right now its not full so isFull should return false:\n");
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
    printf("  now the it full, so it should return true:\n");
    full = isFull(ht);
    if (full == 0)
        printf("    false\n");
    else 
        printf("    true\n");
    
    printf("\nChecking the removeEntry function:\n");
    int removedVal = *(int *)removeEntry(ht, 5199961221);
    printf("  the value removed was: %d\n",removedVal);
    printf("\nCheching if the key was removed:\n  if the key was removed properly then it shouldn't exist:\n");
    check = exists(ht, 5199961221);
     if (check == 1)
        printf("    the key exists\n");
    else 
        printf("    the key doesn't exist\n"); 
    
    value3 = 22;
    insert(ht, 5199961193, &value3);
    
    printf("\nChecking that removeEntry function removes chained entries properly:\n");
    printf("  removing from the middle:\n");
    //remove from middle: use key2
    removedVal = *(int *)removeEntry(ht, key2);
    printf("    the value of the removed entry should be: 13, the the value removed was: %d\n", removedVal);
    printf("  removing from the back:\n");
    int correctVal = *(int *)lookup(ht, 5199961232);
    removedVal = *(int *)removeEntry(ht, 5199961232);
        printf("    the value of the removed entry should be: %d, the the value removed was: %d\n", correctVal, removedVal);

    
    return 0;
}

