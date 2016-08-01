#include <stdio.h>
#include "restaurant.h"
#include "treeInterface.h"

int count;



void printRestaurant(void * toPrint) {
    Restaurant * temp = (Restaurant*) toPrint;
    printf("Name: %s\n",temp->name);
    printf("Type: %s\n", temp->type);
    printf("Rating: %d/5\n", temp->rating);
}

int maxHeight(Tree * tree);
int printTree(Tree * tree, int level);


int main(){
    
    //make test restaurants
    Restaurant * r1 = createRestaurant("Subway", "sandwich", 4);
    Restaurant * r2 = createRestaurant("Mr Sub", "sandwich", 3);
    Restaurant * r3 = createRestaurant("Pizza Pizza", "pizza", 4);
    Restaurant * r4 = createRestaurant("Swiss Chalet", "eat in", 3);
    Restaurant * r5 = createRestaurant("Burrito Boys", "mexican", 5);
    Restaurant * r6 = createRestaurant("The Keg", "steak house", 5);
    Restaurant * r7 = createRestaurant("McDonalds", "fast", 2);
    Restaurant * r8 = createRestaurant("Dairy Queen", "ice cream", 4);
    Restaurant * r9 = createRestaurant("Wendy's", "fast", 2);
    Restaurant * r10 = createRestaurant("Wok Wagon", "fast", 3);
    
    // create trees
    Tree * nameTree, * ratingTree;
    
    nameTree = createBinTree(&compareName, &destroyRestaurant);
    ratingTree = createBinTree(&compareRating, &destroyRestaurant);

    // add the restaurants to the tree sorted by name
    addToTree(nameTree, r1);
    addToTree(nameTree, r2);
    addToTree(nameTree, r3);
    addToTree(nameTree, r4);
    addToTree(nameTree, r5);
    addToTree(nameTree, r6);
    addToTree(nameTree, r7);
    addToTree(nameTree, r8);
    addToTree(nameTree, r9);
    addToTree(nameTree, r10);


    
    printInOrder(nameTree, &printRestaurant);
    printf("\n");
    //printPreOrder(nameTree, &printRestaurant);
    
    // add the restaurants to the tree sorted by rating
    addToTree(ratingTree, r1);
    addToTree(ratingTree, r2);
    addToTree(ratingTree, r7);
    addToTree(ratingTree, r3);
    addToTree(ratingTree, r4);
    addToTree(ratingTree, r5);
    addToTree(ratingTree, r6);

    //printInOrder(ratingTree, &printRestaurant);
    //printPreOrder(ratingTree, &printRestaurant);

    printf("maxLen: %d\n",maxHeight(nameTree));
    printTree(nameTree, 0);

    return 0;
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

int printTree(Tree * tree, int level){
    
    Restaurant * root = getRootData(tree);
    //if (root == NULL) //this branch is done
      //  return 0;
    
    Tree * right = getRightSubtree(tree);
    Tree * left = getLeftSubtree(tree);
//printf("here\n");
    if (right != NULL)
        printTree(right, level+1);
    
    for (int i=0; i<(level*12); i++){
        printf(" ");
    }
    printf("%s(%d)\n", root->name, root->rating);
    
    if (left != NULL)
        printTree(left, level+1);
    
    return 0;
}



