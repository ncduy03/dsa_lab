/*
int a[1000] -> cấp phát tĩnh 1000 số int (1 int -> 4 byte)
cấp phát động: cần đến đâu cấp phát đến đó
VD: đọc input n = 10 -> chỉ xin OS cấp phảt array 10 phần tử vừa đủ lưu trữ dãy đầu vào n phần tử
*/

#include <stdio.h>
int main(){
    int i, n, *p;
    printf("How many numbers do you want to enter?\n");
    scanf("%d", &n);
}