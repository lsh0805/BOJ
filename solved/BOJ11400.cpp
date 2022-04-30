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

int V, E, u, v, p[1000001], dfsn[1000001], cnt, scc[1000001];
vector<vector<int>> adj;
set<pii> e;
bool finished[1000001];
stack<int> st;

int dfs(int curr) {
    dfsn[curr] = ++cnt;
    int result = dfsn[curr];
    st.push(curr);
    dbg(curr);
    for (int next : adj[curr]) {
        if (p[curr] == next) continue;
        if (dfsn[next] == 0) {
            p[next] = curr;
            result = min(result, dfs(next));
        } else if (!finished[next]) {
            result = min(result, dfsn[next]);
        }
    }
    if (result == dfsn[curr]) {
        while (st.top() != curr) {
            finished[st.top()] = true;
            scc[st.top()] = curr;
            st.pop();
        }
        finished[st.top()] = true;
        scc[st.top()] = curr;
        st.pop();
    }
    return result;
}

void solve() {
    cin >> V >> E;
    adj.resize(V + 1);
    for (int i = 0; i < E; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1);
    vector<pii> ans;
    for (int i = 1; i < V + 1; i++) {
        for (int next : adj[i]) {
            if (next < i) continue;
            if (scc[next] != scc[i]) {
                ans.push_back({i, next});
            }
        }
    }
    sort(all(ans));
    cout << ans.size() << '\n';
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i].fi << " " << ans[i].se << '\n';
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