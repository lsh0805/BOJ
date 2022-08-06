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
const int MAX_M = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll MOD1 = 998'244'353;
const ll INF = 1e9;
const ld EPS = 1e-9;

int N, a[MAX_N], seg[MAX_N * 4], M, l, r, k, ans[MAX_M];
vector<ar<int, 2>> v;
vector<ar<int, 4>> q;

int update(int idx, int nl, int nr, int n) {
    if (idx > nr || idx < nl) return seg[n];
    if (idx == nl && idx == nr) return seg[n] = 1;
    int mid = (nl + nr) / 2;
    return seg[n] = update(idx, nl, mid, 2 * n) + update(idx, mid + 1, nr, 2 * n + 1);
}

int query(int l, int r, int nl, int nr, int n) {
    if (l > nr || r < nl) return 0;
    if (l <= nl && r >= nr) return seg[n];
    int mid = (nl + nr) / 2;
    return query(l, r, nl, mid, 2 * n) + query(l, r, mid + 1, nr, 2 * n + 1);
}

void solve() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
        v.push_back({a[i], i});
    }
    sort(v.begin(), v.end());
    cin >> M;
    for (int i = 0; i < M; i++) {
        cin >> l >> r >> k;
        q.push_back({k, l - 1, r - 1, i});
    }
    sort(q.begin(), q.end());
    int idx = N - 1;
    for (int i = M - 1; i >= 0; i--) {
        while (idx >= 0 && q[i][0] < v[idx][0]) {
            update(v[idx][1], 0, N - 1, 1);
            idx--;
        }
        ans[q[i][3]] = query(q[i][1], q[i][2], 0, N - 1, 1);
    }
    for (int i = 0; i < M; i++) {
        cout << ans[i] << '\n';
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