
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

remove from tree wasn't removing the root node
deleting the left node didn't work either
 -- was comparing the outcome of the compare pointer function to the wwrong number
 






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
    //free(toDestroy);
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
 
    for(i=1; i<=h; i++){
        printf("Level %d : ", i);
        printTreeLevelRec(tree->root, i);
        printf("\n");
        
    }
}

int main(){
    
    //create
    BinTree * newTree = createBinTree(&testCompare, &testDestroyNode);
    
    
    int num1, num2, num3, num4, num5, num6;
    num1 = 6;
    num2 = 10;
    num3 = 13;
    num4 = 2;
    num5 = 9;
    num6 = 7;
    
    // add to the tree
    printf("\nAdding node: 6\n--------------\n");
    newTree = addToTree(newTree, &num1);
    printTreeLevel(newTree);
    
    printf("\nAdding node: 6\n--------------\n");
    newTree = addToTree(newTree, &num2);
    printTreeLevel(newTree);
    
    printf("\nAdding node: 6\n--------------\n");
    newTree = addToTree(newTree, &num3);
    printTreeLevel(newTree);
    
    // testing removeFromTree
    printf("\nDeleteing the root node\n----------------------\n");
    newTree = removeFromTree(newTree, &num2);
    printTreeLevel(newTree);
    
    // add node 10 back
    printf("\nAdding node: 10\n--------------\n");
    newTree = addToTree(newTree, &num2);
    printTreeLevel(newTree);
    
    //test what happens when we add a multiple
    printf("\nAdding node: 10\n--------------\n");
    newTree = addToTree(newTree, &num2);
    printTreeLevel(newTree);
    
    // testing more addToTree
    printf("\nAdding node: 2\n--------------\n");
    newTree = addToTree(newTree, &num4);
    printTreeLevel(newTree);

    printf("\nAdding node: 7\n--------------\n");
    newTree = addToTree(newTree, &num6);
    printTreeLevel(newTree);
    
    printf("\nAdding node: 9\n--------------\n");
    newTree = addToTree(newTree, &num5);
    printTreeLevel(newTree);

    
    destroyBinTree(newTree);
    
    if (newTree->root == NULL)
        printf("the tree is gone\n");
    else 
        printf("%p\n",(void *)newTree);
    
    return 0;
}
