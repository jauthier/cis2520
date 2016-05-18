#include "fractions.h"

Fraction *createFraction( int numer, int denom) {
    
    if (denom != 0){
        Fraction *frac;
        frac = (Fraction *)malloc(sizeof(Fraction));
        frac->numerator = numer;
        frac->denominator = denom;
        return frac;
    }
    else {
        printf("You cannot divide by 0!\nYour fraction was not created\n");
        return NULL;
    }
}

int getNumerator(Fraction *frac) {
    
    return frac->numerator;
}

int getDenominator(Fraction *frac) {
    
    return frac->denominator;
}

Fraction *add(Fraction *f1, Fraction *f2) {
    
    Fraction *sum;
    /* f1=a/b  f2=c/d */
    int a, b, c, d;
    
    a = f1->numerator;
    b = f1->denominator;
    c = f2->numerator;
    d = f2->denominator;
    sum = (Fraction *)malloc(sizeof(Fraction));
    
    if (b == d){ /* same denominator*/
        sum->numerator = a + c;
        sum->denominator = b;
    }else { /*find a common denominator*/
        sum->numerator = (a * d) + (c * b);
        sum->denominator = b * d;
    }
    
    return sum;
}

Fraction *multiply (Fraction *f1, Fraction *f2) {
    
    Fraction *product;
    
    /* f1=a/b  f2=c/d */
    int a, b, c, d;
    
    a = f1->numerator;
    b = f1->denominator;
    c = f2->numerator;
    d = f2->denominator;
    product = (Fraction *)malloc(sizeof(Fraction));
    
    product->numerator = a * c;
    product->denominator = b * d;
    
    return product;
}

void destroyFraction(Fraction *toDestroy) {
    
    free(toDestroy);
}

