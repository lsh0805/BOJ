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

int N, dp[6][MAX_N];
string str, unist = "UNIST";

int convert(const char &c) {
    if (c == 'U') return 0;
    if (c == 'N') return 1;
    if (c == 'I') return 2;
    if (c == 'S') return 3;
    if (c == 'T') return 4;
    return -1;
}

void solve() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> str;
        for (int j = 0; j < 5; j++) {
            int idx = j + convert(str[0]);
            if (idx == -1) break;
            if (j < str.length() && idx < 5 && str[j] == unist[idx]) {
                if (idx == 0) {
                    dp[idx][i] = 1;
                } else if (j == 0) {
                    dp[idx][i] = dp[idx - 1][i - 1];
                } else {
                    dp[idx][i] = dp[idx - 1][i];
                }
                dp[idx][i] %= MOD;
            } else {
                break;
            }
        }
        for (int j = 0; j < 5; j++) {
            dp[j][i] += dp[j][i - 1];
            dp[j][i] %= MOD;
        }
    }
    cout << dp[4][N];
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