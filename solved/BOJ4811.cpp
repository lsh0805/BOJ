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
long long dp[31][31];

long long solve(int one, int half){
    if(one == 0 && half == 0)
        return 1;
    long long & ret = dp[one][half];
    if(ret != 0)
        return ret;
    if(one > 0)
        ret += solve(one - 1, half + 1);
    if(half > 0)
        ret += solve(one, half - 1);
    return ret;
}


int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    while(true){
        cin >> N;
        if(N == 0) break;
        memset(dp, 0, sizeof(dp));
        cout << solve(N - 1, 1) << "\n";
    }
    return 0;
}