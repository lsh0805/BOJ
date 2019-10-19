#include <iostream>

using namespace std;

string s;

int m[26], odd = -1;
char c;

bool check(){
    for(int i = 0; i < 26; i++){
        if(m[i] % 2 != 0){
            if(odd != -1)
                return false;
            odd = i;
        }
    }
    return true;
}

int main(){
    cin >> s;
    for(int i = 0; i < s.size(); i++){
        m[s[i] - 'A']++;
    }
    if(check() == false){
        printf("I'm Sorry Hansoo");
        return 0;
    }
    for(int i = 0; i < 26; i++){
        for(int j = 0; j < m[i] / 2; j++){
            putchar('A' + i);
        }
    }
    if(odd != -1)
        putchar('A' + odd);
    for(int i = 25; i >= 0; i--){
        for(int j = 0; j < m[i] / 2; j++){
            putchar('A' + i);
        }
    }
    return 0;
}