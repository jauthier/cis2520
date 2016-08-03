/*
    
    
    
    
*/

#include "bintree.h"

BinTree * createBinTree(int (*compare)(void *, void *), void (*destroy)(void *)){
    
    BinTree * tree = malloc(sizeof(BinTree));
    tree->compare = compare;
    tree->destroy = destroy;
    tree->root = NULL;
    
    return tree;
}

void destroyBinTree(BinTree * tree){
    
    
    free(tree);
}