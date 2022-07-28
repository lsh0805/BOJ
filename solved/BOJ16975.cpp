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

ll N, M, A[MAX_N], lazy[MAX_N * 4], seg[MAX_N * 4], x, a, b, c;
bool leaf[MAX_N * 4];

void init(int l, int r, int n) {
    if (l == r) {
        leaf[n] = true;
        seg[n] = A[l];
        return;
    }
    int mid = (l + r) / 2;
    init(l, mid, 2 * n);
    init(mid + 1, r, 2 * n + 1);
}

void propagate(int n) {
    if (!leaf[n]) {
        lazy[2 * n] += lazy[n];
        lazy[2 * n + 1] += lazy[n];
    } else {
        seg[n] += lazy[n];
    }
    lazy[n] = 0;
}

void update(int l, int r, int nl, int nr, int n, ll k) {
    propagate(n);
    if (nl > r || nr < l) return;
    if (l <= nl && r >= nr) {
        lazy[n] += k;
        return;
    }
    int mid = (nl + nr) / 2;
    update(l, r, nl, mid, 2 * n, k);
    update(l, r, mid + 1, nr, 2 * n + 1, k);
}

ll query(int idx, int nl, int nr, int n) {
    propagate(n);
    if (nl > idx || nr < idx) return 0;
    if (idx == nl && idx == nr) {
        return seg[n];
    }
    int mid = (nl + nr) / 2;
    return query(idx, nl, mid, 2 * n) + query(idx, mid + 1, nr, 2 * n + 1);
}

void solve() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }
    init(1, N, 1);
    cin >> M;
    for (int i = 0; i < M; i++) {
        cin >> x;
        if (x == 1) {
            cin >> a >> b >> c;
            update(a, b, 1, N, 1, c);
        } else {
            cin >> a;
            cout << query(a, 1, N, 1) << "\n";
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