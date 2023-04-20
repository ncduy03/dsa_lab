#include <stdio.h>
#include <string.h>
#define N 10000
char p1[N], p2[N], t[N], res[N];
void input(){
    // gets(p1);
    // gets(p2);
    // gets(t);
    fgets(p1, N, stdin); // char c = fgetc(stdin)
    fgets(p2, N, stdin); // c = fgetc(stdin)
    fgets(t, N, stdin);
    if(p1[strlen(p1) - 1] == '\n')
        p1[strlen(p1) - 1] = '\0'; // remove break-line character \n
    if(p2[strlen(p2) - 1] == '\n')
        p2[strlen(p2) - 1] = '\0';
    if(t[strlen(t) - 1] == '\n')
        t[strlen(t) - 1] = '\0';
}

int check(int i){
    // check if sub-string t[i, i + strlen(p1)] = p1?
    if(i + strlen(p1) > strlen(t))
        return 0;
    for(int k = 0; k < strlen(p1); k++){
        if(p1[k] != t[i + k])
            return 0;
    }
    return 1;
}

void solve(){
    int i = 0, j = 0;
    while(i < strlen(t)){
        if(check(i)){
            for(int k = 0; k < strlen(p2); k++){
                res[j + k] = p2[k];
            }
            i += strlen(p1);
            j += strlen(p2);
        }
        else{
            res[j] = t[i];
            i++; j++;
        }
    }
}

void output(){
    printf("%s", res);
}

int main(){
    input();
    solve();
    output();
    return 0;
}