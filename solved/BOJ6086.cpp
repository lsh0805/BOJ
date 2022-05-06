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

const int S = 26;
const int E = 51;

int N, f[52][52], c[52][52];
vector<int> adj[52];

int ctoi(char c) {
    if (c >= 'a' && c <= 'z')
        return c - 'a';
    else
        return c - 'A' + 26;
}

void solve() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        char a, b;
        int add;
        cin >> a >> b >> add;
        int u = ctoi(a);
        int v = ctoi(b);
        if (c[u][v] == 0 && c[v][u] == 0) {
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        c[u][v] = c[v][u] += add;
    }
    int ans = 0;
    while (true) {
        queue<int> q;
        vector<int> prev(E + 1, -1);
        q.push(S);
        while (!q.empty() && prev[E] == -1) {
            int curr = q.front();
            q.pop();
            for (int next : adj[curr]) {
                if (c[curr][next] - f[curr][next] > 0 && prev[next] == -1) {
                    prev[next] = curr;
                    if (next == E) break;
                    q.push(next);
                }
            }
        }
        int flow = 1e5;
        if (prev[E] == -1) break;
        for (int curr = E; curr != S; curr = prev[curr]) {
            flow = min(flow, c[prev[curr]][curr] - f[prev[curr]][curr]);
        }
        for (int curr = E; curr != S; curr = prev[curr]) {
            f[prev[curr]][curr] += flow;
            f[curr][prev[curr]] -= flow;
        }
        ans += flow;
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