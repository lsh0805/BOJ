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
const ll INF = 1e9;
const ld EPS = 1e-9;

int N, dp[1001][3][3], c[1001][3];

void solve() {
    cin >> N;
    int ans = 1e9;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> c[i][j];
            for (int k = 0; k < 3; k++) {
                dp[i][j][k] = 1e9;
            }
        }
    }
    for (int k = 0; k < 3; k++) {
        dp[0][k][k] = c[0][k];
        for (int i = 1; i < N; i++) {
            for (int j = 0; j < 3; j++) {
                if (i == N - 1 && j == k) continue;
                dp[i][j][k] = min(dp[i - 1][(j + 1) % 3][k], dp[i - 1][(j + 2) % 3][k]) + c[i][j];
                if (i == N - 1)
                    ans = min(ans, dp[i][j][k]);
            }
        }
    }
    cout << ans << "\n";
}

int main() {
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