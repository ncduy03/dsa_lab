#include <stdio.h>
#include <stdlib.h>
int main(){
    int *p; // p is a pointer to a variable of type int
    int a; // a is a variable of type int
    a = 123;
    p = &a; // let b point to the variable a
    *p = 456; // assign the memory point by p with a value 456
    printf("p = %ld, sizeof(p) = %d, a = %d\n", p, sizeof(p), a);

    p = (int*)malloc(sizeof(int));
    *p = 1000;
    printf("p = %ld, value of variable pointed by p = %d, a = %d\n", p, *p, a);

    // dynamic allocate array
    int* q = (int*)malloc(10*sizeof(int)); // allocate array having 10 elments, each elemeny is an int
    for(int i = 0; i < 10; i++){
        q[i] = i;
    }
    // *(q + i) == q[i]
    *(q + 2) = 1000; // assign the second element of the array by 1000
    for(int i = 0; i < 10; i++){
        printf("q[%d] = %d\n", i, q[i]);
    }
    
    int b[10];
    int* ptr = b; // let ptr points to the array b, equavalent ptr = %b[0]
    for(int i = 0; i < 10; i++){
        *(ptr + i) = 10 - i; // b[i] = 10 - i
                             // ptr[i] = 10 - i;
    }
    for(int i = 0; i < 10; i++){
        printf("%d ", b[i]);
    }
    return 0;
} 
