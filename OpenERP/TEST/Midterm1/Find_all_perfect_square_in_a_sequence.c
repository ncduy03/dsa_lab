#include <stdio.h>
#include <math.h>
int check(int n){
    int x = sqrt(n);
    return x * x == n;
}
int main(){
  int n; scanf("%d", &n);\
  int a[n];
  for(int i = 0; i < n; i++){
    scanf("%d", &a[i]);
  }
  int cnt = 0;
  for(int i = 0; i < n; i++){
    if(check(a[i]))cnt++;
  }
  printf("%d", cnt);
  return 0;
}