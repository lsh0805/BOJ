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

int N, K, dp[201][201][21];
vector<int> v;

int f(int s, int e, int c) {
    if (s > e) return 0;
    if (s == e) return v[s] != c;
    int &ret = dp[s][e][c];
    if (ret != -1) return ret;
    ret = f(s, s, c) + f(s + 1, e, c);
    for (int i = s + 1; i <= e; i++) {
        if (v[s] == v[i]) {
            int c1 = f(s + 1, i - 1, v[s]) + f(i, e, v[s]) + (c != v[s]);
            int c2 = f(s + 1, i - 1, v[s]) + f(i + 1, e, c) + (c != v[s]);
            ret = min({ret, c1, c2});
        }
    }
    return ret;
}

void solve() {
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        int n;
        cin >> n;
        if (v.empty() || v.back() != n) {
            v.push_back(n);
        }
    }
    N = v.size();
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 1; k <= K; k++) {
                dp[i][j][k] = -1;
            }
        }
    }
    dbg(N, v.size());
    int ans = 2e9;
    for (int i = 1; i <= K; i++) {
        ans = min(ans, f(0, N - 1, i));
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