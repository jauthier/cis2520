
#include <stdio.h>
#include <stdlib.h>

void printArray(int a[], int n);
void swap(int * x, int * y);
void bubblesort(int a[], int n);

int main(){
    
    int array[50];
    
    for (int i=0;i<50;i++){
        array = rand() % 1000;
    }
    
    printArray(array, 50);
    
    bubblesort(array, 50);
    
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

void bubblesort(int a[], int n){
    int i, j;
    
    for (i=0;i<n;i++){
        for (j=0;j<n-i-1;j++){
            if (a[j]>a[j+1])
                swap(&a[j], &a[j+1]);
        }
    }
}
