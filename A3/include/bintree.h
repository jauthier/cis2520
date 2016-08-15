/*
    Binary Tree ADT
    
    Author: Jessica Authier
    2016/08/12
*/

#ifndef BINTREE_H
#define BINTREE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct BinTreeNode {
    void * data;
    struct BinTreeNode * left;
    struct BinTreeNode * right;
} BinTreeNode;

typedef struct BinTree {
    int (*compare)(void *, void *);
    void (*destroy)(void *);
    BinTreeNode * root;
} BinTree;

/*
    Purpose: to create, initialize and allocate memory for a new binary tree
    Preconditions: a function pointer to a compare function and a function pointer to a destroy function
        
        The compare function must have the signature: int compare (void * data1, void * data2); and must
        return an int > 0 if data1 is "greater" than data2, an int < 0 if  data1 is "less" than data2, and 
        0 if data1 is the same as data2.
        
        The destoy function must have the signature: void (*destroy)(void * data);
        
    Postconditions: none
*/
BinTree * createBinTree(int (*compare)(void *, void *), void (*destroy)(void *));

/*
    Purpose: to destroy and free the the memory of a binary tree and all its nodes
    Preconditions: an initialized binary tree
    Postconditions: the memory allocated for the tree is freed
*/
void destroyBinTree(BinTree * tree);

/*
    Purpose: to add a node to a binary tree
    Preconditions: a non-NULL void pointer to be stored as the data of the node
    Postconditions: a node is created and added to the appropriate spot in the tree
*/
BinTree * addToTree(BinTree * tree, void * data);

/*
    Purpose: to remove a node from the tree and adjust the remaining nodes
    Preconditions: an initialized, non-empty binary tree
    Postconditions: the node is removed and destroyed and the data if rearranged to keep a balanced tree
*/
BinTree * removeFromTree(BinTree * tree, void * data);

/*
    Purpose: to return the node with the lowest data value in the tree
    Preconditions: an initialized, non-empty binary tree
    Postconditions: none
*/
BinTreeNode * getMin(BinTreeNode * root);

/*
    Purpose: to return the node with the highest data value in the tree
    Preconditions: an initialized, non-empty binary tree
    Postconditions: none
*/
BinTreeNode * getMax(BinTreeNode * root);

/*
    Purpose: to determine whether the tree is empty or not, returns 0 if 
    the tree is not empty and 1 if it is
    Preconditions: an initialized binary tree
    Postconditions: none
*/
int isTreeEmpty(BinTree * tree);

/*
    Purpose: to return the node at the root of the tree
    Preconditions: an initialized, non-empty binary tree
    Postconditions: none
*/
BinTreeNode * getRootNode(BinTree * tree);

/*
    Purpose: to return the data of the tree's root node
    Preconditions: an initialized, non-empty binary tree
    Postconditions: none
*/
void * getRootData(BinTree * tree);

/*
    Purpose: to return the left subtree of the given tree
    Preconditions: an initialized, non-empty binary tree
    Postconditions: none
*/
BinTree * getLeftSubtree(BinTree * tree);

/*
    Purpose: to return the right subtree of the given tree
    Preconditions: an initialized, non-empty binary tree
    Postconditions: none
*/
BinTree * getRightSubtree(BinTree * tree);

/*
    Purpose: to return the height of the tallest branch in the tree
    Preconditions: an initialized, non-empty binary tree
    Postconditions: none
*/
int maxHeight(BinTree * tree);

#endif
