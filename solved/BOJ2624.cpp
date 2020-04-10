#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define fi first
#define se second
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, pair<int, int>> p2;
typedef vector<int> vi;

int T, N, ans, cost[101], cnt[101], dp[10001][101];

int solve(int remain, int curr){
    if(remain == 0)
        return 1;
    if(remain < 0 || curr == N)
        return 0;
    int & ret = dp[remain][curr];
    if(ret != -1)
        return ret;
    ret = 0;
    for(int i = 0; i <= cnt[curr]; i++)
        ret += solve(remain - (cost[curr] * i), curr + 1);
    return ret;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> T >> N;
    memset(dp, -1, sizeof(dp));
    for(int i = 0; i < N; i++)
        cin >> cost[i] >> cnt[i];
    cout << solve(T, 0);
    return 0;
}