

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 20

typedef struct Entry {
    int key;
    void * value;
    struct Entry * next;
    
} Entry;

/*
    purpose:
    preconditions:
    postconditions:
    
*/
Entry * create();

/*
    purpose:
    preconditions:
    postconditions:
    
*/
void destroy(Entry * hashTable);

/*
    purpose:
    preconditions:
    postconditions:
    
*/
void insert(Entry * hashTable, int key, void * value);

/*
    purpose:
    preconditions:
    postconditions:
    
*/
Entry * createEntry(int key, void * value)

/*
    purpose:
    preconditions:
    postconditions:
    
*/
void * remove(Entry * hashTable, int key);

/*
    purpose:
    preconditions:
    postconditions:
    
*/
void * lookup(Entry * hashTable, int key);

/*
    purpose:
    preconditions:
    postconditions:
    
*/
void update(Entry * hashTable, int key, void * newValue);

/*
    purpose:
    preconditions:
    postconditions:
    
*/
int exists(Entry * hashTable, int key);

/*
    purpose:
    preconditions:
    postconditions:
    
*/
int isEmpty(Entry * hashTable);

/*
    purpose:
    preconditions:
    postconditions:
    
*/
int isFull(Entry * hashTable);

/*
    purpose:
    preconditions:
    postconditions:
    
*/
int hash(int key);

#endif