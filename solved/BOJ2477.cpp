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

int K, d, l, dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};

int getArea(pii l, pii r) {
    int w = abs(l.se - r.se);
    int h = abs(l.fi - r.fi);
    return w * h;
}

void solve() {
    cin >> K;
    pii p[6];
    for (int i = 0; i < 6; i++) {
        cin >> d >> l;
        d--;
        if (i == 0) {
            p[0] = {l * dy[d], l * dx[d]};
        } else {
            p[i] = {p[i - 1].fi + l * dy[d], p[i - 1].se + l * dx[d]};
        }
    }
    sort(p, p + 6);
    int area = 0;
    if (p[3].se == p[4].se) {
        area = getArea(p[0], p[3]) + getArea(p[4], p[1]);
    } else if (p[0].se == p[3].se) {
        area = getArea(p[0], p[5]) + getArea(p[4], p[3]);
    } else if (p[1].se == p[2].se) {
        area = getArea(p[0], p[2]) + getArea(p[4], p[3]);
    } else if (p[2].se == p[5].se) {
        area = getArea(p[0], p[5]) + getArea(p[2], p[1]);
    }
    cout << area * K;
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