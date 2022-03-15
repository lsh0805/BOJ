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

int A, B, C, N;
int dp[301];

int main()
{
    IO;
    cin >> A >> B >> C >> N;
    dp[A] = 1;
    dp[B] = 1;
    dp[C] = 1;
    for (int i = 0; i <= N; i++) {
        if (i >= A)
            dp[i] |= dp[i - A];
        if (i >= B)
            dp[i] |= dp[i - B];
        if (i >= C)
            dp[i] |= dp[i - C];
    }
    cout << dp[N];
    return 0;
}