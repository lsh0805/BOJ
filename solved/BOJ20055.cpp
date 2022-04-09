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

int N, K;
void solve() {
    cin >> N >> K;
    vector<int> d(2 * N);
    vector<bool> r(N, false);
    for (int i = 0; i < 2 * N; i++)
        cin >> d[i];
    int ans = 0;
    while (K > 0) {
        rotate(d.rbegin(), d.rbegin() + 1, d.rend());
        rotate(r.rbegin(), r.rbegin() + 1, r.rend());
        if (r.back()) {
            r[N - 1] = false;
        }
        // dbg(d, r);
        for (int i = N - 2; i >= 0; i--) {
            if (r[i] && !r[i + 1] && d[i + 1] > 0) {
                r[i] = false;
                r[i + 1] = true;
                if (--d[i + 1] == 0)
                    K--;
                if (i + 1 == N - 1)
                    r[i + 1] = false;
            }
        }
        if (d[0] != 0) {
            if (--d[0] == 0)
                K--;
            r[0] = true;
        }
        // dbg(K);
        ans++;
    }
    cout << ans << "\n";
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