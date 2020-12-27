#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second

typedef long long ll;
typedef pair<char, int> P;
typedef pair<int, pair<int, int>> P2;

vector<vector<int>> v;
int T, K, st;
string str;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> T;
    while(T--){
        cin >> str >> K;
        v = vector<vector<int>>(26);
        int ans[2] = {(int)2e9, -1};
        for(int i = 0; i < str.length(); i++){
            int curr = str[i] - 'a';
            v[curr].push_back(i);
            if((int)v[curr].size() >= K){
                ans[0] = min(ans[0], i - v[curr][(int)v[curr].size() - K] + 1);
                ans[1] = max(ans[1], i - v[curr][(int)v[curr].size() - K] + 1);
            }
        }
        if(ans[1] == -1)
            cout << "-1\n";
        else
            cout << ans[0] << " " << ans[1] << "\n";
    }
}