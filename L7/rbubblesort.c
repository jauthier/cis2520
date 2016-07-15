#include <stdio.h>
#include <stdlib.h>

void printArray(int a[], int n);
void swap(int * x, int * y);
void rbubblesort(int a[], int n);

int main(){
    
    int array[50];
    
    for (int i=0;i<50;i++){
        array[i] = rand() % 1000;
    }
    
    printArray(array, 50);
    
    rbubblesort(array, 50);
    
    printArray(array, 50);
    
    return 0;
}

void printArray(int a[], int n){
    int i;
    for (i=0;i<n;i++){
        printf("%d, ",a[i]);
    }
    printf("\n");
}

void swap(int * x, int * y){
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void rbubblesort (int a[], int n){
    int i;
    
    for (i=0;i<n-1;i++){
        if (a[i] >  a[i+1])
            swap(&a[i],&a[i+1]);
    }
    
    if (n > 2)
        rbubblesort(a, n-1);
}