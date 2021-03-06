/*
    Author: Jessica Authier
    2016/07/08
*/

#include "hashtable.h"

Entry ** create(){
    Entry ** ht;
    ht = malloc(MAXSIZE * sizeof(Entry));
    for (int i=1; i<MAXSIZE; i++){
        ht[i] = NULL;
    }
    return ht;
}

void destroy(Entry ** hashTable){
    //free the elements
    for (int i=0; i<MAXSIZE; i++){
        if (hashTable[i] == NULL)
            free(hashTable[i]);
    }
    
    //free the array
    free(hashTable);
}

void insert(Entry ** hashTable, long key, void * value){
    int checkKey = exists(hashTable, key);
    if (checkKey == 0){ //false --> doesn't already exist
        
        Entry * newEntry = createEntry(key, value);
        if (hashTable[hash(key)] == NULL){ // no collision
            hashTable[hash(key)] = newEntry;
        } else { // collision
            //lets chain
            Entry * temp = hashTable[hash(key)];
            while (temp->next != NULL){ // find the end of the chain
                temp = temp->next;
            }
            temp->next = newEntry; // add it to the end
        }
    } else {
        printf("The key you wish to add already exist.\n");
    }
}


Entry * createEntry(long key, void * value){
    
    Entry * newEntry;
    newEntry = malloc(sizeof(Entry));
    newEntry->key = key;
    newEntry->value = value;
    newEntry->next = NULL;
    
    return newEntry;
}

void * removeEntry(Entry ** hashTable, long key){
    
    int checkEmpty = isEmpty(hashTable);
    int index = hash(key);
    Entry * temp = hashTable[index]; // set it to the first value
    void * holdValue;
    
    if (checkEmpty == 1){ // the hashTabe is empty
        printf("There are no entries to remove.\n");
        return NULL;
    }
    if (temp == NULL){ // the index given has no entries
        printf("Could not find the entry you wish to remove.\n");
        return NULL;
    }
    if (temp->key == key){ // if the first entry is a match
        
        if (temp->next == NULL){ // no chaining
            hashTable[index] = NULL;
            holdValue = temp->value;
            free(temp);
            return holdValue;
        } else { // there is a chain
            hashTable[index] = temp->next;
            holdValue = temp->value;
            free(temp);
            return holdValue;
        }
    } else { // the first entry is not a match
        if (temp->next == NULL){ // there are no more entries after the first
            printf("Could not find the entry you wish to remove.\n");
            return NULL;
        }
        // there are entries after the first
        while (temp->next->next != NULL){ // check if the next entry is the last
            //if its not the last
            if (temp->next->key == key){ // check if its a match
                // if it is we need to remove it
                Entry * hold = temp->next->next; // hold the next entry
                holdValue = temp->next->value; // hold the value of the entry being removed
                free(temp->next); // free the memory
                temp->next = hold; // link the previous and following entries of the entry that was removed
                return holdValue;
            }
            temp = temp->next;
        }
        if (temp->next->key != key){ // chain ended without finding a match
            printf("The key you gave was not found.\n");
            return NULL;
        } else { // the last one is a match 
            holdValue = temp->next->value;
            free(temp->next);
            temp->next = NULL;
            return holdValue;
        }
    }
}

void * lookup(Entry ** hashTable, long key){
    
    int checkEmpty = isEmpty(hashTable);
    Entry * hold = hashTable[hash(key)];
    
    if (checkEmpty == 1){ // the hashTable is empty
        printf ("There are no entries to search.\n");
        return NULL;
    }
        
    if (hold->key == key) // the first one is a match
        return hold->value;
    else {
        hold = hold->next;
        while (hold->key != key || hold-> next != NULL){
            hold = hold->next;
        }
        if (hold->next == NULL && hold->key != key){ // chain ended without finding a match
            printf("The search was unsuccessful. The key you gave was not found.\n");
            return NULL;
        } else
            return hold->value;
    }
}

void update(Entry ** hashTable, long key, void * newValue){
    
    int checkEmpty = isEmpty(hashTable);
    Entry * hold = hashTable[hash(key)];
    
    if (checkEmpty == 1){ // the hashTabe is empty
        printf ("There are no entries to update.\n");
    }
        
    if (hold->key == key) // the first one is a match
        hold->value = newValue;
    else {
        hold = hold->next;
        while (hold->key != key || hold-> next != NULL){
            hold = hold->next;
        }
        if (hold->next == NULL && hold->key != key) // chain ended without finding a match
            printf("The search was unsuccessful. The key you gave was not found.\n");
        else
            hold->value = newValue;
    }
}

int exists(Entry ** hashTable, long key){
    //return 0 false and 1 if true
    
    //find hash
    int checkEmpty = isEmpty(hashTable);
    int index = hash(key);
    Entry * hold = hashTable[index];
    if (checkEmpty == 1) // the hashTabe is empty
        return 0; // key doesn't exist

    if (hold == NULL){ // nothing is there
        return 0;
    }

    if (hold->key == key){ // the first one is a match
        return 1; // key exists
    } else {

        while (hold-> next != NULL){
            hold = hold->next;
        }
        if (hold->next == NULL && hold->key != key) // chain ended without finding a match
            return 0; // key doesn't exist
        else
            return 1; // key exists 
    }
}

int isEmpty(Entry ** hashTable){
    
    for (int i=0; i<MAXSIZE; i++){
        if (hashTable[i] != NULL)
            return 0; // not empty
    }
    // if it makes it to the end of the loop then all are NULL
    return 1; // empty
}

int isFull(Entry ** hashTable){
    
    for (int i=0; i<MAXSIZE; i++){
        if (hashTable[i] == NULL)
            return 0; // not full
    }
    // if it makes it to the end of the loop then none are NULL
    return 1; // full
}

int hash(long key){
    
    return key%MAXSIZE;
}
