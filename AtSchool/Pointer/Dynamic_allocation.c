/*
int a[1000] -> cấp phát tĩnh 1000 số int (1 int -> 4 byte)
cấp phát động: cần đến đâu cấp phát đến đó
VD: đọc input n = 10 -> chỉ xin OS cấp phát array 10 phần tử vừa đủ lưu trữ dãy đầu vào n phần tử
*/

#include <stdio.h>
#include <stdlib.h>
int main(){
    int i, n, *p;
    printf("How many numbers do you want to enter?\n");
    scanf("%d", &n);
    p = (int *)malloc(n * sizeof(int));
    if(p == NULL){
        printf("Memory allocation failed\n");
        return 1;
    }

    free(p); // deallocate
    return 0;
}