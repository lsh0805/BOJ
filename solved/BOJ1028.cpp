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

int m[751][751], R, C, dp[751][751][4], dy[4] = {-1, -1, 1, 1}, dx[4] = {-1, 1, -1, 1};
string str;
void solve() {
    cin >> R >> C;
    for (int i = 0; i < R; i++) {
        cin >> str;
        for (int j = 0; j < C; j++) {
            m[i][j] = str[j] - '0';
        }
    }
    for (int k = 0; k < 2; k++) {
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                int ny = i + dy[k], nx = j + dx[k];
                dp[i][j][k] = m[i][j];
                if (ny >= 0 && ny < R && nx >= 0 && nx < C && m[i][j]) dp[i][j][k] += dp[ny][nx][k];
            }
        }
    }
    for (int k = 2; k < 4; k++) {
        for (int i = R - 1; i >= 0; i--) {
            for (int j = 0; j < C; j++) {
                int ny = i + dy[k], nx = j + dx[k];
                dp[i][j][k] = m[i][j];
                if (ny >= 0 && ny < R && nx >= 0 && nx < C && m[i][j]) dp[i][j][k] += dp[ny][nx][k];
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            for (int k = ans + 1; j + 2 * k - 2 < C; k++) {
                int nx = j + 2 * k - 2;
                bool a = dp[i][j][1] >= k - 1 && dp[i][nx][0] >= k;
                bool b = dp[i][j][1] >= k && dp[i][nx][0] >= k - 1;
                bool c = dp[i][j][3] >= k - 1 && dp[i][nx][2] >= k;
                bool d = dp[i][j][3] >= k && dp[i][nx][2] >= k - 1;
                if ((a || b) && (c || d)) {
                    if (k == 3) dbg(dp[i][j][1]);
                    ans = max(ans, k);
                }
            }
        }
    }
    cout << ans;
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