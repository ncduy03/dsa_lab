#include <stdio.h>
#include <ctype.h>
int main(){
    FILE* f;
    if((f = fopen("test.txt", "r")) == NULL){
        printf("The file does not exist");
        return 1; // return error
    }
    printf("Open file successfully\n");

    FILE* f1 = fopen("test1.txt", "w");
    if (f1 == NULL){
        printf("Cannot open the file for writing\n");
        return 1;
    }

    while(!feof(f)){
        char c = fgetc(f);
        // printf("read %c ascii code is %d\n", c, c);
        if(c != -1){ // not the eof character
            c = toupper(c); // convert into upper case
            fputc(c, f1); // write the character c to the file f1(tes1.txt)
        }
    }

    fclose(f); // free the resource
    fclose(f1);
    return 0; // return without error
}