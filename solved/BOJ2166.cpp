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

typedef pair<ll, ll> pii;

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll MOD1 = 998'244'353;
const ll INF = 1e9;
const ld EPS = 1e-9;

int N;
pii p[10001];

int sign(ll a) {
    if (a == 0) return 0;
    return (a > 0 ? 1 : -1);
}

void solve() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> p[i].fi >> p[i].se;
    }
    ll r = 0, ans = 0;
    for (int i = 1; i < N - 1; i++) {
        pii a = {p[i].fi - p[0].fi, p[i].se - p[0].se};
        pii b = {p[i + 1].fi - p[0].fi, p[i + 1].se - p[0].se};
        ll ccw = a.fi * b.se - a.se * b.fi;
        dbg(ccw);
        r += ccw % 2;
        ans += ccw / 2;
    }
    ans += r / 2;
    if (r != 0 && sign(ans) != sign(r)) {
        ans = abs(ans) - 1;
    }
    ans = abs(ans);
    cout << ans << (r % 2 != 0 ? ".5" : ".0");
}

int main() {
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