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

const int S = 0;
const int E = 450;

int N, M, f[451][451], c[451][451], n, v, p[451];

void solve() {
    cin >> N >> M;
    vector<vector<int>> adj(E + 1);
    for (int i = 1; i <= N; i++) {
        cin >> n;
        for (int j = 0; j < n; j++) {
            cin >> v;
            c[i][N + v] = 1;
            adj[i].push_back(N + v);
            adj[N + v].push_back(i);
        }
    }
    for (int i = 1; i <= N; i++) {
        c[S][i] = 1;
        adj[S].push_back(i);
        adj[i].push_back(S);
    }
    for (int i = 1; i <= M; i++) {
        c[N + i][E] = 1;
        adj[E].push_back(N + i);
        adj[N + i].push_back(E);
    }
    while (true) {
        queue<pii> q;
        q.push({S, 2});
        vector<bool> visited(E + 1, false);
        visited[S] = true;
        bool flag = false;
        while (!q.empty()) {
            int qsize = q.size();
            for (int i = 0; i < qsize; i++) {
                auto front = q.front();
                int curr = front.fi;
                q.pop();
                if (curr == E) {
                    while (curr != S) {
                        int prev = p[curr];
                        int d = front.se;
                        f[prev][curr] += d;
                        f[curr][prev] -= d;
                        curr = prev;
                        flag = true;
                    }
                    break;
                }
                for (int next : adj[curr]) {
                    if (visited[next] || f[curr][next] == c[curr][next]) continue;
                    p[next] = curr;
                    q.push({next, min(front.se, c[curr][next] - f[curr][next])});
                    visited[next] = true;
                }
            }
            if (flag) break;
        }
        if (!flag) break;
    }
    int ans = 0;
    for (int i = 1; i <= M; i++) {
        ans += f[N + i][E];
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