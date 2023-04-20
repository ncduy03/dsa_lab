#include <stdio.h>
int main(int argc, char* argv[]){
    // argc is the number of arguments that users enter
    // argv is the list of arguments, each one is a string
    printf("number of arguments is %d\n", argc);
    for(int i = 0; i < argc; i++){
        printf("The %dth argument is %s\n", argv[i]);
    }
    return 0;
}
