/*
    Author; jessica Authier
    2016/07/08
*/

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 20

typedef struct Entry {
    long key;
    void * value;
    struct Entry * next;
    
} Entry;

/*
    purpose: to create an empty, initalized hash table
    preconditions: none
    postconditions: an empty, initalized hash table is created
    
*/
Entry ** create();

/*
    purpose: to destroy an initalized hash table
    preconditions: an initalized hash table exists
    postconditions: the given hash table is destroyed and it memory is freed
    
*/
void destroy(Entry ** hashTable);

/*
    purpose: to add a key/value pair to the hash table
    preconditions: an initalized hash table exists
    postconditions: the key/value pair is initalized and added at the appropriate index
    
*/
void insert(Entry ** hashTable, long key, void * value);

/*
    purpose: to initalize and allocate memory for a new Entry variable 
    preconditions: a valid key and value are provided as parameters
    postconditions: a Entry variable is initalized and its values are set to the parameters given
    
*/
Entry * createEntry(long key, void * value);

/*
    purpose: to remove an entry from the hash table and return its value
    preconditions: an initalized, non-empty hash table exist
    postconditions: the key/value pair is removed from the hash table and it memory is freed
    
*/
void * removeEntry(Entry ** hashTable, long key);

/*
    purpose: to get the value that is linked to the key, which is given as a parameter
    preconditions: an initalized, non-empty hash table
    postconditions: none
    
*/
void * lookup(Entry ** hashTable, long key);

/*
    purpose: to change the value that is linked to a given key
    preconditions: an initalized hash table that includes the key given as a parameter, and a new value
    postconditions: the the value linked to the given key is changed to the new value given
    
*/
void update(Entry ** hashTable, long key, void * newValue);

/*
    purpose: to check if the given key already exists in the hash table
    preconditions: an initalized hash table
    postconditions: none
    
*/
int exists(Entry ** hashTable, long key);

/*
    purpose: to check if the hash table is empty or not
    preconditions: an initalized hash table
    postconditions: none
    
*/
int isEmpty(Entry ** hashTable);

/*
    purpose: to check if the hash table is full or not
    preconditions: an initalized hash table
    postconditions: none
    
*/
int isFull(Entry ** hashTable);

/*
    purpose: to return the index value associated with the given key
    preconditions: a key is given
    postconditions: none
    
*/
int hash(long key);

#endif