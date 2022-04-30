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

int N, M;
vector<pii> seg(4 * MAX_N, {INF, INF});

pii update(int nl, int nr, int n, int idx, int num) {
    if (nl > idx || nr < idx || nl > nr) return seg[n];
    if (nl == idx && nr == idx) return seg[n] = {num, idx};
    int mid = (nl + nr) / 2;
    return seg[n] = min(update(nl, mid, 2 * n, idx, num), update(mid + 1, nr, 2 * n + 1, idx, num));
}

pii query(int nl, int nr, int n, int l, int r) {
    if (nl > nr || nl > r || nr < l) return {INF, INF};
    if (l <= nl && r >= nr) return seg[n];
    int mid = (nl + nr) / 2;
    return min(query(nl, mid, 2 * n, l, r), query(mid + 1, nr, 2 * n + 1, l, r));
}

void solve() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        int val;
        cin >> val;
        update(1, N, 1, i, val);
    }
    cin >> M;
    int a, b, c;
    for (int i = 0; i < M; i++) {
        cin >> a >> b >> c;
        if (a == 1) {
            update(1, N, 1, b, c);
        } else {
            cout << query(1, N, 1, b, c).se << '\n';
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