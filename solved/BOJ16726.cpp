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

int N, M, A[2501], B[2501], dy[4] = {-1, 1, 0, 0}, dx[4] = {0, 0, -1, 1}, ans, match;
vector<int> adj[2501];
bool visited[2501];
char m[51][51];

bool dfs(int a) {
    visited[a] = true;
    for (int b : adj[a]) {
        if (B[b] == -1 || !visited[B[b]] && dfs(B[b])) {
            A[a] = b;
            B[b] = a;
            return true;
        }
    }
    return false;
}

void solve() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> m[i][j];
            if (m[i][j] == '.') ans++;
        }
    }
    fill(A, A + 2501, -1);
    fill(B, B + 2501, -1);
    int id = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i % 2; j < M; j += 2) {
            for (int k = 0; k < 4; k++) {
                if (m[i][j] == 'X') continue;
                int ny = i + dy[k], nx = j + dx[k];
                if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
                if (m[ny][nx] == '.') {
                    adj[i * M + j].push_back(ny * M + nx);
                    dbg(i, j, ny, nx);
                }
            }
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = i % 2; j < M; j += 2) {
            fill(visited, visited + 2501, false);
            if (dfs(i * M + j)) {
                match++;
            }
        }
    }
    dbg(match);
    ans -= match;
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