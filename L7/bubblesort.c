
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printArray(int a[], int n);
void swap(int * x, int * y);
void bubblesort(int a[], int n);

int main(){
    
    clock_t start, end;
    int array[1000];
    
    for (int i=0;i<1000;i++){
        array[i] = rand() % 1000;
    }
    
    //printArray(array,1000);
    start = clock();
    bubblesort(array, 1000);
    end = clock();
    //printArray(array, 1000);
    
    printf("time it took: %f", (double)(end - start) / CLOCKS_PER_SEC );    
    
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
