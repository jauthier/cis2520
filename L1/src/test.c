/*
    Fraction ADT test file
    Author: Jessica Authier, 0849720
    
    This file tests all the functions of the fraction ADT.
*/

#include <stdio.h>
#include "fractions.h"

int main(int argc, char * argv[]){
    
    int a, b, c, d;
    Fraction *fract, *fract2, *sum, *product;
    int check = 0;
    
    printf("Welcome to fraction test program\n");
    
    printf("Enter a numerator:\n");
    scanf("%d", &a);

    while (check == 0){
        printf("Enter a denominator:\n");
        scanf("%d", &b);
        
        fract = createFraction(a, b);
        if (fract != NULL) /*Check if the denominator is 0, if it is the user is prompted to enter a new number*/
            check = 1;
        else 
            printf("You cannot divide by 0!\n");
    }
    
    printf("The numerator is: %d, the denominator is: %d.\n", getNumerator(fract), getDenominator(fract));
    
    check = 0;
    printf("Lets make another fraction.\nEnter a numerator:\n");
    scanf("%d", &c);

    while (check == 0){
        printf("Enter a denominator:\n");
        scanf("%d", &d);
        
        fract2 = createFraction(c, d);
        if (fract2 != NULL) /*Check if the denominator is 0, if it is the user is prompted to enter a new number*/
            check = 1;
        else 
            printf("You cannot divide by 0!\n");
    }
    
    printf("The numerator is: %d, the denominator is: %d.\n", getNumerator(fract2), getDenominator(fract2));

    
    /*Test add function*/
    sum = add(fract, fract2);
    printf("The sum is: %d/%d.\n", getNumerator(sum), getDenominator(sum));

    /*Test multiply function*/
    product = multiply(fract, fract2);
    printf("The product is: %d/%d.\n", getNumerator(product), getDenominator(product));

    return 0;
}
