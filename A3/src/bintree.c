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

static void destroyNode(BinTreeNode * toDestroy, void (*destroy)(void *)){
    
    destroy(toDestroy->data);
    free(toDestroy);
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

static BinTreeNode * delete(BinTreeNode * root, void * data, int (*compare)(void *, void *), void (*destroy)(void *)){
    
    BinTreeNode * temp;
    void * removedData;
    //make sure tree isn't empty
    if (root == NULL){
        return NULL;
    }
        
    //finding the node
    if (compare(root->data, data) > 0){ // root->data > data
        root->left = delete(root->left, data, compare, destroy);
    } else if (compare(root->data, data) < 0){ // root->data < data
       root->right = delete(root->right, data, compare, destroy);
    } else { //root->data == data
       if ((root->left != NULL) && (root->right != NULL)){ // if node has two children
            
            temp = getMin(root->right);
            removedData = root->data;
            destroy(removedData);
            root->data = temp->data;
            root->right = delete(root->right, temp->data, compare, destroy);
            
        } else {
            temp = root;
            if (root->left == NULL)
                root = root->right;
            else if (root->right == NULL)
                root = root->left;
            
            destroyNode(temp, destroy);
        }
    }
    return root;
}

BinTree * createBinTree(int (*compare)(void *, void *), void (*destroy)(void *)){
    
    BinTree * tree = malloc(sizeof(BinTree)); // make space
    tree->compare = compare; // compare function ptr
    tree->destroy = destroy; // destroy node function ptr
    tree->root = NULL; // set root to NULL
    
    return tree;
}

void destroyBinTree(BinTree * tree){
    
    BinTreeNode * root = tree->root;
    int i = 0;
    int h = maxHeight(tree);
 
    for(i=1; i<=h; i++){
        destroyRec(tree->root, i, tree->destroy);
    }
    free(tree); // free the tree
}


void destroylRec(BinTreeNode * node, int level, void (*destroy)(void *)){
    
    if (level == 1){
        if (node == NULL){
            return;
        } else {
            destroyNode(node, destroy);
        }
    } else {
        if (node == NULL)
            return;
        printTreeLevelRec(node->left, level-1);
        printTreeLevelRec(node->right, level-1);
    }    
}

BinTree * addToTree(BinTree * tree, void * data){
    
    return insert(tree, data);
}

BinTree * removeFromTree(BinTree * tree, void * data){
    
    tree->root = delete(tree->root, data, tree->compare, tree->destroy);
    return tree;
}


BinTreeNode * getMin(BinTreeNode * root){
    
    if (root == NULL)
        return NULL;
    
    while (root->left != NULL){
        root = root->left;
    }
    return root;
}

BinTreeNode * getMax(BinTreeNode * root){
    
    if (root == NULL)
        return NULL;
    
    while (root->right != NULL){
        root = root->right;
    }
    return root;
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
    
    if (tree->root == NULL)
        return 0;
    int left = maxHeight(getLeftSubtree(tree));
    int right = maxHeight(getRightSubtree(tree));
    //printf("rightH: %d, leftH: %d\n",right, left);
    if (left < right)
        return right + 1;
    else
        return left + 1;
}
