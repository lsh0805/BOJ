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

const int S = 0, E = 2001, W = 1000;
int N, M, c[2002][2002], f[2002][2002], n, x, y, p[2002];
bool visited[2002];

vector<vector<int>> adj;

void reset() {
    for (int i = S; i <= E; i++) {
        visited[i] = false;
    }
}

void solve() {

    cin >> N >> M;

    adj = vector<vector<int>>(2002);
    for (int x = 1; x <= N; x++) {
        cin >> n;
        adj[S].push_back(x);
        adj[x].push_back(S);
        c[S][x] = 2;
        for (int j = 0; j < n; j++) {
            cin >> y;
            y += W;
            c[x][y] = 1;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
    }

    for (int i = 1 + W; i <= M + W; i++) {
        adj[i].push_back(E);
        adj[E].push_back(i);
        c[i][E] = 1;
    }

    int ans = 0;
    while (true) {
        reset();
        queue<int> q = queue<int>();
        q.push(S);
        visited[S] = true;
        bool flag = false;
        while (!q.empty()) {
            int qsize = q.size();
            for (int i = 0; i < qsize; i++) {
                int curr = q.front();
                q.pop();
                if (curr == E) {
                    flag = true;
                    break;
                }
                for (int next : adj[curr]) {
                    if (!visited[next] && c[curr][next] > f[curr][next]) {
                        visited[next] = true;
                        p[next] = curr;
                        q.push(next);
                    }
                }
            }
        }
        if (!flag) {
            break;
        }

        int curr = E;

        while (true) {
            f[p[curr]][curr]++;
            f[curr][p[curr]]--;
            if (p[curr] == 0) break;
            curr = p[curr];
        }

        ans++;
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