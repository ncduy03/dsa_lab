#include <stdio.h>
int check(int a[9][9]){
    
}

int main(){
    int t; scanf("%d", &t);
    while(t--){
        int a[10][10];
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                scanf("%d", &a[i][j]);
            }
        }
        printF("%d\n", check(a));
    }
    return 0;
}