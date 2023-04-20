#include <stdio.h>
#include <string.h>
char str[1001], a, b;
void input(){
    scanf("%s %c %c", str, &a, &b);
}

void replace(){
    for(int i = 0; i < strlen(str); i++){
        if(str[i] == a) str[i] = b;
    }
}
 
void output(){
    for(int i = 0; i < strlen(str); i++){
        printf("%c", str[i]);
    }
}

int main(){
    input();
    replace();
    output();
    return 0;
}