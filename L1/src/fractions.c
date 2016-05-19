/*
Fraction ADT

Author: Jessica Authier, 0849720

This file contains functions that create, manipulate and destroy 
fraction data types.

*/

#include "fractions.h"

/*
    createFraction takes two intergers, one for the numerator and one for the denominator,
    and creates a fraction with them. 
    
    Parameters: int numer --> the numerator of the fraction
                int denom --> the denominatorof the fraction
    
    Return: if the fraction is valid --> pointer to the fraction
            if the fraction isn't valid (dividing by 0) --> NULL
        
*/
Fraction *createFraction( int numer, int denom) {
    
    if (denom != 0){
        Fraction *frac;
        frac = (Fraction *)malloc(sizeof(Fraction));
        frac->numerator = numer;
        frac->denominator = denom;
        return frac;
    }
    else {
        //printf("You cannot divide by 0!\nYour fraction was not created\n");
        return NULL;
    }
}

/*
    getNumerator takes a fraction and returns its numerator
    
    parameter: frac --> pointer to a fraction

    return: the numerator of the given fraction
    
*/
int getNumerator(Fraction *frac) {
    
    return frac->numerator;
}

/*
    getDenominator takes a fraction and returns its denominator
    
    parameter: frac --> pointer to a fraction

    return: the denominator of the given fraction
    
*/
int getDenominator(Fraction *frac) {
    
    return frac->denominator;
}

/*
    add takes two fractions and adds them, keeping them in their fraction form
    
    parameters: f1 --> pointer to the first fraction
                f2 --> pointer to the second fraction
                
    return: a pointer to the sum fraction
    
*/
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

/*
    multiply takes two fractions and multiplies them, keeping them in their fraction form
    
    parameters: f1 --> pointer to the first fraction
                f2 --> pointer to the second fraction
                
    return: a pointer to the product fraction
    
*/
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

/*
    destroyFraction gets rid of the fraction and frees the memory is was occuping
    
    parameter: toDestroy --> a pointer to the fraction you wish to destroy
    
    return: none 

*/
void destroyFraction(Fraction *toDestroy) {
    
    free(toDestroy);
}

