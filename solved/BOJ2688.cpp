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

int T, N, ans;
ll dp[65][11];

ll solve(int remain, int curr){
    if(remain == 0)
        return 1;
    ll & ret = dp[remain][curr];
    if(ret != 0)
        return ret;
    for(int next = curr; next >= 0; next--)
        ret += solve(remain - 1, next);
    return ret;
}

int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> T;
    while(T--){
        cin >> N;
        memset(dp, 0, sizeof(dp));
        ll ans = 0;
        for(int i = 0; i < 10; i++)
            ans += solve(N - 1, i);
        cout << ans << '\n';
    }
    return 0;
}