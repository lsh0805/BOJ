#include <bits/stdc++.h>
using namespace std;
#define IO                       \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0);
#define ll long long
#define endl "\n"
#define fi first
#define se second
typedef pair<int, int> ii;

int dp[4][100001], N, T;
const int MOD = 1e9 + 9;

int main()
{
    IO;
    cin >> T;
    dp[1][1] = 1;
    dp[2][2] = 1;
    dp[3][3] = 1;
    for (int i = 2; i <= 100000; i++) {
        dp[1][i] += dp[2][i - 1] + dp[3][i - 1];
        dp[1][i] %= MOD;
        if (i >= 2) {
            dp[2][i] += dp[1][i - 2] + dp[3][i - 2];
            dp[2][i] %= MOD;
        }
        if (i >= 3) {
            dp[3][i] += dp[1][i - 3] + dp[2][i - 3];
            dp[3][i] %= MOD;
        }
    }
    while(T--) {
        cin >> N;

        cout << ((dp[1][N] + dp[2][N]) % MOD + dp[3][N]) % MOD << endl;
    }
    return 0;
}