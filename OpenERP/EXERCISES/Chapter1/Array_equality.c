#include <stdio.h>
int t, n, m;
int a[1001], b[1001];
void input(){
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    for(int j = 0; j < m; j++){
        scanf("%d", &b[j]);
    }
}

int solve(){
    if(n != m) return 0;
    for(int i = 0; i < n; i++){
        if(a[i] != b[i])
            return 0;
    }
    return 1;
}

int main(){
    scanf("%d", &t);
    while(t--){
       input();
       printf("%d\n", solve()); 
    }
    return 0;
}