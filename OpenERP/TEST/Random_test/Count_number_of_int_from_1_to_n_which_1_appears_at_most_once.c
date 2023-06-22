#include <stdio.h>
int count(int n){
    int cnt = 0;
    for (int i = 1; i <= n; i++){
        int x = i;
        int tmp = 0;
        while (x > 0){
            if (x % 10 == 1){
                tmp++;
            }
            x /= 10;
        }
        if (tmp <= 1) {
            cnt++;
        }
    }
    return cnt;
}

int main() {
    int n; scanf("%d", &n);
    printf("%d", count(n));
    return 0;
}
