#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define fi first
#define se second
typedef long long ll;
typedef vector<int> vi;

int N, a, b, d, dp[1000001], sum[1000001];
const int MOD = 1000;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> a >> b >> d >> N;
    dp[0] = 1;
    sum[0] = 1;
    for(int i = 1; i <= N; i++){
        dp[i] = (1000 + (i - a >= 0 ? sum[i - a] : 0) - (i - b >= 0 ? sum[i - b] : 0)) % MOD;
        sum[i] = (sum[i - 1] + dp[i]) % MOD;
    }
    cout << (1000 + sum[N] - (N - d >= 0 ? sum[N - d] : 0)) % MOD << "\n";
    return 0;
}