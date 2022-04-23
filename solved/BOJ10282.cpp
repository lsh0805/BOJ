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

int N, D, C, ans, S, a, b, s, d[10001];
vector<vector<pii>> adj;
void solve() {
    ans = 0;
    S = 0;
    for (int i = 0; i < 10001; i++)
        d[i] = INF;
    cin >> N >> D >> C;
    adj = vector<vector<pii>>(N + 1);
    for (int i = 0; i < D; i++) {
        cin >> a >> b >> s;
        adj[b].push_back({a, s});
    }
    priority_queue<pii> pq;
    d[C] = 0;
    pq.push({0, C});
    while (!pq.empty()) {
        auto front = pq.top();
        pq.pop();
        int curr = front.se;
        int cost = -front.fi;
        if (d[curr] < cost) continue;
        S = max(S, cost);
        for (auto next : adj[curr]) {
            int nc = cost + next.se;
            int nv = next.fi;
            if (d[nv] > nc) {
                d[nv] = nc;
                pq.push({-nc, nv});
            }
        }
    }
    ans = N;
    for (int i = 1; i <= N; i++) {
        if (d[i] == INF)
            ans--;
    }
    cout << ans << " " << S << "\n";
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