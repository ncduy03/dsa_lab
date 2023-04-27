#include<stdio.h>
int n, m;
int c[16][16];
int x[16];
int cnt, t, f;
int mark[16];

void Try(int k){
    for(int i = 2; i <= n; i++){
        if(mark[i] == 0){
            x[k] = i;
            t += c[x[k - 1]][x[k]];
            mark[i] = 1;
            if(k == n){
                f = t + c[x[n]][x[1]];
                if(f <= m){
                    cnt++;
                }
            }else{
                Try(k + 1);
            }
            t -= c[x[k - 1]][x[k]];
            mark[i] = 0;
        }
    }
}

int main(){
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            scanf("%d", &c[i][j]);
        }
    }
    x[1] = 1;
    Try(2);
    printf("%d", cnt);
    return 0;
}
