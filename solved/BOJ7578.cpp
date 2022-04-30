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

const int MAX_N = 5e5;
const ll MOD = 1e9 + 7;
const ll MOD1 = 998'244'353;
const ll INF = 1e9;
const ld EPS = 1e-9;

int N;
vector<ll> v(MAX_N * 4, 0);
ll ans;

ll update(int l, int r, int n, int idx) {
    if (l > idx || r < idx || l > r) return v[n];
    if (l == idx && r == idx) return v[n] = 1;
    int m = (l + r) / 2;
    return v[n] = update(l, m, 2 * n, idx) + update(m + 1, r, 2 * n + 1, idx);
}

ll query(int l, int r, int nl, int nr, int n) {
    if (l > nr || r < nl || nl > nr) return 0;
    if (nl >= l && nr <= r) return v[n];
    int m = (nl + nr) / 2;
    return query(l, r, nl, m, 2 * n) + query(l, r, m + 1, nr, 2 * n + 1);
}

void solve() {
    cin >> N;
    vector<int> a(N);
    vector<int> b(N);
    vector<ll> c(1000001);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
        c[a[i]] = i + 1;
    }
    for (int i = 0; i < N; i++) {
        cin >> b[i];
        ans += c[b[i]] - (query(1, c[b[i]], 1, N, 1) + 1);
        update(1, N, 1, c[b[i]]);
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