
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
   -- to check if it worked i called getRootData, because it should be the 
    only node in the tree
      -- the output was ""
 









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
    int num1, num2;
    num1 = 6;
    
    newTree = addToTree(newTree, &num1);
    
    printf("%d\n", *(int *)(getRootData(newTree)));
    
    
    
    destroyBinTree(newTree);
    return 0;
}

