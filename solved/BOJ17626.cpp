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

int N, dp[50001];

int main()
{
    IO;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        dp[i] = 5;
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= 223; j++) {
            int mul = j * j;
            if (i < mul) continue;
            dp[i] = min(dp[i], 1 + dp[i - mul]);
        }
    }
    cout << dp[N];
    return 0;
}