#include <stdio.h>
#define N 100
int n;
int mark[N];
int x[N];
int check(int v, int k){
    return mark[v] == 0;
}

void solution(){
    for(int i = 1; i <= n; i++){
        printf("%d ", x[i]);
    }
    printf("\n");
}

void Try(int k){
    for(int v = 1; v <= n; v++){
        if(check(v, k)){
            x[k] = v;
            mark[v] = 1;
            if(k == n) solution();
            else Try(k + 1);
            mark[v] = 0;
        }
    }
}

int main(){
    scanf("%d", &n);
    Try(1);
    return 0;
}