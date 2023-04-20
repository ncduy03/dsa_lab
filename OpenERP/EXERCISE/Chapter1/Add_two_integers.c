#include <stdio.h>
#include <string.h>
char a[101], b[101];
int sum[101];
int carry = 0, k = 0;
void input(){
    scanf("%s %s", a, b);
}

void solve(){
    int i = strlen(a) - 1, j = strlen(b) - 1;
    while(i >= 0 && j >= 0){
        int x = (a[i] - '0') + (b[j] - '0') + carry;
        if(x >= 10){
            carry = 1;
            sum[k] = x - 10;
        }
        else{
            carry = 0;
            sum[k] = x;
        }
        k++; i--; j--;
    }
    while(i >= 0){
        int x = (a[i] - '0') + carry;
        if(x >= 10){
            carry = 1;
            sum[k] = x - 10;
        }
        else{
            carry = 0;
            sum[k] = x;
        }
        k++; i--;
    } 
    while(j >= 0){
        int x = (b[j] - '0') + carry;
        if(x >= 10){
            carry = 1;
            sum[k] = x - 10;
        }
        else{
            carry = 0;
            sum[k] = x;
        }
        k++; j--;
    } 
    if(carry == 1){
        sum[k] = 1;
        k++;
    }
}

void output(){
    k--;
    while(k >= 0){
        printf("%d", sum[k]);
        k--;
    }
}

int main(){
    input();
    solve();
    output();
    return 0;
}
