#include <stdio.h>
int m, n, p;
int a[101][101], b[101][101], c[101][101];
void input(){
    scanf("%d %d", &m, &n);
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            scanf("%d", &a[i][j]);
        }
    }
    scanf("%d %d", &n, &p);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < p; j++){
            scanf("%d", &b[i][j]);
        }
    } 
}

void output(){
   for(int i = 0; i < m; i++){
        for(int j = 0; j < p; j++){
            printf("%d ", c[i][j]);
        }
        printf("\n");
   } 
}

void solve(){
    for(int i = 0; i < m; i++){
        for(int j = 0; j < p; j++){
            for(int k = 0; k < n; k++){
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

int main(){
    input();
    solve();
    output();
}