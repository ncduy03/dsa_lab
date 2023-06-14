#include <stdio.h>
void merge(int A[], int L, int M, int R){
    int i, j, k;
    int n1 = M - L + 1;
    int n2 = R - M;

    // Tạo các mảng tạm thời để lưu trữ các phần tử
    int Left[n1], Right[n2];

    // Sao chép dữ liệu vào các mảng tạm thời
    for (i = 0; i < n1; i++)
        Left[i] = A[L + i];
    for (j = 0; j < n2; j++)
        Right[j] = A[M + 1 + j];

    // Trộn các mảng tạm thời vào mảng gốc A
    i = 0; // Chỉ số ban đầu của mảng con trái
    j = 0; // Chỉ số ban đầu của mảng con phải
    k = L; // Chỉ số ban đầu của mảng kết quả

    for (k = L; k <= R; k++) {
        if (i < n1 && (j >= n2 || Left[i] <= Right[j])) {
            A[k] = Left[i];
            i++;
        } else {
            A[k] = Right[j];
            j++;
        }
    }
}

void mergeSort(int A[], int L, int R){
    if (L < R){
        int M = L + (R - L) / 2;
        // Gọi đệ quy để sắp xếp hai nửa mảng
        mergeSort(A, L, M);
        mergeSort(A, M + 1, R);
        // Trộn hai nửa mảng đã sắp xếp
        merge(A, L, M, R);
    }
}

int main() {
    int N; scanf("%d", &N);
    int A[N];
    for(int i = 0; i < N; i++){
        scanf("%d", &A[i]);
    }
    mergeSort(A, 0, N - 1);
    for (int i = 0; i < N; i++) {
        printf("%d ", A[i]);
    }
    return 0;
}
