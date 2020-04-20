#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define fi first
#define se second
typedef long long ll;

int N, K, ans, a[101];
set<int> s;

int solve(int idx){
    pair<int, int> ret = mp(-1, -1);
    for(auto it = s.begin(); it != s.end(); it++){
        bool flag = false;
        for(int i = idx; i < K; i++){
            if(a[i] == *it){
                ret = max(ret, mp(i, a[i]));
                flag = true;
                break;
            }
        }
        if(!flag)
            return *it;
    }
    return ret.second;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> K;
    for(int i = 0; i < K; i++)
        cin >> a[i];
    for(int i = 0; i < K; i++){
        if(s.find(a[i]) != s.end())
            continue;
        if(s.find(a[i]) == s.end() && s.size() < N)
            s.insert(a[i]);
        else{
            ans++;
            int unplug = solve(i + 1);
            s.erase(unplug);
            s.insert(a[i]);
        }
    }
    cout << ans << "\n";
    return 0;
}