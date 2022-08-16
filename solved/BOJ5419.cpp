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

map<int, int> cvt_y;
int N, x, y, seg[MAX_N * 4];
vector<int> y_v;
vector<pii> v;

int update(int idx, int nl, int nr, int n) {
    if (idx < nl || idx > nr) return seg[n];
    if (idx == nl && idx == nr) return ++seg[n];
    int mid = (nl + nr) / 2;
    return seg[n] = update(idx, nl, mid, 2 * n) + update(idx, mid + 1, nr, 2 * n + 1);
}

int query(int l, int r, int nl, int nr, int n) {
    if (l > r || l > nr || r < nl) return 0;
    if (l <= nl && r >= nr) return seg[n];
    int mid = (nl + nr) / 2;
    return query(l, r, nl, mid, 2 * n) + query(l, r, mid + 1, nr, 2 * n + 1);
}

void init() {
    cvt_y.clear();
    fill(seg, seg + N * 4, 0);
    y_v.clear();
    v = vector<pii>(N);
}

void solve() {
    cin >> N;
    init();
    for (int i = 0; i < N; i++) {
        cin >> v[i].fi >> v[i].se;
        y_v.push_back(v[i].se);
        v[i].se = -v[i].se;
    }
    sort(y_v.begin(), y_v.end());
    reverse(y_v.begin(), y_v.end());
    sort(v.begin(), v.end());
    for (int i = 0; i < N; i++) {
        if (cvt_y.find(y_v[i]) == cvt_y.end()) {
            cvt_y.insert({y_v[i], cvt_y.size()});
        }
    }
    ll ans = 0;
    for (int i = 0; i < N; i++) {
        v[i].se = cvt_y[-v[i].se];
        ans += query(0, v[i].se, 0, N - 1, 1);
        update(v[i].se, 0, N - 1, 1);
    }
    cout << ans << "\n";
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}