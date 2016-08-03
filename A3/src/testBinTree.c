
/*
---------------
wrote createBinTree and destroyBinTree functions first and tested them:
NOTE: destroyBinTree only freed the tree, not the nodes at this point
- forgot a library


----------------









*/

#include <stdio.h>
#include "bintree.h"

int testCompare(void * data1, void * data2){
    return 1;
}

void testDestroyNode(void * toDestroy){
    printf("\n");
}

int main(){
    
    //create
    BinTree * newTree = createBinTree(&testCompare, &testDestroyNode);
    
    
    
    return 0;
}

