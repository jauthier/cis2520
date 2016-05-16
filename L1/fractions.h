#include <stdio.h>

typedef struct {
    int numerator;
    int denominator;
    int gcd;
} Fraction;

Fraction createFraction( int numer, int denom);
/*
    preconditions: none
    postconditions: a fraction it created with the appropriate numerator and denominator
*/

int getNumerator(Fraction frac);
/*
    preconditions: an initialized fraction is given as a parameter
    postconditions: none
*/

int getDenominator(Fraction frac);
/*
    preconditions: an initialized fraction is given as a parameter
    postconditions: none
*/

Fraction add(Fraction f1, Fraction f2);
/*
    preconditions: two initialized fractions are given as parameters
    postconditions: the two fractions are added together and the result
    is placed in a new Fraction variable and return to the calling function
*/

Fraction multiply (Fraction f1, Fraction f2);
/*
    preconditions: two initialized fractions are given as parameters
    postconditions: the two fractions are multiplied together and the result
    is placed in a new Fraction variable and return to the calling function
*/

void destroyFraction(Fraction toDestroy);
/*
    preconditions: an initialized fraction is given as a parameter
    postconditions: the fraction is destroyed and the memory is released
*/