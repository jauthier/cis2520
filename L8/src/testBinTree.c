#include <stdio.h>
#include "restaurant.h"
#include "treeInterface.h"

int main(){
    
    //make test restaurants
    Restaurant * r1 = createRestaurant("Subway", "sandwich", 1);
    Restaurant * r2 = createRestaurant("Mr Sub", "sandwich", 5);
    Restaurant * r3 = createRestaurant("Pizza Pizza", "pizza", 4);
    Restaurant * r4 = createRestaurant("Swiss Chalet", "eat in", 3);
    Restaurant * r5 = createRestaurant("Burrito Boys", "mexican", 5);
    Restaurant * r6 = createRestaurant("The Keg", "steak house", 5);
    Restaurant * r7 = createRestaurant("McDonalds", "fast", 2);
    
    // create trees
    Tree * nameTree, * ratingTree;
    
    nameTree = createBinTree(compareName, destroyRestaurant);
    ratingTree = createBinTree(compareRating, destroyRestaurant);

    // add the restaurants to the tree sorted by name
    addToTree(nameTree, r1);
    addToTree(nameTree, r2);
    addToTree(nameTree, r3);
    addToTree(nameTree, r4);
    addToTree(nameTree, r5);
    addToTree(nameTree, r6);
    addToTree(nameTree, r7);
    
    // add the restaurants to the tree sorted by rating
    addToTree(ratingTree, r1);
    addToTree(ratingTree, r2);
    addToTree(ratingTree, r3);
    addToTree(ratingTree, r4);
    addToTree(ratingTree, r5);
    addToTree(ratingTree, r6);
    addToTree(ratingTree, r7);
    // first row
    Restaurant * test = (Restaurant *)getRootData(ratingTree);
    printf("%s\n",test->name);
    
    // second row
    Tree * right1 = getRightSubtree(ratingTree);
    if (right1 == NULL ){
        printf("Here\n");
    } else {
        test = (Restaurant *)getRootData(right1);
        printf("%s\n",test->name);
    }

    Tree * left1 = getLeftSubtree(ratingTree);
    if (left1 == NULL ){
        printf("Here\n");
    } else {
        test = (Restaurant *)getRootData(left1);
        printf("%s\n",test->name);
    }

    // third row

    Tree * hold = right1;
    right1 = getRightSubtree(hold);
    if (right1 == NULL ){
        printf("Here\n");
    } else {
        test = (Restaurant *)getRootData(right1);
        printf("%s\n",test->name);
    }
    left1 = getLeftSubtree(hold);
    if (left1 == NULL ){
        printf("Here\n");
    } else {
        test = (Restaurant *)getRootData(left1);
        printf("%s\n",test->name);
    }

    // forth row
    hold = left1;
    right1 = getRightSubtree(hold);
    if (right1 == NULL ){
        printf("Here\n");
    } else {
        test = (Restaurant *)getRootData(right1);
        printf("%s\n",test->name);
    }
    left1 = getLeftSubtree(hold);
    if (left1 == NULL ){
        printf("Here\n");
    } else {
        test = (Restaurant *)getRootData(left1);
        printf("%s\n",test->name);
    }
    
    
    hold = left1;
    right1 = getRightSubtree(hold);
    if (right1 == NULL ){
        printf("Here\n");
    } else {
        test = (Restaurant *)getRootData(right1);
        printf("%s\n",test->name);
    }
    left1 = getLeftSubtree(hold);
    if (left1 == NULL ){
        printf("Here\n");
    } else {
        test = (Restaurant *)getRootData(left1);
        printf("%s\n",test->name);
    }

    return 0;
}
