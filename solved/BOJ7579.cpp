#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second

typedef long long ll;
typedef pair<int, int> P;
typedef pair<int, pair<int, int>> P2;

int dp[10000][101], N, M, m[101], c[101];

int solve(int remain, int idx){
    int & ret = dp[remain][idx];
    if(ret != 0) return ret;
    ret = m[idx];
    for(int i = idx + 1; i < N; i++){
        if(remain >= c[i])
            ret = max(ret, solve(remain - c[i], i) + m[idx]);
    }
    return ret;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> M;
    for(int i = 0; i < N; i++)
        cin >> m[i];
    for(int i = 0; i < N; i++)
        cin >> c[i];
    int ans = 0;
    for(int i = 10000; i >= 0; i--){
        int max_ = 0;
        for(int j = 0; j < N; j++){
            if(c[j] <= i)
                max_ = max(max_, solve(i - c[j], j));
        }
        if(max_ >= M)
            ans = i;
    }
    cout << ans;
}