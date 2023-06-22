#include<stdio.h>
int main(){
    float a; scanf("%f", &a);
    if(a < 0){
        int integer = (int)a-1;
        printf("%d %.2f", integer, a - integer);
    }   
    else{
        int integer = (int)a;
        printf("%d %.2f", integer, a-integer);
    }
    return 0;
}
