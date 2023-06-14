#include <stdio.h>
int main(){
    int n, q; scanf("%d %d", &n, &q);
    int a[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    int cnt = 0;
    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            if(a[i] + a[j] == q)
                cnt++;
        }
    }
    printf("%d", cnt);
    return 0;
}