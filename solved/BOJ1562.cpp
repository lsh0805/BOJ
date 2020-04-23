#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define fi first
#define se second
typedef long long ll;
typedef vector<int> vi;

const int MOD = 1e9;
int N;
ll dp[101][10][1025];

ll solve(int idx, int curr, int used){
    if(idx == N)
        return used == 1023;
    ll & ret = dp[idx][curr][used];
    if(ret != -1)
        return ret;
    ret = 0;
    if(curr != 0)
        ret = solve(idx + 1, curr - 1, used | (1 << (curr - 1)));
    if(curr != 9)
        ret += solve(idx + 1, curr + 1, used | (1 << (curr + 1)));
    return ret % MOD;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    memset(dp, -1, sizeof(dp));
    ll ans = 0;
    for(int i = 1; i <= 9; i++)
        ans += solve(1, i, (1 << i));
    cout << ans % MOD << "\n";
    return 0;
}