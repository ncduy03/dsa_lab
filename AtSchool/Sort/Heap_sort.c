#include <stdio.h>
void heapify(int A[], int i, int N){
    int L = 2 * i;
    int R = 2 * i + 1;
    int max = i;
    if(L <= N && A[L] > A[i])
        max = L;
    if(R <= N && A[R] > A[max])
        max = R;
    if(max != i){ 
        int tmp = A[i];
        A[i] = A[max];
        A[max] = tmp;
        heapify(A, max, N);
    }
}

void buildHeap(int A[], int N){
    for(int i = N / 2; i >= 1; i--)
        heapify(A, i, N);
    }
void heapSort(int A[], int N){
    // index từ 1 -> N
    buildHeap(A,N);
    for(int i = N; i > 1; i--){
        int tmp = A[i];
        A[i] = A[1];
        A[1] = tmp;
        heapify(A, 1, i-1); 
    }
}

int main(){
    int N; scanf("%d", &N);
    int A[N];
    for(int i = 1; i <= N; i++){
        scanf("%d", &A[i]);
    }
    heapSort(A, N);
    for (int i = 1; i <= N; i++) {
        printf("%d ", A[i]);
    }
    return 0;
}
