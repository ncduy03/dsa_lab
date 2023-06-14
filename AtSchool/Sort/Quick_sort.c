#include <stdio.h>
int partition(int A[], int L, int R, int indexPivot){
    int pivot = A[indexPivot];
    int tmp1 = A[R];
    A[R] = A[indexPivot];
    A[indexPivot] = tmp1;
    int storeIndex = L;
    for(int i = L; i <= R-1; i++){
        if(A[i] < pivot){
            int tmp2 = A[i];
            A[i] = A[storeIndex];
            A[storeIndex] = tmp2;
            storeIndex++;
        }
    }
    int tmp3 = A[R];
    A[R] = A[storeIndex];
    A[storeIndex] = tmp3;
    return storeIndex;
}

void quickSort(int A[], int L, int R){
    if(L < R){
        int index = (L + R)/2;
        index = partition(A, L, R, index);
    if(L < index)
        quickSort(A, L, index-1);
    if(index < R)
        quickSort(A, index+1, R);
    }
}

int main(){
    int N; scanf("%d", &N);
    int A[N];
    for(int i = 0; i < N; i++){
        scanf("%d", &A[i]);
    }
    quickSort(A, 0, N - 1);
    for (int i = 0; i < N; i++) {
        printf("%d ", A[i]);
    }
    return 0;
}