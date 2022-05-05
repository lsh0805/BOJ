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

int N, K, M, d[1001], m[1001][1001];
bool visited[100001];
vector<vector<int>> adj;

void solve() {
    cin >> N >> K >> M;
    adj = vector<vector<int>>(N + 1);
    queue<int> q;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < K; j++) {
            cin >> m[i][j];
            adj[m[i][j]].push_back(i);
            if (m[i][j] == 1) {
                visited[1] = true;
                d[i] = 1;
                q.push(i);
            }
        }
    }
    if (N == 1 && visited[1]) {
        cout << 1;
        return;
    } else {
        int ans = 1;
        while (!q.empty()) {
            int qsize = q.size();
            for (int i = 0; i < qsize; i++) {
                int curr = q.front();
                q.pop();
                for (int x = 0; x < K; x++) {
                    if (visited[m[curr][x]]) continue;
                    if (m[curr][x] == N) {
                        cout << d[curr] + 1;
                        return;
                    }
                    visited[m[curr][x]] = true;
                    for (int next : adj[m[curr][x]]) {
                        if (d[next] == 0) {
                            q.push(next);
                            d[next] = d[curr] + 1;
                        }
                    }
                }
            }
            ans++;
        }
        cout << "-1";
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