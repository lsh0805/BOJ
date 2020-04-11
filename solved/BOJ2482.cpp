#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define fi first
#define se second
typedef long long ll;
typedef vector<int> vi;

int T, N, K, ans, dp[1001][1001][2];
const int MOD = 1e9 + 3;

int solve(int remain, int curr, bool first){
    int &ret = dp[remain][curr][first];
    if (ret != -1)
        return ret;
    if(curr == N - 1 && first)
        return ret = 0;
    if(remain == 0)
        return ret = 1;
    ret = 0;
    for(int i = curr + 2; i < N; i++){
        if((N - i) / 2 + 1 < remain) break; 
        ret += solve(remain - 1, i, first);
        ret %= MOD;
    }
    return ret;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    memset(dp, -1, sizeof(dp));
    cin >> N >> K;
    ans += solve(K - 1, 0, true);
    for(int i = 1; i < N; i++){
        ans += solve(K - 1, i, false);
        ans %= MOD;
    }
    cout << ans << '\n';
    return 0;
}