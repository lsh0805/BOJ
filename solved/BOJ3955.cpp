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

ll K, C;

ll f(ll a, ll b) {
    ll r1 = a, r2 = b, r = 0;
    ll s1 = 1, s2 = 0, s = 0;
    ll t1 = 0, t2 = 1, t = 0;
    while (r2 != 0) {
        ll q = r1 / r2;
        r = r1 % r2;
        r1 = r2;
        r2 = r;
        s = s1 - q * s2;
        s1 = s2;
        s2 = s;
        t = t1 - q * t2;
        t1 = t2;
        t2 = t;
    }
    dbg(r1, s1, t1);

    if (r1 == 1) {
        while (s1 >= 0 || t1 <= 0) {
            s1 -= b;
            t1 += a;
        }
        return t1;
    } else
        return -1;
}

void solve() {
    cin >> K >> C;
    if (K == 1 && C == 1) {
        cout << "2\n";
        return;
    }
    ll res = f(K, C);

    if (res == -1 || res > 1e9)
        cout << "IMPOSSIBLE\n";
    else
        cout << res << '\n';
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