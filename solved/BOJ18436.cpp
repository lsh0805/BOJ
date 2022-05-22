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

const int MAX_N = 1e5 + 1;
const ll EVEN = 2e5;
const ll MOD = 1e9 + 7;
const ll MOD1 = 998'244'353;
const ll INF = 1e9;
const ld EPS = 1e-9;

ll N, a[MAX_N], seg[MAX_N * 4], M;

ll init(int nl, int nr, int n, int l, int r) {
    if (nl > r || l > nr) return 0;
    if (nl == nr) return seg[n] = a[nl];
    int mid = (nl + nr) / 2;
    return seg[n] = init(nl, mid, 2 * n, l, r) + init(mid + 1, nr, 2 * n + 1, l, r);
}

ll update(int nl, int nr, int n, int idx) {
    if (nl > idx || idx > nr) return seg[n];
    if (nl == idx && nr == idx) return seg[n] = a[idx];
    int mid = (nl + nr) / 2;
    return seg[n] = update(nl, mid, 2 * n, idx) + update(mid + 1, nr, 2 * n + 1, idx);
}

ll query(int nl, int nr, int n, int l, int r) {
    if (nl > r || l > nr) return 0;
    if (nl >= l && r >= nr) return seg[n];
    int mid = (nl + nr) / 2;
    return query(nl, mid, 2 * n, l, r) + query(mid + 1, nr, 2 * n + 1, l, r);
}

void solve() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> a[i];
        if (a[i] % 2)
            a[i] = 1;
        else
            a[i] = EVEN;
    }
    init(1, N, 1, 1, N);
    cin >> M;
    while (M--) {
        int o, i, l, r, x;
        cin >> o;
        if (o == 1) {
            cin >> i >> x;
            if (x % 2 != a[i] % 2) {
                a[i] = x % 2;
                if (a[i] == 0) a[i] = EVEN;
                update(1, N, 1, i);
            }
        } else {
            cin >> l >> r;
            ll res = query(1, N, 1, l, r);
            if (o == 2) {
                cout << res / EVEN << '\n';
            } else if (o == 3) {
                cout << res % EVEN << '\n';
            }
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