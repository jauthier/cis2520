
/*
---------------
wrote createBinTree and destroyBinTree functions first and tested them:
NOTE: destroyBinTree only freed the tree, not the nodes at this point
- forgot a library
- fixed BinTreeNode struct 
- compiles and runs
----------------

Wrote isTreeEmpty, getRootNode, getLeftSubtree, getLeftSubtree, maxHeight

Then wrote insert, which is the static function that addToTree calls
 -- after writing insert I tested it by calling it and passing it the 
  value 6
   -- to check if it worked I called getRootData, because it should be the 
    only node in the tree
      -- the output should be "6" 
      -- the output was "6"
 -- I then added another node with the value of 10
   -- to check if it worked I called getRootData(getRightSubTree(newTree))
    which gets the data of the root of the right subtree\
      -- the output shoud be "10"
      -- the output was "10"
 -- I then added another node with the value of 13
   -- to check if it worked I called getRootData(getRightSubTree(getRightSubTree(newTree)))
    which gets the data of the root of the right subtree of the right subtree
      -- the output shoud be "13"
      -- the output was "13"









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
    newTree = addToTree(newTree, &num3);
    
    printf("%d\n", *(int *)(getRootData(newTree)));
    printf("%d\n", *(int *)(getRootData(getRightSubtree(newTree))));
    printf("%d.\n", *(int *)(getRootData(getRightSubtree(getRightSubtree(newTree)))));
    
    destroyBinTree(newTree);
    return 0;
}

