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

int N, M, dx[4] = {0, 0, -1, 1}, dy[4] = {-1, 1, 0, 0};
bool visited[101][101];
char m[101][101];
pii ans = {0, 0};
string str;

pii f(int y, int x, int keys);

bool open(char door, int keys) {
    return ((1 << (door - 'A')) & keys) != 0;
}

pii dfs(int y, int x, int keys) {
    visited[y][x] = true;
    pii ret = {keys, m[y][x] == '$'};
    if (m[y][x] >= 'a' && m[y][x] <= 'z') {
        ret.fi |= (1 << (m[y][x] - 'a'));
        keys = ret.fi;
    }
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i], nx = x + dx[i];
        auto res = f(ny, nx, keys);
        ret = make_pair(ret.fi | res.fi, ret.se + res.se);
    }
    return ret;
}

pii f(int y, int x, int keys) {
    pii ret = {0, 0};
    if (y < 0 || y >= N || x < 0 || x >= M || m[y][x] == '*' || visited[y][x]) return {0, 0};
    if (m[y][x] >= 'A' && m[y][x] <= 'Z' && !open(m[y][x], keys)) return {0, 0};
    return dfs(y, x, keys);
}

void solve() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> m[i][j];
        }
    }
    cin >> str;
    ans = {0, 0};
    if (str != "0") {
        for (int i = 0; i < str.length(); i++) {
            int key = str[i] - 'a';
            ans.fi |= (1 << key);
        }
    }
    for (int i = 0; i < 27; i++) {
        pii res = {0, 0};
        for (int y = 0; y < N; y++)
            for (int x = 0; x < M; x++)
                visited[y][x] = false;
        for (int j = 0; j < N; j++) {
            auto temp = f(j, 0, ans.fi);
            res = {res.fi | temp.fi, res.se + temp.se};
            // dbg(j, res);
        }
        for (int j = 0; j < N; j++) {
            auto temp = f(j, M - 1, ans.fi);
            res = {res.fi | temp.fi, res.se + temp.se};
        }
        for (int j = 0; j < M; j++) {
            auto temp = f(0, j, ans.fi);
            res = {res.fi | temp.fi, res.se + temp.se};
        }
        for (int j = 0; j < M; j++) {
            auto temp = f(N - 1, j, ans.fi);
            res = {res.fi | temp.fi, res.se + temp.se};
        }
        ans = {ans.fi | res.fi, res.se};
    }
    cout << ans.se << '\n';
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}