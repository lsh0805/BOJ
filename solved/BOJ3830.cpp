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

const int MAX_N = 1e5;
const ll MOD = 1e9 + 7;
const ll MOD1 = 998'244'353;
const ll INF = 1e14;
const ld EPS = 1e-9;

ll N, M, p[MAX_N + 1], r[MAX_N + 1], d[MAX_N + 1], a, b, w;
char c;

void init() {
    for (int i = 1; i <= N; i++) {
        p[i] = i;
        r[i] = 1;
        d[i] = 0;
    }
}

int find(int u) {
    if (p[u] == u) return u;
    return find(p[u]);
}

ll getDist(int u) {
    if (p[u] == u) return 0;
    return d[u] + getDist(p[u]);
}

ll diff(int u, int v) {
    if (find(u) != find(v)) return INF;
    return getDist(v) - getDist(u);
}

void merge(int u, int v, ll w) {
    int pu = find(u), pv = find(v);
    if (pu == pv) return;
    ll du = getDist(u), dv = getDist(v), e = du - dv + w;
    if (r[pu] < r[pv]) {
        e = dv - du - w;
        swap(pu, pv);
    }
    d[pv] = e;
    p[pv] = pu;
    if (r[pu] == r[pv]) r[pu]++;
}

bool solve() {
    cin >> N >> M;
    if (N == 0 && M == 0) return false;
    init();
    for (int i = 0; i < M; i++) {
        cin >> c;
        if (c == '!') {
            cin >> a >> b >> w;
            merge(a, b, w);
        } else {
            cin >> a >> b;
            ll res = diff(a, b);
            if (res == INF)
                cout << "UNKNOWN\n";
            else
                cout << res << '\n';
        }
    }
    return true;
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
    while (true) {
        // cout << "Case #" << t << ": ";
        if (!solve()) break;
    }
}