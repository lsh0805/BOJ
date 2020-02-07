#include <bits/stdc++.h>

using namespace std;

string name, type;
int T, N;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> T;
    while(T--){
        cin >> N;
        if(N == 0){
            cout << "0\n";
            continue;
        }
        map<string, int> m;
        for(int i = 0; i < N; i++){
            cin >> name >> type;
            m[type]++;
        }
        int ans = 1;
        for(auto it = m.begin(); it != m.end(); it++)
            ans *= (it->second) + 1;
        ans--;
        cout << ans << '\n';
    }
    return 0;
}