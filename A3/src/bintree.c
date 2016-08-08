/*
    Binary Tree ADT
    
   Author: Jessica Authier 
    
*/

#include "bintree.h"

static int checkBalance(BinTree * tree){
    
    BinTree * right, * left;
    int rightHeight, leftHeight;
    
    // get the heigth of the right subtree
    right = getRightSubtree(tree);
    rightHeight = maxHeight(right);
    
    // get the height of the
    left = getLeftSubtree(tree);
    leftHeight = maxHeight(left);
    
    return rightHeight - leftHeight;
}

static BinTreeNode * rotateRight(BinTreeNode * hold){
    
    BinTreeNode * temp = hold->right;
    hold->right = temp->left;
    temp->left = hold;
    
    return temp;
}

static BinTreeNode * rotateLeft(BinTreeNode * hold){
    
    BinTreeNode * temp = hold->left;
    hold->left = temp->right;
    temp->right = hold;
    
    return temp;
}

static BinTreeNode * createNode(void * data){
    
    BinTreeNode * newNode = malloc(sizeof(BinTreeNode));
    newNode->data = data;
    newNode->nodeBalance = 0;
    newNode->left = NULL;
    newNode->right = NULL;
    
    return newNode;
}

static BinTree * insert(BinTree * tree, void * data){
    
    /*  if the data from toAdd is 'less than' the data from the root(tree->root) then it goes to the left
        the compare function will return a number greater than 0 if this is the case

        if the data from toAdd is 'greater than' the data from the root(tree->root) then it goes to the right
        the compare function will return a number less than 0 if this is the case  */
    
    if (isTreeEmpty(tree) == 1){ // if (tree->root == NULL) --->the tree is empty
        
        BinTreeNode * toAdd = createNode(data); // create the node to store the data
        tree->root = toAdd; // add it to the tree
        
    } else if (tree->compare(tree->root->data, data) > 0){ // if (tree->root->data > data)
        
        tree->root->left = (insert(getLeftSubtree(tree), data))->root; // set the left node --> data less than the root data goes to the left
        if (checkBalance(tree) == -2){ // there is an imbalance -- left is longer
            if (tree->compare(tree->root->left->data, data) > 0) {
                tree->root = rotateLeft(tree->root);
            } else {
                tree->root->left = rotateRight(tree->root->left);
                tree->root = rotateLeft(tree->root);
            }
        }   
    } else if (tree->compare(tree->root->data, data) < 0){ // if (tree->root->data < data)
        
        tree->root->right = (insert(getRightSubtree(tree), data))->root; // set the right node --> data greater than the root data goes to the right
        if (checkBalance(tree) == 2){ // there is an imbalance -- right is longer
            if (tree->compare(tree->root->right->data, data) < 0) { // if the node that was just added is greater than the right node
                tree->root = rotateRight(tree->root);
            } else {
                tree->root->right = rotateLeft(tree->root->right);
                tree->root = rotateRight(tree->root);
            }
        }
    }
    return tree;
}

BinTree * createBinTree(int (*compare)(void *, void *), void (*destroy)(void *)){
    
    BinTree * tree = malloc(sizeof(BinTree)); // make space
    tree->compare = compare; // compare function ptr
    tree->destroy = destroy; // destroy node function ptr
    tree->root = NULL; // set root to NULL
    
    return tree;
}

void destroyBinTree(BinTree * tree){
    
    
    free(tree); // free the tree
}

BinTree * addToTree(BinTree * tree, void * data){
    
    return insert(tree, data);
}

BinTreeNode * removeFromTree(BinTree * tree, BinTreeNode * toAdd){
    return tree->root;
}

int isTreeEmpty(BinTree * tree){
    if (tree->root == NULL)
        return 1;
    else 
        return 0;
}

BinTreeNode * getRootNode(BinTree * tree){
    return tree->root;
}

void * getRootData(BinTree * tree){
    return tree->root->data;
}

BinTree * getLeftSubtree(BinTree * tree){
    
    if (isTreeEmpty(tree) == 1)
        return NULL;
    
    BinTree * temp = createBinTree(tree->compare ,tree->destroy);
    temp->root = tree->root->left;
    
    return temp;
}

BinTree * getRightSubtree(BinTree * tree){
    
    if (isTreeEmpty(tree) == 1)
        return NULL;
    
    BinTree * temp = createBinTree(tree->compare ,tree->destroy);
    temp->root = tree->root->right;
    
    return temp;
}

int maxHeight(BinTree * tree){
    
    if (tree == NULL)
        return 0;
    int left = maxHeight(getLeftSubtree(tree));
    int right = maxHeight(getRightSubtree(tree));
    if (left < right)
        return right + 1;
    else
        return left + 1;
}
