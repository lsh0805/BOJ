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

ll N, K, a[15], dp[101][(1 << 15)], r[101][15];
string s[15];

ll f(int num, int state) {
    ll &ret = dp[num][state];
    if (state == ((1 << N) - 1)) return ret = (num == 0);
    if (ret != -1) return ret;
    ret = 0;
    for (int i = 0; i < N; i++) {
        if ((state & (1 << i)) == 0)
            ret += f(r[num][i], state | (1 << i));
    }
    return ret;
}

ll gcd(ll a, ll b) {
    while (b != 0) {
        ll n = a % b;
        a = b;
        b = n;
    }
    return a;
}

void solve() {
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> s[i];
    cin >> K;
    for (int i = 0; i < 101; i++) {
        for (int j = 0; j < (1 << N); j++) {
            dp[i][j] = -1;
        }
    }
    for (int i = 0; i < N; i++) {
        for (int k = 0; k < 100; k++) {
            ll c = k % K;
            for (int j = 0; j < s[i].length(); j++) {
                c *= 10;
                c += (s[i][j] - '0');
                c %= K;
            }
            r[k][i] = c % K;
        }
    }
    ll p = f(0, 0);
    ll q = 1;
    for (int i = 1; i <= N; i++) {
        q *= i;
    }
    ll g = gcd(p, q);
    p /= g;
    q /= g;
    cout << p << "/" << q;
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