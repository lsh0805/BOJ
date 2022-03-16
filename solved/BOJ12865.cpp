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
typedef pair<int, int> pii;

int N, K, dp[101][100001], w[101], v[101];

int main()
{
    IO;
    cin >> N >> K;
    for (int i = 1; i <= N; i++) {
        cin >> w[i] >> v[i];
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= K; j++) {
            if (j - w[i] >= 0)
                dp[i][j] = dp[i - 1][j - w[i]] + v[i];
            dp[i][j] = max(dp[i][j], dp[i - 1][j]);
        }
    }
    cout << dp[N][K];
    return 0;
}