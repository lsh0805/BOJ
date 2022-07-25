#include <bits/stdc++.h>

using namespace std;

template <typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template <typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type>
ostream &operator<<(ostream &os, const T_container &v) {
    os << '{';
    string sep;
    for (const T &x : v)
        os << sep << x, sep = ", ";
    return os << '}';
}
void dbg_out() { cerr << endl; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T) {
    cerr << ' ' << H;
    dbg_out(T...);
}
#ifndef ONLINE_JUDGE
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

#define ar array
#define ll long long
#define ld long double
#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()
#define fi first
#define se second

typedef pair<int, int> pii;

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll MOD1 = 998'244'353;
const ll INF = 2e9;
const ld EPS = 1e-9;

int N, M, a, b, c, d[101][101], f[101][101];
vector<int> r[101][101];

void tracking(int i, int j, int depth) {
    if (i == j) {
        cout << depth << " " << i << " ";
        return;
    }
    if (d[i][j] == f[i][j]) {
        tracking(i, i, depth + 1);
        cout << j << " ";
        return;
    }
    for (int k = 1; k <= N; k++) {
        if (d[k][j] + f[i][k] == f[i][j]) {
            tracking(i, k, depth + 1);
            cout << j << " ";
            return;
        }
    }
}

void solve() {
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            d[i][j] = 2e6;
            f[i][j] = d[i][j];
        }
    }
    for (int i = 0; i < M; i++) {
        cin >> a >> b >> c;
        d[a][b] = min(d[a][b], c);
        f[a][b] = d[a][b];
    }

    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
            }
        }
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cout << (i == j || f[i][j] == 2e6 ? 0 : f[i][j]) << " ";
        }
        cout << '\n';
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (f[i][j] >= 2e6 || i == j) {
                cout << "0\n";
            } else {
                tracking(i, j, 1);
                cout << "\n";
            }
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);
    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}