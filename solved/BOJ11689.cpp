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

ll N, n;

ll gcd(ll a, ll b) {
    if (a < b) swap(a, b);
    while (a % b) {
        ll temp = a;
        a = b;
        b = temp % b;
    }
    return b;
}

void solve() {
    cin >> N;
    vector<ll> p;
    n = N;
    if (n % 2 == 0) {
        p.push_back(2);
        while (n % 2 == 0) {
            n /= 2;
        }
    }
    for (int i = 3; i <= sqrt(n) + 1; i += 2) {
        if (n % i == 0) {
            p.push_back(i);
            while (n % i == 0) {
                n /= i;
            }
        }
    }
    if (n > 1) p.push_back(n);
    int s = (int)p.size();
    dbg(s);
    ll ans = N;
    for (int i = 1; i <= (1 << s) - 1; i++) {
        ll lcm = 1;
        int cnt = 0;
        for (int temp = i, j = 0; temp; j++) {
            if (temp & 1) {
                lcm = p[j] * lcm / gcd(p[j], lcm);
                cnt++;
            }
            temp >>= 1;
        }
        if (cnt % 2) {
            ans -= N / lcm;
        } else {
            ans += N / lcm;
        }
    }
    cout << ans;
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