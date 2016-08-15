/*
    Binary Tree ADT
    
    Author: Jessica Authier 
    2016/08/12
*/

#include "bintree.h"

/*
    This function take a binary tree as a parameter, checks the height of it's left and right branches
    
    then returns the difference in height of the two branches.  
    The function returns 0 if the right and left branches have the same height (the tree is balanced).
                         -1 if the left branch has a height one greater than the right branch (the tree is balanced)
                         1 if the  right branch has a height one greater than the left branch (the tree is balanced)
                         < -1 if the left branch has a height two or more greater than the right branch (the tree is not balanced)
                         > 1 if the right branch has a height two or more greater than the left branch (the tree is not balanced)
*/
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

/*
    This funtion is used in the balancing step.
    
    If the imbalance looks like this:
    
    1 
     \
      2
       \
        3
    
    Then, this function is called and it rearranges the tree to look like:
    
      2
     / \
    1   3
    
*/
static BinTreeNode * rotateRight(BinTreeNode * hold){
    
    BinTreeNode * temp = hold->right; // store the right node of hold as temp
    hold->right = temp->left; // replace the right node of hold with the left node of temp
    temp->left = hold; // set hold as the left node of temp
    
    return temp; // returns temp which was the right node of the given root, but will now be the new root
}

/*
    This funtion is used in the balancing step.
    
    If the imbalance looks like this:
    
        3
       /
      2
     /
    1
    
    Then, this function is called and it rearranges the tree to look like:
    
      2
     / \
    1   3
    
*/
static BinTreeNode * rotateLeft(BinTreeNode * hold){
    
    BinTreeNode * temp = hold->left; // store the left node of hold as temp
    hold->left = temp->right; // replace the left node of hold with the right node of temp
    temp->right = hold; // set the right node of temp to be hold
    
    return temp; // returns temp, which was the left node of the given root, but will now be the new root
}

/*
    This function creates, initializes and allocates memory for a new tree node.
    It takes in a void pointer as a parameter, which points to the data the node will contain.
    It returns the newly created node.
*/
static BinTreeNode * createNode(void * data){
    
    BinTreeNode * newNode = malloc(sizeof(BinTreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    
    return newNode;
}

/*
    This function is for destroying nodes.
    It calls the destroy function given by the user to destroy the data contained in the node.
    Then it frees the memory allocated for the node.
*/
static void destroyNode(BinTreeNode * toDestroy, void (*destroy)(void *)){
    
    destroy(toDestroy->data);
    free(toDestroy);
}

/*
    This function is a recursive function used to cycle through the nodes and destroy them.
*/
static void destroyRec(BinTreeNode * node, int level, void (*destroy)(void *)){
    
    if (level == 1){
        if (node == NULL){
            return;
        } else {
            destroyNode(node, destroy);
        }
    } else {
        if (node == NULL)
            return;
        destroyRec(node->left, level-1, destroy);
        destroyRec(node->right, level-1, destroy);
    }    
}

/*
    This function is the recursive function used to insert new nodes to the tree.
*/
static BinTree * insert(BinTree * tree, void * data){
    
    /*  if the data from toAdd is 'less than' the data from the root(tree->root) then it goes to the left
        the compare function will return a number greater than 0 if this is the case

        if the data from toAdd is 'greater than' the data from the root(tree->root) then it goes to the right
        the compare function will return a number less than 0 if this is the case  */
    
    if (isTreeEmpty(tree) == 1){ // if (tree->root == NULL) --->the tree is empty
        
        BinTreeNode * toAdd = createNode(data); // create the node to store the data
        tree->root = toAdd; // add it to the tree
        
    } else if (tree->compare(tree->root->data, data) > 0){ // if (tree->root->data > data)
        
        // set the left node --> data less than the root data goes to the left
        tree->root->left = (insert(getLeftSubtree(tree), data))->root; 
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

/*
    This function is a recursive function used to remove nodes from a tree.
*/
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
    
    int i = 0;
    int h = maxHeight(tree);
 
    for(i=1; i<=h; i++){
        destroyRec(tree->root, i, tree->destroy);
    }
    free(tree); // free the tree
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
