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

int N, M, x, y, a, b, dy[4] = {-1, 1, 0, 0}, dx[4] = {0, 0, -1, 1}, ans;
vector<pii> adj[101][101];
bool visited[101][101], on[101][101];
queue<pii> q;

void solve() {
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        cin >> x >> y >> a >> b;
        adj[y][x].push_back({b, a});
    }
    q.push({1, 1});
    visited[1][1] = true;
    on[1][1] = true;
    while (!q.empty()) {
        int qsize = q.size();
        for (int i = 0; i < qsize; i++) {
            auto front = q.front();
            q.pop();
            int cy = front.fi;
            int cx = front.se;
            dbg(cx, cy);
            for (int j = 0; j < 4; j++) {
                int ny = cy + dy[j];
                int nx = cx + dx[j];
                if (ny <= 0 || ny > N || nx <= 0 || nx > N || visited[ny][nx] || !on[ny][nx]) continue;
                visited[ny][nx] = true;
                q.push({ny, nx});
            }
            for (auto nxt : adj[cy][cx]) {
                if (visited[nxt.fi][nxt.se]) continue;
                on[nxt.fi][nxt.se] = true;
                for (int j = 0; j < 4; j++) {
                    int ny = nxt.fi + dy[j];
                    int nx = nxt.se + dx[j];
                    if (visited[ny][nx]) {
                        visited[nxt.fi][nxt.se] = true;
                        q.push({nxt.fi, nxt.se});
                        break;
                    }
                }
            }
        }
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (on[i][j]) {
                ans++;
            }
        }
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