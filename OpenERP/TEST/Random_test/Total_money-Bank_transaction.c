#include <stdio.h>
#include <string.h>
char f_acc[21];
char t_acc[21];
int money;
char time[9];
char atm[11];
int sum = 0;
int main(){
    while(1){
        scanf("%s", f_acc);
        if(strcmp(f_acc, "#") == 0) break;
        else{
            scanf("%s %d %s %s", t_acc, &money, time, atm);
            sum += money;
        }
    }
    printf("%d", sum);
    return 0;
}