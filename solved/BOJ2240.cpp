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

int T, W, dp[1001][31], a[1001];

int f(int curr, int cnt) {
    if (curr == T) return 0;
    if (cnt == W + 1) return 0;
    int &ret = dp[curr][cnt];
    if (ret != -1) return ret;
    if (a[curr] == 1 + (cnt % 2))
        ret = 1;
    else
        ret = 0;
    return ret += max(f(curr + 1, cnt), f(curr + 1, cnt + 1));
}

void solve() {
    cin >> T >> W;
    for (int i = 0; i < T; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < T; i++) {
        for (int j = 0; j <= W; j++) {
            dp[i][j] = -1;
        }
    }
    cout << max(f(0, 0), f(0, 1));
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