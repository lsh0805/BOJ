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

int N, M, K, A[1001], B[1001], n, w;
bool visited[1001];
vector<int> adj[1001];

bool dfs(int a) {
    visited[a] = true;
    for (int b : adj[a]) {
        if (!B[b] || !visited[B[b]] && dfs(B[b])) {
            B[b] = a;
            A[a] = b;
            return true;
        }
    }
    return false;
}

int matching() {
    int res_a = 0, res_b = 0;
    for (int i = 1; i <= N; i++) {
        fill(visited, visited + N + 1, false);
        if (dfs(i)) res_a++;
    }
    for (int i = 1; i <= N; i++) {
        fill(visited, visited + N + 1, false);
        if (dfs(i)) res_b++;
        if (res_b == K) return res_a + res_b;
    }
    return res_a + res_b;
}

void solve() {
    cin >> N >> M >> K;
    for (int i = 0; i < N; i++) {
        cin >> n;
        for (int j = 0; j < n; j++) {
            cin >> w;
            adj[i + 1].push_back(w);
        }
    }
    cout << matching();
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