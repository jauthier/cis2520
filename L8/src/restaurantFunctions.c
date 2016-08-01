/*
    restaurantFunctions.c
    
    Author: Jessica Authier
    2016/08/01    
*/

#include "restaurantFunctions.c"

void printRestaurant(void * toPrint) {
    Restaurant * temp = (Restaurant*) toPrint;
    printf("Name: %s\n",temp->name);
    printf("Type: %s\n", temp->type);
    printf("Rating: %d/5\n", temp->rating);
}

int maxHeight(Tree * tree){
    
    if (tree == NULL)
        return 0;
    int left = maxHeight(getLeftSubtree(tree));
    int right = maxHeight(getRightSubtree(tree));
    if (left < right)
        return right + 1;
    else
        return left + 1;
}

void printTree(Tree * tree, int level){
    
    Restaurant * root = getRootData(tree);
    
    Tree * right = getRightSubtree(tree); // set set the right side as a subtree
    Tree * left = getLeftSubtree(tree); // set set the left side as a subtree
    
    if (right != NULL) // if there is a node on the right
        printTree(right, level+1); // evaluate that node
    
    for (int i=0; i<(level*5); i++){
        printf(" ");
    }
    
    printf(" %s(%d)\n", root->name, root->rating);
    
    if (left != NULL) // if there is a node on the right
        printTree(left, level+1);
    count = count + 1;
    return 0;
}
