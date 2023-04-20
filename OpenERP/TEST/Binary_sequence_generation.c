#include <stdio.h>
int n, a[1000], ok;
void ktao(){
    for(int i = 0; i < n; i++){
        a[i] = 0;
    }
}

void generate_binString(){
    int i = n - 1;
    while(i >= 0 && a[i] == 1){
        a[i] = 0;
        i--;
    }
    if(i == -1){
        ok = 0;
    }
    else{
        a[i] = 1;
    }
}

int main(){
    scanf("%d", &n);
    ktao();
    ok = 1;
    while(ok){
        for(int i = 0; i < n; i++){
            printf("%d", a[i]);
        }
        printf("\n");
        generate_binString();
    }
}
