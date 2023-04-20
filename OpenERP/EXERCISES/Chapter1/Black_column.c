#include <stdio.h>
int n, m;
int a[1001][1001];
int b[1001];
int cnt;
void input(){
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf("%d", &a[i][j]);
        }
    }
}

void solve(){
    for(int i = 0; i < m; i++){
        b[i] = 1;
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(a[i][j] == 0){
                b[j] = 0;
            }
        }
    }
    for(int i = 0; i < m; i++){
        if(b[i] == 1){
            cnt++;
        }
    }
}

int main(){
    input();
    solve();
    printf("%d", cnt);
}