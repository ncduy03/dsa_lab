#include <stdio.h>
void insertionSort(int A[], int N){
    // index 1 -> N
    for(int k = 2; k <= N; k++){
        int last = A[k];
        int j = k;
        while(j > 1 && A[j-1] > last){
            A[j] = A[j-1];
            j--;
        }
        A[j] = last;
        for(int i = 0; i < N; i++){
            printf("%d ", A[i]);
        }
        printf("\n");
    }
}

void selectionSort(int A[], int N){
    // index 1 -> N
    for(int k = 1; k <= N; k++){
        int min = k;
        for(int j = k + 1; j <= N; j++){
            if(A[min] > A[j]) min = j;
        }
        int tmp = A[min]; 
        A[min] = A[k]; 
        A[k] = tmp;
    }
}

void bubleSort(int A[], int N){
    // index tu 1 den N
    int swapped;
    do{
        swapped = 0;
        for(int i = 1; i < N; i++){
            if(A[i] > A[i+1]){
                int tmp = A[i]; 
                A[i] = A[i+1];
                A[i+1] = tmp;
                swapped = 1;
            }
        }
        // for(int i = 1; i <= N; i++){
        //     printf("%d ", A[i]);
        // }
        // printf("\n");
    }while(swapped == 1); 
}

int main(){
    int n; scanf("%d", &n);
    int a[n];
    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
    }
    // insertionSort(a, n);
    // selectionSort(a, n);
    bubleSort(a, n);
    for(int i = 1; i <= n; i++){
        printf("%d ", a[i]);
    }
}