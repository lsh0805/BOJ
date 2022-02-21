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

ll H, W, N, M;

int main()
{
    IO;
    cin >> H >> W >> N >> M;
    ll h = ((W - 1) / (M + 1)) + 1;
    ll v = ((H - 1) / (N + 1)) + 1;
    cout << h * v << endl;
    return 0;
}