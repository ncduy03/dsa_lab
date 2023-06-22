#include <stdio.h>
int checkrow(int a[][10]){
    for(int i = 0; i < 9; i++){
        int s = 0;
        for(int j = 0; j < 9; j++){
            s += a[i][j];
        }
        if(s != 45) return 0;
    }
    return 1;
}

int checkcolumn(int a[][10]){
    for(int i = 0; i < 9; i++){
        int s = 0;
        for(int j = 0; j < 9; j++){
            s += a[j][i];
        }
        if(s != 45) return 0;
    }
    return 1;
}

int check(int a[][10]){
    return checkcolumn(a) == 1 && checkrow(a) == 1;
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
        printf("%d\n", check(a));
    }
    return 0;
}
