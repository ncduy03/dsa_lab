#include<stdio.h>
#include<string.h>
int max(int n, int a[]){
    int max = a[0];
    for(int i = 1; i < n; i++){
        if(a[i] > max){
            max = a[i];
        }
    }
    return max;
}

int min(int n, int a[]){
    int min = a[0];
    for(int i = 1; i < n; i++){
        if(a[i] < min){
            min = a[i];
        }
    }
    return min;
}

int sum(int n, int a[]){
     int sum = 0;
     for(int i = 0; i < n; i++){
        sum += a[i];
     }
     return sum;
}

int max_segment(int a[], int i, int j){
    int max = a[i - 1];
    for(int k = i; k < j; k++){
        if(a[k] > max){
            max = a[k];
        }
        
    }
    return max;
}

int main(){
    int n; scanf("%d", &n);
    int a[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    char ignore[2];
    scanf("%s", ignore);
    char req[100];
    while(1){
        scanf("%s", req);
        if(strcmp(req, "***") == 0){
            break;
        }
        if(strcmp(req, "find-max") == 0){
            printf("%d\n", max(n, a));
        }
        if(strcmp(req, "find-min") == 0){
            printf("%d\n", min(n, a));
        }
        if(strcmp(req, "sum") == 0){
            printf("%d\n", sum(n, a));
        }
        if(strcmp(req, "find-max-segment") == 0){
            int i, j; scanf("%d %d", &i, &j);
            printf("%d\n", max_segment(a, i, j));
        }
    }
    return 0;
}
