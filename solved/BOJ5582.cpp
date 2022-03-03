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

int dp[4001][4001], N, M, ans;
string a, b;

int main()
{
    IO;
    cin >> a >> b;
    N = a.length(), M = b.length();
    for (int i = N - 1; i >= 0; i--) {
        for (int j = M - 1; j >= 0; j--) {
            if (a[i] == b[j]){
                dp[i][j] = 1;
                if (i < N - 1 && j < M - 1)
                    dp[i][j] += dp[i + 1][j + 1];
            }
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans;
    return 0;
}