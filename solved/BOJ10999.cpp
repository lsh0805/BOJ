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

const int MAX_N = 1e6 + 1;
const ll MOD = 1e9 + 7;
const ll MOD1 = 998'244'353;
const ll INF = 1e9;
const ld EPS = 1e-9;
int N, M, K;
vector<ll> seg(4 * MAX_N), lazy(4 * MAX_N), v;

ll init(int nl, int nr, int n) {
    if (nl == nr) return seg[n] = v[nl];
    int mid = (nl + nr) / 2;
    return seg[n] = init(nl, mid, 2 * n) + init(mid + 1, nr, 2 * n + 1);
}

void propagate(int n, ll s, ll e) {
    if (lazy[n] != 0) {
        if (s != e) {
            lazy[2 * n] += lazy[n];
            lazy[2 * n + 1] += lazy[n];
        }
        seg[n] += (e - s + 1) * lazy[n];
        lazy[n] = 0;
    }
}

void update(int nl, int nr, int n, int l, int r, ll val) {
    propagate(n, nl, nr);
    if (nr < l || nl > r) return;
    if (nl >= l && nr <= r) {
        lazy[n] += val;
        propagate(n, nl, nr);
        return;
    }
    int mid = (nl + nr) / 2;
    update(nl, mid, 2 * n, l, r, val);
    update(mid + 1, nr, 2 * n + 1, l, r, val);
    seg[n] = seg[2 * n] + seg[2 * n + 1];
}

ll query(int nl, int nr, int n, int l, int r) {
    propagate(n, nl, nr);
    if (nr < l || nl > r) return 0;
    if (l <= nl && nr <= r) return seg[n];
    int mid = (nl + nr) / 2;
    return query(nl, mid, 2 * n, l, r) + query(mid + 1, nr, 2 * n + 1, l, r);
}

void solve() {
    cin >> N >> M >> K;
    v.resize(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> v[i];
    }
    init(1, N, 1);
    for (int i = 1; i <= M + K; i++) {
        ll a, b, c, d;
        cin >> a >> b >> c;
        if (a == 1) {
            cin >> d;
            update(1, N, 1, b, c, d);
        } else {
            cout << query(1, N, 1, b, c) << '\n';
        }
    }
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