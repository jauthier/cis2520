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



BinTree * createBinTree(int (*compare)(void *, void *), void (*destroy)(void *));

void destroyBinTree(BinTree * tree);

BinTree * insert(BinTree * tree, BinTreeNode * toAdd);

BinTreeNode * removeFromTree(BinTree * tree, BinTreeNode * toAdd);

static BinTreeNode * createNode(void * data);

int isTreeEmpty(BinTree * tree);

BinTreeNode * getRootNode(BinTree * tree);

BinTree * getLeftSubtree(BinTree * tree);

BinTree * getRightSubtree(BinTree * tree);

int maxHeight(BinTree * tree);

static int checkBalance(BinTree * tree);

static BinTreeNode * rotateRight(BinTree * tree);

static BinTreeNode * rotateLeft(BinTree * tree);

#endif
