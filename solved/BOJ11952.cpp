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

typedef pair<ll, int> pii;

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll MOD1 = 998'244'353;
const ll INF = 1e12;
const ld EPS = 1e-9;

int N, M, K, S;
ll d[MAX_N], P, Q;
vector<vector<int>> adj;
bool invaded[MAX_N], danger[MAX_N];

void solve() {
    cin >> N >> M >> K >> S;
    cin >> P >> Q;
    adj.resize(N + 1);
    queue<pii> q;
    for (int i = 1; i <= N; i++) {
        d[i] = INF;
    }
    int u, v;
    for (int i = 0; i < K; i++) {
        cin >> u;
        invaded[u] = true;
        q.push({u, 0});
    }
    for (int i = 0; i < M; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    while (!q.empty()) {
        int qsize = q.size();
        for (int i = 0; i < qsize; i++) {
            auto front = q.front();
            int curr = front.fi;
            int move = front.se;
            q.pop();
            if (move == S) {
                continue;
            }
            for (int next : adj[curr]) {
                if (invaded[next] || danger[next]) continue;
                q.push({next, move + 1});
                danger[next] = true;
            }
        }
    }
    priority_queue<pii> pq;
    pq.push({0, 1});
    d[1] = 0;
    while (!pq.empty()) {
        auto top = pq.top();
        int curr = top.se;
        ll cost = -top.fi;
        pq.pop();
        if (d[curr] < cost) continue;
        if (curr == N) break;
        for (int next : adj[curr]) {
            if (invaded[next]) continue;
            ll nc = cost + (danger[next] ? Q : P);
            if (d[next] > nc) {
                d[next] = nc;
                pq.push({-nc, next});
            }
        }
    }
    cout << d[N] - (danger[N] ? Q : P);
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