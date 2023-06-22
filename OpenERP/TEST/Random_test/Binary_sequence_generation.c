#include <stdio.h>
int n;
int x[100];

void output(){
    for(int i = 1; i <= n; i++){
        printf("%d", x[i]);
    }
    printf("\n");
}

void Try(int k){
    for(int v = 0; v <= 1; v++){
        x[k] = v;
        if(k == n) output();
        else Try(k + 1);
    }
}

int main(){
    scanf("%d", &n);
    Try(1);
    return 0;
}
