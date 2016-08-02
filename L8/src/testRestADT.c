
#include <stdio.h>
#include "restaurant.h"

int main(){
    
    // testing the create function
    Restaurant * r1 = createRestaurant("Subway","sanwiches",4);
    Restaurant * r2 = createRestaurant("Mr Sub","sandwiches",5);
    Restaurant * r3 = createRestaurant("Swiss Chalet","sandwiches",3);
    Restaurant * r4 = createRestaurant("McDonalds","sandwiches",2);
    Restaurant * r5 = createRestaurant("Burrito Boys","sandwiches",5);
    Restaurant * r6 = createRestaurant("Taco Bell","sandwiches",1);

    // testing the compare rating function
    /*
        testing when the first parameter is rated less than the second
        The program you print to consol "Mr Sub is rated higher than Subway."
        if the compareRating function work correctly
    */
    int compRating = compareRating(r1,r2);
    if (compRating < 0)
        printf("%s is rated higher than %s.\n", r2->name, r1->name);
    else if (compRating == 0)
        printf("They have the same rating.\n");
    else
        printf("%s is rated higher than %s.\n", r1->name, r2->name);
    
    /*
        testing when the first parameter is rated more than the second
        The program you print to consol "Subway is rated higher than Swiss Chalet."
        if the compareRating function work correctly
    */
    compRating = compareRating(r1,r3);
    if (compRating < 0)
        printf("%s is rated higher than %s.\n", r3->name, r1->name);
    else if (compRating == 0)
        printf("They have the same rating.\n");
    else
        printf("%s is rated higher than %s.\n", r1->name, r3->name);
    
    /*
        testing when the first and second parameters are rated the same
        The program you print to consol "They have the same rating."
        if the compareRating function work correctly
    */
    compRating = compareRating(r5,r2);
    if (compRating < 0)
        printf("%s is rated higher than %s.\n", r2->name, r5->name);
    else if (compRating == 0)
        printf("They have the same rating.\n");
    else
        printf("%s is rated higher than %s.\n", r5->name, r2->name);





    // testing the compare name function
    int compName = compareName(r1,r2);
    
    if (compName < 0)
        printf("%s, %s\n.", r2->name, r1->name);
    else if (compName == 0)
        printf("They have the same name.\n");
    else
        printf("%s, %s\n.", r1->name, r2->name);
    
    // testing destroy function
    destroyRestaurant(r1);
    destroyRestaurant(r2);
    
    return 0;
}
