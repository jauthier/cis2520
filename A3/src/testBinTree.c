
/*
---------------
wrote createBinTree and destroyBinTree functions first and tested them:
NOTE: destroyBinTree only freed the tree, not the nodes at this point
- forgot a library
- fixed BinTreeNode struct 
- compiles and runs
----------------

Wrote isTreeEmpty, getRootNode, getLeftSubtree, getLeftSubtree, maxHeight


Started addToTree







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
    newTree = addToTree(&num1);
    
    
    destroyBinTree(newTree);
    return 0;
}

