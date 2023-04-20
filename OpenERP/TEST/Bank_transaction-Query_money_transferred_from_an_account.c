#include<stdio.h>
#include<string.h>
typedef struct Transmitsion{
    char f_acc[21];
    char t_acc[21];
    int money;
    char time[9];
    char atm[4];
}trans;
int main(){
    trans a[1000];
    int i = 0;
    char req[100];
    while(1){
        scanf("%s", a[i].f_acc);
        if(strcmp(a[i].f_acc, "#")==0){
            break;
        }else{
            scanf("%s %d %s %s", a[i].t_acc, &a[i].money, a[i].time, a[i].atm);
            i++;
        }
    }

    while(1){
        scanf("%s", req);
        if(strcmp(req,"#")==0){
            break;
        }   
        if(strcmp(req, "?total_money_transaction_from")==0){
            char from_account[21];
            scanf("%s", from_account);
            int total = 0;
            for(int j = 0; j < i; j++){
                if(strcmp(a[j].f_acc, from_account)==0){
                    total += a[j].money;
                }
            }
            printf("%d\n", total);
        }
    }
    return 0;
}
