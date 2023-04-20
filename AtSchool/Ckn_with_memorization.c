#include <stdio.h>
#define MAX 1000
#define P 1000000007;
int M[MAX][MAX];
int k, n;
int C(int k, int n){
    if(k == 0 || k == n)
        M[k][n] = 1;
    else if(M[k][n] == 0)
        M[k][n] = (C(k, n - 1) + C(k - 1, n - 1));
    return M[k][n];
}

int main(){
    scanf("%d %d", &k, &n);
    for(int i = 0; i < MAX; i++){
        for(int j = 0; j < MAX; j++){
            M[i][j] = 0;
        }
    }
    printf("%d ", C(k, n));
}