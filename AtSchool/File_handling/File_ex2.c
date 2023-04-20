#include <stdio.h>
int main(){
    FILE* fi = fopen("data.txt", "r");
    if(fi == NULL){
        printf("Cannot open file data.txt for reading");
        return 1;
    }
    int a, b;
    fscanf(fi, "%d %d", &a, &b);
    int res = a + b;
    FILE* fo = fopen("result.txt", "w");
    if(fo == NULL){
        printf("Cannot open file result.txt for writing");
        return 1;
    }
    fprintf(fo, "The sum is %d", res);
    fclose(fi); fclose(fo);
    return 0;
}
