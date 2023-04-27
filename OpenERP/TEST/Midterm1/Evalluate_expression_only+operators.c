#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MOD 1000000007
int is_digit(char c){
    return c >= '0' && c <= '9';
}

int is_op(char c){
    return c == '+';
}

int sum(char *s){
    int n = strlen(s);
    int res = 0, cur = 0;
    for(int i = 0; i < n; i++){
        if(is_digit(s[i])){
            cur = cur * 10 + (s[i] - '0');
        }else if(is_op(s[i])){
            res = (res + cur) % MOD;
            cur = 0;
        }else{
            return -1;
        }
    }
    return (res + cur) % MOD;
}

int main() {
    char s[1000001];
    fgets(s, 10000001, stdin);
    int n = strlen(s);
    s[n-1] = '\0';
    int m = strlen(s);
    if (m == 0){
        printf("NOT_CORRECT\n");
        return 0;
    }
    if (!is_digit(s[m-1])) {
        printf("NOT_CORRECT\n");
        return 0;
    }
    printf("%d\n", sum(s));
    return 0;
}