#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second

typedef long long ll;
typedef pair<int, int> P;
typedef pair<int, pair<int, int>> P2;

string str;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> str;
    ll total = 0, curr = 0;
    bool minus = false;
    for(int i = 0; i < str.length(); i++){
        if(str[i] == '-'){
            if(minus) total -= curr;
            if(!minus){
                total += curr;
                minus = true;
            }
            curr = 0;
        }else if(str[i] == '+'){
            if(minus) total -= curr;
            if(!minus) total += curr;
            curr = 0;
        }else{
            curr *= 10;
            curr += str[i] - '0';
        }
    }
    if(minus) total -= curr;
    if(!minus) total += curr;
    cout << total << "\n";
}