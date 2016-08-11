/*
    Binary Tree ADT
    
    Author: Jessica Authier
    2016/08/02
*/

#ifndef BINTREE_H
#define BINTREE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct BinTreeNode {
    void * data;
    int nodeBalance;
    struct BinTreeNode * left;
    struct BinTreeNode * right;
} BinTreeNode;

typedef struct BinTree {
    int (*compare)(void *, void *);
    void (*destroy)(void *);
    BinTreeNode * root;
} BinTree;

/*
    Purpose:
    Preconditions:
    Postconditions:
*/
BinTree * createBinTree(int (*compare)(void *, void *), void (*destroy)(void *));

/*
    Purpose:
    Preconditions:
    Postconditions:
*/
void destroyBinTree(BinTree * tree);

/*
    Purpose:
    Preconditions:
    Postconditions:
*/
BinTree * addToTree(BinTree * tree, void * data);

/*
    Purpose:
    Preconditions:
    Postconditions:
*/
BinTreeNode * removeFromTree(BinTree * tree, void * data);

/*
    Purpose:
    Preconditions:
    Postconditions:
*/
BinTreeNode * getMin(BinTreeNode * root);

/*
    Purpose:
    Preconditions:
    Postconditions:
*/
BinTreeNode * getMax(BinTreeNode * root);

/*
    Purpose:
    Preconditions:
    Postconditions:
*/
int isTreeEmpty(BinTree * tree);

/*
    Purpose:
    Preconditions:
    Postconditions:
*/
BinTreeNode * getRootNode(BinTree * tree);

/*
    Purpose:
    Preconditions:
    Postconditions:
*/
void * getRootData(BinTree * tree);

/*
    Purpose:
    Preconditions:
    Postconditions:
*/
BinTree * getLeftSubtree(BinTree * tree);

/*
    Purpose:
    Preconditions:
    Postconditions:
*/
BinTree * getRightSubtree(BinTree * tree);

/*
    Purpose:
    Preconditions:
    Postconditions:
*/
int maxHeight(BinTree * tree);

#endif
