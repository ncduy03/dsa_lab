#include <stdio.h>
int binomialCoeff(int k, int n) {
    int C[k+1];
    for(int i = 0; i <= k; i++) {
        C[i] = 0;
    }
    C[0] = 1;
    for(int i = 1; i <= n; i++) {
        for(int j = k; j > 0; j--) {
            C[j] = C[j] + C[j-1];
        }
    }
    return C[k];
}

int main() {
    int k, n; scanf("%d %d", &k, &n);
    int res = binomialCoeff(k, n);
    printf("%d", res);
    return 0;
}
