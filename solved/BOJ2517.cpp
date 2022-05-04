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

int N, seg[500001 * 4];

int update(int nl, int nr, int n, int idx, int val) {
    if (nl > idx || nr < idx) return seg[n];
    if (nl == nr && nl == idx) return seg[n] = val;
    int mid = (nl + nr) / 2;
    return seg[n] = update(nl, mid, 2 * n, idx, val) + update(mid + 1, nr, 2 * n + 1, idx, val);
}

int query(int nl, int nr, int n, int l, int r) {
    if (nr < l || nl > r) return 0;
    if (l <= nl && nr <= r) return seg[n];
    int mid = (nl + nr) / 2;
    return query(nl, mid, 2 * n, l, r) + query(mid + 1, nr, 2 * n + 1, l, r);
}

void solve() {
    cin >> N;
    vector<int> a(N);
    vector<pii> b(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
        b[i] = {a[i], i};
    }
    sort(b.begin(), b.end());
    for (int i = 0; i < N; i++) {
        a[b[i].se] = i;
    }
    for (int i = 0; i < N; i++) {
        cout << (i + 1) - query(0, N - 1, 1, 0, a[i]) << '\n';
        update(0, N - 1, 1, a[i], 1);
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