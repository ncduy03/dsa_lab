#include <stdio.h>
#define N 100
int n, M;
int x[N]; // solution representing
int T; // represents the sum of the assigned variables
void solution(){
    for(int i = 1; i <= n; i++){
        printf("%d ", x[i]);
    }
    printf("\n");
}

int check(int v, int k){
    if(k < n) return 1;
    return T + v == M;
}

void Try(int k){
    for(int v = 1; v <= M - T - (n - k); v++){
        if(check(v, k)){
            x[k] = v;
            T += v;
            if(k == n) solution();
            else Try(k + 1);
            T -= v;
        }
    }
}

int main(){
    scanf("%d %d", &n, &M);
    Try(1);
    return 0;
}