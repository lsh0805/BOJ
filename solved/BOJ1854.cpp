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

typedef pair<ll, ll> pii;

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll MOD1 = 998'244'353;
const ll INF = 1e9;
const ld EPS = 1e-9;

int N, M, K;
vector<ll> dist[1001];
vector<vector<pii>> e;
priority_queue<pii> pq;

void solve() {
    cin >> N >> M >> K;
    e.resize(N + 1);
    for (int i = 0; i < M; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        e[u].push_back({v, c});
    }
    dist[1].push_back(0);
    pq.push({0, 1});
    while (!pq.empty()) {
        auto top = pq.top();
        pq.pop();
        int curr = top.se;
        ll d = -top.fi;
        if (d > dist[curr].back()) continue;
        for (auto ne : e[curr]) {
            int next = ne.fi;
            ll cost = ne.se + d;
            if (dist[next].empty()) {
                dist[next].push_back(cost);
                pq.push({-cost, next});
            } else if (cost <= dist[next].back()) {
                dist[next].push_back(cost);
                pq.push({-cost, next});
                for (int i = dist[next].size() - 1; i > 0; i--) {
                    if (dist[next][i] < dist[next][i - 1]) {
                        swap(dist[next][i], dist[next][i - 1]);
                    } else {
                        break;
                    }
                }
                // if (*lower_bound(dist[next].begin(), dist[next].end(), cost) != cost) {
                //     dist[next].push_back(cost);
                //     for (int i = dist[next].size() - 1; i > 0; i--) {
                //         if (dist[next][i] < dist[next][i - 1]) {
                //             swap(dist[next][i], dist[next][i - 1]);
                //         } else {
                //             break;
                //         }
                //     }
                // }
            } else if (cost > dist[next].back() && dist[next].size() < K) {
                dist[next].push_back(cost);
                pq.push({-cost, next});
            }
            if (dist[next].size() > K) dist[next].pop_back();
        }
    }
    for (int i = 1; i <= N; i++) {
        cout << (dist[i].size() == K ? dist[i][K - 1] : -1) << '\n';
    }
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