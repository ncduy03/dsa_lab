#include <stdio.h>
int f(int n){
    printf("%d\n", n);
    if(n == 0 || n == 1) return 1;
    return f(n - 1) + f(n - 2);
}

int main(){
    for(int i = 0; i <= 4; i++){
        printf("i = %d\n%d\n\n", i, f(i));
    }
}