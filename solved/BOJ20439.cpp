#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second

typedef long long ll;
typedef pair<int, int> P;
typedef pair<int, pair<int, int>> P2;

int N, K, t[13], dp[1441][4100]; 
vector<int> s, e;
bool solve(int curr, int completed){
    if(completed == (1 << K) - 1) return true;
    if(curr >= 1440) return false;
    int & ret = dp[curr][completed];
    if(ret != -1) return ret;
    int idx = lower_bound(s.begin(), s.end(), curr) - s.begin();
    int nearest_s = s[idx], nearest_e = e[idx];
    for(int i = 0; i < K; i++){
        if((completed & (1 << i)) == 0 && t[i] + curr <= nearest_s){
            if(solve(curr + t[i], completed | (1 << i)))
                return ret = true;
        }
    }
    return ret = solve(nearest_e, completed);
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> K;
    s = vector<int>(N);
    e = vector<int>(N);
    for(int i = 0; i <= 1440; i++)
        for(int j = 0; j < 4100; j++)
            dp[i][j] = -1;
    for(int i = 0; i < N; i++)
        cin >> s[i] >> e[i];
    if(e[e.size() - 1] != 1440){
        s.push_back(1440);
        e.push_back(1440);
    }
    for(int i = 0; i < K; i++)
        cin >> t[i];
    cout << (solve(0, 0) ? "GOOD" : "BAD");
}