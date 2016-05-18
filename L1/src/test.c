#include <stdio.h>
#include "fractions.h"

int main(int argc, char * argv[]){
    
    int a, b, c, d;
    Fraction *fract, *fract2, *sum, *product;

    printf("Welcome to fraction test program\n");
    
    printf("Enter a numerator:\n");
    scanf("%d", &a);

    printf("Enter a denominator:\n");
    scanf("%d", &b);
    
    fract = createFraction(a, b);
    if ()//check if returns null

    printf("The numerator is: %d, the denominator is: %d.\n", getNumerator(fract), getDenominator(fract));
    
    printf("Lets make another fraction.\nEnter a numerator:\n");
    scanf("%d", &c);

    printf("Enter a denominator:\n");
    scanf("%d", &d);

    fract2 = createFraction(c, d);
    printf("The numerator is: %d, the denominator is: %d.\n", getNumerator(fract2), getDenominator(fract2));

    sum = add(fract, fract2);
    printf("The sum is: %d/%d.\n", getNumerator(sum), getDenominator(sum));

    product = multiply(fract, fract2);
    printf("The product is: %d/%d.\n", getNumerator(product), getDenominator(product));

    return 0;
}
