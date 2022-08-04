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

typedef struct Point {
    ll x, y;
} Point;

typedef struct Line {
    Point p1, p2;
} Line;

ll ccw(const Point &p1, const Point &p2, const Point &p3) {
    return (p2.x - p1.x) * (p3.y - p1.y) - (p3.x - p1.x) * (p2.y - p1.y);
}

ld get_dist(const Point &p1, const Point &p2) {
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

int sign(ll num) {
    if (num > 0) return 1;
    if (num < 0) return -1;
    return 0;
}

bool is_cross(const Line &l1, const Line &l2) {
    ll c1 = ccw(l1.p1, l1.p2, l2.p1);
    ll c2 = ccw(l1.p1, l1.p2, l2.p2);
    ll c3 = ccw(l2.p1, l2.p2, l1.p1);
    ll c4 = ccw(l2.p1, l2.p2, l1.p2);
    ld d1 = get_dist(l1.p1, l1.p2);
    ld d2 = get_dist(l2.p1, l2.p2);

    ld d1_1 = get_dist(l1.p1, l2.p1);
    ld d1_2 = get_dist(l1.p2, l2.p1);
    ld d1_3 = get_dist(l1.p1, l2.p2);
    ld d1_4 = get_dist(l1.p2, l2.p2);

    ld d2_1 = get_dist(l2.p1, l1.p1);
    ld d2_2 = get_dist(l2.p2, l1.p1);
    ld d2_3 = get_dist(l2.p1, l1.p2);
    ld d2_4 = get_dist(l2.p2, l1.p2);
    if (c1 == 0 && d1 <= d1_1 + d1_2 + EPS && d1 >= d1_1 + d1_2 - EPS) {
        dbg(1);
        return true;
    }
    if (c2 == 0 && d1 <= d1_3 + d1_4 + EPS && d1 >= d1_3 + d1_4 - EPS) {
        dbg(2);
        return true;
    }
    if (c3 == 0 && d2 <= d2_1 + d2_2 + EPS && d2 >= d2_1 + d2_2 - EPS) {
        dbg(3);

        return true;
    }
    if (c4 == 0 && d2 <= d2_3 + d2_4 + EPS && d2 >= d2_3 + d2_4 - EPS) {
        dbg(4);
        return true;
    }
    if (sign(c1) != sign(c2) && sign(c3) != sign(c4)) {
        dbg(5);
        return true;
    }
    return false;
}

int N, parent[3001], r[3001], cnt[3001], group;
Line l[3001];

int get_parent(int u) {
    if (parent[u] == u) return u;
    return parent[u] = get_parent(parent[u]);
}

void merge(int u, int v) {
    u = get_parent(u);
    v = get_parent(v);
    if (u == v) return;
    if (r[u] < r[v]) swap(u, v);
    if (r[u] == r[v]) r[u]++;
    parent[v] = u;
}

void solve() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> l[i].p1.x >> l[i].p1.y >> l[i].p2.x >> l[i].p2.y;
    }
    for (int i = 0; i < N; i++)
        parent[i] = i;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j) continue;
            if (is_cross(l[i], l[j])) {
                dbg(i, j);
                merge(i, j);
            }
        }
    }
    int max_idx = 0;
    for (int i = 0; i < N; i++) {
        int g = get_parent(i);
        if (cnt[g]++ == 0) {
            group++;
        }
        if (cnt[max_idx] < cnt[g]) {
            max_idx = g;
        }
    }
    cout << group << "\n"
         << cnt[max_idx] << "\n";
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