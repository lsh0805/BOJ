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
const int M = 500000;

int N, h[51];
int dp[51][1000001];

int f(int idx, int val) {
    if (idx == N) {
        if (val == 0) {
            return 0;
        } else {
            return -INF;
        }
    }
    int &ret = dp[idx][val + M];
    if (ret != -1) return ret;
    int add = f(idx + 1, val + h[idx]) + h[idx];
    int sub = f(idx + 1, val - h[idx]);
    int ignore = f(idx + 1, val);
    return ret = max({add, sub, ignore});
}

void solve() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> h[i];
        for (int j = 0; j < 1000001; j++) {
            dp[i][j] = -1;
        }
    }
    int ans = f(0, 0);
    if (ans <= 0)
        cout << -1;
    else
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