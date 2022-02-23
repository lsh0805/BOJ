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

int N, num[11], x, a, visited, total, ans = 2e9;
bool adj[11][11];

bool dfs(int idx, int state) {
    bool ret = false;
    visited |= (1 << idx);
    if ((visited & state) == state) {
        return true;
    }
    for (int i = 0; i < N; i++) {
        int next = (1 << i);
        if ((state & next) && adj[idx][i]) {
            if (visited & next) continue;
            ret |= dfs(i, state);
        }
    }
    return ret;
}

bool solve(int state) {
    visited = 0;
    for (int i = 0; i < N; i++) {
        if (state & (1 << i)) {
            return dfs(i, state);
        }
    }
    return false;
}

int getDiff(int state) {
    int val = 0;
    for (int i = 0; i < N; i++) {
        if (state & (1 << i)) {
            val += num[i];
        }
    }
    return abs(val - (total - val));
}

int main()
{
    IO;
    cin >> N;
    memset(adj, false, sizeof(adj));
    for (int i = 0; i < N; i++) {
        cin >> num[i];
        total += num[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> x;
        for (int j = 0; j < x; j++) {
            cin >> a;
            adj[i][a - 1] = true;
            adj[a - 1][i] = true;
        }
    }
    for (int i = 1; i < (1 << N) - 1; i++) {
        bool res_a = solve(i);
        bool res_b = solve(i ^ ((1 << N) - 1));

        if (res_a && res_b) {
            ans = min(ans, getDiff(i));
        }
    }
    if (ans == 2e9) {
        cout << "-1\n";
    } else {
        cout << ans << endl;
    }
    return 0;
}