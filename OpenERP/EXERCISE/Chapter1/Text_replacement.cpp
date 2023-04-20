#include <bits/stdc++.h>
using namespace std;
string p1, p2, t, res;
void input(){
    getline(cin, p1);
    getline(cin, p2);
    getline(cin, t);    
}

void solve(){
    int i = 0, j = 0;
    while(i < t.size()){
        if(t[i] == p1[j]){
            string tmp = "";
            while(t[i] == p1[j]){
                tmp += t[i];
                i++; j++;
            }
            if(tmp.size() == p1.size()){
                res += p2;
            }
            else{
                res += tmp;
            }
            j = 0;
        }
        else{
            res += t[i];
            i++;
        }
    }
}

void output(){
    cout << res;
}

int main(){
    input();
    solve();
    output();
}