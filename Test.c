#include <stdio.h>
#include <math.h>
#include <limits.h>
int main(){
    int t; scanf("%d" , &t);
    while(t--){
        int ok = 0;
        int x1, y1, x2, y2; scanf("%d %d %d %d", &x1 ,&y1, &x2, &y2);
        int x3 = x1, y3 = y2;
        int x4 = x2, y4 = y1;
        int x, y, r; scanf("%d %d %d", &x, &y, &r);
        // float d1 = sqrt(pow(x - x1, 2) + pow(y - y1, 2));
        // float d2 = sqrt(pow(x - x2, 2) + pow(y - y2, 2));
        // float d3 = sqrt(pow(x - x3, 2) + pow(y - y3, 2));
        // float d4 = sqrt(pow(x - x4, 2) + pow(y - y4, 2));
        // if(d1 <= r || d2 <= r || d3 <= r || d4 <= r){
        //     ok = 1;
        // }
        int a1 = x, b1 = y + r;
        int a2 = x + r, b2 = y;
        int a3 = x, b3 = y - r;
        int a4 = x - r, b4 = y;
        int tmp = 0;
        
    }
    return 0;
}