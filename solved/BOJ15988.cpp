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

int dp[1000001], T;
const int MOD = 1e9 + 9;

int solve(int val)
{
    if (val < 0)
        return 0;
    if (val == 0)
        return 1;
    int &ret = dp[val];
    if (ret != 0)
        return ret;
    for (int i = 1; i <= 3; i++)
    {
        ret += solve(val - i);
        ret %= MOD;
    }
    return ret;
}

int main()
{
    IO;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        int a;
        cin >> a;
        cout << solve(a) << endl;
    }
    return 0;
}