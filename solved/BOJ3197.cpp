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

const int MAX_N = 1500 + 1;
const ll MOD = 1e9 + 7;
const ll MOD1 = 998'244'353;
const ll INF = 1e9;
const ld EPS = 1e-9;

int R, C, dy[4] = {0, -1, 1, 0}, dx[4] = {-1, 0, 0, 1}, p[MAX_N * MAX_N + 1], r[MAX_N * MAX_N + 1];
int a_y = -1, a_x, b_y, b_x;
bool visited[MAX_N][MAX_N], ready[MAX_N][MAX_N];
char m[MAX_N][MAX_N];
queue<pii> q;

int cvt(int y, int x) {
    return y * MAX_N + x;
}

void init() {
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            p[cvt(i, j)] = cvt(i, j);
        }
    }
}

int parent(int u) {
    if (u == p[u]) return u;
    return p[u] = parent(p[u]);
}

void merge(int u, int v) {
    u = parent(u), v = parent(v);
    if (u == v) return;
    if (r[u] < r[v]) swap(u, v);
    p[v] = u;
    if (r[u] == r[v]) r[u]++;
}

void dfs(int y, int x) {
    visited[y][x] = true;
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i], nx = x + dx[i];
        if (ny < 0 || ny >= R || nx < 0 || nx >= C) continue;
        if (m[ny][nx] == 'X') {
            if (ready[ny][nx]) continue;
            q.push({ny, nx});
            ready[ny][nx] = true;
            continue;
        } else {
            merge(cvt(y, x), cvt(ny, nx));
            if (visited[ny][nx]) continue;
        }
        dfs(ny, nx);
    }
}

int melting() {
    int ret = 0;
    while (!q.empty()) {
        if (parent(cvt(a_y, a_x)) == parent(cvt(b_y, b_x))) return ret;
        int qsize = q.size();
        for (int i = 0; i < qsize; i++) {
            auto front = q.front();
            q.pop();
            int y = front.fi, x = front.se;
            m[y][x] = '.';
            for (int j = 0; j < 4; j++) {
                int ny = y + dy[j], nx = x + dx[j];
                if (ny < 0 || ny >= R || nx < 0 || nx >= C) continue;
                if (m[ny][nx] == 'X') {
                    if (ready[ny][nx]) continue;
                    q.push({ny, nx});
                    ready[ny][nx] = true;
                    continue;
                } else {
                    merge(cvt(y, x), cvt(ny, nx));
                }
            }
        }
        ret++;
    }
    return ret;
}

void solve() {
    cin >> R >> C;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> m[i][j];
            if (m[i][j] == 'L') {
                if (a_y == -1) {
                    a_y = i;
                    a_x = j;
                } else {
                    b_y = i;
                    b_x = j;
                }
            }
        }
    }
    init();
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (m[i][j] != 'X' && !visited[i][j])
                dfs(i, j);
        }
    }
    cout << melting();
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