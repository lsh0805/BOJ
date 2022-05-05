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

int N, m[101][101], dy[4] = {-1, 1, 0, 0}, dx[4] = {0, 0, -1, 1};
int visited[101][101][201];

bool bfs(int y, int x, int d) {
    queue<ar<int, 4>> q;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            for (int k = 0; k < 201; k++)
                visited[i][j][k] = 201;
    q.push({0, 0, m[y][x], m[y][x]});
    visited[y][x][m[y][x]] = m[y][x];
    while (!q.empty()) {
        int qsize = q.size();
        for (int i = 0; i < qsize; i++) {
            auto curr = q.front();
            q.pop();
            int y = curr[0];
            int x = curr[1];
            int min_ = curr[2];
            int max_ = curr[3];
            // dbg(y, x, min_, max_);
            if (y == N - 1 && x == N - 1) return true;
            for (int j = 0; j < 4; j++) {
                int ny = y + dy[j], nx = x + dx[j];
                if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue;
                int nmin = min(min_, m[ny][nx]);
                int nmax = max(max_, m[ny][nx]);
                if (nmax - nmin > d) continue;
                if (visited[ny][nx][nmin] <= nmax) continue;
                visited[ny][nx][nmin] = nmax;
                q.push({ny, nx, nmin, nmax});
            }
        }
    }
    return false;
}
void solve() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> m[i][j];
        }
    }
    int l = -1, r = 200;
    while (l < r - 1) {
        int m = (l + r) / 2;
        if (bfs(0, 0, m)) {
            r = m;
        } else {
            l = m;
        }
        // dbg(m);
    }
    cout << r;
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