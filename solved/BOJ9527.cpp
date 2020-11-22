#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second

typedef long long ll;
typedef pair<int, int> P;
typedef pair<int, pair<int, int>> P2;

ll A, B;
vector<ll> bits[2];

ll power(int num, int p){
    if(p == 0) return 1; 
    if(p == 1) return num;
    if(p % 2){
        return power(num, p - 1) * num;
    }else{
        return power(num, p / 2) * power(num, p / 2);
    }
}

ll getBitOnCount(int idx){
    ll ret = 0;
    for(int i = 0; i < bits[idx].size(); i++){
        for(int j = i + 1; j < bits[idx].size(); j++){
            ret += bits[idx][j] * power(2, j - i - 1) * power(2, i);
        }
        if(bits[idx][i]){
            for(int j = i - 1; j >= 0; j--){
                ret += bits[idx][j] * power(2, j);
            }
            ret++;
        }
    }
    return ret;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> A >> B;
    A--;
    for(int i = 0; A; i++){
        bits[0].push_back(A%2);
        A/=2;
    }
    for(int i = 0; B; i++){
        bits[1].push_back(B%2);
        B/=2;
    }
    cout << getBitOnCount(1) - getBitOnCount(0) << "\n";
}