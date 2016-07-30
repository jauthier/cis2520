
#include <stdio.h>
#include "restaurant.h"

int main(){
    
    // testing the create function
    Restaurant * r1 = createRestaurant("Subway","sanwiches",4);
    Restaurant * r2 = createRestaurant("Mr Sub","sandwiches",5);
    
    // testing the compare rating function
    int compRating = compareRating(r1,r2);
    
    if (compRating < 0)
        printf("%s is rated higher than %s.\n", r2->name, r1->name);
    else if (compRating == 0)
        printf("They have the same rating.\n");
    else
        printf("%s is rated higher than %s.\n", r1->name, r2->name);
    
    
    // testing the compare name function
    int compName = compareName(r1,r2);
    
    if (compName < 0)
        printf("%s, %s\n.", r2->name, r1->name);
    else if (compName == 0)
        printf("They have the same name.\n");
    else
        printf("%s, %s\n.", r1->name, r2->name);
    
    // testing destroy function
    destroy(r1);
    destroy(r2);
    
    return 0;
}