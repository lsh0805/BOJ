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

int N, M, a, b, ans;
bool adj[501][501], inv[2][501];

int main()
{
    IO;
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        adj[a][b] = true;
        adj[b][a] = true;
        if (a == 1) {
            inv[0][b] = true;
        } else if (b == 1) {
            inv[0][a] = true;
        }
    }
    for (int i = 2; i <= N; i++) {
        if(inv[0][i]) {
            for(int j = 2; j <= N; j++) {
                if(i == j) continue;
                if(adj[i][j]) inv[1][j] = true;
            }
        }
    }
    for (int i = 2; i <= N; i++) {
        inv[0][i] |= inv[1][i];
        ans += inv[0][i];
    }
    cout << ans;
    return 0;
}