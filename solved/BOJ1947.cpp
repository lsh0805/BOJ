#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define fi first
#define se second
typedef long long ll;
typedef vector<int> vi;

int N;
ll dp[1000001];
const int MOD = 1e9;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    dp[1] = 0, dp[2] = 1;
    for(int i = 3; i <= N; i++)
        dp[i] = ((i - 1) * (dp[i - 2] + dp[i - 1])) % MOD;
    cout << dp[N];
    return 0;
}