#include <stdio.h>
int main(){
    int n, k; scanf("%d %d", &n, &k);
    int a[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    int cnt = 0, s = 0;
    for(int i = 0; i < k; i++){
        s += a[i];
    }
    if(s % 2 == 0) cnt++;
    for(int i = k; i < n; i++){
        s -= a[i - k];
        s += a[i];
        if(s % 2 == 0) cnt++;
    }
    printf("%d", cnt);
    return 0;
}