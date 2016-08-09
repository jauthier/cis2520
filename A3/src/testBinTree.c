
/*
---------------
wrote createBinTree and destroyBinTree functions first and tested them:
NOTE: destroyBinTree only freed the tree, not the nodes at this point
- forgot a library
- fixed BinTreeNode struct 
- compiles and runs
----------------

Wrote isTreeEmpty, getRootNode, getLeftSubtree, getLeftSubtree, maxHeight

----------------
wrote insert, which is the static function that addToTree calls
 -- after writing insert I tested it by calling it and passing it the 
  value 6
   -- to check if it worked I called getRootData, because it should be the 
    only node in the tree
      -- the output should be "root: 6" 
      -- the output was "root: 6"
 -- I then added another node with the value of 10
   -- to check if it worked I called getRootData(getRightSubTree(newTree))
    which gets the data of the root of the right subtree\
      -- the output shoud be "root: 6, right: 10"
      -- the output was "root: 6, right: 10"
 -- I then added another node with the value of 13
   -- to check if it worked I called, getRootData(newTree) to check the new root, because it 
    should have changed from balancing, getRootData(getLeftSubtree(newTree)) to check the left
    node, and getRootData(getRightSubTree(newTree)) to check the right node
      -- the output shoud be "root: 10, right: 13, left: 6"
      -- the output was "root: 10, right: 13, left: 6"
----------------








*/

#include <stdio.h>
#include "bintree.h"

int testCompare(void * data1, void * data2){
    int num1, num2;
    
    num1 = *(int *)data1;
    num2 = *(int *)data2;
    
    return num1 - num2;
}

void testDestroyNode(void * toDestroy){
    printf("\n");
}

void printTreeLevelRec(BinTreeNode * node, int level){
    
    if (level == 1){
        if (node == NULL){
            printf("NULL ");
            return;
        } else {
            printf("%d ", *(int *)(node->data));
        }
    } else {
        if (node == NULL)
            return;
        printTreeLevelRec(node->left, level-1);
        printTreeLevelRec(node->right, level-1);
    }    
}

void printTreeLevel(BinTree * tree){
    int i = 0;
    int h = maxHeight(tree);
    printf("height: %d\n", h);
 
    for(i=1; i<=h; i++){
        printf("Level %d : ", i);
        printTreeLevelRec(tree->root, i);
        printf("\n");
    }
}

int main(){
    
    //create
    BinTree * newTree = createBinTree(&testCompare, &testDestroyNode);
    
    // add to the tree
    int num1, num2, num3;
    num1 = 6;
    num2 = 10;
    num3 = 13;
    
    newTree = addToTree(newTree, &num1);
    newTree = addToTree(newTree, &num2);
    //newTree = addToTree(newTree, &num3);
    
    printf("root: %d\n", *(int *)(getRootData(newTree)));
    printf("right: %d\n", *(int *)(getRootData(getRightSubtree(newTree))));
    //printf("left: %d\n", *(int *)(getRootData(getLeftSubtree(newTree))));
    
    printTreeLevel(newTree);
    
    
    destroyBinTree(newTree);
    return 0;
}
