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

int N, dp[1001], a[1001];

int main()
{
    IO;
    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> a[i];
    for (int i = 1; i <= N; i++) {
        dp[i] = a[i];
        for (int j = 1; j < i; j++) {
            dp[i] = min(dp[i], dp[j] + dp[i - j]);
        }
    }
    cout << dp[N];
    return 0;
}