/*
    Binary Tree ADT
    
    Author: Jessica Authier
    2016/08/02
*/

#ifndef BINTREE_H
#define BINTREE_H

#include <stdio.h>

typedef struct BinTreeNode {
    void * data;
    BinTreeNode * left;
    BinTreeNode * right;
} BinTreeNode;

typedef struct BinTree {
    int (*compare)(void *, void *)
    void (*destroy)(void *)
    BinTreeNode * root;
} BinTree;



BinTree * createBinTree();

void destroyBinTree(BinTree * tree);

BinTree * addToTree(BinTree * tree, BinTreeNode * toAdd);

BinTreeNode * removeFromTree(BinTree * tree, BinTreeNode * toAdd);

int isTreeEmpty(BinTree * tree);

BinTreeNode * getRootNode(BinTree * tree);

BinTree * getLeftSubtree(BinTree * tree);

BinTree * getRightSubtree(BinTree * tree);



#endif
