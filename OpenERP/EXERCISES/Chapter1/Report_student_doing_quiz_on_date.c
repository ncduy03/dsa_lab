#include <stdio.h>
#include <string.h>
typedef struct Information{
    char date[21];
    char time[9];
    char name[100];
    char id[100];
}inf;

void sort_inf(){
    for(int i = 0; i < 1000; i++){

    }
}

int main(){
    inf a[1000];
    int i = 0;
    while(1){
        scanf("%s", a[i].date);
        if(strcmp(a[i].date, "*") == 0) break;
        else{
            scanf("%s %s %s", a[i].time, a[i].name, a[i].id);
            i++;
        }
    }

    for(int i = 0; i < 1000; i++){

    }
}
