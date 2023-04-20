#include <stdio.h>
#include <limits.h>
int xmin = INT_MAX, xmax = INT_MIN;
int ymin = INT_MAX, ymax = INT_MIN;
int main(){
    int n; scanf("%d", &n);
    while(n--){
        int x1, y1, x2, y2;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        if(x1 > xmax) xmax = x1;
        else if(x1 < xmin) xmin = x1;
        if(y1 > ymax) ymax = y1;
        else if(y1 < ymin) ymin = y1;
        if(x2 > xmax) xmax = x2;
        else if(x2 < xmin) xmin = x2;
        if(y2 > ymax) ymax = y2;
        else if(y2 < ymin) ymin = y2;
    }
    int res = (xmax - xmin) * (ymax - ymin);
    printf("%d", res);
}