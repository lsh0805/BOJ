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

ll x[2][2], y[2][2];

ll ccw(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3) {
    return (x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1);
}

ld get_distance(ll x1, ll y1, ll x2, ll y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int sign(ll num) {
    if (num > 0) return 1;
    if (num < 0) return -1;
    return 0;
}

void solve() {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cin >> x[i][j] >> y[i][j];
        }
    }
    int dir[2][2] = {{0, 0}, {0, 0}};
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            ll res = ccw(x[i][0], y[i][0], x[i][1], y[i][1], x[(i + 1) % 2][j], y[(i + 1) % 2][j]);
            if (res == 0) {
                ld dist_a = get_distance(x[i][0], y[i][0], x[(i + 1) % 2][j], y[(i + 1) % 2][j]);
                ld dist_b = get_distance(x[i][1], y[i][1], x[(i + 1) % 2][j], y[(i + 1) % 2][j]);
                ld dist_c = get_distance(x[i][0], y[i][0], x[i][1], y[i][1]);
                if (dist_a + dist_b >= dist_c - EPS && dist_a + dist_b <= dist_c + EPS) {
                    cout << "1";
                    return;
                }
            }
            dir[(i + 1) % 2][j] = sign(res);
        }
    }
    // dbg(dir[0][0], dir[0][1], dir[1][0], dir[1][1]);
    if ((dir[0][0] != dir[0][1]) && (dir[1][0] != dir[1][1])) {
        cout << "1";
    } else {
        cout << "0";
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