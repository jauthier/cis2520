/*
    Program for testing some binTree functions.
    
    Author: Jessica Authier
    2016/08/01    
*/

#include "restaurantFunctions.h"

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


    
    printInOrder(nameTree, &printRestaurant); // print in order
    printf("\n");
    printTree(nameTree, 0); // print as a tree
    printf("\n");
    
    // add the restaurants to the tree sorted by rating
    addToTree(ratingTree, r1);
    addToTree(ratingTree, r2);
    addToTree(ratingTree, r7);
    addToTree(ratingTree, r3);
    addToTree(ratingTree, r4);
    addToTree(ratingTree, r5);
    addToTree(ratingTree, r6);

    printInOrder(ratingTree, &printRestaurant); //print in order
    printf("\n");
    printTree(ratingTree); // print as a tree
    printf("\n");
    
    //destroy the trees
    destory(nameTree);
    destroy(ratingTree);
    
    return 0;
}

