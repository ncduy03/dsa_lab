#include <stdio.h>
int sum(int n){
    printf("%d\n", n);
    if(n == 1) return 1;
    return n + sum(n - 1);
}

int main(){
    int n; scanf("%d", &n);
    printf("%d", sum(n));
}