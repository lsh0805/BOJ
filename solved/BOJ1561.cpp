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

long long N, M, m[10001];

ll test(ll num) {
    num++;
    ll ret = 0;
    for (int i = 0; i < M; i++) {
        ret += num / m[i] + (ll)(num % m[i] != 0);
    }
    return ret;
}
ll get_last(ll time) {
    ll a = M;
    for (int i = 0; i < M; i++)
        a += (time - 1) / m[i];
    for (int i = 0; i < M; i++) {
        a += (ll)(time % m[i] == 0);
        if (a == N) return i + 1;
    }
    assert(false);
    return -1;
}
void solve() {
    cin >> N >> M;
    for (int i = 0; i < M; i++)
        cin >> m[i];
    if (N <= M) {
        cout << N;
        return;
    }
    ll l = 0, r = 6e10;
    while (l + 1 < r) {
        ll mid = (l + r) / 2;
        ll result = test(mid);
        if (result >= N) {
            r = mid;
        } else {
            l = mid;
        }
    }
    if (test(r - 1) >= N) r--;
    dbg(r);
    cout << get_last(r);
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