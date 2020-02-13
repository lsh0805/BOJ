#include <bits/stdc++.h>

using namespace std;

int N, max_cnt;
string str, ans;
map<string, int> m;

int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> str;
        m[str]++;
    }
    for(auto it = m.begin(); it != m.end(); it++){
        if(it->second > max_cnt){
            max_cnt = it->second;
            ans = it->first;
        }
    }
    cout << ans << '\n';
    return 0;
}