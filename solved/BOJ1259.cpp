#include <bits/stdc++.h>

using namespace std;

string str;
int main(){
    while((cin >> str) && str != "0"){
        bool flag = false;
        for(int i = 0; i < str.size()/2 + (str.size() % 2); i++){
            if(str[i] != str[str.size() - 1 - i]){
                cout << "no\n";
                flag = true;
                break;
            }
        }
        if(!flag)
            cout << "yes\n";
    }
    return 0;
}