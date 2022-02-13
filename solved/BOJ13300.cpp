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

int N, K, c[2][6], ans;

int main()
{
    IO;
    cin >> N >> K;
    int a, b;
    for (int i = 0; i < N; i++) {
        cin >> a >> b;
        c[a][--b]++;
    }
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 6; j++) {
            ans += c[i][j] / K + (c[i][j] % K != 0);
        }
    }
    cout << ans;
    return 0;
}