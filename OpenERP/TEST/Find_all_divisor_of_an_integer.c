#include <stdio.h>
int a[100000];
int main(){
    int j = 0;
    int n; scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        if(n % i == 0){
            a[j] = i;
            j++;
        }
    }
    for(int i = j - 1; i >= 0; i--){
        printf("-%d ", a[i]);
    }
    for(int i = 0; i < j; i++){
        printf("%d ", a[i]);
    }
}