#include <stdio.h>
int n, k, a, b;
int cnt = 0;
int c[100001];
void input(){
    scanf("%d %d %d %d", &n, &k, &a, &b);
    for(int i = 0; i < n; i++){
        scanf("%d", &c[i]);
    }
}

void solve(){
    int s = 0;
    for(int i = 0; i < k; i++){
        s += c[i];
    }
    if(s >= a && s <= b) cnt++;
    for(int i = k; i < n; i++){
        s -= c[i - k];
        s += c[i];
        if(s >= a && s <= b) cnt++;
    }
}

int main(){
    input();
    solve();
    printf("%d", cnt);
}