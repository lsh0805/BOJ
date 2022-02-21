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

int N, dp[31];

int main()
{
    IO;
    cin >> N;
    dp[0] = 1;
    dp[2] = 3;
    dp[4] = 11;
    for (int i = 5; i <= N; i++) {
        dp[i] = dp[i - 2] * 3;
        if (i % 2 == 0) {
            for (int j = i - 4; j >= 0; j-=2) {
                dp[i] += dp[j] * 2;
            }
        }
    }
    cout << dp[N] << endl;
    return 0;
}