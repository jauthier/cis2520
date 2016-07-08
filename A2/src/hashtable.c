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

void insert(Entry ** hashTable, int key, void * value){
    
    int checkKey = exists(hashTable, key);
    if (checkKey == 0){ //false --> doesn't already exist
        // get the index
        int index = hash(Entry * hashTable, int key);
        // make an Entry
        Entry * newEntry;
        newEntry = createEntry(key, value)
        //put in the array
        if (hashTable[index] == NULL){ // no collision
            hashTable[index] = newEntry;
        } else { // collision
            //lets chain
            Entry * temp = hashTable[index];
            while (temp->next != NULL){ // find the end of the chain
                temp = temp->next;
            }
            temp->next = newEntry; // add it to the end
        }
    } else if (checkKey == 1){
        printf("The key you wish to add already exist.\n");
    }
}

Entry * createEntry(int key, void * value){
    
    Entry * newEntry
    newEntry = malloc(sizeof(Entry));
    newEntry->key = key;
    newEntry->value = value;
    newEntry->next = NULL;
    
    return newEntry;
}

void * removeEntry(Entry ** hashTable, int key){
    
    int checkEmpty = isEmpty(hashTable);
    int index = hash(int key);
    Entry * temp = hashTable[index]; // set it to the first value
    void * holdValue;
    
    if (checkEmpty == 1){ // the hashTabe is empty
        pirntf ("There are no entries to remove.\n");
        return NULL;
    }
    
    if (temp->key == key){ // if the first one is a match
        
        if (temp->next == NULL){ // no chaining
            hashTable[index] = NULL;
            holdValue = temp->value;
            free(temp);
            return holdValue;
        } else { 
            hashTable[index] = temp->next;
            holdValue = temp->value;
            free(temp);
            return holdValue;
        }
    } else {
        
        while (temp->next->key != key || temp->next->next != NULL){ // go throught the chain till we find it or it runs out
            temp = temp->next;
        }
        
        if (temp->next->next == NULL && temp->next->key != key){ // chain ended without finding a match
            printf("The key you gave was not found.\n");
            return NULL;
        } else if (temp->next->next == NULL && temp->next->key == key){ // the last one is a match 
            holdValue = temp->next->value;
            free(temp->next);
            temp->next = NULL;
            return holdValue;
        } else{
            Entry * hold = temp->next->next; // the value after the one being removed
            holdValue = temp->next->value;
            free(temp->next);
            temp->next = hold;
            return holdValue;
        }
    }
}

void * lookup(Entry ** hashTable, int key){
    int index = hash(key);
    Entry * hold = hashTabe[index];
    
    if (checkEmpty == 1){ // the hashTabe is empty
        pirntf ("There are no entries to search.\n");
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

void update(Entry ** hashTable, int key, void * newValue){
    
    int checkEmpty;
    Entry * hold = hashTable[hash(key)];
    
    if (checkEmpty == 1){ // the hashTabe is empty
        pirntf ("There are no entries to update.\n");
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

int exists(Entry ** hashTable, int key){
    //return 0 false and 1 if true
    
    //find hash
    int checkEmpty;
    int index = hash(key);
    Entry * hold = hashTable[index];
    
    if (checkEmpty == 1) // the hashTabe is empty
        return 0; // key doesn't exist
        
    if (hold->key == key){ // the first one is a match
        return 1; // key exists
    } else {
        hold = hold->next;
        while (hold->key != key || hold-> next != NULL){
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

int hash(int key){
    
    return key%MAXSIZE;
}