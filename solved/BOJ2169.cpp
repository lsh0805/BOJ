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

typedef pair<int, pair<int, int>> pii;

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll MOD1 = 998'244'353;
const ll INF = 1e9;
const ld EPS = 1e-9;

int N, M, m[1001][1001], dp[2][1001][1001];

void solve() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> m[i][j];
        }
    }
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < M; k++) {
                dp[i][j][k] = -INF;
            }
        }
    }
    dp[0][0][0] = m[0][0];
    for (int i = 1; i < M; i++) {
        dp[0][0][i] = dp[0][0][i - 1] + m[0][i];
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (i > 0) dp[0][i][j] = max(dp[0][i][j], max(dp[1][i - 1][j], dp[0][i - 1][j]) + m[i][j]);
            if (j > 0) dp[0][i][j] = max(dp[0][i][j], dp[0][i][j - 1] + m[i][j]);
        }
        for (int j = M - 1; j >= 0; j--) {
            if (i > 0) dp[1][i][j] = max(dp[1][i][j], max(dp[1][i - 1][j], dp[0][i - 1][j]) + m[i][j]);
            if (j < M - 1) dp[1][i][j] = max(dp[1][i][j], dp[1][i][j + 1] + m[i][j]);
        }
    }
    cout << max(dp[0][N - 1][M - 1], dp[1][N - 1][M - 1]);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}