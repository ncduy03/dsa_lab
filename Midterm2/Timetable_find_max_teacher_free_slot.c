#include <stdio.h>
int main(){
    int n, t, s, r; scanf("%d %d %d %d", &n, &t, &s, &r);
    int a[n];
    int x, y, z;
    for(int i = 0; i < n; i++){
        scanf("%d %d %d %d", &x, &y,&a[i], &z);
    }
    int mark[1001] ={0};
    for(int i = 0; i < n; i++){
        mark[a[i]]++;
    }
    int k;
    int min = mark[1];
    for(int i= 1; i <=s; i++){
        if(mark[i] < min){
            min = mark[i];
            k = i;
        }
    }
    printf("%d", t - min);
}
