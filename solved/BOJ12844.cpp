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

int N, M, v[500001], seg[500001 * 4], o, a, b, c, lazy[500001 * 4];
bool leaf[500001 * 4];

int init(int l, int r, int n) {
    if (l == r) {
        leaf[n] = true;
        return seg[n] = v[l];
    }
    int mid = (l + r) / 2;
    return seg[n] = init(l, mid, 2 * n) ^ init(mid + 1, r, 2 * n + 1);
}

void propagation(int n, int s, int e) {
    if (lazy[n]) {
        if (!leaf[n]) {
            lazy[2 * n] ^= lazy[n];
            lazy[2 * n + 1] ^= lazy[n];
        }
        if ((e - s) % 2 == 0) seg[n] ^= lazy[n];
        lazy[n] = 0;
    }
}

int update(int l, int r, int nl, int nr, int n, int val) {
    propagation(n, nl, nr);
    if (nl > r || nr < l) return seg[n];
    if (nl >= l && nr <= r) {
        lazy[n] ^= val;
        propagation(n, nl, nr);
        return seg[n];
    }
    int mid = (nl + nr) / 2;
    int l_res = update(l, r, nl, mid, 2 * n, val);
    int r_res = update(l, r, mid + 1, nr, 2 * n + 1, val);
    return seg[n] = l_res ^ r_res;
}

int query(int l, int r, int nl, int nr, int n) {
    propagation(n, nl, nr);
    if (l > nr || r < nl) return 0;

    if (l <= nl && r >= nr) return seg[n];
    int mid = (nl + nr) / 2;
    int l_res = query(l, r, nl, mid, 2 * n);
    int r_res = query(l, r, mid + 1, nr, 2 * n + 1);
    return l_res ^ r_res;
}

void solve() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> v[i];
    }
    init(1, N, 1);
    cin >> M;
    for (int i = 1; i <= M; i++) {
        cin >> o;
        if (o == 1) {
            cin >> a >> b >> c;
            a++, b++;
            update(a, b, 1, N, 1, c);
        } else if (o == 2) {
            cin >> a >> b;
            a++, b++;
            cout << query(a, b, 1, N, 1) << '\n';
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