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

int N, T;
ll a[101][(1 << 4)];

void cal() {
    a[0][0] = 1;
    a[1][0] = 1;
    a[1][1 + 8] = 1;
    a[1][1 + 2] = 1;
    a[1][4 + 8] = 1;
    for (int i = 2; i <= 100; i++) {
        a[i][0] = a[i - 2][0] + a[i - 1][1 + 8] + a[i - 1][1 + 2] + a[i - 1][4 + 8] + a[i - 1][0];
        a[i][1 + 2] = a[i - 1][0] + a[i - 1][4 + 8];
        a[i][1 + 4] = a[i - 1][2 + 8];
        a[i][1 + 8] = a[i - 1][0] + a[i - 1][2 + 4];
        a[i][2 + 4] = a[i - 1][1 + 8];
        a[i][2 + 8] = a[i - 1][1 + 4];
        a[i][4 + 8] = a[i - 1][0] + a[i - 1][1 + 2];
        if (a[i][0] >= 2e9) break;
    }
}

void solve() {
    cin >> N;
    cout << a[N][0] << '\n';
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cal();
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}