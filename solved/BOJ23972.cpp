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

ll K, N;

int main()
{
    IO;
    cin >> K >> N;
    if (N == 1) {
        cout << -1;
        return 0;
    }
    ll x = N * K / (N - 1) + (((N * K) % (N - 1)) != 0);
    cout << x;
    return 0;
}